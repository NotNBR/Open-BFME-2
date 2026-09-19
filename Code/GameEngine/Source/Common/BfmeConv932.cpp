class BfmeSub932C
{
public:
	unsigned char bfmeQuery932C();
};

class BfmeThing932C
{
public:
	int bfmeGo932C();
	char m_bfmePad[0x24];
	BfmeSub932C *m_bfmeSub;
};

int BfmeThing932C::bfmeGo932C()
{
	BfmeSub932C *s = m_bfmeSub;
	if (s)
		return s->bfmeQuery932C();
	return 0;
}

class BfmeThing932E
{
public:
	void bfmeGo932E();
	int bfmeTest932E();
	void bfmeTail932E();
};

void BfmeThing932E::bfmeGo932E()
{
	if (!bfmeTest932E())
		bfmeTail932E();
}

struct BfmeSlotJA;

class BfmeHookJA
{
public:
	BfmeSlotJA *bfmeCallJA();
};

struct BfmeSlotJA
{
	char m_bfmePad[4];
	BfmeHookJA *m_bfmeHook;
};

class BfmeThing932A
{
public:
	BfmeSlotJA *bfmeGo932A();
	char m_bfmePad[0x18];
	BfmeSlotJA *m_bfmeSlot;
};

// ?bfmeGo932A@BfmeThing932A@@QAEPAUBfmeSlotJA@@XZ, retail 0x0030D833 (22B).
//
// The hook call is a tail jmp (same shape as the donor); it resolves
// through the ledger pin at 0x001E35DF, whose +4-chain-walker bytes are
// neutrally rowed as a dup_ span.
BfmeSlotJA *BfmeThing932A::bfmeGo932A()
{
	BfmeSlotJA *s = m_bfmeSlot;
	if (s) {
		BfmeHookJA *h = s->m_bfmeHook;
		if (h)
			return h->bfmeCallJA();
		return s;
	}
	return 0;
}
