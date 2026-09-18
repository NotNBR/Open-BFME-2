// BFME1 byte-identical donor: reference/open-bfme-1/Code/GameEngine/Source/Common/R2ZeroingConstructors.cpp
// Trimmed to the bodies that reproduce game.dat bytes. The donor holds a large
// family of tiny zeroing constructors; only the claimed ones below are carried.
// The R2Data externs are address-derived placeholders (DIR32 sites the patcher
// fills from retail) and carry no type information, per the donor's own notes.

extern int R2Data010EC784;
extern int R2Data010EC760;

class Rva003B85D0
{
public:
	void * m_at00;
	int m_at04;
	int m_at08;
	int m_at0C;
	char m_at10;
	Rva003B85D0();
};
Rva003B85D0::Rva003B85D0()
{
	m_at00 = &R2Data010EC784;
	m_at04 = 0;
	m_at08 = 0;
	m_at0C = 0;
	m_at10 = 0;
}
