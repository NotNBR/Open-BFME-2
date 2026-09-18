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

// ?Rva00131062GetByte@@YAEXZ @ 0x00131062 (6B) over 0x00DB5F98.

extern unsigned char g_Va00DB5F98;

unsigned char Rva00131062GetByte(void)
{
	return g_Va00DB5F98;
}

// ?Rva00131068GetByte@@YAEXZ @ 0x00131068 (6B) over 0x00DEDA04.

extern unsigned char g_Va00DEDA04;

unsigned char Rva00131068GetByte(void)
{
	return g_Va00DEDA04;
}

// ?Rva0006E19BGetByte@@YAEXZ @ 0x0006E19B (6B) over 0x00DB5FCD.

extern unsigned char g_Va00DB5FCD;

unsigned char Rva0006E19BGetByte(void)
{
	return g_Va00DB5FCD;
}

// ?Rva0006E1A1GetByte@@YAEXZ @ 0x0006E1A1 (6B) over 0x00DEDA05.

extern unsigned char g_Va00DEDA05;

unsigned char Rva0006E1A1GetByte(void)
{
	return g_Va00DEDA05;
}

// ?Rva00110094GetByte@@YAEXZ @ 0x00110094 (6B) over 0x00DEC3D7.

extern unsigned char g_Va00DEC3D7;

unsigned char Rva00110094GetByte(void)
{
	return g_Va00DEC3D7;
}

// ?Rva000308D0GetByte@@YAEXZ @ 0x000308D0 (6B) over 0x00DE0818.

extern unsigned char g_Va00DE0818;

unsigned char Rva000308D0GetByte(void)
{
	return g_Va00DE0818;
}
