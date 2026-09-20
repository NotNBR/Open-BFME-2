// Cold-slice bool-true returners without vtable carriage (twin-free TU).
//
// Same discipline as ConstZeroGetters.cpp (opaque address-derived names for
// unclaimed leaves with no callers, no branch sources and no .rdata vtable
// slot) but for the 3-byte shape (mov al,1 / ret). Each follows a ret
// (prev C3/C2) or padding (prev CC) and is followed by a function prologue,
// so the boundary is proven. Kept in a fresh TU to avoid contending with
// hot getter files.
// No // cl: line (defaults match the frameless 3-byte shape; verified
// `b001c3` with zero relocs for `bool Name(void) { return true; }`).

// ?Rva000454B7Get@@YA_NXZ @ 0x000454b7 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva000454B7Get(void)
{
	return true;
}

// ?Rva00065E39Get@@YA_NXZ @ 0x00065e39 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00065E39Get(void)
{
	return true;
}

// ?Rva000B2EB2Get@@YA_NXZ @ 0x000b2eb2 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva000B2EB2Get(void)
{
	return true;
}
