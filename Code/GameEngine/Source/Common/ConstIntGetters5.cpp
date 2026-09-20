// Cold-slice B8-imm32 const-int returners without vtable carriage (twin-free TU).
//
// Same 6-byte shape as ConstIntGetters4.cpp (mov eax,<IMM32> / ret) but for
// bodies with no .rdata vtable slot, no direct callers and no branch sources:
// each follows a ret-imm (C2-04-00) and is an unclaimed leaf, so the opaque
// address-derived name witnesses only the address and the returned constant.
// Kept in a fresh TU so this batch does not contend with the hot
// ConstIntGetters4 appends on origin/master. No // cl: line (defaults match
// the frameless 6-byte shape).

// ?Rva0004546DGet@@YAHXZ @ 0x0004546d (6B): returns 0x00dbaa98.
// Follows a ret-4 (prev C2-04-00), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0004546DGet(void)
{
	return 0x00dbaa98;
}
