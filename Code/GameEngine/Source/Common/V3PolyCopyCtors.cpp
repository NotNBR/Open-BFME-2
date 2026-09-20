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
typedef short Short;

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

// ------------------------- vptr + two ints + a byte (retail 0x003AE315)
// B2 body-address name: B1's Rva005EA240 has this shape but is a different
// class (different vtable), so the B2 address names the body.
class Rva003AE315
{
public:
	Rva003AE315(const Rva003AE315 &other);
	virtual ~Rva003AE315();

	Int m_field04;
	Int m_field08;
	char m_field0C;
};

Rva003AE315::Rva003AE315(const Rva003AE315 &other)
{
	m_field04 = other.m_field04;
	m_field08 = other.m_field08;
	m_field0C = other.m_field0C;
}

// ------------------------- vptr + one int (retail 0x004AB7EB)
// B2 body-address name: same 21-byte shape as 0x003AE07D with a different
// vtable so a different class. Retail caller 0x004ABB0A re-installs this
// same vptr right after the call.
class Rva004AB7EB
{
public:
	Rva004AB7EB(const Rva004AB7EB &other);
	virtual ~Rva004AB7EB();

	Int m_field04;
};

Rva004AB7EB::Rva004AB7EB(const Rva004AB7EB &other)
{
	m_field04 = other.m_field04;
}

// ------------------------- vptr + one int (retail 0x004C9F61)
// B2 body-address name: same 21-byte shape with a different vtable so a
// different class. Retail caller 0x004C9FC8 installs derived vptr 0xC07E54
// right after the call so this is the base-class copy.
class Rva004C9F61
{
public:
	Rva004C9F61(const Rva004C9F61 &other);
	virtual ~Rva004C9F61();

	Int m_field04;
};

Rva004C9F61::Rva004C9F61(const Rva004C9F61 &other)
{
	m_field04 = other.m_field04;
}

// -------------------- vptr + two ints + a byte (retail 0x0028C6D6)
// B2 body-address name: same 33-byte shape as 0x003AE315 with a different
// vtable so a different class. Retail caller 0x0028F6B0 is itself a ret-4
// copy-ctor tail so this is the base-class copy.
class Rva0028C6D6
{
public:
	Rva0028C6D6(const Rva0028C6D6 &other);
	virtual ~Rva0028C6D6();

	Int m_field04;
	Int m_field08;
	char m_field0C;
};

Rva0028C6D6::Rva0028C6D6(const Rva0028C6D6 &other)
{
	m_field04 = other.m_field04;
	m_field08 = other.m_field08;
	m_field0C = other.m_field0C;
}

// ------------------------- vptr + three ints (retail 0x00318B5C)
// B2 body-address name: same head as the 33-byte pair but the +0x0C member
// is a dword (8B49/8948) not a byte. Retail caller 0x00318D6F guards on
// null then tail-calls into this body.
class Rva00318B5C
{
public:
	Rva00318B5C(const Rva00318B5C &other);
	virtual ~Rva00318B5C();

	Int m_field04;
	Int m_field08;
	Int m_field0C;
};

Rva00318B5C::Rva00318B5C(const Rva00318B5C &other)
{
	m_field04 = other.m_field04;
	m_field08 = other.m_field08;
	m_field0C = other.m_field0C;
}

// -------------------- vptr + one int + two bytes (retail 0x003ADE98)
// B2 body-address name: +0x08 and +0x09 are byte members (8A51/8850 and
// 8A49/8848). Retail caller 0x003ADE78 installs adjacent-vtable parts
// after the call so this is the subobject copy.
class Rva003ADE98
{
public:
	Rva003ADE98(const Rva003ADE98 &other);
	virtual ~Rva003ADE98();

	Int m_field04;
	char m_field08;
	char m_field09;
};

Rva003ADE98::Rva003ADE98(const Rva003ADE98 &other)
{
	m_field04 = other.m_field04;
	m_field08 = other.m_field08;
	m_field09 = other.m_field09;
}

// ------------------------------------------ vptr + ten ints (retail 0x003ADF61)
// B2 body-address name: straight ten-dword run +0x04..+0x28. Four retail
// E8 callers all sit in 0x003AE1xx copy tails.
class Rva003ADF61
{
public:
	Rva003ADF61(const Rva003ADF61 &other);
	virtual ~Rva003ADF61();

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
};

Rva003ADF61::Rva003ADF61(const Rva003ADF61 &other)
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
}

// ------------------------------------------ vptr + ten ints (retail 0x004F5FD8)
// B2 body-address name: same ten-dword run as 0x003ADF61 with a different
// vtable so a different class. Two retail E8 callers.
class Rva004F5FD8
{
public:
	Rva004F5FD8(const Rva004F5FD8 &other);
	virtual ~Rva004F5FD8();

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
};

Rva004F5FD8::Rva004F5FD8(const Rva004F5FD8 &other)
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
}

// ------------------------------------------- vptr + six ints (retail 0x0020E449)
// B2 body-address name: straight six-dword run +0x04..+0x18. Two retail E8
// callers at 0x0020F399 and 0x004FF2B4.
class Rva0020E449
{
public:
	Rva0020E449(const Rva0020E449 &other);
	virtual ~Rva0020E449();

	Int m_field04;
	Int m_field08;
	Int m_field0C;
	Int m_field10;
	Int m_field14;
	Int m_field18;
};

Rva0020E449::Rva0020E449(const Rva0020E449 &other)
{
	m_field04 = other.m_field04;
	m_field08 = other.m_field08;
	m_field0C = other.m_field0C;
	m_field10 = other.m_field10;
	m_field14 = other.m_field14;
	m_field18 = other.m_field18;
}

// ------------------------- vptr + three words (retail 0x004EE1A9)
// B2 body-address name: three word members at +0x04/+0x06/+0x08 with
// 66-prefixed loads and stores. Five retail E8 callers.
class Rva004EE1A9
{
public:
	Rva004EE1A9(const Rva004EE1A9 &other);
	virtual ~Rva004EE1A9();

	Short m_field04;
	Short m_field06;
	Short m_field08;
};

Rva004EE1A9::Rva004EE1A9(const Rva004EE1A9 &other)
{
	m_field04 = other.m_field04;
	m_field06 = other.m_field06;
	m_field08 = other.m_field08;
}
