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

// ?Rva003E46B1Get@@YAHXZ @ 0x003e46b1 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva003E46B1Get(void)
{
	return 0;
}

// ?Rva003FE25AGet@@YAHXZ @ 0x003fe25a (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva003FE25AGet(void)
{
	return 0;
}

// ?Rva00406E1FGet@@YAHXZ @ 0x00406e1f (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00406E1FGet(void)
{
	return 0;
}

// ?Rva004110D9Get@@YAHXZ @ 0x004110d9 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva004110D9Get(void)
{
	return 0;
}

// ?Rva00418BF8Get@@YAHXZ @ 0x00418bf8 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00418BF8Get(void)
{
	return 0;
}

// ?Rva0043287BGet@@YAHXZ @ 0x0043287b (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0043287BGet(void)
{
	return 0;
}

// ?Rva00444506Get@@YAHXZ @ 0x00444506 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00444506Get(void)
{
	return 0;
}

// ?Rva00449A26Get@@YAHXZ @ 0x00449a26 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00449A26Get(void)
{
	return 0;
}

// ?Rva004524E2Get@@YAHXZ @ 0x004524e2 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva004524E2Get(void)
{
	return 0;
}

// ?Rva004697DEGet@@YAHXZ @ 0x004697de (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva004697DEGet(void)
{
	return 0;
}

// ?Rva0047E4FCGet@@YAHXZ @ 0x0047e4fc (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0047E4FCGet(void)
{
	return 0;
}

// ?Rva004C30D5Get@@YAHXZ @ 0x004c30d5 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva004C30D5Get(void)
{
	return 0;
}

// ?Rva004D8D7CGet@@YAHXZ @ 0x004d8d7c (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva004D8D7CGet(void)
{
	return 0;
}

// ?Rva004DD655Get@@YAHXZ @ 0x004dd655 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva004DD655Get(void)
{
	return 0;
}

// ?Rva00523F1FGet@@YAHXZ @ 0x00523f1f (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00523F1FGet(void)
{
	return 0;
}

// ?Rva0052B23AGet@@YAHXZ @ 0x0052b23a (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0052B23AGet(void)
{
	return 0;
}

// ?Rva005312BBGet@@YAHXZ @ 0x005312bb (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva005312BBGet(void)
{
	return 0;
}

// ?Rva0055D3F2Get@@YAHXZ @ 0x0055d3f2 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0055D3F2Get(void)
{
	return 0;
}

// ?Rva005CCAC7Get@@YAHXZ @ 0x005ccac7 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva005CCAC7Get(void)
{
	return 0;
}

// ?Rva005EB88CGet@@YAHXZ @ 0x005eb88c (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva005EB88CGet(void)
{
	return 0;
}
