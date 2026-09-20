// cl: /GX-
// Cold-slice global dword getters without vtable carriage (twin-free TU).
//
// Same shape as GlobalGetterSingles.cpp (mov eax,[mem] / ret, 6B) but kept in
// a separate TU so this batch does not contend with appends there. Each reads
// one .data dword global; identity unrecoverable, so globals and functions
// are address-derived (g_Va<VA> / Rva<RVA>Get). Opaque names witness only the
// address and the global. The /GX- line matches the sibling TUs (verified
// frameless six-byte shape).
extern int g_Va00DEC3CC;

// ?Rva00083B7BGet@@YAHXZ @ 0x00083b7b (6B) over 0x00DEC3CC.
// Follows a ret-with-pop (prev C2), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00083B7BGet(void)
{
	return g_Va00DEC3CC;
}

extern int g_Va00DB47EC;

// ?Rva00094B87Get@@YAHXZ @ 0x00094b87 (6B) over 0x00DB47EC.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00094B87Get(void)
{
	return g_Va00DB47EC;
}

extern int g_Va00DEDA14;

// ?Rva0014D241Get@@YAHXZ @ 0x0014d241 (6B) over 0x00DEDA14.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0014D241Get(void)
{
	return g_Va00DEDA14;
}

extern int g_Va00DFE348;

// ?Rva0021913AGet@@YAHXZ @ 0x0021913a (6B) over 0x00DFE348.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0021913AGet(void)
{
	return g_Va00DFE348;
}

extern int g_Va00E032E0;

// ?Rva0023C54CGet@@YAHXZ @ 0x0023c54c (6B) over 0x00E032E0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0023C54CGet(void)
{
	return g_Va00E032E0;
}

extern int g_Va00E0333C;

// ?Rva00248D60Get@@YAHXZ @ 0x00248d60 (6B) over 0x00E0333C.
// Follows a ret-with-pop (prev C2), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00248D60Get(void)
{
	return g_Va00E0333C;
}

extern int g_Va00E03354;

// ?Rva00248D66Get@@YAHXZ @ 0x00248d66 (6B) over 0x00E03354.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00248D66Get(void)
{
	return g_Va00E03354;
}

extern int g_Va00DBB708;

// ?Rva0027C220Get@@YAHXZ @ 0x0027c220 (6B) over 0x00DBB708.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0027C220Get(void)
{
	return g_Va00DBB708;
}

extern int g_Va00E04450;

// ?Rva0029A26FGet@@YAHXZ @ 0x0029a26f (6B) over 0x00E04450.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0029A26FGet(void)
{
	return g_Va00E04450;
}

extern int g_Va00E04478;

// ?Rva0031AA00Get@@YAHXZ @ 0x0031aa00 (6B) over 0x00E04478.
// Follows a ret-with-pop (prev C2), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0031AA00Get(void)
{
	return g_Va00E04478;
}

extern int g_Va00E032C8;

// ?Rva00320607Get@@YAHXZ @ 0x00320607 (6B) over 0x00E032C8.
// Follows a ret-with-pop (prev C2), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00320607Get(void)
{
	return g_Va00E032C8;
}

extern int g_Va00DBD0F0;

// ?Rva00328A65Get@@YAHXZ @ 0x00328a65 (6B) over 0x00DBD0F0.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00328A65Get(void)
{
	return g_Va00DBD0F0;
}

extern int g_Va00E04910;

// ?Rva00376D17Get@@YAHXZ @ 0x00376d17 (6B) over 0x00E04910.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00376D17Get(void)
{
	return g_Va00E04910;
}

extern int g_Va00E04908;

// ?Rva00376D1DGet@@YAHXZ @ 0x00376d1d (6B) over 0x00E04908.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00376D1DGet(void)
{
	return g_Va00E04908;
}

extern int g_Va00E05FAC;

// ?Rva00376D23Get@@YAHXZ @ 0x00376d23 (6B) over 0x00E05FAC.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00376D23Get(void)
{
	return g_Va00E05FAC;
}

extern int g_Va00E032FC;

// ?Rva0038071EGet@@YAHXZ @ 0x0038071e (6B) over 0x00E032FC.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0038071EGet(void)
{
	return g_Va00E032FC;
}

extern int g_Va00E046B8;

// ?Rva00380724Get@@YAHXZ @ 0x00380724 (6B) over 0x00E046B8.
// Follows a ret (prev C3), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva00380724Get(void)
{
	return g_Va00E046B8;
}

extern int g_Va00E048D0;

// ?Rva0040596CGet@@YAHXZ @ 0x0040596c (6B) over 0x00E048D0.
// Follows a ret-with-pop (prev C2), no .rdata vtable slot, no direct callers,
// no branch sources. Opaque address-derived name.
int Rva0040596CGet(void)
{
	return g_Va00E048D0;
}
