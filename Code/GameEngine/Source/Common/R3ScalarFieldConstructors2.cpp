// Two constant-field constructors from the R3 scalar-field family.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/R3ScalarFieldConstructors2.cpp); trimmed to
// the two T1 bodies the sweep places.

class Rva006853A0
{
public:
	Rva006853A0();
	int m_00, m_04, m_08, m_0C, m_10, m_14;
	short m_18;
};
Rva006853A0::Rva006853A0()
{
	m_00 = 0;
	m_04 = 0;
	m_08 = 0;
	m_0C = 0;
	m_10 = 0;
	m_14 = 0;
	m_18 = 0;
}

class Rva007BA110
{
public:
	Rva007BA110();
	int m_00, m_04, m_08, m_0C, m_10, m_14, m_18;
	char m_pad1C[0x44 - 0x1C];
	int m_44;
};
Rva007BA110::Rva007BA110()
{
	m_00 = 0;
	m_04 = 0;
	m_08 = 0;
	m_0C = 0;
	m_10 = 0;
	m_14 = 0;
	m_18 = 0;
	m_44 = 8;
}
