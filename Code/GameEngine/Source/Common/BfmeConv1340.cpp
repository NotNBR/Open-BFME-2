// A 64-byte write probe returning 1 on full write (trimmed from a two-body
// donor; the UQC node maker is declared-only here).
//
// The T2 body needs one ledger pin (bfmeWriteUQB at 0x00615390).

class BfmeChunkUQB
{
public:
	unsigned bfmeWriteUQB(void *p, unsigned n);
};

// ?bfmeGoUQB@@YGDPAVBfmeChunkUQB@@PAX@Z
char __stdcall bfmeGoUQB(BfmeChunkUQB *c, void *p)
{
	char r = 0;
	if (c->bfmeWriteUQB(p, 0x40) == 0x40)
		r = 1;
	return r;
}

struct BfmeNodeUQC
{
	void *m_bfmeNext;
	void *m_bfmePrev;
	unsigned short m_bfmeValue;
};

BfmeNodeUQC *__stdcall bfmeGoUQC(const unsigned short *v);
