// A ctor through an init helper and a queue pop.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeConv881.cpp); trimmed to the two T1
// bodies the sweep places.

struct BfmeThingEOE
{
	BfmeThingEOE *bfmeCtorEOE();
};

void __stdcall bfmeInitEOE(BfmeThingEOE *o, int a, int b, void (*ca)(), void (*cb)());
extern "C" void bfmeCbEOEa();
extern "C" void bfmeCbEOEb();

BfmeThingEOE *BfmeThingEOE::bfmeCtorEOE()
{
	bfmeInitEOE(this, 0x14, 8, bfmeCbEOEa, bfmeCbEOEb);
	return this;
}

struct BfmeQueueEOF
{
	unsigned char m_bfmeHead[4];
	void **m_bfmeEnd;
	unsigned char m_bfmePad[4];
	void **volatile m_bfmeCur;
};

struct BfmeThingEOF
{
	void *bfmeGoEOF();
	BfmeQueueEOF *m_bfmeQ;
};

void *BfmeThingEOF::bfmeGoEOF()
{
	BfmeQueueEOF *q = m_bfmeQ;
	if (q->m_bfmeCur == q->m_bfmeEnd)
		return 0;
	void **cur = q->m_bfmeCur;
	void *v = *cur;
	q->m_bfmeCur = cur + 2;
	return v;
}
