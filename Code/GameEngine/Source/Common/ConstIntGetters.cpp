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
