// Cold-slice xor-eax zero returners without vtable carriage (twin-free TU).
//
// Same discipline as ConstIntGetters5.cpp (opaque address-derived names for
// unclaimed leaves with no callers, no branch sources and no .rdata vtable
// slot) but for the 3-byte shape (xor eax,eax / ret). Each follows a ret
// (prev C3) and is followed by a function prologue, so the boundary is
// proven. Kept in a fresh TU to avoid contending with hot getter files.
// No // cl: line (defaults match the frameless 3-byte shape).

// ?Rva00075692Get@@YAHXZ @ 0x00075692 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00075692Get(void)
{
	return 0;
}

// ?Rva0017FB0CGet@@YAHXZ @ 0x0017fb0c (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0017FB0CGet(void)
{
	return 0;
}

// ?Rva001E38B6Get@@YAHXZ @ 0x001e38b6 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva001E38B6Get(void)
{
	return 0;
}

// ?Rva001E4012Get@@YAHXZ @ 0x001e4012 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva001E4012Get(void)
{
	return 0;
}

// ?Rva001F53FEGet@@YAHXZ @ 0x001f53fe (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva001F53FEGet(void)
{
	return 0;
}

// ?Rva002221A6Get@@YAHXZ @ 0x002221a6 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002221A6Get(void)
{
	return 0;
}

// ?Rva0023C921Get@@YAHXZ @ 0x0023c921 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0023C921Get(void)
{
	return 0;
}

// ?Rva0025DD45Get@@YAHXZ @ 0x0025dd45 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0025DD45Get(void)
{
	return 0;
}

// ?Rva00271776Get@@YAHXZ @ 0x00271776 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00271776Get(void)
{
	return 0;
}

// ?Rva0028B3A3Get@@YAHXZ @ 0x0028b3a3 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0028B3A3Get(void)
{
	return 0;
}

// ?Rva0028D4DDGet@@YAHXZ @ 0x0028d4dd (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0028D4DDGet(void)
{
	return 0;
}

// ?Rva002B2CC3Get@@YAHXZ @ 0x002b2cc3 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002B2CC3Get(void)
{
	return 0;
}

// ?Rva002B3635Get@@YAHXZ @ 0x002b3635 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002B3635Get(void)
{
	return 0;
}

// ?Rva002B3EF7Get@@YAHXZ @ 0x002b3ef7 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002B3EF7Get(void)
{
	return 0;
}

// ?Rva002D6BFFGet@@YAHXZ @ 0x002d6bff (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002D6BFFGet(void)
{
	return 0;
}

// ?Rva00301B51Get@@YAHXZ @ 0x00301b51 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00301B51Get(void)
{
	return 0;
}

// ?Rva003427A6Get@@YAHXZ @ 0x003427a6 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva003427A6Get(void)
{
	return 0;
}

// ?Rva003956E5Get@@YAHXZ @ 0x003956e5 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva003956E5Get(void)
{
	return 0;
}
