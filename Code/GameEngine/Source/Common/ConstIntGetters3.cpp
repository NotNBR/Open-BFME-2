// C2-ret-prev B8-imm32 const-int returners, 0x342xxx cluster (twin-free TU).
//
// Same 6-byte shape as ConstIntGetters.cpp (mov eax,<IMM32> / ret) but for
// bodies following a ret-imm (prev byte[addr-3]==C2) instead of CC-islands.
// Kept in a separate TU so this lane does not contend with the hot
// ConstIntGetters/ConstIntGetters2 appends on origin/master. Rows are opaque
// address-derived names: each body is a ret-prev leaf carried by .rdata
// vtable slots with no direct callers and no branch sources, so no class
// identity is witnessed. The imm falls in the .rdata VA window so it is kept
// as a plain int literal (no DIR32 for literals).
// No // cl: line (defaults match the frameless 6-byte shape).

// ?Rva00342972Get@@YAHXZ @ 0x00342972 (6B): returns 0x00C12658.
// Follows a ret-16 (prev C2-10-00: mov eax,esi/pop esi/ret), carried by
// 2 .rdata vtable slots (0x812618 and 0x812680, same family tables),
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342972Get(void)
{
	return 0x00C12658;
}

// ?Rva00342BA8Get@@YAHXZ @ 0x00342ba8 (6B): returns 0x00C12918.
// Follows a ret-4 (prev C2-04-00: mov eax,esi/pop esi/ret), carried by
// 2 .rdata vtable slots (0x8128D8 and 0x86A258, same family tables),
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342BA8Get(void)
{
	return 0x00C12918;
}

// ?Rva00342CF6Get@@YAHXZ @ 0x00342cf6 (6B): returns 0x00C12B10.
// Follows a ret-4 (prev C2-04-00), carried by 2 .rdata vtable slots
// (0x812AD0 and 0x812B30, same family tables), no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00342CF6Get(void)
{
	return 0x00C12B10;
}

// ?Rva00342D70Get@@YAHXZ @ 0x00342d70 (6B): returns 0x00C12C10.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots
// (0x812BD0 and 0x8172C0, same family tables), no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00342D70Get(void)
{
	return 0x00C12C10;
}

// ?Rva0034256CGet@@YAHXZ @ 0x0034256c (6B): returns 0x00C123BC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0034256CGet(void)
{
	return 0x00C123BC;
}

// ?Rva00342636Get@@YAHXZ @ 0x00342636 (6B): returns 0x00C1241C.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342636Get(void)
{
	return 0x00C1241C;
}

// ?Rva003426C8Get@@YAHXZ @ 0x003426c8 (6B): returns 0x00C1247C.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003426C8Get(void)
{
	return 0x00C1247C;
}

// ?Rva003429F4Get@@YAHXZ @ 0x003429f4 (6B): returns 0x00C12708.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003429F4Get(void)
{
	return 0x00C12708;
}

// ?Rva00342A4AGet@@YAHXZ @ 0x00342a4a (6B): returns 0x00C12778.
// Follows a ret-16 (prev C2-10-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342A4AGet(void)
{
	return 0x00C12778;
}

// ?Rva00342A90Get@@YAHXZ @ 0x00342a90 (6B): returns 0x00C127E0.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342A90Get(void)
{
	return 0x00C127E0;
}

// ?Rva00342AD0Get@@YAHXZ @ 0x00342ad0 (6B): returns 0x00C12848.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342AD0Get(void)
{
	return 0x00C12848;
}

// ?Rva00342B14Get@@YAHXZ @ 0x00342b14 (6B): returns 0x00C128B0.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342B14Get(void)
{
	return 0x00C128B0;
}

// ?Rva00342BF6Get@@YAHXZ @ 0x00342bf6 (6B): returns 0x00C12978.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342BF6Get(void)
{
	return 0x00C12978;
}

// ?Rva00342C63Get@@YAHXZ @ 0x00342c63 (6B): returns 0x00C129E0.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342C63Get(void)
{
	return 0x00C129E0;
}

// ?Rva00342C91Get@@YAHXZ @ 0x00342c91 (6B): returns 0x00C12A50.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342C91Get(void)
{
	return 0x00C12A50;
}

// ?Rva00342CB9Get@@YAHXZ @ 0x00342cb9 (6B): returns 0x00C12AB8.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342CB9Get(void)
{
	return 0x00C12AB8;
}

// ?Rva00342D3BGet@@YAHXZ @ 0x00342d3b (6B): returns 0x00C12BB8.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342D3BGet(void)
{
	return 0x00C12BB8;
}

// ?Rva00342DA5Get@@YAHXZ @ 0x00342da5 (6B): returns 0x00C12C70.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342DA5Get(void)
{
	return 0x00C12C70;
}

// ?Rva00342DCCGet@@YAHXZ @ 0x00342dcc (6B): returns 0x00C12CD0.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342DCCGet(void)
{
	return 0x00C12CD0;
}

// ?Rva00342DF3Get@@YAHXZ @ 0x00342df3 (6B): returns 0x00C12D30.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342DF3Get(void)
{
	return 0x00C12D30;
}

// ?Rva00342E11Get@@YAHXZ @ 0x00342e11 (6B): returns 0x00C12D9C.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342E11Get(void)
{
	return 0x00C12D9C;
}

// ?Rva00342E2FGet@@YAHXZ @ 0x00342e2f (6B): returns 0x00C12E04.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342E2FGet(void)
{
	return 0x00C12E04;
}

// ?Rva00342E52Get@@YAHXZ @ 0x00342e52 (6B): returns 0x00C12E70.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342E52Get(void)
{
	return 0x00C12E70;
}

// ?Rva00342ED1Get@@YAHXZ @ 0x00342ed1 (6B): returns 0x00C12ED8.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342ED1Get(void)
{
	return 0x00C12ED8;
}

// ?Rva00342EF4Get@@YAHXZ @ 0x00342ef4 (6B): returns 0x00C12F30.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342EF4Get(void)
{
	return 0x00C12F30;
}

// ?Rva00342F1FGet@@YAHXZ @ 0x00342f1f (6B): returns 0x00C12F88.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00342F1FGet(void)
{
	return 0x00C12F88;
}
