// Cold-slice global-int returners without vtable carriage (twin-free TU).
//
// Same discipline as ConstZeroGetters.cpp (opaque address-derived names for
// unclaimed leaves with no callers, no branch sources and no .rdata vtable
// slot) but for the 6-byte shape (mov eax,[global] / ret). Each follows a ret
// (prev C3/C2/CC) and is followed by a function start, so the boundary is
// proven. Kept in a fresh TU to avoid contending with hot getter files.
// No // cl: line (defaults match the frameless 6-byte shape).
//
// The G00xxxxxx externs are address-derived placeholders (DIR32 sites the
// verifier fills from retail) and carry no type information beyond int.

// ?Rva000752F2Get@@YAHXZ @ 0x000752F2 (6B): returns global at 0x9EDA30.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
extern int G009EDA30;
int Rva000752F2Get(void)
{
	return G009EDA30;
}

// ?Rva00116E20Get@@YAHXZ @ 0x00116E20 (6B): returns global at 0x9B5FD4.
// Follows int3 (prev CC), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
extern int G009B5FD4;
int Rva00116E20Get(void)
{
	return G009B5FD4;
}

// ?Rva00116E30Get@@YAHXZ @ 0x00116E30 (6B): returns global at 0x9B5FD8.
// Follows int3 (prev CC), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
extern int G009B5FD8;
int Rva00116E30Get(void)
{
	return G009B5FD8;
}

// ?Rva00117C30Get@@YAHXZ @ 0x00117C30 (6B): returns global at 0x9B5FE0.
// Follows int3 (prev CC), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
extern int G009B5FE0;
int Rva00117C30Get(void)
{
	return G009B5FE0;
}

// ?Rva0011C450Get@@YAHXZ @ 0x0011C450 (6B): returns global at 0x9B5F9C.
// Follows int3 (prev CC), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
extern int G009B5F9C;
int Rva0011C450Get(void)
{
	return G009B5F9C;
}

// ?Rva0011D200Get@@YAHXZ @ 0x0011D200 (6B): returns global at 0x9EDA9C.
// Follows int3 (prev CC), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
extern int G009EDA9C;
int Rva0011D200Get(void)
{
	return G009EDA9C;
}

// ?Rva0011D210Get@@YAHXZ @ 0x0011D210 (6B): returns global at 0x9EDAA0.
// Follows int3 (prev CC), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
extern int G009EDAA0;
int Rva0011D210Get(void)
{
	return G009EDAA0;
}
