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

// ?Rva005EEA1DGet@@YAHXZ @ 0x005eea1d (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva005EEA1DGet(void)
{
	return 0;
}

// ?Rva005F0233Get@@YAHXZ @ 0x005f0233 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva005F0233Get(void)
{
	return 0;
}

// ?Rva005F88F1Get@@YAHXZ @ 0x005f88f1 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva005F88F1Get(void)
{
	return 0;
}

// ?Rva0060B883Get@@YAHXZ @ 0x0060b883 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0060B883Get(void)
{
	return 0;
}

// ?Rva00740A5DGet@@YAHXZ @ 0x00740a5d (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00740A5DGet(void)
{
	return 0;
}

// ?Rva00021736Get@@YAHXZ @ 0x00021736 (3B): returns 0.
// Follows a ret (prev C3), padded (CC) before next function, no .rdata
// vtable slot, no direct callers, no branch sources. Opaque name.
int Rva00021736Get(void)
{
	return 0;
}

// ?Rva00030514Get@@YAHXZ @ 0x00030514 (3B): returns 0.
// Follows a ret (prev C3), padded (CC) before next function, no .rdata
// vtable slot, no direct callers, no branch sources. Opaque name.
int Rva00030514Get(void)
{
	return 0;
}

// ?Rva000310EBGet@@YAHXZ @ 0x000310eb (3B): returns 0.
// Follows a ret (prev C3), padded (CC) before next function, no .rdata
// vtable slot, no direct callers, no branch sources. Opaque name.
int Rva000310EBGet(void)
{
	return 0;
}

// ?Rva001499A5Get@@YAHXZ @ 0x001499a5 (3B): returns 0.
// Follows a ret (prev C3), padded (CC) before next function, no .rdata
// vtable slot, no direct callers, no branch sources. Opaque name.
int Rva001499A5Get(void)
{
	return 0;
}
// ?Rva00042FF5Get@@YAHXZ @ 0x00042ff5 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00042FF5Get(void)
{
	return 0;
}

// ?Rva00094BEFGet@@YAHXZ @ 0x00094bef (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00094BEFGet(void)
{
	return 0;
}

// ?Rva00149A6CGet@@YAHXZ @ 0x00149a6c (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00149A6CGet(void)
{
	return 0;
}

// ?Rva00179930Get@@YAHXZ @ 0x00179930 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00179930Get(void)
{
	return 0;
}

// ?Rva00202028Get@@YAHXZ @ 0x00202028 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00202028Get(void)
{
	return 0;
}

// ?Rva0028B83FGet@@YAHXZ @ 0x0028b83f (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0028B83FGet(void)
{
	return 0;
}

// ?Rva002B256BGet@@YAHXZ @ 0x002b256b (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002B256BGet(void)
{
	return 0;
}

// ?Rva002D9580Get@@YAHXZ @ 0x002d9580 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002D9580Get(void)
{
	return 0;
}

// ?Rva002E6C8AGet@@YAHXZ @ 0x002e6c8a (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002E6C8AGet(void)
{
	return 0;
}

// ?Rva0035B1C0Get@@YAHXZ @ 0x0035b1c0 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0035B1C0Get(void)
{
	return 0;
}

// ?Rva00411128Get@@YAHXZ @ 0x00411128 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00411128Get(void)
{
	return 0;
}

// ?Rva004A9911Get@@YAHXZ @ 0x004a9911 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva004A9911Get(void)
{
	return 0;
}

// ?Rva00538D14Get@@YAHXZ @ 0x00538d14 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00538D14Get(void)
{
	return 0;
}

// ?Rva0059F379Get@@YAHXZ @ 0x0059f379 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0059F379Get(void)
{
	return 0;
}

// ?Rva0065EC9AGet@@YAHXZ @ 0x0065ec9a (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0065EC9AGet(void)
{
	return 0;
}

// ?Rva006C6490Get@@YAHXZ @ 0x006c6490 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva006C6490Get(void)
{
	return 0;
}

// ?Rva007542B3Get@@YAHXZ @ 0x007542b3 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva007542B3Get(void)
{
	return 0;
}
// ?Rva00050D50Get@@YAHXZ @ 0x00050d50 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00050D50Get(void)
{
	return 0;
}

// ?Rva000B19F8Get@@YAHXZ @ 0x000b19f8 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva000B19F8Get(void)
{
	return 0;
}

// ?Rva00149A8CGet@@YAHXZ @ 0x00149a8c (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00149A8CGet(void)
{
	return 0;
}

// ?Rva0017EF80Get@@YAHXZ @ 0x0017ef80 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0017EF80Get(void)
{
	return 0;
}

// ?Rva00215EE9Get@@YAHXZ @ 0x00215ee9 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00215EE9Get(void)
{
	return 0;
}

// ?Rva0028B872Get@@YAHXZ @ 0x0028b872 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0028B872Get(void)
{
	return 0;
}

// ?Rva002C0A0CGet@@YAHXZ @ 0x002c0a0c (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002C0A0CGet(void)
{
	return 0;
}

// ?Rva002D95A9Get@@YAHXZ @ 0x002d95a9 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002D95A9Get(void)
{
	return 0;
}

// ?Rva002E6E9CGet@@YAHXZ @ 0x002e6e9c (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva002E6E9CGet(void)
{
	return 0;
}

// ?Rva0035BD7BGet@@YAHXZ @ 0x0035bd7b (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0035BD7BGet(void)
{
	return 0;
}

// ?Rva0042D6D3Get@@YAHXZ @ 0x0042d6d3 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0042D6D3Get(void)
{
	return 0;
}

// ?Rva004B0D49Get@@YAHXZ @ 0x004b0d49 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva004B0D49Get(void)
{
	return 0;
}

// ?Rva0053EC1EGet@@YAHXZ @ 0x0053ec1e (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0053EC1EGet(void)
{
	return 0;
}

// ?Rva005A671AGet@@YAHXZ @ 0x005a671a (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva005A671AGet(void)
{
	return 0;
}

// ?Rva00661618Get@@YAHXZ @ 0x00661618 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00661618Get(void)
{
	return 0;
}

// ?Rva006C64F5Get@@YAHXZ @ 0x006c64f5 (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva006C64F5Get(void)
{
	return 0;
}

// ?Rva0075ACADGet@@YAHXZ @ 0x0075acad (3B): returns 0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0075ACADGet(void)
{
	return 0;
}
