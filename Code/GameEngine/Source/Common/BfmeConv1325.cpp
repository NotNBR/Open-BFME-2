// Byte-identical BFME1 donor extract (see reference/open-bfme-1/
// Code/GameEngine/Source/Common/BfmeConv1325.cpp). bfmeDelTWA and
// bfmeDelTWB are served here; the donor's TWC sibling lives in
// BfmeConv1325TWC.cpp, so the whole file cannot land as one TU.

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

extern void *g_bfmeVftATWB[];
extern void *g_bfmeVftBTWB[];

class BfmeStrTWB
{
public:
	void bfmeDtorTWB(void);
	char m_bfmePad[0x10];
};

class BfmeListTWB
{
public:
	void bfmeDropTWB(void);
	char m_bfmePad[0x10];
};

void bfmeFreeTWB(void *place);

class BfmeThingTWB
{
public:
	void *bfmeDelTWB(unsigned char flags);
	void *m_bfmeVft;
	char m_bfmePad[4];
	int m_bfme08;
	char m_bfmePad2[0x10];
	BfmeListTWB m_bfmeList;
	BfmeStrTWB m_bfmeB;
	BfmeStrTWB m_bfmeA;
};

// ?bfmeDelTWB@BfmeThingTWB@@QAEPAXE@Z
void *BfmeThingTWB::bfmeDelTWB(unsigned char flags)
{
	m_bfmeVft = g_bfmeVftATWB;
	m_bfme08 = 0;
	m_bfmeA.bfmeDtorTWB();
	m_bfmeB.bfmeDtorTWB();
	m_bfmeList.bfmeDropTWB();
	m_bfmeVft = g_bfmeVftBTWB;
	if (flags & 1)
		bfmeFreeTWB(this);
	return this;
}
