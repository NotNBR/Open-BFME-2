// Nine __thiscall constructors that zero a fixed set of members (trimmed to
// the placed Rva007E3A20 body; the other eight are declared-only here).

class Rva00351BC0
{
public:
	Rva00351BC0();
};

class Rva00351BD0
{
public:
	Rva00351BD0();
};

class Rva003A4300
{
public:
	Rva003A4300();
};

class Rva003BEA20
{
public:
	Rva003BEA20();
};

class Rva003F6A60
{
public:
	Rva003F6A60();
};

class Rva00339C20
{
public:
	Rva00339C20();
};

class Rva00739DE0
{
public:
	Rva00739DE0();
};

class Rva003366B0
{
public:
	Rva003366B0();
};

// Three byte members, two adjacent at 0 and 1 and one far out at 0x105.
class Rva007E3A20
{
public:
	Rva007E3A20();
	unsigned char m_a;
	unsigned char m_b;
	char m_gap[ 0x103 ];
	unsigned char m_c;
};

// ??0Rva007E3A20@@QAE@XZ
Rva007E3A20::Rva007E3A20()
{
	m_a = 0;
	m_b = 0;
	m_c = 0;
}
