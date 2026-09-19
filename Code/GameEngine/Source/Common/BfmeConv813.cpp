// ?bfmeUpdate@BfmeThingEFC@@QAEXH@Z, retail 0x0039B1E2 (23B). Ported from
// Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv813.cpp (BFME1 0x001B2690).
// Trimmed to the placed scalar update; siblings declared-only here. Callee
// bfmeCalcEFC resolves via the new ledger pin at 0x0039B145 (the donor's own
// family name on unclaimed ground).

float __stdcall bfmeCalcEFC(int val);

struct BfmeThingEFC
{
	unsigned char m_pad[0x8];
	float m_f8;
	int m_valC;
	void bfmeUpdate(int val);
};

// ?bfmeUpdate@BfmeThingEFC@@QAEXH@Z
void BfmeThingEFC::bfmeUpdate(int val)
{
	m_valC = val;
	m_f8 = bfmeCalcEFC(val);
}
