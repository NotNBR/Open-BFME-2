// BfmeThingUNC constructor, retail 0x00674ED0 (62B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv1338.cpp
// (BFME1 0x00808FD0). Only the placed constructor is defined here; the
// donor's UNA/UNB/UND helpers stay out, so the unmatched-definition gate
// passes. Retail installs the UNC vtable, runs the base helper, stores the
// owner and int members, takes an id from the global counter, then chains
// owner->mid->sink and registers through the sink vtable slot.

extern void *g_bfmeVftUNC[];

class BfmeThingUNC;

class BfmeSinkUNC
{
public:
	virtual void bfmeV0UNC() = 0;
	virtual void bfmeRegisterUNC(BfmeThingUNC *p) = 0;
};

struct BfmeMidUNC
{
	char m_bfmePad[0x2a0];
	BfmeSinkUNC *m_bfmeSink;
};

struct BfmeOwnerUNC
{
	char m_bfmePad[0xc];
	BfmeMidUNC *m_bfmeMid;
};

int bfmeNextIdUNC(void);

class BfmeThingUNC
{
public:
	BfmeThingUNC(int a, BfmeOwnerUNC *o);
	void bfmeBaseUNC(void);
	void *m_bfmeVft;
	int m_bfmeA;
	BfmeOwnerUNC *m_bfmeOwner;
	int m_bfmeId;
	BfmeSinkUNC *m_bfmeSink;
};

// ??0BfmeThingUNC@@QAE@HPAUBfmeOwnerUNC@@@Z, retail 0x00674ED0 (62B).
BfmeThingUNC::BfmeThingUNC(int a, BfmeOwnerUNC *o)
{
	m_bfmeVft = g_bfmeVftUNC;
	bfmeBaseUNC();
	m_bfmeOwner = o;
	m_bfmeA = a;
	m_bfmeId = bfmeNextIdUNC();
	m_bfmeSink = o->m_bfmeMid->m_bfmeSink;
	m_bfmeSink->bfmeRegisterUNC(this);
}
