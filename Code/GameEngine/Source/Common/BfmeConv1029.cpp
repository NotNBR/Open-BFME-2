// bfmeGo1029B, retail 0x006656A0 (32B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv1029.cpp
// (BFME1 0x007F9100). Only the placed reset is defined here; the donor's
// other three members stay out, so the unmatched-definition gate passes.
// The body clears the flag, re-inits the sub-block through the single
// pinned call site, zeroes both coordinates, and returns this.

class BfmeSub1029
{
public:
	void bfmeInit1029(void);
};

class BfmeB1029
{
public:
	BfmeB1029 *bfmeGo1029B(void);

	char m_bfmeFlag;
	char m_bfmePad[3];
	BfmeSub1029 m_bfmeSub;
	char m_bfmePad2[0xb];
	int m_bfmeX;
	int m_bfmeY;
};

// ?bfmeGo1029B@BfmeB1029@@QAEPAV1@XZ, retail 0x006656A0 (32B).
BfmeB1029 *BfmeB1029::bfmeGo1029B(void)
{
	m_bfmeFlag = 0;
	m_bfmeSub.bfmeInit1029();
	m_bfmeX = 0;
	m_bfmeY = 0;
	return this;
}
