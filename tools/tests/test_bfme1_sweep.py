"""What the cross-image matcher may explain away, and what it must refuse.

The sweep has no relocation table to consult -- both retail images ship with
the .reloc directory stripped -- so it decides which bytes two different builds
are allowed to disagree on by reading the instruction stream. That judgement is
the whole tool: over-explain and it invents matches out of coincidental byte
runs, under-explain and every real donor is rejected for the call displacement
it was always going to have.

The images are built as real PE32 files rather than mocked, because section
bounds are what `in_image` and `in_text` answer with, and a stub that returned
True would test nothing.
"""
import struct
import sys
from pathlib import Path

import pytest

TOOLS = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(TOOLS))

import bfme1_sweep


IMAGE_BASE = 0x00400000
TEXT_RVA = 0x1000


def make_pe(text, rdata=b"", image_size=0x100000):
    """A PE32 with one code section and one data section, nothing else."""
    headers = bytearray(0x400)
    headers[0:2] = b"MZ"
    pe = 0x80
    struct.pack_into("<I", headers, 0x3C, pe)
    headers[pe : pe + 4] = b"PE\0\0"
    coff = pe + 4
    optional_size = 0xE0
    struct.pack_into("<HHIIIHH", headers, coff, 0x014C, 2, 0, 0, 0, optional_size, 0x0102)
    optional = coff + 20
    struct.pack_into("<H", headers, optional, 0x010B)
    struct.pack_into("<I", headers, optional + 28, IMAGE_BASE)
    struct.pack_into("<I", headers, optional + 56, image_size)

    rdata_rva = TEXT_RVA + max(0x1000, (len(text) + 0xFFF) & ~0xFFF)
    table = coff + 20 + optional_size
    for index, (name, rva, payload, pointer) in enumerate(
            [(b".text", TEXT_RVA, text, 0x400),
             (b".rdata", rdata_rva, rdata, 0x400 + len(text))]):
        offset = table + index * 40
        headers[offset : offset + 8] = name.ljust(8, b"\0")
        struct.pack_into("<IIII", headers, offset + 8, len(payload), rva, len(payload), pointer)
        struct.pack_into("<I", headers, offset + 36, 0x60000020 if index == 0 else 0x40000040)
    return bytes(headers) + text + rdata


def donor_side(donor, size):
    """(body, fields, comparable runs) -- what `explain` derives once per donor."""
    body = donor.text[:size]
    fields = bfme1_sweep.volatile_fields(body, donor)
    return body, fields, bfme1_sweep.clear_runs(bfme1_sweep.mask_from(fields, size))


def image(tmp_path, name, text, rdata=b""):
    path = tmp_path / name
    path.write_bytes(make_pe(text, rdata))
    return bfme1_sweep.Image(path)


# `mov eax, <dir32>` then `call <rel32>` then `ret`, with a two-byte tail so the
# body has an unmasked run long enough to be a needle.
def body(dir32, rel32, tail=b"\x33\xC0\x8B\xFF\x5D\xC3"):
    return b"\xB8" + struct.pack("<I", dir32) + b"\xE8" + struct.pack("<i", rel32) + tail


def test_mask_covers_the_call_displacement_and_the_address_operand(tmp_path):
    donor = image(tmp_path, "a.exe", body(IMAGE_BASE + 0x2000, 0x40).ljust(0x200, b"\xCC"))
    mask = bfme1_sweep.volatile_mask(donor.text[: len(body(0, 0))], donor)
    assert mask[1:5] == b"\1" * 4, "the mov's absolute operand must be masked"
    assert mask[6:10] == b"\1" * 4, "the call's displacement must be masked"
    assert not any(mask[10:]), "the tail holds no relocation and must stay comparable"


def test_mask_does_not_open_a_second_field_inside_a_displacement(tmp_path):
    """A displacement byte that reads as 0xE8 must not start another rel32."""
    text = (b"\xE8" + struct.pack("<i", 0xE8) + b"\x90" * 16).ljust(0x200, b"\xCC")
    donor = image(tmp_path, "a.exe", text)
    mask = bfme1_sweep.volatile_mask(donor.text[:21], donor)
    assert mask[1:5] == b"\1" * 4
    assert not any(mask[5:]), "the walk must step over the field it just claimed"


def test_explain_accepts_a_body_differing_only_in_its_relocations(tmp_path):
    donor_text = body(IMAGE_BASE + 0x2000, 0x40).ljust(0x200, b"\xCC")
    target_text = body(IMAGE_BASE + 0x5000, 0x80).ljust(0x200, b"\xCC")
    donor = image(tmp_path, "a.exe", donor_text)
    target = image(tmp_path, "b.exe", target_text)
    size = len(body(0, 0))
    unexplained, dir32, rel32 = bfme1_sweep.explain(
        *donor_side(donor, size), target.text[:size], TEXT_RVA, TEXT_RVA, donor, target)
    assert unexplained == 0
    assert [slot for slot, _, _ in dir32] == [1]
    assert [slot for slot, _, _ in rel32] == [6]
    assert rel32[0][1] == TEXT_RVA + 10 + 0x40
    assert rel32[0][2] == TEXT_RVA + 10 + 0x80


def test_explain_refuses_a_changed_opcode(tmp_path):
    donor_text = body(IMAGE_BASE + 0x2000, 0x40).ljust(0x200, b"\xCC")
    target_text = bytearray(donor_text)
    target_text[10] = 0x40             # xor eax,eax -> inc eax: a real difference
    donor = image(tmp_path, "a.exe", donor_text)
    target = image(tmp_path, "b.exe", bytes(target_text))
    size = len(body(0, 0))
    unexplained, _, _ = bfme1_sweep.explain(
        *donor_side(donor, size), target.text[:size], TEXT_RVA, TEXT_RVA, donor, target)
    assert unexplained == 1, "one unexplained byte must reject the placement"


def test_explain_refuses_an_absolute_operand_that_leaves_the_image(tmp_path):
    """A dword is only a DIR32 when it addresses BOTH images; a literal that
    happens to look like an address on one side is not a licence to ignore it."""
    donor_text = body(IMAGE_BASE + 0x2000, 0x40).ljust(0x200, b"\xCC")
    target_text = body(0x7FFFFFFF, 0x40).ljust(0x200, b"\xCC")
    donor = image(tmp_path, "a.exe", donor_text)
    target = image(tmp_path, "b.exe", target_text)
    size = len(body(0, 0))
    unexplained, dir32, _ = bfme1_sweep.explain(
        *donor_side(donor, size), target.text[:size], TEXT_RVA, TEXT_RVA, donor, target)
    assert dir32 == []
    assert unexplained > 0


def test_explain_refuses_a_call_leaving_text(tmp_path):
    donor_text = body(IMAGE_BASE + 0x2000, 0x40).ljust(0x200, b"\xCC")
    target_text = body(IMAGE_BASE + 0x2000, 0x7000).ljust(0x200, b"\xCC")
    donor = image(tmp_path, "a.exe", donor_text)
    target = image(tmp_path, "b.exe", target_text)
    size = len(body(0, 0))
    unexplained, _, rel32 = bfme1_sweep.explain(
        *donor_side(donor, size), target.text[:size], TEXT_RVA, TEXT_RVA, donor, target)
    assert rel32 == [], "a displacement landing outside .text is not a call"
    assert unexplained > 0


def test_clear_runs_returns_longest_first():
    mask = bytes([0, 0, 1, 0, 0, 0, 0, 1, 0])
    assert bfme1_sweep.clear_runs(mask) == [(3, 4), (0, 2), (8, 1)]


def test_occurrences_is_uncapped_by_default():
    haystack = b"abab" * 10
    assert len(bfme1_sweep.occurrences(haystack, b"abab")) > 2
    assert len(bfme1_sweep.occurrences(haystack, b"abab", cap=2)) == 2


def test_cstring_refuses_binary_and_short_runs(tmp_path):
    rdata = b"Brightness\0\x01\x02\0ab\0"
    pe = image(tmp_path, "a.exe", b"\x90" * 0x100, rdata)
    base = IMAGE_BASE + pe.sections[1]["rva"]
    assert pe.cstring(base) == b"Brightness"
    assert pe.cstring(base + 11) is None, "non-printable bytes are not a string"
    assert pe.cstring(base + 14) is None, "a two-character run is not evidence"


class FakeClaims:
    def __init__(self, names=(), addresses=None, covering=None):
        self.names = set(names)
        self.addresses = dict(addresses or {})
        self._covering = covering

    def covering(self, rva, size):
        return self._covering


def record(**overrides):
    base = {
        "name": "?fn@@QAEXXZ", "source": "Code/GameEngine/Source/Common/X.cpp",
        "bfme1_rva": 0x900000, "size": 64, "bfme2_rva": 0x500000,
        "fanout": 1, "icf_twins": [],
        "needle": 20, "strings": [], "calls": [],
    }
    base.update(overrides)
    return base


def test_tier_string_conflict_outranks_a_clean_body():
    tier, reasons, _ = bfme1_sweep.body_tier(
        record(strings=[{"offset": 1, "bfme1": "Brightness", "bfme2": "Gamma", "agree": False}]),
        FakeClaims(), {})
    assert tier == "T4"
    assert "DIR32 string differs" in reasons[0]


def test_tier_pins_needed_is_t2_and_hands_back_the_pin_line():
    tier, reasons, pins = bfme1_sweep.body_tier(
        record(calls=[{"offset": 6, "bfme1_target": 1, "bfme2_target": 0x501234,
                       "bfme1_names": ["?callee@@YAXXZ"]}]),
        FakeClaims(), {})
    assert tier == "T2"
    assert "1 symbols.csv pin(s) needed" in reasons
    assert pins == [("?callee@@YAXXZ", 0x501234)]


def test_tier_treats_an_already_pinned_callee_as_resolved():
    """A scan is minutes stale by the time its work is served, so a pin that
    landed in between must count and take the body out of the pin tier."""
    tier, _, pins = bfme1_sweep.body_tier(
        record(calls=[{"offset": 6, "bfme1_target": 1, "bfme2_target": 0x501234,
                       "bfme1_names": ["?callee@@YAXXZ"]}]),
        FakeClaims(), {"?callee@@YAXXZ": 0x501234})
    assert tier == "T1"
    assert pins == []


def test_tier_refuses_a_callee_the_ledger_places_elsewhere():
    """A matched row disagreeing with the call site is the same finding as a
    contradicting pin, and must be caught even though the name resolves."""
    tier, reasons, _ = bfme1_sweep.body_tier(
        record(calls=[{"offset": 6, "bfme1_target": 1, "bfme2_target": 0x501234,
                       "bfme1_names": ["?callee@@YAXXZ"]}]),
        FakeClaims({"?callee@@YAXXZ"}, {"?callee@@YAXXZ": 0x777777}), {})
    assert tier == "T4"
    assert "0x00777777" in reasons[0]


def test_tier_refuses_a_callee_symbols_csv_pins_elsewhere():
    """Two images disagreeing about where a callee lives is evidence against
    the placement, not a pin to paste over the existing one."""
    tier, reasons, _ = bfme1_sweep.body_tier(
        record(calls=[{"offset": 6, "bfme1_target": 1, "bfme2_target": 0x501234,
                       "bfme1_names": ["?callee@@YAXXZ"]}]),
        FakeClaims(), {"?callee@@YAXXZ": 0x999999})
    assert tier == "T4"
    assert "0x00999999" in reasons[0] and "0x00501234" in reasons[0]


def test_tier_icf_fanout_is_t3_even_with_no_pins():
    tier, reasons, pins = bfme1_sweep.body_tier(record(fanout=3), FakeClaims(), {})
    assert pins == []
    assert tier == "T3"
    assert "ICF-folded" in reasons[0]


def test_tier_refuses_a_name_this_repo_already_spends():
    tier, reasons, _ = bfme1_sweep.body_tier(record(), FakeClaims({"?fn@@QAEXXZ"}), {})
    assert tier == "T4"
    assert "already spends that name" in reasons[0]


def test_tier_clean_body_is_t1_and_cites_its_strings():
    tier, reasons, _ = bfme1_sweep.body_tier(
        record(strings=[{"offset": 1, "bfme1": "Brightness", "bfme2": "Brightness", "agree": True}]),
        FakeClaims(), {})
    assert tier == "T1"
    assert "1 DIR32 string literal(s) agree" in reasons


def test_policy_holds_nbench_out():
    verdict, reason = bfme1_sweep.policy("Code/Libraries/Source/Benchmark/nbench1.cpp")
    assert verdict == "refused"
    assert "no permission grant" in reason
    assert bfme1_sweep.policy("Code/GameEngine/Source/Common/X.cpp")[0] == "ok"


def test_packet_names_every_step_a_lander_needs():
    entry = {
        "source": "Code/GameEngine/Source/Common/X.cpp", "copy_tier": "A",
        "copy_note": "self-contained", "cl": "/O2 /Ob0", "stlport": False,
        "policy": "ok", "policy_note": "", "bytes": 64, "best_tier": "T2",
        "bodies": [dict(record(), tier="T2", reasons=["1 symbols.csv pin(s) needed"],
                        pins=[("?callee@@YAXXZ", 0x501234)])],
        "held": [],
    }
    text = bfme1_sweep.packet_text(entry)
    assert "reference/open-bfme-1/Code/GameEngine/Source/Common/X.cpp" in text
    assert "?callee@@YAXXZ,0x00501234" in text
    assert "tools/pin_consistency.py --symbol '?callee@@YAXXZ'" in text
    assert "tools/add_match.py '?fn@@QAEXXZ' 0x00500000 64" in text
    assert "./build.sh Code/GameEngine/Source/Common/X.cpp" in text
    assert "tools/re_log.py record" in text


def test_claims_finds_a_long_body_that_starts_before_a_shorter_one():
    """A short row can sit between the query and the long row that spans it.
    Walking back only to the first non-overlapping row would return None."""
    claims = bfme1_sweep.Claims([
        (0x1000, 0x800, "?long@@YAXXZ", "Code/a.cpp", ""),
        (0x1900, 0x10, "?short@@YAXXZ", "Code/b.cpp", ""),
    ])
    assert claims.covering(0x1700, 8)[2] == "?long@@YAXXZ"
    assert claims.covering(0x1900, 8)[2] == "?short@@YAXXZ"
    assert claims.covering(0x2000, 8) is None
    assert claims.covering(0x0F00, 8) is None


def test_tier_refuses_an_address_the_ledger_already_covers():
    """Claim state is read live, not cached from the scan, so a row that landed
    since must take the address off the queue."""
    tier, reasons, _ = bfme1_sweep.body_tier(
        record(), FakeClaims(covering=(0x500000, 64, "?other@@YAXXZ", "Code/z.cpp", "")), {})
    assert tier == "T4"
    assert "?other@@YAXXZ" in reasons[0]


def test_occurrences_reports_the_cap_so_a_truncated_search_reads_as_ambiguous():
    """The caller distinguishes "all of them" from "at least this many" by the
    count alone, so hitting the cap has to be visible in the return."""
    haystack = b"ab" * 50
    assert len(bfme1_sweep.occurrences(haystack, b"ab", cap=10)) == 10
    assert len(bfme1_sweep.occurrences(haystack, b"ab")) == 50


def test_tier_pins_every_name_bfme1_knows_for_one_callee():
    """A call reached through an ILT thunk in BFME 1 carries both the thunk's
    pinned name and the body's ledger name, and which one the donor object asks
    for depends on how its source declared the callee. Pin both."""
    tier, _, pins = bfme1_sweep.body_tier(
        record(calls=[{"offset": 6, "bfme1_target": 1, "bfme2_target": 0x501234,
                       "bfme1_names": ["?thunk@@YAXXZ", "?body@@YAXXZ"]}]),
        FakeClaims(), {})
    assert tier == "T2"
    assert pins == [("?body@@YAXXZ", 0x501234), ("?thunk@@YAXXZ", 0x501234)]


def test_ledger_note_carries_no_comma():
    """functions.csv is raw comma-joined with no quoting, so add_match refuses a
    note holding one; both the packet and `land` go through this."""
    note = bfme1_sweep.ledger_note(dict(record(
        strings=[{"offset": 1, "bfme1": "x", "bfme2": "x", "agree": True}]), tier="T3"))
    assert "," not in note
    assert "0x00900000" in note and "ICF-folded" in note and "1 DIR32" in note
