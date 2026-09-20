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
