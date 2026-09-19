// One constant-field constructor from the R3 scalar-field family.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/R3ScalarFieldConstructors2.cpp); trimmed to
// the single body that places in game.dat. The mov-eax-ecx opening marks a
// constructor (the return value is `this`). Identity is not recovered: the
// class name is the BFME1 constructor RVA and fields are offsets. The
// relocated immediate is spelled as the address of an extern named for the
// BFME2 address build.py fills in from retail.

extern int Gen00BE4324;

class Rva000D1930
{
public:
	Rva000D1930();
	int *m_vtable;
	int m_04, m_08, m_0C, m_10, m_14, m_18;
};
Rva000D1930::Rva000D1930()
{
	m_vtable = &Gen00BE4324;
	m_04 = 0;
	m_08 = 0;
	m_0C = 0;
	m_10 = 0;
	m_14 = 0;
	m_18 = 0;
}
