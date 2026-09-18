// Byte-identical BFME1 donor extract (see reference/open-bfme-1/
// Code/GameEngine/Source/Common/BfmeConv1325.cpp). Only bfmeDelTWA is
// served here; the donor's TWB sibling has no ledger row and its TWC
// sibling lives in BfmeConv1325TWC.cpp, so the whole file cannot land
// as one TU.

extern void *g_bfmeVftATWA[];
extern void *g_bfmeVftBTWA[];
extern void *g_bfmeVftCTWA[];

class BfmeStrTWA
{
public:
	void bfmeDtorTWA();
	char m_bfmePad[0x20];
};

void bfmeFreeTWA(void *p, int n);

class BfmeThingTWA
{
public:
	void *bfmeDelTWA(unsigned char flags);
	void bfmeStepTWA();
	void *m_bfmeVft0;
	void *m_bfmeVft1;
	char m_bfmePad[8];
	BfmeStrTWA m_bfmeStr;
};

void *BfmeThingTWA::bfmeDelTWA(unsigned char flags)
{
	m_bfmeVft0 = g_bfmeVftATWA;
	m_bfmeVft1 = g_bfmeVftBTWA;
	bfmeStepTWA();
	m_bfmeStr.bfmeDtorTWA();
	m_bfmeVft0 = g_bfmeVftCTWA;
	if (flags & 1)
		bfmeFreeTWA(this, 0x30);
	return this;
}
