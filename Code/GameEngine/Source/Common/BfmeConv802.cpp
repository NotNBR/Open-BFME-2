// ?bfmeGoEBC@BfmeThingEBC@@QAEXPAX@Z, retail 0x00460A85 (19B) and
// ?bfmeGoEBD@BfmeThingEBD@@QAEXXZ, retail 0x003862CA (17B). Ported from
// Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv802.cpp (BFME1 0x001F8660
// and 0x006374B0). Trimmed to the two placed owner/sub dispatches; the EBE
// lookup is declared-only here. Callees resolve via new ledger pins at
// 0x0046094C (bfmeCallEBC) and 0x00383EEA (bfmeCallEBD), the donor's own
// family names on unclaimed ground.

class BfmeOwnerEBC
{
public:
	void bfmeCallEBC();
};

struct BfmeThingEBC
{
	void bfmeGoEBC(void *unused);
	unsigned char m_bfmeHead[0x21];
	char m_bfmeFlag;
};

// ?bfmeGoEBC@BfmeThingEBC@@QAEXPAX@Z
void BfmeThingEBC::bfmeGoEBC(void *unused)
{
	((BfmeOwnerEBC *)((char *)this - 0x1c))->bfmeCallEBC();
	m_bfmeFlag = 1;
}

class BfmeSubEBD
{
public:
	void bfmeCallEBD();
};

struct BfmeThingEBD
{
	void bfmeGoEBD();
	unsigned char m_bfmeHead[0x18];
	BfmeSubEBD m_bfmeSub;
	// Retail seats the flag at +0x6C, four bytes past the donor's +0x68
	// (empty sub + 0x4F pad); the filler absorbs the drift here.
	unsigned char m_bfmePad[0x53];
	char m_bfmeFlag;
};

// ?bfmeGoEBD@BfmeThingEBD@@QAEXXZ
void BfmeThingEBD::bfmeGoEBD()
{
	m_bfmeSub.bfmeCallEBD();
	m_bfmeFlag = 0;
}
