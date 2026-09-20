// Open-BFME5 conversions.

// ?bfmeDelTYA@BfmeThingTYA@@QAEPAXE@Z, retail 0x0066E3D0 (83B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv1327.cpp
// (BFME1 0x00802110). Only the placed TYA deleter is defined here; the
// donor's TYB half stays out, so the unmatched-definition gate passes.
// Callees mirror the BFME1 pins: bfmeDtorBTYA at 0x00663FA0 and bfmeFreeTYA
// at 0x0065D030 were already pinned, bfmeDtorATYA at 0x0066D900 rides with
// this body. The vftable globals are masked DIR32.

extern void *g_bfmeVftATYA[];
extern void *g_bfmeVftBTYA[];

class BfmeSlotTYA
{
public:
	void bfmeDtorBTYA();
	char m_bfmePad[8];
};

class BfmeHeadTYA
{
public:
	void bfmeDtorATYA();
	char m_bfmePad[8];
};

void bfmeFreeTYA(void *p, int n);

class BfmeThingTYA
{
public:
	void *bfmeDelTYA(unsigned char flags);
	void *m_bfmeVft;
	int m_bfme04;
	char m_bfmePad[8];
	BfmeSlotTYA m_bfmeC;
	BfmeSlotTYA m_bfmeB;
	BfmeHeadTYA m_bfmeA;
	int m_bfme28;
	int m_bfme2c;
	char m_bfme30;
	char m_bfmePad2[0x24];
	char m_bfme55;
};

void *BfmeThingTYA::bfmeDelTYA(unsigned char flags)
{
	m_bfmeVft = g_bfmeVftATYA;
	m_bfme04 = 0;
	m_bfme28 = 0;
	m_bfme30 = 0;
	m_bfme55 = 0;
	m_bfme2c = 0;
	m_bfmeA.bfmeDtorATYA();
	m_bfmeB.bfmeDtorBTYA();
	m_bfmeC.bfmeDtorBTYA();
	m_bfmeVft = g_bfmeVftBTYA;
	if (flags & 1)
		bfmeFreeTYA(this, 0xd8);
	return this;
}
