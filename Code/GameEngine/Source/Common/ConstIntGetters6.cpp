// Cold-slice B8-imm32 const-int returners without vtable carriage (twin-free TU).
//
// Same 6-byte shape as ConstIntGetters5.cpp (mov eax,<IMM32> / ret) but for
// bodies following a plain ret (prev C3) rather than a ret-imm: each is an
// unclaimed leaf with no .rdata vtable slot, no direct callers and no branch
// sources, so the opaque address-derived name witnesses only the address and
// the returned constant. Kept in a fresh TU to avoid contending with hot
// getter files. No // cl: line (defaults match the frameless 6-byte shape).

// ?Rva001363C6Get@@YAHXZ @ 0x001363c6 (6B): returns 0x00bbac1c.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva001363C6Get(void)
{
	return 0x00bbac1c;
}

// ?Rva001ED62EGet@@YAHXZ @ 0x001ed62e (6B): returns 0x00c036e8.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva001ED62EGet(void)
{
	return 0x00c036e8;
}
