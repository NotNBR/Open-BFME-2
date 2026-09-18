// cl: /GX-
// Global byte getters, each `mov al,[mem]; ret` (6B), ported from Open-BFME-1
// (same shape as its GlobalDwordGetters file, byte-width). Each reads one
// .data byte global into AL; identity unrecoverable, so globals and functions
// are address-derived (g_Va<VA> / Rva<RVA>GetByte). One shared TU, one row
// per body.

// ?Rva0004CAB1GetByte@@YAEXZ @ 0x0004CAB1 (6B) over 0x00DB5F7D.

extern unsigned char g_Va00DB5F7D;

unsigned char Rva0004CAB1GetByte(void)
{
	return g_Va00DB5F7D;
}

// ?Rva0004CAB7GetByte@@YAEXZ @ 0x0004CAB7 (6B) over 0x00DEC3D9.

extern unsigned char g_Va00DEC3D9;

unsigned char Rva0004CAB7GetByte(void)
{
	return g_Va00DEC3D9;
}
