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

// ?Rva0044E60AGet@@YA_NXZ @ 0x0044e60a (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0044E60AGet(void)
{
	return false;
}

// ?Rva0045314BGet@@YA_NXZ @ 0x0045314b (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0045314BGet(void)
{
	return false;
}

// ?Rva004A6AB2Get@@YA_NXZ @ 0x004a6ab2 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva004A6AB2Get(void)
{
	return false;
}
// ?Rva00040FB2Get@@YA_NXZ @ 0x00040fb2 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00040FB2Get(void)
{
	return false;
}

// ?Rva00040FCAGet@@YA_NXZ @ 0x00040fca (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00040FCAGet(void)
{
	return false;
}

// ?Rva0004E50FGet@@YA_NXZ @ 0x0004e50f (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0004E50FGet(void)
{
	return false;
}

// ?Rva00050DCDGet@@YA_NXZ @ 0x00050dcd (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00050DCDGet(void)
{
	return false;
}

// ?Rva00050DE0Get@@YA_NXZ @ 0x00050de0 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00050DE0Get(void)
{
	return false;
}

// ?Rva0005155BGet@@YA_NXZ @ 0x0005155b (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0005155BGet(void)
{
	return false;
}

// ?Rva0005320CGet@@YA_NXZ @ 0x0005320c (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0005320CGet(void)
{
	return false;
}

// ?Rva00072580Get@@YA_NXZ @ 0x00072580 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00072580Get(void)
{
	return false;
}

// ?Rva000B3A7DGet@@YA_NXZ @ 0x000b3a7d (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva000B3A7DGet(void)
{
	return false;
}

// ?Rva001EB0C7Get@@YA_NXZ @ 0x001eb0c7 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva001EB0C7Get(void)
{
	return false;
}

// ?Rva001EB0E7Get@@YA_NXZ @ 0x001eb0e7 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva001EB0E7Get(void)
{
	return false;
}

// ?Rva001EB0F8Get@@YA_NXZ @ 0x001eb0f8 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva001EB0F8Get(void)
{
	return false;
}

// ?Rva00203B05Get@@YA_NXZ @ 0x00203b05 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00203B05Get(void)
{
	return false;
}

// ?Rva0020D7B9Get@@YA_NXZ @ 0x0020d7b9 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0020D7B9Get(void)
{
	return false;
}

// ?Rva0028AFCFGet@@YA_NXZ @ 0x0028afcf (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0028AFCFGet(void)
{
	return false;
}

// ?Rva002B2B58Get@@YA_NXZ @ 0x002b2b58 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002B2B58Get(void)
{
	return false;
}

// ?Rva002B3750Get@@YA_NXZ @ 0x002b3750 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002B3750Get(void)
{
	return false;
}
// ?Rva002C96F4Get@@YA_NXZ @ 0x002c96f4 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva002C96F4Get(void)
{
	return false;
}

// ?Rva0030BF63Get@@YA_NXZ @ 0x0030bf63 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0030BF63Get(void)
{
	return false;
}

// ?Rva003182CAGet@@YA_NXZ @ 0x003182ca (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva003182CAGet(void)
{
	return false;
}

// ?Rva003182DEGet@@YA_NXZ @ 0x003182de (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva003182DEGet(void)
{
	return false;
}

// ?Rva00327E1FGet@@YA_NXZ @ 0x00327e1f (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00327E1FGet(void)
{
	return false;
}

// ?Rva00340E5BGet@@YA_NXZ @ 0x00340e5b (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00340E5BGet(void)
{
	return false;
}

// ?Rva003889F3Get@@YA_NXZ @ 0x003889f3 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva003889F3Get(void)
{
	return false;
}

// ?Rva00388A01Get@@YA_NXZ @ 0x00388a01 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva00388A01Get(void)
{
	return false;
}

// ?Rva003ED3A7Get@@YA_NXZ @ 0x003ed3a7 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva003ED3A7Get(void)
{
	return false;
}

// ?Rva003F804FGet@@YA_NXZ @ 0x003f804f (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva003F804FGet(void)
{
	return false;
}

// ?Rva003F8064Get@@YA_NXZ @ 0x003f8064 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva003F8064Get(void)
{
	return false;
}

// ?Rva003FF1A4Get@@YA_NXZ @ 0x003ff1a4 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva003FF1A4Get(void)
{
	return false;
}

// ?Rva0041514AGet@@YA_NXZ @ 0x0041514a (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0041514AGet(void)
{
	return false;
}

// ?Rva0044E630Get@@YA_NXZ @ 0x0044e630 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva0044E630Get(void)
{
	return false;
}

// ?Rva004695FFGet@@YA_NXZ @ 0x004695ff (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva004695FFGet(void)
{
	return false;
}

// ?Rva004A9649Get@@YA_NXZ @ 0x004a9649 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva004A9649Get(void)
{
	return false;
}

// ?Rva004AB4D5Get@@YA_NXZ @ 0x004ab4d5 (3B): returns false.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
bool Rva004AB4D5Get(void)
{
	return false;
}
