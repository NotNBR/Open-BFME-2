// ?bfmeGo1024E@BfmeE1024@@QAEXXZ, retail 0x0061EE50 (36B). Ported from
// Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv1024.cpp (BFME1 0x009EB8D0).
// Trimmed to the placed flag-gated register body; siblings declared-only.
// Callee bfmeReg1024 resolves via the new ledger pin at 0x00621C60 (single
// BFME1 name); the global is a DIR32 slot.

class BfmeE1024;

class BfmeP1024
{
public:
	void bfmeReg1024(BfmeE1024 *entry);
};

extern BfmeP1024 *g_bfmeP1024;

class BfmeE1024
{
public:
	void bfmeGo1024E(void);

	char m_bfmePad[4];
	int m_bfmeFlags;
};

// ?bfmeGo1024E@BfmeE1024@@QAEXXZ
void BfmeE1024::bfmeGo1024E(void)
{
	if ((m_bfmeFlags & 0xff0000) == 0x70000)
		return;

	if (g_bfmeP1024 == 0)
		return;

	g_bfmeP1024->bfmeReg1024(this);
}
