// Two constant-field constructors from the R3 scalar-field family.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/R3ScalarFieldConstructors.cpp); trimmed to
// the two bodies that place in game.dat. The mov-eax-ecx opening marks a
// constructor (the return value is `this`); store order is source order, so
// the out-of-order zeros are written as listed. Identity is not recovered:
// class names are the BFME1 constructor RVAs and fields are offsets. Each
// relocated immediate is spelled as the address of an extern named for the
// BFME2 address build.py fills in from retail.

extern int Gen00C1F470;

class Rva00352900
{
public:
	Rva00352900();
	int *m_00;
	int m_04, m_08;
	char m_0C, m_0D, m_0E;
};
Rva00352900::Rva00352900()
{
	m_04 = 0;
	m_08 = 0;
	m_00 = &Gen00C1F470;
	m_0C = 1;
	m_0D = 0;
	m_0E = 0;
}

class Rva00489BC0
{
public:
	Rva00489BC0();
	int m_00, m_04, m_08, m_0C, m_10, m_14;
};
Rva00489BC0::Rva00489BC0()
{
	m_00 = 0;
	m_04 = 0;
	m_14 = 0;
	m_08 = 0;
	m_0C = 0;
	m_10 = 0;
}
