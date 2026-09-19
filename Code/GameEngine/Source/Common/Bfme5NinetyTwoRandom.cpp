// ?bfmeRandomPositive@@YAHH@Z
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/Bfme5NinetyTwo.cpp); trimmed to the single T3
// body the sweep places.

extern int g_bfmeSeedJC;
extern int g_bfmeCarryJC;

int bfmeRandomPositive(int range)
{
	int seed = g_bfmeSeedJC;
	int carry = g_bfmeCarryJC;

	int mix = seed * 0x3E322 + carry * 0x8149A;
	int next = mix % 0xF408B;

	g_bfmeCarryJC = seed;
	g_bfmeSeedJC = next;

	int value = next % range;
	if (value < 0)
		value = -value;
	return value;
}
