// Cold-slice bool-false returners without vtable carriage (twin-free TU).
//
// Same discipline as ConstZeroGetters.cpp and ConstBoolTrueGetters.cpp
// (opaque address-derived names for unclaimed leaves with no callers,
// no branch sources and no .rdata vtable slot) but for the 3-byte shape
// (xor al,al / ret). Each follows a ret (prev C3) and is followed by a
// function prologue, so the boundary is proven. Kept in a fresh TU to
// avoid contending with hot getter files.
// No // cl: line (defaults match the frameless 3-byte shape; verified
// `32c0c3` with zero relocs for `bool Name(void) { return false; }`).

// ?Rva00040F61Get@@YA_NXZ @ 0x00040f61 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00040F61Get(void)
{
	return false;
}

// ?Rva00040FE2Get@@YA_NXZ @ 0x00040fe2 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00040FE2Get(void)
{
	return false;
}

// ?Rva00075743Get@@YA_NXZ @ 0x00075743 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00075743Get(void)
{
	return false;
}

// ?Rva001D9864Get@@YA_NXZ @ 0x001d9864 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva001D9864Get(void)
{
	return false;
}

// ?Rva001E3952Get@@YA_NXZ @ 0x001e3952 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva001E3952Get(void)
{
	return false;
}

// ?Rva001FF367Get@@YA_NXZ @ 0x001ff367 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva001FF367Get(void)
{
	return false;
}

// ?Rva002146F4Get@@YA_NXZ @ 0x002146f4 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002146F4Get(void)
{
	return false;
}

// ?Rva0023C6FAGet@@YA_NXZ @ 0x0023c6fa (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0023C6FAGet(void)
{
	return false;
}
