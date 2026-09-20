// Open-BFME5 conversions (trimmed; only bfmeGoRF is placed, the rest is
// declared-only).

struct BfmeObjRB
{
	int m_bfmeOn;
};

extern BfmeObjRB *g_bfmeGlobRB;
void bfmeOneRB(int f, BfmeObjRB *p);
void bfmeTwoRB(int k, int f);

void bfmeGoRB(void);

void bfmeFreeRC(void *p);

class BfmeThingRC
{
public:
	void bfmeGoRC();
	char m_bfmePad[0x24];
	void *m_bfmeP;
	int m_bfmeN;
};

class BfmeSubRD
{
public:
	void bfmeFillRD(void **out);
};

class BfmeThingRD
{
public:
	void **bfmeGoRD(void **out);
	char m_bfmePad[0x18];
	BfmeSubRD *m_bfmeSub;
};

class BfmeOtherRE
{
public:
	char bfmeCmpRE(int a, int b);
};

class BfmeThingRE
{
public:
	char bfmeGoRE(BfmeOtherRE *o);
	int m_bfmeA;
	int m_bfmeB;
};

void *bfmeOneRF(void *t, void *a);
void *bfmeTwoRF(void *r, void *b);

class BfmeThingRF
{
public:
	void *bfmeGoRF(void *a, void *b);
	char m_bfmePad[0x10];
	void *m_bfmeT;
};

// ?bfmeGoRF@BfmeThingRF@@QAEPAXPAX0@Z
void *BfmeThingRF::bfmeGoRF(void *a, void *b)
{
	void *r = bfmeOneRF(m_bfmeT, a);
	if (!r)
		return b;
	return bfmeTwoRF(r, b);
}

// ?bfmeGoRE@BfmeThingRE@@QAEDPAVBfmeOtherRE@@@Z
char BfmeThingRE::bfmeGoRE(BfmeOtherRE *o)
{
	if (!o->bfmeCmpRE(m_bfmeA, m_bfmeB))
		return 0;
	++m_bfmeB;
	return 1;
}
