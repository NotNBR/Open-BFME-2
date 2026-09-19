// Guarded indirect call.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeConv816.cpp); trimmed to the single T1
// body the sweep places.

struct BfmeThingELF
{
	void bfmeGoELF(void *a);
	unsigned char m_bfmeHead[4];
	void (__cdecl *m_bfmeFn)(void *ctx, void *a);
	void *m_bfmeCtx;
};

void BfmeThingELF::bfmeGoELF(void *a)
{
	void (__cdecl *fn)(void *, void *) = m_bfmeFn;
	if (fn)
		fn(m_bfmeCtx, a);
}
