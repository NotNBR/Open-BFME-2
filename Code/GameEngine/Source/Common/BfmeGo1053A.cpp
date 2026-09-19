// Open-BFME5 conversions.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeConv1053.cpp); trimmed to the single T2
// body the sweep places. The sibling bfmeGo1053E is not placed in game.dat,
// so only the A-block init moves here under its own TU name.

extern "C" void *bfmeVft1053A[];
void *bfmeAlloc1053(int n);

class BfmeA1053
{
public:
	BfmeA1053 *bfmeGo1053A(void);

	void *m_bfmeVfptr;
	int m_bfme04;
	void *m_bfmeBuf;
	int m_bfme0c;
	char m_bfme10;
};

BfmeA1053 *BfmeA1053::bfmeGo1053A(void)
{
	m_bfmeVfptr = bfmeVft1053A;
	m_bfmeBuf = bfmeAlloc1053(0x1000);

	int z = 0;

	m_bfme04 = z;
	m_bfme0c = z;
	m_bfme10 = (char)z;
	return this;
}
