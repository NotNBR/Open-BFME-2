// Cold-slice B8-imm32 const-int returners (twin-free TU).
//
// Same shape as ConstIntGetters2.cpp/ConstIntGetters3.cpp (mov eax,<IMM32> /
// ret, 6B) but kept in a separate TU so this lane does not contend with the
// hot ConstIntGetters appends on origin/master. Rows are opaque
// address-derived names: each body follows a ret-imm (C2-04-00 / C2-08-00)
// and is carried by .rdata vtable slots with no direct callers and no branch
// sources, so no class identity is witnessed. No // cl: line (defaults match
// the frameless 6-byte shape).

// ?Rva0033F4ABGet@@YAHXZ @ 0x0033f4ab (6B): returns 0x00C1123C.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F4ABGet(void)
{
	return 0x00C1123C;
}

// ?Rva0033F4D9Get@@YAHXZ @ 0x000033f4d9 (6B): returns 0x00C1129C.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F4D9Get(void)
{
	return 0x00C1129C;
}

// ?Rva0033F53AGet@@YAHXZ @ 0x000033f53a (6B): returns 0x00C1135C.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F53AGet(void)
{
	return 0x00C1135C;
}

// ?Rva0033F565Get@@YAHXZ @ 0x000033f565 (6B): returns 0x00C113AC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F565Get(void)
{
	return 0x00C113AC;
}

// ?Rva0033F590Get@@YAHXZ @ 0x0033f590 (6B): returns 0x00C113FC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F590Get(void)
{
	return 0x00C113FC;
}

// ?Rva0033F5B3Get@@YAHXZ @ 0x0033f5b3 (6B): returns 0x00C11454.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F5B3Get(void)
{
	return 0x00C11454;
}

// ?Rva0033F5DDGet@@YAHXZ @ 0x0033f5dd (6B): returns 0x00C114AC.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F5DDGet(void)
{
	return 0x00C114AC;
}

// ?Rva0033F5FFGet@@YAHXZ @ 0x0033f5ff (6B): returns 0x00C11504.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F5FFGet(void)
{
	return 0x00C11504;
}

// ?Rva0033F621Get@@YAHXZ @ 0x0033f621 (6B): returns 0x00C11564.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F621Get(void)
{
	return 0x00C11564;
}

// ?Rva0033F648Get@@YAHXZ @ 0x0033f648 (6B): returns 0x00C115CC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F648Get(void)
{
	return 0x00C115CC;
}

// ?Rva0033F676Get@@YAHXZ @ 0x0033f676 (6B): returns 0x00C1162C.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F676Get(void)
{
	return 0x00C1162C;
}

// ?Rva0033F698Get@@YAHXZ @ 0x0033f698 (6B): returns 0x00C1167C.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F698Get(void)
{
	return 0x00C1167C;
}

// ?Rva0033F6BAGet@@YAHXZ @ 0x0033f6ba (6B): returns 0x00C116DC.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F6BAGet(void)
{
	return 0x00C116DC;
}

// ?Rva0033F6FBGet@@YAHXZ @ 0x0033f6fb (6B): returns 0x00C11784.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F6FBGet(void)
{
	return 0x00C11784;
}
