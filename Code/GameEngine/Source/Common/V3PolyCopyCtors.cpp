// cl: /O1 /DNDEBUG /MD /EHsc
// Retail RVA 0x003AE20D, 93 bytes.
// Rva005EA0D0 copy constructor: vptr plus thirteen scalar dwords (0x38).
// Ported from Open-BFME-1 V3PolyCopyCtors.cpp, which documents the family:
// the class identity is not recovered, so the B1 body-address name carries
// over; the vptr dword is a DIR32 site the gate takes from the target.
// /O1, not the base /O2: the one-int sibling below needs the size-optimizer
// scratch choice (mov ecx,[ecx+4], not edx), and the thirteen-int body is
// identical under both.

typedef int Int;

class Rva005EA0D0
{
public:
	Rva005EA0D0(const Rva005EA0D0 &other);
	virtual ~Rva005EA0D0();

	Int m_field04;
	Int m_field08;
	Int m_field0C;
	Int m_field10;
	Int m_field14;
	Int m_field18;
	Int m_field1C;
	Int m_field20;
	Int m_field24;
	Int m_field28;
	Int m_field2C;
	Int m_field30;
	Int m_field34;
};

Rva005EA0D0::Rva005EA0D0(const Rva005EA0D0 &other)
{
	m_field04 = other.m_field04;
	m_field08 = other.m_field08;
	m_field0C = other.m_field0C;
	m_field10 = other.m_field10;
	m_field14 = other.m_field14;
	m_field18 = other.m_field18;
	m_field1C = other.m_field1C;
	m_field20 = other.m_field20;
	m_field24 = other.m_field24;
	m_field28 = other.m_field28;
	m_field2C = other.m_field2C;
	m_field30 = other.m_field30;
	m_field34 = other.m_field34;
}

// ------------------------------------ vptr + one int (retail 0x003AE07D)
// B2 body-address name: B1 holds two identical one-int classes, so no B1
// name is justified for this body.
class Rva003AE07D
{
public:
	Rva003AE07D(const Rva003AE07D &other);
	virtual ~Rva003AE07D();

	Int m_field04;
};

Rva003AE07D::Rva003AE07D(const Rva003AE07D &other)
{
	m_field04 = other.m_field04;
}

// ----------------------------------- vptr + two ints (retail 0x003AE11B)
// B2 body-address name: no B1 class has exactly this shape.
class Rva003AE11B
{
public:
	Rva003AE11B(const Rva003AE11B &other);
	virtual ~Rva003AE11B();

	Int m_field04;
	Int m_field08;
};

Rva003AE11B::Rva003AE11B(const Rva003AE11B &other)
{
	m_field04 = other.m_field04;
	m_field08 = other.m_field08;
}
