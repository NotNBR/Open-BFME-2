// Cold-slice B8-imm32 const-int returners (twin-free TU).
//
// Same shape as ConstIntGetters.cpp (mov eax,<IMM32> / ret, 6B) but kept in
// a separate TU so this lane does not contend with the hot ConstIntGetters
// appends on origin/master. Rows are opaque address-derived names: each
// body is a CC-island or ret-prev leaf carried by .rdata vtable slots with
// no direct callers and no branch sources, so no class identity is
// witnessed. No // cl: line (defaults match the frameless 6-byte shape).

// ?Rva00742550Get@@YAHXZ @ 0x00742550 (6B): returns 0x1C (28). CC-island
// (16xCC before, 20xCC after), carried by 2 .rdata slots (0x7D3D4C and
// 0x8F1694, same vtable family suffix 4D43D0/4D43D0/46CE6B/87A69C),
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00742550Get(void)
{
	return 0x1C;
}

// ?Rva002BE8CEGet@@YAHXZ @ 0x002BE8CE (6B): returns 0x00BFE4D4.
// Follows a leave/ret-4 (prev C2-04-00), carried by 2 .rdata vtable slots
// (0x7C89D0 in the 0x49xxxx family, 0x7FE510 beside the 0x4B3FD0 slot),
// no direct callers, no branch sources. The imm falls in the .rdata VA
// window so it is kept as a plain int literal (no DIR32 for literals).
// Opaque address-derived name.
int Rva002BE8CEGet(void)
{
	return 0x00BFE4D4;
}

// ?Rva0009FDF5Get@@YAHXZ @ 0x0009FDF5 (6B): returns 0x0048F925.
// Follows a cmov-style ret (prev C3), carried by 1 .rdata slot (0x7C8CB0)
// in a vtable family shared with Rva0009FDFBGet (identical neighbours,
// parallel tables 44B apart), no direct callers, no branch sources.
// Opaque address-derived name.
int Rva0009FDF5Get(void)
{
	return 0x0048F925;
}

// ?Rva0009FDFBGet@@YAHXZ @ 0x0009FDFB (6B): returns 0x0048F95F.
// Immediately follows Rva0009FDF5Get (prev is its C3), carried by 1 .rdata
// slot (0x7C8CDC) in the parallel vtable, no direct callers, no branch
// sources. Opaque address-derived name.
int Rva0009FDFBGet(void)
{
	return 0x0048F95F;
}

// ?Rva0018026EGet@@YAHXZ @ 0x0018026E (6B): returns 0x4D455348.
// Follows a leave/ret (prev C9-C3), carried by 1 .rdata slot (0x7D4FC4)
// in a vtable family shared with Rva00180581Get (identical neighbours),
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0018026EGet(void)
{
	return 0x4D455348;
}

// ?Rva00180581Get@@YAHXZ @ 0x00180581 (6B): returns 0x50415254.
// Follows a leave/ret (prev C9-C3), carried by 1 .rdata slot (0x7D5004)
// in the parallel vtable to Rva0018026EGet, no direct callers, no branch
// sources. Opaque address-derived name.
int Rva00180581Get(void)
{
	return 0x50415254;
}

// ?Rva00180778Get@@YAHXZ @ 0x00180778 (6B): returns 0x00424F58.
// Follows a leave/ret (prev C9-C3), carried by 1 .rdata slot (0x7D5044)
// in the 0x180xxx vtable family (prefix 530FCE/A1EE20/A1EE50, suffix
// 6A79A1/4B3FD0), no direct callers, no branch sources.
// Opaque address-derived name.
int Rva00180778Get(void)
{
	return 0x00424F58;
}
