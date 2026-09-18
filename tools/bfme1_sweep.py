#!/usr/bin/env python3
"""Find BFME 1 source files whose bodies are byte-identical in BFME 2's game.dat.

BFME 1 and BFME 2 are the same SAGE engine built with the same MSVC 7.1
toolchain, so a translation unit Open-BFME-1 already converted frequently emits
a function body that appears verbatim in game.dat. Open-BFME-1's ledger holds
tens of thousands of such bodies; this sweep finds the ones game.dat still has
no source for, and serves each donor FILE as a work packet, because copying the
file across is the whole conversion.

  scan      compare lotrbfme.exe against game.dat   -> build/bfme1_sweep/match.json
  ranked    the donor queue, best first
  packets   write one work packet per donor file    -> build/bfme1_sweep/packets/
  show      print one donor file's packet to stdout
  land      copy, pin, add_match and build one donor file (reverts on failure)

SCOPE: byte-exact transfers only. The BFME1-verbatim ports already in this
repo's history -- getBrightness (0x002E4A47), hasGotOnline, getRemainingAmmo --
are SOURCE-verbatim and byte-DIVERGENT: their BFME1 bodies are three to six
bytes longer and only 15-31 of ~90-105 bytes agree. No binary comparison can
find those, and this tool does not try; they belong to a compile-based sweep
like tools/zh_sweep.py. What is here is the population a copy alone lands.

Both images have a STRIPPED .reloc directory, so unlike zh_sweep.py -- which
reads DIR32/REL32 sites out of a COFF object's relocation table -- there is no
relocation table to read and the volatile bytes have to be derived from the
instruction stream:

  REL32   a four-byte field behind E8/E9 or 0F 80..0F 8F whose decoded target
          lands in .text in BOTH images
  DIR32   a four-byte dword whose value lands inside [ImageBase, +SizeOfImage)
          in BOTH images

One unexplained differing byte rejects a placement. The check on that rule is
the sweep's own output: 2,837 of its 4,331 unique placements land on an address
this repo had already matched independently, at exactly the claimed RVA and
size. Watch that number -- `scan` prints it and refuses the run if it falls --
because a drop means the mask or the explainer broke, not that the donors
moved. The remaining 1,443 placements, 161,585 bytes, are the queue.

A placement proves identical CODE, which is not identity. Two separate hazards
get their own tier rather than a footnote: a body the compiler folded inside
lotrbfme.exe carries several BFME1 names and picking one is a guess (T3), and a
DIR32 pointing at a different string literal on each side says the two bodies
are not the same function at all (T4).
"""
import argparse
import bisect
import csv
import json
import re
import shutil
import struct
import subprocess
import sys
import time
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import build

ROOT = build.ROOT
BFME1 = ROOT / "reference" / "open-bfme-1"
BFME1_EXE = BFME1 / "baselines" / "bfme1" / "workshop-vanilla-1.03" / "files" / "lotrbfme.exe"
BFME1_LEDGER = BFME1 / "reverse" / "functions.csv"
BFME2_LEDGER = ROOT / "reverse" / "functions.csv"
BFME2_SYMBOLS = ROOT / "reverse" / "symbols.csv"
OUT_DIR = ROOT / "build" / "bfme1_sweep"
MATCH_JSON = OUT_DIR / "match.json"
# Scratch, not tracked. A packet is derived from match.json and the live
# ledger, `show` prints one in under a second, and rows land continuously --
# four hundred committed packets would be stale by the end of the day. `packets`
# exists for a fleet that wants them on disk, not for the repository.
PACKET_DIR = OUT_DIR / "packets"

# Under this a body is a stub whose bytes occur all over .text. zh_sweep.py uses
# 24 against compiled COMDATs; 16 is workable here because both sides come from
# a ledger row with a proven boundary, so a short body still has a real extent.
MIN_FUNC = 16
# A needle shorter than this matches so much of .text that every placement it
# proposes has to be re-rejected by the explainer, which is the slow half.
MIN_NEEDLE = 6
# How many BFME1 .text occurrences of a needle to count before concluding the
# donor body is ICF-folded. Two is the answer; the rest is for the packet.
FANOUT_CAP = 8
# How many windows one donor's needle may propose before the donor is called
# ambiguous and dropped. Reaching it means the needle is too common to identify
# anything; the sweep never reports a capped search as a unique placement.
PLACEMENT_CAP = 4096
# A DIR32 target only counts as string evidence when it really is one.
MIN_STRING = 3

# nbench/BYTEmark ships no permission grant of any kind -- see AGENTS.md, which
# refuses it on the merits. Its donors are found and scored like any other and
# then held out of the served queue.
REFUSED_PREFIXES = {
    "Code/Libraries/Source/Benchmark/":
        "nbench/BYTEmark carries no permission grant (AGENTS.md refuses it on the merits)",
}
# Permitted, but the sources may not be vendored here until the grant statement
# is mirrored into this repo. docs/matching.md has the scope.
FLAGGED_SUBSTRINGS = {
    "GameSpy": "GameSpy SDK is permitted but needs PROVENANCE.txt mirrored here first",
}

GEN_SOURCE_PREFIXES = ("Code/gen_small", "Code/gen_asm", "Code/masm_dumps")
INCLUDE_RE = re.compile(r'^\s*#\s*include\s*([<"])([^">]+)[">]', re.M)
CL_RE = re.compile(r"^// cl:(.*)$", re.M)


class Image:
    """One retail PE, with the reads this sweep needs and nothing else."""

    def __init__(self, path):
        self.path = path
        self.data = path.read_bytes()
        self.sections = build.pe_sections(self.data)
        optional = build.u32(self.data, 0x3C) + 4 + 20
        self.base = build.u32(self.data, optional + 28)
        self.image_size = build.u32(self.data, optional + 56)
        code = next(s for s in self.sections if s["name"].lower().startswith(".text"))
        self.text_rva = code["rva"]
        start = code["raw_pointer"]
        self.text = self.data[start : start + code["raw_size"]]

    def body(self, rva, size):
        try:
            return build.read_pe_bytes(self.data, self.sections, rva, size)
        except ValueError:
            return None

    def in_image(self, va):
        return self.base <= va < self.base + self.image_size

    def in_text(self, rva):
        return self.text_rva <= rva < self.text_rva + len(self.text)

    def cstring(self, va, limit=256):
        """The NUL-terminated printable string at a virtual address, or None."""
        try:
            offset = build.rva_to_file_offset(self.sections, va - self.base)
        except ValueError:
            return None
        end = self.data.find(b"\0", offset, offset + limit)
        if end < 0:
            return None
        text = self.data[offset:end]
        if len(text) < MIN_STRING or not all(32 <= byte < 127 or byte in (9, 10, 13) for byte in text):
            return None
        return text


def volatile_fields(body, image):
    """The relocation slots in a body, as {offset: kind}, by one forward walk.

    The REL32 pass runs first and steps over each field it claims, so a
    displacement byte that happens to read as E8 cannot open a second field
    inside the first. The DIR32 pass then fills the gaps: any four-byte window
    not already spoken for whose value is an address in this image.

    One walk, one set of field boundaries -- `volatile_mask` and `explain` both
    read this rather than each deciding for itself where a field starts. That
    matters: re-deriving the window around a differing byte lets a misaligned
    dword straddling an operand and the next opcode read as an address on both
    sides and explain away a difference that is really there.
    """
    size = len(body)
    fields = {}
    claimed = bytearray(size)
    index = 0
    while index < size:
        byte = body[index]
        if byte in (0xE8, 0xE9) and index + 5 <= size:
            fields[index + 1] = "rel32"
            claimed[index + 1 : index + 5] = b"\1" * 4
            index += 5
            continue
        if byte == 0x0F and index + 6 <= size and 0x80 <= body[index + 1] <= 0x8F:
            fields[index + 2] = "rel32"
            claimed[index + 2 : index + 6] = b"\1" * 4
            index += 6
            continue
        index += 1
    for index in range(max(0, size - 3)):
        if any(claimed[index : index + 4]):
            continue
        if image.in_image(struct.unpack_from("<I", body, index)[0]):
            fields[index] = "dir32"
            claimed[index : index + 4] = b"\1" * 4
    return fields


def mask_from(fields, size):
    """A byte mask over `size` bytes covering each four-byte field."""
    mask = bytearray(size)
    for offset in fields:
        mask[offset : offset + 4] = b"\1" * 4
    return bytes(mask)


def volatile_mask(body, image):
    """Byte positions two different images cannot be expected to agree on."""
    return mask_from(volatile_fields(body, image), len(body))


def clear_runs(mask):
    """(offset, length) of every unmasked run, longest first."""
    runs = []
    start = None
    for index, flagged in enumerate(mask):
        if not flagged and start is None:
            start = index
        elif flagged and start is not None:
            runs.append((start, index - start))
            start = None
    if start is not None:
        runs.append((start, len(mask) - start))
    return sorted(runs, key=lambda run: -run[1])


def occurrences(haystack, needle, cap=None):
    """Offsets of `needle`, stopping after `cap` of them.

    A truncated search must never be read as a unique placement -- that is the
    one error this sweep cannot make -- so callers treat "returned `cap`
    offsets" as *at least* `cap`, which is ambiguous, rather than as all of
    them. Uncapped is still available and is what the ICF fan-out count wants
    for small caps, but the main search caps: a six-byte needle of common
    opcodes occurs tens of thousands of times in eight megabytes of .text, and
    checking every one of those windows costs more than the donor is worth.
    """
    found = []
    position = haystack.find(needle)
    while position >= 0:
        found.append(position)
        if cap is not None and len(found) >= cap:
            break
        position = haystack.find(needle, position + 1)
    return found


def explain(donor, donor_fields, donor_runs, window, donor_rva, target_rva,
            donor_image, target_image):
    """Account for every differing byte as a relocation, or refuse the window.

    A difference is only forgiven where BOTH sides independently place a
    relocation field of the same kind at the same offset. Deriving the field
    from one side alone is how a coincidence gets promoted to a match: a
    misaligned dword straddling an operand and the next opcode reads as an
    address in either image often enough to matter.

    The refusal is done first and in whole slices. Every byte outside a donor
    relocation field has to agree exactly, and comparing those runs as slices
    is a memcmp per run rather than a Python loop per byte -- which is what
    this costs, because a short needle proposes hundreds of windows and nearly
    all of them die here. Only survivors pay for the second field derivation.

    `donor_fields` and `donor_runs` are the same for every window of one donor,
    so they are derived once by the caller.

    Returns (unexplained, dir32, rel32). `dir32` entries are
    (offset, donor_va, target_va); `rel32` entries are
    (offset, donor_call_rva, target_call_rva).
    """
    for start, length in donor_runs:
        if donor[start : start + length] != window[start : start + length]:
            return 1, [], []

    target_fields = volatile_fields(window, target_image)
    dir32 = []
    rel32 = []
    unexplained = 0
    for offset, kind in donor_fields.items():
        donor_slot = donor[offset : offset + 4]
        target_slot = window[offset : offset + 4]
        if target_fields.get(offset) == kind:
            if kind == "rel32":
                donor_call = (donor_rva + offset + 4 + struct.unpack("<i", donor_slot)[0]) & 0xFFFFFFFF
                target_call = (target_rva + offset + 4 + struct.unpack("<i", target_slot)[0]) & 0xFFFFFFFF
                if donor_image.in_text(donor_call) and target_image.in_text(target_call):
                    rel32.append((offset, donor_call, target_call))
                    continue
            else:
                dir32.append((offset, struct.unpack("<I", donor_slot)[0],
                              struct.unpack("<I", target_slot)[0]))
                continue
        # The two sides do not agree that this is a relocation, so the slot is
        # ordinary code again and has to match byte for byte like any other.
        unexplained += sum(1 for index in range(4) if donor_slot[index] != target_slot[index])
    return unexplained, sorted(dir32), sorted(rel32)


def donor_rows(min_size):
    """Open-BFME-1's clean converted bodies: real C++ at a real Code/ path.

    gen_small/gen_asm/masm_dumps are byte-true placeholders, and a `gen-` or
    `vendored=` note says the same about a row whose path looks ordinary.
    Neither is a donor: copying one across moves a dump, not a conversion.
    """
    rows = []
    with BFME1_LEDGER.open(newline="", encoding="utf-8") as handle:
        for row in csv.DictReader(handle):
            source = row.get("source") or ""
            if not source.startswith("Code/") or source.startswith(GEN_SOURCE_PREFIXES):
                continue
            notes = row.get("notes") or ""
            if "gen-" in notes or "vendored=" in notes:
                continue
            try:
                rva = int(row["target_rva"], 16)
                size = int(row["target_size"])
            except (KeyError, ValueError, TypeError):
                continue
            if size < min_size:
                continue
            rows.append({"name": row["name"], "rva": rva, "size": size, "source": source})
    return rows


def ledger_claims(path):
    """Sorted (rva, size, name, source, notes), for interval lookup."""
    claims = []
    with path.open(newline="", encoding="utf-8") as handle:
        for row in csv.DictReader(handle):
            try:
                rva = int(row["target_rva"], 16)
                size = int(row["target_size"])
            except (KeyError, ValueError, TypeError):
                continue
            claims.append((rva, size, row["name"], row.get("source") or "", row.get("notes") or ""))
    claims.sort()
    return claims


class Claims:
    def __init__(self, claims):
        self.claims = claims
        self.starts = [claim[0] for claim in claims]
        self.names = {claim[2] for claim in claims}
        # Where the build would resolve a call to each name. A placement whose
        # call site points somewhere else is not a pin candidate, it is a
        # disagreement about the callee.
        self.addresses = {claim[2]: claim[0] for claim in claims}
        # How far back a claim can start and still reach forward into a query.
        # Walking back only until the first non-overlapping row would miss a
        # long body that starts well before a short one and spans past it.
        self.reach = max((claim[1] for claim in claims), default=0)

    def covering(self, rva, size):
        """Any claim overlapping [rva, rva+size), or None."""
        index = bisect.bisect_right(self.starts, rva + size - 1) - 1
        while index >= 0 and self.starts[index] + self.reach > rva:
            start, extent = self.claims[index][0], self.claims[index][1]
            if start < rva + size and start + extent > rva:
                return self.claims[index]
            index -= 1
        return None


BFME1_SYMBOLS = BFME1 / "reverse" / "symbols.csv"


def bfme1_names_by_rva():
    """Every name Open-BFME-1 resolves at an address, ledger rows AND pins.

    The pins matter more than they look. A donor object references the callee
    name ITS OWN source declares, which is frequently not the ledger's name for
    the body -- that is exactly why Open-BFME-1 needed a pin for it. Its
    symbols.csv is therefore the list of names a BFME 2 build of the same file
    will ask for, and pinning anything else leaves ./build.sh printing an
    unresolved symbol nobody wrote. The pins also carry ILT thunk addresses,
    which is what a call site decodes to in the first place.
    """
    names = defaultdict(list)
    with BFME1_LEDGER.open(newline="", encoding="utf-8") as handle:
        for row in csv.DictReader(handle):
            try:
                names[int(row["target_rva"], 16)].append(row["name"])
            except (KeyError, ValueError, TypeError):
                continue
    if BFME1_SYMBOLS.exists():
        with BFME1_SYMBOLS.open(newline="", encoding="utf-8") as handle:
            for row in csv.DictReader(handle):
                try:
                    address = int(row["address"], 16)
                except (KeyError, ValueError, TypeError):
                    continue
                if row["name"] not in names[address]:
                    names[address].append(row["name"])
    return names


def pinned_symbols():
    if not BFME2_SYMBOLS.exists():
        return {}
    pins = {}
    with BFME2_SYMBOLS.open(newline="", encoding="utf-8") as handle:
        for row in csv.DictReader(handle):
            try:
                pins[row["name"]] = int(row["address"], 16)
            except (KeyError, ValueError, TypeError):
                continue
    return pins


def _header_index(root):
    """Every header basename under a tree, for the tier-B resolution check."""
    index = defaultdict(list)
    for path in (root / "Code").rglob("*.h"):
        index[path.name].append(path.relative_to(root).as_posix())
    return index


_BFME2_HEADERS = None


def bfme2_headers():
    global _BFME2_HEADERS
    if _BFME2_HEADERS is None:
        _BFME2_HEADERS = _header_index(ROOT)
    return _BFME2_HEADERS


def copy_tier(source):
    """How much work moving this donor file is, and why.

    A: no project includes -- `cp` is the conversion.
    B: quotes project headers, which have to exist here too.
    C: its `// cl:` names vendored-tree include paths that are one level deeper
       in this repo (reference/open-bfme-1/reference/... not reference/...).
    D: the destination path is already taken, so the copy would clobber a body
       this repo owns; the donor needs a distinct TU name.
    """
    path = BFME1 / source
    try:
        text = path.read_text(encoding="utf-8", errors="replace")
    except OSError:
        return "D", "donor file is missing from the submodule", "", False
    cl_match = CL_RE.search(text)
    cl_line = cl_match.group(1).strip() if cl_match else ""
    stlport = "// stlport" in text
    project = [name for quote, name in INCLUDE_RE.findall(text) if quote == '"']
    if (ROOT / source).exists():
        return "D", f"{source} already exists in this repo", cl_line, stlport
    if "reference/CnC_Generals_Zero_Hour" in cl_line or "reference/shims" in cl_line:
        return "C", "// cl: include paths need the reference/open-bfme-1/ prefix", cl_line, stlport
    if project:
        # Naming which quoted headers this repo does not have yet is the whole
        # difference between "copy it" and "port a subsystem first".
        index = bfme2_headers()
        missing = sorted({name for name in project if Path(name).name not in index})
        if missing:
            note = (f"quotes {len(missing)} header(s) this repo does not have: "
                    + ", ".join(missing[:4]))
        else:
            note = f"quotes {len(set(project))} project header(s), all present here"
        return "B", note, cl_line, stlport
    return "A", "self-contained", cl_line, stlport


def policy(source):
    for prefix, reason in REFUSED_PREFIXES.items():
        if source.startswith(prefix):
            return "refused", reason
    for needle, reason in FLAGGED_SUBSTRINGS.items():
        if needle in source:
            return "flagged", reason
    return "ok", ""


def do_scan(args):
    if not BFME1_EXE.exists():
        raise SystemExit(
            f"bfme1_sweep: {BFME1_EXE.relative_to(ROOT)} is missing — "
            "run `git submodule update --init reference/open-bfme-1`")
    build.verify_baseline()
    donor_image = Image(BFME1_EXE)
    target_image = Image(build.EXE)
    print(f"bfme1 .text 0x{donor_image.text_rva:08X} {len(donor_image.text)} bytes")
    print(f"bfme2 .text 0x{target_image.text_rva:08X} {len(target_image.text)} bytes")

    claims = Claims(ledger_claims(BFME2_LEDGER))
    bfme1_names = bfme1_names_by_rva()
    rows = donor_rows(args.min_size)
    print(f"donors: {len(rows)} clean Open-BFME-1 bodies >= {args.min_size}B")

    tally = Counter()
    records = []
    started = time.monotonic()
    for position, row in enumerate(rows, 1):
        if position % 2000 == 0:
            elapsed = time.monotonic() - started
            print(f"  {position}/{len(rows)} donors, {tally['unique']} placed, "
                  f"{elapsed:.0f}s elapsed, ~{elapsed / position * (len(rows) - position):.0f}s left",
                  file=sys.stderr, flush=True)
        donor = donor_image.body(row["rva"], row["size"])
        if donor is None or len(donor) != row["size"]:
            tally["unreadable"] += 1
            continue
        donor_fields = volatile_fields(donor, donor_image)
        runs = clear_runs(mask_from(donor_fields, row["size"]))
        # Every byte outside a relocation field, as slices to memcmp per window,
        # longest first so the most discriminating comparison fails first.
        comparable = runs
        if not runs or runs[0][1] < MIN_NEEDLE:
            tally["no-needle"] += 1
            continue
        offset, length = runs[0]
        needle = donor[offset : offset + length]
        candidates = occurrences(target_image.text, needle, cap=PLACEMENT_CAP)
        if len(candidates) >= PLACEMENT_CAP:
            tally["needle-too-common"] += 1
            continue
        survivors = []
        for position in candidates:
            start = position - offset
            if start < 0 or start + row["size"] > len(target_image.text):
                continue
            target_rva = target_image.text_rva + start
            window = target_image.text[start : start + row["size"]]
            unexplained, dir32, rel32 = explain(
                donor, donor_fields, comparable, window, row["rva"], target_rva,
                donor_image, target_image)
            if unexplained == 0:
                survivors.append((target_rva, dir32, rel32))
                if len(survivors) > 1:
                    break       # already ambiguous; the rest cannot change that
        if not survivors:
            tally["no-placement"] += 1
            continue
        if len(survivors) > 1:
            tally["ambiguous"] += 1
            continue
        target_rva, dir32, rel32 = survivors[0]
        tally["unique"] += 1

        # Counted for the control figure only. Whether an address is free is
        # re-decided every time work is served -- rows land continuously, and a
        # cached verdict would send two agents at the same address.
        claim = claims.covering(target_rva, row["size"])
        if claim is not None:
            tally["claimed"] += 1
            tally["claimed-exact-boundary"] += int(claim[0] == target_rva and claim[1] == row["size"])
        else:
            tally["free"] += 1
            tally["free-bytes"] += row["size"]

        fanout = len(occurrences(donor_image.text, needle, cap=FANOUT_CAP))
        twins = []
        if fanout > 1:
            for position in occurrences(donor_image.text, needle, cap=FANOUT_CAP):
                twin_rva = donor_image.text_rva + position - offset
                twins.extend(bfme1_names.get(twin_rva, []))
            twins = sorted(set(twins))

        strings = []
        for slot, donor_va, target_va in dir32:
            donor_text = donor_image.cstring(donor_va)
            target_text = target_image.cstring(target_va)
            if donor_text is None and target_text is None:
                continue
            strings.append({
                "offset": slot,
                "bfme1": donor_text.decode("ascii", "replace") if donor_text else None,
                "bfme2": target_text.decode("ascii", "replace") if target_text else None,
                "agree": bool(donor_text) and donor_text == target_text,
            })

        # Every name the donor object might reference for this callee, not one
        # pick: a body that BFME 1 reached through an ILT thunk carries the
        # thunk's pinned name and the body's ledger name, and which one the
        # object asks for depends on how the donor source declared it.
        calls = []
        for slot, donor_call, target_call in rel32:
            calls.append({
                "offset": slot,
                "bfme1_target": donor_call,
                "bfme2_target": target_call,
                "bfme1_names": bfme1_names.get(donor_call, []),
            })

        records.append({
            "name": row["name"],
            "source": row["source"],
            "bfme1_rva": row["rva"],
            "size": row["size"],
            "bfme2_rva": target_rva,
            "fanout": fanout,
            "icf_twins": twins,
            "needle": length,
            "strings": strings,
            "calls": calls,
        })

    OUT_DIR.mkdir(parents=True, exist_ok=True)
    payload = {
        "min_size": args.min_size,
        "bfme1_exe": str(BFME1_EXE.relative_to(ROOT)),
        "bfme2_exe": str(build.EXE.relative_to(ROOT)),
        "tally": dict(tally),
        "records": records,
    }
    MATCH_JSON.write_text(json.dumps(payload, indent=1), encoding="utf-8")

    print()
    print(f"unique placements       {tally['unique']}")
    print(f"  on claimed ground     {tally['claimed']} "
          f"({tally['claimed-exact-boundary']} at exactly the claimed RVA+size)")
    print(f"  on free ground        {tally['free']}  ({tally['free-bytes']} bytes)")
    print(f"ambiguous (>1 place)    {tally['ambiguous']}")
    print(f"needle too common       {tally['needle-too-common']}")
    print(f"no placement            {tally['no-placement']}")
    print(f"no usable needle        {tally['no-needle']}")
    control = tally["claimed-exact-boundary"]
    print()
    print(f"CONTROL: {control} placements reproduce a boundary this repo matched independently.")
    if control < args.control_floor:
        print(f"bfme1_sweep: CONTROL BELOW {args.control_floor} — the mask or the explainer "
              "has regressed; do not trust this run's free candidates.", file=sys.stderr)
        return 1
    print(f"wrote {MATCH_JSON.relative_to(ROOT)}")
    return 0


# ---------------------------------------------------------------- serving work

def load_matches():
    if not MATCH_JSON.exists():
        raise SystemExit("bfme1_sweep: no build/bfme1_sweep/match.json — run `scan` first")
    return json.loads(MATCH_JSON.read_text(encoding="utf-8"))


def body_tier(record, claims, pins):
    """T1 drop-in, T2 needs pins, T3 the name is an ICF guess, T4 do not serve.

    Returns (tier, reasons, pin_lines). The order of the checks is deliberate:
    a string conflict outranks everything, because it says the placement is not
    this function however clean the bytes look.
    """
    reasons = []
    conflict = [s for s in record["strings"] if s["bfme1"] and not s["agree"]]
    if conflict:
        reasons.append(f"DIR32 string differs: {conflict[0]['bfme1']!r} vs {conflict[0]['bfme2']!r}")
        return "T4", reasons, []
    claim = claims.covering(record["bfme2_rva"], record["size"])
    if claim is not None:
        reasons.append(f"0x{claim[0]:08X} is claimed by {claim[2]} ({claim[3]})")
        return "T4", reasons, []
    if record["name"] in claims.names:
        reasons.append("this repo already spends that name at another address")
        return "T4", reasons, []
    # Resolution is re-decided here rather than trusted from the scan: pins and
    # rows land continuously, and a four-minute scan would otherwise keep
    # serving a body as "needs a pin" that somebody already pinned.
    unnamed = [call for call in record["calls"] if not call["bfme1_names"]]
    if unnamed:
        reasons.append(f"{len(unnamed)} call site(s) with no name on the BFME1 side")
        return "T4", reasons, []
    # A callee this repo already places somewhere else is not a pin to paste
    # over: it says the two images disagree about what this call site calls,
    # which is evidence against the placement rather than work to do.
    needed = {}
    for call in record["calls"]:
        for name in call["bfme1_names"]:
            settled = claims.addresses.get(name, pins.get(name))
            if settled is None:
                needed[name] = call["bfme2_target"]
            elif settled != call["bfme2_target"]:
                reasons.append(f"this repo places {name} at 0x{settled:08X}, "
                               f"but the call site reaches 0x{call['bfme2_target']:08X}")
                return "T4", reasons, []
    pin_lines = sorted(needed.items())
    if record["fanout"] > 1:
        reasons.append(f"ICF-folded in lotrbfme.exe across {record['fanout']} addresses")
        return "T3", reasons, pin_lines
    if pin_lines:
        reasons.append(f"{len(pin_lines)} symbols.csv pin(s) needed")
        return "T2", reasons, pin_lines
    agree = sum(1 for s in record["strings"] if s["agree"])
    if agree:
        reasons.append(f"{agree} DIR32 string literal(s) agree")
    return "T1", reasons, []


TIER_ORDER = {"T1": 0, "T2": 1, "T3": 2, "T4": 3}


def group_files(payload, include_refused=False, tiers=("T1", "T2", "T3")):
    claims = Claims(ledger_claims(BFME2_LEDGER))
    pins = pinned_symbols()
    files = defaultdict(lambda: {"bodies": [], "held": []})
    for record in payload["records"]:
        tier, reasons, pin_lines = body_tier(record, claims, pins)
        record = dict(record, tier=tier, reasons=reasons, pins=pin_lines)
        bucket = files[record["source"]]
        (bucket["bodies"] if tier in tiers else bucket["held"]).append(record)

    served = []
    for source, bucket in files.items():
        if not bucket["bodies"]:
            continue
        verdict, reason = policy(source)
        if verdict == "refused" and not include_refused:
            continue
        tier, note, cl_line, stlport = copy_tier(source)
        bodies = sorted(bucket["bodies"], key=lambda r: (TIER_ORDER[r["tier"]], -r["size"]))
        served.append({
            "source": source,
            "copy_tier": tier,
            "copy_note": note,
            "cl": cl_line,
            "stlport": stlport,
            "policy": verdict,
            "policy_note": reason,
            "bytes": sum(body["size"] for body in bodies),
            "best_tier": min(body["tier"] for body in bodies),
            "bodies": bodies,
            "held": bucket["held"],
        })
    served.sort(key=lambda entry: (TIER_ORDER[entry["best_tier"]],
                                   {"A": 0, "B": 1, "C": 2, "D": 3}[entry["copy_tier"]],
                                   -entry["bytes"]))
    return served


def do_ranked(args):
    payload = load_matches()
    served = group_files(payload, include_refused=args.include_refused)
    if args.copy_tier:
        served = [entry for entry in served if entry["copy_tier"] in args.copy_tier]
    if args.tier:
        served = [entry for entry in served if entry["best_tier"] in args.tier]
    if args.json:
        print(json.dumps(served[: args.limit], indent=1))
        return 0
    total = sum(entry["bytes"] for entry in served)
    print(f"{len(served)} donor file(s), {total} bytes of unclaimed game.dat .text")
    print()
    print(f"{'bytes':>7}  {'fn':>3}  tier  copy  source")
    for entry in served[: args.limit]:
        flag = "!" if entry["policy"] != "ok" else " "
        print(f"{entry['bytes']:>7}  {len(entry['bodies']):>3}  {entry['best_tier']:>4}  "
              f"{entry['copy_tier']:>4}{flag} {entry['source']}")
    if len(served) > args.limit:
        print(f"... {len(served) - args.limit} more (--limit)")
    if served:
        print()
        print(f"next: python3 tools/bfme1_sweep.py show {served[0]['source']}")
    return 0


def packet_text(entry):
    source = entry["source"]
    donor = f"reference/open-bfme-1/{source}"
    lines = []
    lines.append(f"# {source}")
    lines.append("")
    lines.append(f"{entry['best_tier']} · copy-tier {entry['copy_tier']} · "
                 f"{len(entry['bodies'])} bod{'y' if len(entry['bodies']) == 1 else 'ies'} · "
                 f"{entry['bytes']} bytes of unclaimed game.dat .text")
    lines.append("")
    lines.append(f"    donor   {donor}")
    lines.append(f"    dest    {source}")
    lines.append(f"    copy    {entry['copy_note']}")
    lines.append(f"    cl:     {entry['cl'] or '(none — build.py base flags)'}")
    lines.append(f"    stlport {'yes' if entry['stlport'] else 'no'}")
    if entry["policy"] != "ok":
        lines.append(f"    POLICY  {entry['policy'].upper()}: {entry['policy_note']}")
    lines.append("")
    lines.append("These bodies are byte-identical between lotrbfme.exe and game.dat once")
    lines.append("relocation slots are set aside, so the donor file is expected to compile to")
    lines.append("retail bytes here unchanged. A failure is a finding: record it and move on.")
    lines.append("")
    lines.append("| BFME1 name | b1 RVA | size | b2 RVA | tier | evidence |")
    lines.append("|---|---|---|---|---|---|")
    for body in entry["bodies"]:
        evidence = "; ".join(body["reasons"]) or "clean transfer"
        lines.append(f"| `{body['name']}` | 0x{body['bfme1_rva']:08X} | {body['size']} | "
                     f"0x{body['bfme2_rva']:08X} | {body['tier']} | {evidence} |")
    lines.append("")

    pins = sorted({(name, address) for body in entry["bodies"]
                   for name, address in body["pins"]})
    icf = [body for body in entry["bodies"] if body["tier"] == "T3"]
    if icf:
        lines.append("## The name is a guess on these")
        lines.append("")
        lines.append("The compiler folded these bodies inside lotrbfme.exe, so several BFME1")
        lines.append("names share the bytes and the sweep cannot tell which one game.dat means.")
        lines.append("Read AGENTS.md on over-claiming before spending a name here.")
        lines.append("")
        for body in icf:
            twins = ", ".join(f"`{name}`" for name in body["icf_twins"][:8]) or "(unnamed)"
            lines.append(f"- 0x{body['bfme2_rva']:08X}: {twins}")
        lines.append("")

    lines.append("## Steps")
    lines.append("")
    lines.append("```sh")
    lines.append(f"mkdir -p {str(Path(source).parent)}")
    lines.append(f"cp {donor} \\")
    lines.append(f"   {source}")
    lines.append(f"git add -- {source}       # check_csv refuses an untracked ledger source")
    if entry["copy_tier"] == "C":
        lines.append("# then rewrite the `// cl:` -I paths: reference/CnC_Generals_Zero_Hour/...")
        lines.append("#                              -> reference/open-bfme-1/reference/CnC_Generals_Zero_Hour/...")
    if entry["copy_tier"] == "D":
        lines.append("# the destination is occupied — give the donor a distinct TU name instead")
    lines.append("```")
    lines.append("")
    if pins:
        lines.append("Append to `reverse/symbols.csv` (LF only — the file is `merge=union` and a")
        lines.append("CRLF twin duplicates on the next rebase). Check each one first:")
        lines.append("")
        lines.append("```sh")
        for name, _ in pins:
            lines.append(f"python3 tools/pin_consistency.py --symbol '{name}'")
        lines.append("```")
        lines.append("")
        lines.append("```csv")
        for name, address in pins:
            lines.append(f"{name},0x{address:08X}")
        lines.append("```")
        lines.append("")
    else:
        lines.append("No new `reverse/symbols.csv` pin is needed: every call site this file emits")
        lines.append("already resolves through the ledger.")
        lines.append("")
    lines.append("```sh")
    for body in entry["bodies"]:
        lines.append(f"python3 tools/add_match.py '{body['name']}' 0x{body['bfme2_rva']:08X} "
                     f"{body['size']} {source} \\")
        lines.append(f"    --notes '{ledger_note(body)}'")
    lines.append(f"./build.sh {source}")
    lines.append("python3 tools/check_csv.py")
    if pins:
        lines.append("python3 tools/pin_consistency.py --check")
    lines.append("```")
    lines.append("")
    lines.append("On a refusal, revert your own work only and record the verdict:")
    lines.append("")
    lines.append("```sh")
    lines.append(f"git checkout -- reverse/functions.csv reverse/symbols.csv && rm -f {source}")
    first = entry["bodies"][0]
    lines.append(f"python3 tools/re_log.py record '{first['name']}' 0x{first['bfme2_rva']:08X} "
                 f"{first['size']} no-match 'bfme1_sweep donor <what cl did instead>'")
    lines.append("```")
    if entry["held"]:
        lines.append("")
        lines.append("## Not served from this file")
        lines.append("")
        for body in sorted(entry["held"], key=lambda r: -r["size"]):
            lines.append(f"- 0x{body['bfme2_rva']:08X} {body['size']}B `{body['name']}` — "
                         + ("; ".join(body["reasons"]) or "held"))
    lines.append("")
    return "\n".join(lines)


def ledger_note(body):
    """The notes column for one claim.

    No commas: functions.csv is raw comma-joined with no quoting, and
    add_match.py refuses a note carrying one rather than corrupt the ledger.
    """
    note = f"BFME1 byte-identical donor; b1 0x{body['bfme1_rva']:08X}"
    if body["tier"] == "T3":
        note += "; ICF-folded in BFME1 so the name is this sweep's pick among its twins"
    agree = sum(1 for entry in body["strings"] if entry["agree"])
    if agree:
        note += f"; {agree} DIR32 string literal(s) agree"
    return note


def packet_path(source):
    return PACKET_DIR / (re.sub(r"[^A-Za-z0-9]+", "_", source).strip("_") + ".md")


def do_packets(args):
    payload = load_matches()
    served = group_files(payload, include_refused=args.include_refused)
    PACKET_DIR.mkdir(parents=True, exist_ok=True)
    written = 0
    for entry in served[: args.limit]:
        path = packet_path(entry["source"])
        path.write_text(packet_text(entry), encoding="utf-8")
        written += 1
    print(f"wrote {written} packet(s) to {PACKET_DIR.relative_to(ROOT)}")
    return 0


def find_entry(served, source):
    exact = [entry for entry in served if entry["source"] == source]
    if exact:
        return exact[0]
    loose = [entry for entry in served if source in entry["source"]]
    if len(loose) == 1:
        return loose[0]
    if not loose:
        raise SystemExit(f"bfme1_sweep: no served donor file matches {source!r}")
    raise SystemExit("bfme1_sweep: ambiguous — " + ", ".join(entry["source"] for entry in loose[:8]))


def do_show(args):
    served = group_files(load_matches(), include_refused=True)
    print(packet_text(find_entry(served, args.source)))
    return 0


def do_land(args):
    """Copy one donor file, append its pins, claim its bodies, build.

    add_match.py already verifies each row and puts the ledger back when the
    row does not byte-match, so all this owns is the copy and the pin lines --
    and putting those back, which it does before it reports anything.
    """
    served = group_files(load_matches(), include_refused=args.include_refused)
    entry = find_entry(served, args.source)
    wanted = ("T1", "T2", "T3") if args.allow_icf else ("T1", "T2")
    bodies = [body for body in entry["bodies"] if body["tier"] in wanted]
    if not bodies:
        raise SystemExit(f"bfme1_sweep: {entry['source']} has no T1/T2 body "
                         "(pass --allow-icf to land its ICF-named ones)")
    if entry["policy"] == "refused":
        raise SystemExit(f"bfme1_sweep: refused — {entry['policy_note']}")
    if entry["copy_tier"] == "D":
        raise SystemExit(f"bfme1_sweep: {entry['copy_note']} — land this one by hand "
                         "under a distinct TU name")

    source = entry["source"]
    donor = BFME1 / source
    dest = ROOT / source
    pins = sorted({(name, address) for body in bodies for name, address in body["pins"]})

    print(f"donor  {donor.relative_to(ROOT)}")
    print(f"dest   {source}  (copy-tier {entry['copy_tier']}: {entry['copy_note']})")
    for name, address in pins:
        print(f"pin    {name},0x{address:08X}")
    for body in bodies:
        print(f"claim  0x{body['bfme2_rva']:08X} {body['size']:>5}B  {body['name']}")
    if args.dry_run:
        print("--dry-run: nothing written")
        return 0

    if dest.exists():
        raise SystemExit(f"bfme1_sweep: {source} already exists — landing would overwrite a "
                         "body this repo owns; resolve it by hand")
    symbols_before = BFME2_SYMBOLS.read_bytes() if BFME2_SYMBOLS.exists() else None
    dest.parent.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(donor, dest)
    # check_csv refuses a row whose source is untracked, so the copy is staged
    # as part of making it: an unstaged donor is a ledger error, not a file the
    # committer will notice later.
    subprocess.run(["git", "add", "--", source], cwd=ROOT, check=True)
    if pins:
        with BFME2_SYMBOLS.open("a", encoding="utf-8", newline="") as handle:
            for name, address in pins:
                handle.write(f"{name},0x{address:08X}\n")

    landed = []
    try:
        for body in bodies:
            command = [sys.executable, str(ROOT / "tools" / "add_match.py"), body["name"],
                       f"0x{body['bfme2_rva']:08X}", str(body["size"]), source,
                       "--notes", ledger_note(body)]
            result = subprocess.run(command, cwd=ROOT)
            if result.returncode != 0:
                raise RuntimeError(f"add_match refused {body['name']} at 0x{body['bfme2_rva']:08X}")
            landed.append(body)
    except (RuntimeError, KeyboardInterrupt) as error:
        print(f"bfme1_sweep: {error}", file=sys.stderr)
        if not landed:
            subprocess.run(["git", "rm", "--cached", "--quiet", "--", source], cwd=ROOT)
            dest.unlink(missing_ok=True)
            if symbols_before is not None:
                BFME2_SYMBOLS.write_bytes(symbols_before)
            print("bfme1_sweep: reverted the copy and the pins; the ledger was never written.",
                  file=sys.stderr)
        else:
            print(f"bfme1_sweep: {len(landed)} row(s) DID land and are verified — keep them, "
                  "and record the refusal for the rest:", file=sys.stderr)
            for body in bodies[len(landed):]:
                print(f"  python3 tools/re_log.py record '{body['name']}' "
                      f"0x{body['bfme2_rva']:08X} {body['size']} no-match "
                      "'bfme1_sweep donor: <what cl did instead>'", file=sys.stderr)
        return 1

    # A pin is an additive candidate, and a wrong one still byte-matches -- the
    # gate proves nothing about it. This is the check AGENTS.md asks for, run
    # here so `land` cannot leave a fresh inconsistency behind unreported.
    if pins:
        check = subprocess.run([sys.executable, str(ROOT / "tools" / "pin_consistency.py"), "--check"],
                               cwd=ROOT)
        if check.returncode != 0:
            print("bfme1_sweep: the rows verified but pin_consistency --check now fails. The "
                  "pins this landed are suspect even though the bytes match; resolve them "
                  "before committing.", file=sys.stderr)
            return 1
    print(f"landed {len(landed)} row(s) from {source}")
    return 0


def main(argv=None):
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    sub = parser.add_subparsers(dest="command", required=True)

    scan = sub.add_parser("scan", help="compare the two retail images")
    scan.add_argument("--min-size", type=int, default=MIN_FUNC)
    # Measured 2,837 on 2026-09-18 against the 1.03/1.06 baselines. The floor
    # sits a few percent under it so ordinary ledger churn does not trip it,
    # and RAISE it when a re-measure comes in higher -- a floor that never
    # moves stops being a check.
    scan.add_argument("--control-floor", type=int, default=2700,
                      help="fail if fewer placements reproduce a boundary this repo already matched")
    scan.set_defaults(func=do_scan)

    ranked = sub.add_parser("ranked", help="the donor queue, best first")
    ranked.add_argument("--limit", type=int, default=40)
    ranked.add_argument("--json", action="store_true")
    ranked.add_argument("--tier", action="append", choices=["T1", "T2", "T3"])
    ranked.add_argument("--copy-tier", action="append", choices=["A", "B", "C", "D"])
    ranked.add_argument("--include-refused", action="store_true",
                        help="also list donors held out on licence grounds")
    ranked.set_defaults(func=do_ranked)

    packets = sub.add_parser("packets", help="write one work packet per donor file")
    packets.add_argument("--limit", type=int, default=200)
    packets.add_argument("--include-refused", action="store_true")
    packets.set_defaults(func=do_packets)

    show = sub.add_parser("show", help="print one donor file's packet")
    show.add_argument("source")
    show.set_defaults(func=do_show)

    land = sub.add_parser("land", help="copy, pin, claim and build one donor file")
    land.add_argument("source")
    land.add_argument("--dry-run", action="store_true")
    land.add_argument("--allow-icf", action="store_true",
                      help="also land bodies whose name is an ICF guess")
    land.add_argument("--include-refused", action="store_true")
    land.set_defaults(func=do_land)

    args = parser.parse_args(argv)
    return args.func(args)


if __name__ == "__main__":
    sys.exit(main())
