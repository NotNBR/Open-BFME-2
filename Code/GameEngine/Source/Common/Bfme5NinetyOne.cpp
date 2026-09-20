extern int g_bfmeSeedJC;
extern int g_bfmeCarryJC;

// ?bfmeRandom@@YAHH@Z
int bfmeRandom(int range)
{
	int seed = g_bfmeSeedJC;
	int carry = g_bfmeCarryJC;

	int mix = seed * 0x3E322 + carry * 0x8149A;
	int next = mix % 0xF408B;

	g_bfmeCarryJC = seed;
	g_bfmeSeedJC = next;
	return next % range;
}
