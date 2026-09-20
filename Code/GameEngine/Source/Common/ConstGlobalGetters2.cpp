// Cold-slice global-int returners without vtable carriage (twin-free TU).
//
// Same discipline as ConstGlobalGetters.cpp (opaque address-derived names for
// unclaimed leaves with no callers, no branch sources and no .rdata vtable
// slot) but kept in a separate TU to avoid contending with that file's active
// worker. Each is the 6-byte shape (mov eax,[global] / ret), follows int3
// (prev CC) with CC padding after, so the boundary is proven.
// No // cl: line (defaults match the frameless 6-byte shape).
//
// The G00xxxxxx externs are address-derived placeholders (DIR32 sites the
// verifier fills from retail) and carry no type information beyond int.

// ?Rva00139450Get@@YAHXZ @ 0x00139450 (6B): returns global at 0x9F2A40.
// Follows int3 (prev CC), followed by CC padding, no .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
extern int G009F2A40;
int Rva00139450Get(void)
{
	return G009F2A40;
}

// ?Rva00139460Get@@YAHXZ @ 0x00139460 (6B): returns global at 0x9F2A84.
// Follows int3 (prev CC), followed by CC padding, no .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
extern int G009F2A84;
int Rva00139460Get(void)
{
	return G009F2A84;
}

// ?Rva00139470Get@@YAHXZ @ 0x00139470 (6B): returns global at 0x9F2A00.
// Follows int3 (prev CC), followed by CC padding, no .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
extern int G009F2A00;
int Rva00139470Get(void)
{
	return G009F2A00;
}

// ?Rva0011CDB0Get@@YAHXZ @ 0x0011CDB0 (6B): returns global at 0x9ED5EC.
// Follows int3 (prev CC), followed by CC padding, no .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
extern int G009ED5EC;
int Rva0011CDB0Get(void)
{
	return G009ED5EC;
}

// ?Rva00120130Get@@YAHXZ @ 0x00120130 (6B): returns global at 0x9EE5D0.
// Follows int3 (prev CC), followed by CC padding, no .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
extern int G009EE5D0;
int Rva00120130Get(void)
{
	return G009EE5D0;
}
