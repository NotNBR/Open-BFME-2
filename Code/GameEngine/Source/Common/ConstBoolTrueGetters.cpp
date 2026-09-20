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

// ?Rva000B3EC4Get@@YA_NXZ @ 0x000b3ec4 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva000B3EC4Get(void)
{
	return true;
}

// ?Rva001DBB01Get@@YA_NXZ @ 0x001dbb01 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva001DBB01Get(void)
{
	return true;
}

// ?Rva00238F8EGet@@YA_NXZ @ 0x00238f8e (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00238F8EGet(void)
{
	return true;
}

// ?Rva0023C59CGet@@YA_NXZ @ 0x0023c59c (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0023C59CGet(void)
{
	return true;
}

// ?Rva002C7269Get@@YA_NXZ @ 0x002c7269 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002C7269Get(void)
{
	return true;
}

// ?Rva002C7512Get@@YA_NXZ @ 0x002c7512 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002C7512Get(void)
{
	return true;
}

// ?Rva002D76A3Get@@YA_NXZ @ 0x002d76a3 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002D76A3Get(void)
{
	return true;
}

// ?Rva002D9C2CGet@@YA_NXZ @ 0x002d9c2c (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002D9C2CGet(void)
{
	return true;
}

// ?Rva00306E3DGet@@YA_NXZ @ 0x00306e3d (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00306E3DGet(void)
{
	return true;
}

// ?Rva0035B161Get@@YA_NXZ @ 0x0035b161 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0035B161Get(void)
{
	return true;
}

// ?Rva0035BEC4Get@@YA_NXZ @ 0x0035bec4 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0035BEC4Get(void)
{
	return true;
}

// ?Rva00388834Get@@YA_NXZ @ 0x00388834 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00388834Get(void)
{
	return true;
}

// ?Rva00390554Get@@YA_NXZ @ 0x00390554 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00390554Get(void)
{
	return true;
}

// ?Rva003B6A37Get@@YA_NXZ @ 0x003b6a37 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva003B6A37Get(void)
{
	return true;
}

// ?Rva003B6C8BGet@@YA_NXZ @ 0x003b6c8b (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva003B6C8BGet(void)
{
	return true;
}
// ?Rva0036E0E0Get@@YA_NXZ @ 0x0036e0e0 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0036E0E0Get(void)
{
	return true;
}

// ?Rva003FF1D7Get@@YA_NXZ @ 0x003ff1d7 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva003FF1D7Get(void)
{
	return true;
}

// ?Rva004291C5Get@@YA_NXZ @ 0x004291c5 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva004291C5Get(void)
{
	return true;
}

// ?Rva004297B8Get@@YA_NXZ @ 0x004297b8 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva004297B8Get(void)
{
	return true;
}

// ?Rva004B0EE2Get@@YA_NXZ @ 0x004b0ee2 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva004B0EE2Get(void)
{
	return true;
}

// ?Rva004D95AFGet@@YA_NXZ @ 0x004d95af (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva004D95AFGet(void)
{
	return true;
}

// ?Rva004F10E3Get@@YA_NXZ @ 0x004f10e3 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva004F10E3Get(void)
{
	return true;
}

// ?Rva004F19F3Get@@YA_NXZ @ 0x004f19f3 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva004F19F3Get(void)
{
	return true;
}

// ?Rva00513863Get@@YA_NXZ @ 0x00513863 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00513863Get(void)
{
	return true;
}

// ?Rva00559B61Get@@YA_NXZ @ 0x00559b61 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00559B61Get(void)
{
	return true;
}

// ?Rva0056B8F1Get@@YA_NXZ @ 0x0056b8f1 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0056B8F1Get(void)
{
	return true;
}

// ?Rva0059EF46Get@@YA_NXZ @ 0x0059ef46 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0059EF46Get(void)
{
	return true;
}

// ?Rva005A678BGet@@YA_NXZ @ 0x005a678b (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva005A678BGet(void)
{
	return true;
}

// ?Rva005DB21EGet@@YA_NXZ @ 0x005db21e (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva005DB21EGet(void)
{
	return true;
}

// ?Rva006C53A5Get@@YA_NXZ @ 0x006c53a5 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva006C53A5Get(void)
{
	return true;
}

// ?Rva006CE7C9Get@@YA_NXZ @ 0x006ce7c9 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva006CE7C9Get(void)
{
	return true;
}

// ?Rva006D0439Get@@YA_NXZ @ 0x006d0439 (3B): returns true.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva006D0439Get(void)
{
	return true;
}
