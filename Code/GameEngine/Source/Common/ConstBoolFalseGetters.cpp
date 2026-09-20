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

// ?Rva0026EF31Get@@YA_NXZ @ 0x0026ef31 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0026EF31Get(void)
{
	return false;
}

// ?Rva0028B13EGet@@YA_NXZ @ 0x0028b13e (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0028B13EGet(void)
{
	return false;
}

// ?Rva002AA359Get@@YA_NXZ @ 0x002aa359 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002AA359Get(void)
{
	return false;
}

// ?Rva002B4C32Get@@YA_NXZ @ 0x002b4c32 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002B4C32Get(void)
{
	return false;
}

// ?Rva002C7608Get@@YA_NXZ @ 0x002c7608 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002C7608Get(void)
{
	return false;
}

// ?Rva002C959BGet@@YA_NXZ @ 0x002c959b (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002C959BGet(void)
{
	return false;
}

// ?Rva002CEF27Get@@YA_NXZ @ 0x002cef27 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002CEF27Get(void)
{
	return false;
}

// ?Rva0030B3CEGet@@YA_NXZ @ 0x0030b3ce (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0030B3CEGet(void)
{
	return false;
}

// ?Rva00318BA2Get@@YA_NXZ @ 0x00318ba2 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00318BA2Get(void)
{
	return false;
}

// ?Rva00318F61Get@@YA_NXZ @ 0x00318f61 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00318F61Get(void)
{
	return false;
}

// ?Rva00341439Get@@YA_NXZ @ 0x00341439 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00341439Get(void)
{
	return false;
}

// ?Rva00342309Get@@YA_NXZ @ 0x00342309 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00342309Get(void)
{
	return false;
}

// ?Rva00405B5DGet@@YA_NXZ @ 0x00405b5d (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00405B5DGet(void)
{
	return false;
}

// ?Rva0041B8B2Get@@YA_NXZ @ 0x0041b8b2 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0041B8B2Get(void)
{
	return false;
}

// ?Rva0041FE60Get@@YA_NXZ @ 0x0041fe60 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0041FE60Get(void)
{
	return false;
}

// ?Rva0042638BGet@@YA_NXZ @ 0x0042638b (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0042638BGet(void)
{
	return false;
}
