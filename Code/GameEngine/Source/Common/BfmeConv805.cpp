// Two tiny accessors through held sub-objects.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeConv805.cpp); trimmed to the two T1
// bodies the sweep places. The donor's ECJ/ECMa defs are omitted.

struct BfmeHeldECKa
{
	unsigned char m_bfmeHead[0x280];
	void *m_bfmeX;
	void bfmeDoECKa();
};

struct BfmeThingECKa
{
	void *bfmeGoECKa();
	unsigned char m_bfmeHead[4];
	BfmeHeldECKa *m_bfmeP;
};

void *BfmeThingECKa::bfmeGoECKa()
{
	m_bfmeP->bfmeDoECKa();
	return m_bfmeP->m_bfmeX;
}

struct BfmeHeldECKb
{
	unsigned char m_bfmeHead[0x29c];
	void *m_bfmeX;
	void bfmeDoECKb();
};

struct BfmeThingECKb
{
	void *bfmeGoECKb();
	unsigned char m_bfmeHead[4];
	BfmeHeldECKb *m_bfmeP;
};

void *BfmeThingECKb::bfmeGoECKb()
{
	m_bfmeP->bfmeDoECKb();
	return m_bfmeP->m_bfmeX;
}
