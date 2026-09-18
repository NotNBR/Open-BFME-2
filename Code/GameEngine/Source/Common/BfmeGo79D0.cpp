// cl: /DNDEBUG /MD /O2

extern int g_bfmeTableC7E0;

extern void __cdecl Rva009A7950(
	int *, unsigned short *, int, int, int, int, const int *);

// Scalar VP6 8x8 interpolation helper at retail RVA 0x009A79D0 (BFME1) and
// 0x001B8430 (BFME2). The table global lives at a different address per game
// (DIR32 auto-patches from retail, no source change); the trailing worker
// resolves via pin. B1 0x009A79D0 295B -> B2 0x001B8430 295B,
// immediate-only drift (table address). The duplicate at B1 0x009A7FE0 is
// not carried here (its B2 twin is unidentified).
void __cdecl Rva009A79D0Vp6Filter(
    const unsigned char *source,
	unsigned short *destination,
	int sourcePitch,
	const int *horizontalWeights,
	const int *verticalWeights)
{
    int sourceDelta = sourcePitch;
    sourceDelta -= 8;
    int *table = &g_bfmeTableC7E0;
    table += 2;
    int rows = 9;
    const unsigned char *sourcePointer = source;

    do
    {
        for (int column = -2; column <= 5; column++)
        {
            table[column] = (sourcePointer[0] * horizontalWeights[0] +
                              sourcePointer[1] * horizontalWeights[1] + 0x40) >> 7;
            sourcePointer++;
        }

        sourcePointer += sourceDelta;
		table += 8;
		--rows;
	}
	while (rows != 0);

	Rva009A7950(&g_bfmeTableC7E0, destination, 8, 8, 8, 8, verticalWeights);
}
