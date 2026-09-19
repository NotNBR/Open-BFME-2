// Open-BFME5 conversions.
// ?bfmeGo928F@BfmeThing928F@@QAEXXZ, retail 0x0010C80A (27B). Ported from
// Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv928.cpp (BFME1 0x007B4F80).
// Trimmed to the placed three-call dispatcher; siblings declared-only here.
// Callees resolve via new ledger pins at 0x0010C6C4 (bfmeOne928F),
// 0x00108342 (bfmeTwo928F) and 0x00108A79 (bfmeTail928F): the donor's own
// family names on unclaimed ground.

class BfmeSub928F
{
public:
	void bfmeTail928F();
};

class BfmeThing928F
{
public:
	void bfmeGo928F();
	void bfmeOne928F();
	void bfmeTwo928F();
	char m_bfmePad[0x24c];
	BfmeSub928F *m_bfmeSub;
};

// ?bfmeGo928F@BfmeThing928F@@QAEXXZ
void BfmeThing928F::bfmeGo928F()
{
	bfmeOne928F();
	bfmeTwo928F();
	m_bfmeSub->bfmeTail928F();
}
