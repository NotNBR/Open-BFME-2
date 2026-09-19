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

// ?Rva00180AA0Get@@YAHXZ @ 0x00180AA0 (6B): returns 0x41474752.
// Follows a leave/ret (prev C9-C3), carried by 1 .rdata slot (0x7D5084)
// in the 0x180xxx vtable family, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva00180AA0Get(void)
{
	return 0x41474752;
}

// ?Rva00180E60Get@@YAHXZ @ 0x00180E60 (6B): returns 0x00BBE8D4.
// CC-island (16xCC before and after), carried by 1 .rdata slot (0x7D5090)
// in the 0x180xxx vtable family, no direct callers, no branch sources.
// The imm falls in the .rdata VA window so it is kept as a plain int
// literal (no DIR32 for literals). Opaque address-derived name.
int Rva00180E60Get(void)
{
	return 0x00BBE8D4;
}

// ?Rva00180E70Get@@YAHXZ @ 0x00180E70 (6B): returns 0x4E554C4C.
// CC-island (16xCC before and after), carried by 1 .rdata slot (0x7D50C4)
// in the 0x180xxx vtable family, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva00180E70Get(void)
{
	return 0x4E554C4C;
}

// ?Rva000A08F1Get@@YAHXZ @ 0x000A08F1 (6B): returns 0x0048F6E1.
// Follows a pop/ret-4 (prev C2-04-00), carried by 1 .rdata slot (0x7C8CC8)
// in a vtable family shared with Rva000A08F7Get (identical neighbours,
// parallel tables 44B apart), no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A08F1Get(void)
{
	return 0x0048F6E1;
}

// ?Rva000A08F7Get@@YAHXZ @ 0x000A08F7 (6B): returns 0x0048F71B.
// Immediately follows Rva000A08F1Get (prev is its C3), carried by 1 .rdata
// slot (0x7C8CF4) in the parallel vtable, no direct callers, no branch
// sources. Opaque address-derived name.
int Rva000A08F7Get(void)
{
	return 0x0048F71B;
}

// ?Rva000A0D52Get@@YAHXZ @ 0x000A0D52 (6B): returns 0x0048FAF5.
// Follows a pop/ret-4 (prev C2-04-00), carried by 1 .rdata slot (0x7C8D90)
// in a vtable family shared with Rva000A0D58Get (identical neighbours,
// parallel tables 44B apart), no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A0D52Get(void)
{
	return 0x0048FAF5;
}

// ?Rva000A0D58Get@@YAHXZ @ 0x000A0D58 (6B): returns 0x0048FB2F.
// Immediately follows Rva000A0D52Get (prev is its C3), carried by 1 .rdata
// slot in the parallel vtable, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A0D58Get(void)
{
	return 0x0048FB2F;
}

// ?Rva000A135EGet@@YAHXZ @ 0x000A135E (6B): returns 0x0048FB69.
// Follows a pop/ret-4 (prev C2-04-00), carried by 1 .rdata slot
// in a vtable family shared with Rva000A1364Get (identical neighbours,
// parallel tables 44B apart), no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A135EGet(void)
{
	return 0x0048FB69;
}

// ?Rva000A1364Get@@YAHXZ @ 0x000A1364 (6B): returns 0x0048FBA3.
// Immediately follows Rva000A135EGet (prev is its C3), carried by 1 .rdata
// slot in the parallel vtable, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A1364Get(void)
{
	return 0x0048FBA3;
}

// ?Rva000A165EGet@@YAHXZ @ 0x000A165E (6B): returns 0x0048FBDD.
// Follows a pop/ret-4 (prev C2-04-00), carried by 1 .rdata slot
// in a vtable family shared with Rva000A1664Get (identical neighbours,
// parallel tables 44B apart), no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A165EGet(void)
{
	return 0x0048FBDD;
}

// ?Rva000A1664Get@@YAHXZ @ 0x000A1664 (6B): returns 0x0048FC17.
// Immediately follows Rva000A165EGet (prev is its C3), carried by 1 .rdata
// slot in the parallel vtable, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A1664Get(void)
{
	return 0x0048FC17;
}

// ?Rva000A2197Get@@YAHXZ @ 0x000A2197 (6B): returns 0x0048FA81.
// Follows a pop/ret-4 (prev C2-04-00), carried by 1 .rdata slot
// in a vtable family shared with Rva000A219DGet (identical neighbours,
// parallel tables 44B apart), no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A2197Get(void)
{
	return 0x0048FA81;
}

// ?Rva000A219DGet@@YAHXZ @ 0x000A219D (6B): returns 0x0048FABB.
// Immediately follows Rva000A2197Get (prev is its C3), carried by 1 .rdata
// slot in the parallel vtable, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A219DGet(void)
{
	return 0x0048FABB;
}

// ?Rva000A2727Get@@YAHXZ @ 0x000A2727 (6B): returns 0x0048F999.
// Follows a pop/ret-4 (prev C2-04-00), carried by 1 .rdata slot
// in a vtable family shared with Rva000A272DGet (identical neighbours,
// parallel tables 44B apart), no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A2727Get(void)
{
	return 0x0048F999;
}

// ?Rva000A272DGet@@YAHXZ @ 0x000A272D (6B): returns 0x0048F9D3.
// Immediately follows Rva000A2727Get (prev is its C3), carried by 1 .rdata
// slot in the parallel vtable, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A272DGet(void)
{
	return 0x0048F9D3;
}

// ?Rva000A2733Get@@YAHXZ @ 0x000A2733 (6B): returns 0x0048FA0D.
// Immediately follows Rva000A272DGet (prev is its C3), carried by 1 .rdata
// slot in the parallel vtable, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A2733Get(void)
{
	return 0x0048FA0D;
}

// ?Rva000A2739Get@@YAHXZ @ 0x000A2739 (6B): returns 0x0048FA47.
// Immediately follows Rva000A2733Get (prev is its C3), carried by 1 .rdata
// slot in the parallel vtable, no direct callers, no branch sources.
// Opaque address-derived name.
int Rva000A2739Get(void)
{
	return 0x0048FA47;
}
