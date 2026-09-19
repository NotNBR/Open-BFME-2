// B8-imm32 const-int returners: six-byte free functions with one shape:
//
//     mov eax,<IMM32> / ret
//
// Each stands on a CC-island (int3 before and after) with no Ghidra entry
// (dead emissions) and is carried in several .rdata vtable slots, so the
// address is a genuine shared virtual implementation whose class identity
// is not witnessed anywhere. Rows are named for their own address with the
// proven return value, following Rva0073B660False.cpp and the Disp family
// (address-derived names, identity unrecoverable from 6 bytes).
// No // cl: line (defaults match the frameless 6-byte shape).

// ?Rva001820A0Get@@YAHXZ @ 0x001820A0 (6B): returns 8. CC-island
// (4xCC before, 8xCC after), 4 vtable refs in the 0x7D49xx-0x7D55xx mapper
// family, no direct callers, no branch sources.
int Rva001820A0Get(void)
{
	return 8;
}

// ?Rva00182D20Get@@YAHXZ @ 0x00182D20 (6B): returns 12. CC-island,
// 5 vtable refs in the same 0x7D3Fxx-0x7D56xx mapper family (each carrying
// it 13 slots after Rva001820A0Get), no direct callers, no branch sources.
int Rva00182D20Get(void)
{
	return 12;
}

// ?Rva0013C650Get@@YAHXZ @ 0x0013C650 (6B): returns 3. CC-island
// (7xCC before, 10xCC after) between the 0x13C630 environment-mapper ctor
// and 0x13C660, carried by 2 .rdata slots (one Vector3Randomizer vtable).
// The value matches CLASSID_SOLIDCYLINDER but the body also sits in an
// unrelated randomizer vtable slot, so the linker folded several const-3
// returners here and no single class identity is witnessed; the row stays
// address-derived. No direct callers, no branch sources.
int Rva0013C650Get(void)
{
	return 3;
}

// ?Rva00250000Get@@YAHXZ @ 0x00250000 (6B): returns 0x81. Follows a
// leave/ret (prev C3) with a larger B8-imm function immediately after,
// 7 .rdata refs across distant tables, no direct callers, no branch
// sources. Opaque address-derived name; the value is a plain integer
// (below any image base), not an address.
int Rva00250000Get(void)
{
	return 0x81;
}

// ?Rva00656B60Get@@YAHXZ @ 0x00656B60 (6B): returns 0x00E09F9C.
// CC-island after a double-ret (xor-eax/ret then ret), 16 direct E8
// callers, Ghidra-6. The lone byte-scan branch hit (js at 0x656B4E) is a
// false decode: capstone shows 0x656B4C is mov [eax],0xCE1078 and the 78
// is its immediate byte. Opaque address-derived name.
int Rva00656B60Get(void)
{
	return 0x00E09F9C;
}

// ?Rva00309E4BGet@@YAHXZ @ 0x00309E4B (6B): returns 0x00DBD7DC.
// Follows the rep-movsd table copier at 0x309E30 (9 dwords
// 0xDBD7B8->0xDBD7DC, ret at 0x309E4A) and returns the filled table's
// address; a larger push-style function starts at 0x309E51. 28 direct E8
// callers, Ghidra-6, no branch sources. The value is carried as a plain
// integer literal (no relocation slot exists here), so no pin is needed.
// Opaque address-derived name.
int Rva00309E4BGet(void)
{
	return 0x00DBD7DC;
}

// ?Rva00309E65Get@@YAHXZ @ 0x00309E65 (6B): returns 0x00DBD860.
// Same copier/getter pair shape as 0x309E4B (rep movsd into 0xDBD860,
// ret at 0x309E64, larger function follows at 0x309E6B). 13 direct E8
// callers, Ghidra-6, no branch sources. Opaque address-derived name.
int Rva00309E65Get(void)
{
	return 0x00DBD860;
}

// ?Rva00309E7FGet@@YAHXZ @ 0x00309E7F (6B): returns 0x00DBD918.
// Third copier/getter pair in the run (rep movsd into 0xDBD918, ret at
// 0x309E7E). 11 direct E8 callers, Ghidra-6, no branch sources.
// Opaque address-derived name.
int Rva00309E7FGet(void)
{
	return 0x00DBD918;
}

// ?Rva004CE52EGet@@YAHXZ @ 0x004CE52E (6B): returns 0x00C5FFA0.
// Follows a neg/sbb/neg boolize tail (ret at 0x4CE52D) with a
// push-style function after. 20 direct E8 callers, Ghidra-6, no branch
// sources. Opaque address-derived name.
int Rva004CE52EGet(void)
{
	return 0x00C5FFA0;
}

// ?Rva00507552Get@@YAHXZ @ 0x00507552 (6B): returns 0x00C63FD0.
// Follows a mov/mov/ret getter (ret at 0x507551) with a frame-style
// function after. 17 direct E8 callers, Ghidra-6, no branch sources.
// Opaque address-derived name.
int Rva00507552Get(void)
{
	return 0x00C63FD0;
}

// ?Rva00510D87Get@@YAHXZ @ 0x00510D87 (6B): returns 0x006D1E55.
// Follows an SEH leave/ret (0x510D85-86) with a sub/cmp-style function
// after. 7 .rdata refs, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva00510D87Get(void)
{
	return 0x006D1E55;
}

// ?Rva0000C124CGet@@YAHXZ @ 0x0000C124C (6B): returns 0x000186A0.
// Follows sibling B8-6 0xC1246 (ret 0xBC5C20, itself leave/ret-prev) with
// a B8-imm/call function after. 6 .rdata refs, no direct callers, no
// branch sources. Opaque address-derived name.
int Rva0000C124CGet(void)
{
	return 0x000186A0;
}

// 0x0000C1246 is already claimed by twin (?name@Rva000C1246Named in
// W3DDrawNameGetters.cpp, a real string getter). Always grep the ledger
// in canonical 8-digit form before serving (",0x0*<ADDR>,"); add_match
// refusal is the backstop, never the plan.

// ?Rva00336E72Get@@YAHXZ @ 0x00336E72 (6B): returns 0x00736E78.
// Follows a byte-identical dead twin at 0x336E6C (whole-image refs 0;
// the linker kept both copies, only this one is used). 6 .rdata refs,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00336E72Get(void)
{
	return 0x00736E78;
}

// ?Rva0013C6C0Get@@YAHXZ @ 0x0013C6C0 (6B): returns 14. CC-island,
// carried at 0x7D31F0 in the same 0x7D31xx family table as Rva0013C650Get
// (10 slots later). 1 .rdata ref, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva0013C6C0Get(void)
{
	return 14;
}

// ?Rva001820B0Get@@YAHXZ @ 0x001820B0 (6B): returns 9. CC-island
// neighbor 16 bytes after Rva001820A0Get (same mapper TU region), 2
// .rdata refs, no direct callers. Opaque address-derived name.
int Rva001820B0Get(void)
{
	return 9;
}

// ?Rva0056DD52Get@@YAHXZ @ 0x0056DD52 (6B): returns 0x00DC2884. Opens a
// contiguous triple (52/58/5E, each B8-6 back to back) after an indirect
// call + leave/ret. 2 direct E8 callers, Ghidra-6. Opaque name.
int Rva0056DD52Get(void)
{
	return 0x00DC2884;
}

// ?Rva0056DD58Get@@YAHXZ @ 0x0056DD58 (6B): returns 0x00DC2D10. Middle
// of the triple. 4 direct E8 callers, Ghidra-6. Opaque name.
int Rva0056DD58Get(void)
{
	return 0x00DC2D10;
}

// ?Rva0056DD5EGet@@YAHXZ @ 0x0056DD5E (6B): returns 0x00DC4B60. Closes
// the triple (a mov-style function follows). 4 direct E8 callers,
// Ghidra-6. Opaque name.
int Rva0056DD5EGet(void)
{
	return 0x00DC4B60;
}

// ?Rva00381452Get@@YAHXZ @ 0x00381452 (6B): returns 0x00E02310.
// Prev C3 with a frame-style function after. 4 direct E8 callers, no
// Ghidra entry (dead emission), no branch sources. Opaque name.
int Rva00381452Get(void)
{
	return 0x00E02310;
}

// ?Rva003EFE9AGet@@YAHXZ @ 0x003EFE9A (6B): returns 0x00DC34A4.
// Prev C3 with a movzx-style function after. 4 direct E8 callers,
// Ghidra-6, no branch sources. Opaque name.
int Rva003EFE9AGet(void)
{
	return 0x00DC34A4;
}
