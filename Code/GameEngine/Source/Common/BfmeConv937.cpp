// BfmeThing937C::bfmeGo937C, retail 0x00176C70 (22B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv937.cpp
// (BFME1 0x00958700). Only the placed null-checked accessor is defined here;
// the donor's 937A/937B/937E helpers stay out, so the unmatched-definition
// gate passes. Retail throws E_POINTER through the single pinned helper when
// the slot is null, then returns it.

void __stdcall bfmeThrow937C(unsigned int code);

class BfmeThing937C
{
public:
	void *bfmeGo937C();
	void *m_bfmeP;
};

// ?bfmeGo937C@BfmeThing937C@@QAEPAXXZ, retail 0x00176C70 (22B).
void *BfmeThing937C::bfmeGo937C()
{
	if (m_bfmeP == 0)
		bfmeThrow937C(0x80004003);
	return m_bfmeP;
}
