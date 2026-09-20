// ?bfmeClearAll@@YAXXZ, retail 0x006B5830 (53 bytes).
// BFME1 Bfme5SeventySeven.cpp donor, trimmed to bfmeClearAll; the file's
// other bodies live at other game.dat addresses and land separately.
// Retail-measured BFME2 repair: the four cleared tables bake to their
// BFME2 absolutes (the donor's externs carry the BFME1 addresses).

extern "C" void * __cdecl memset(void *destination, int value, unsigned int bytes);

#pragma intrinsic(memset)

#define g_bfmeFirstFD ((int *)0x00E1F8E0)
#define g_bfmeSecondFD ((int *)0x00E21220)
#define g_bfmeThirdFD ((int *)0x00E20FC0)
#define g_bfmeFourthFD ((int *)0x00E20DA0)

// ?bfmeClearAll@@YAXXZ
void __cdecl bfmeClearAll(void)
{
	memset(g_bfmeFirstFD, 0, 0x230 * 4);
	memset(g_bfmeSecondFD, 0, 0x230 * 4);
	memset(g_bfmeThirdFD, 0, 0x80 * 4);
	memset(g_bfmeFourthFD, 0, 0x80 * 4);
}
