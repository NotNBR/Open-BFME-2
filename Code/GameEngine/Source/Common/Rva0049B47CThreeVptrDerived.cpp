// cl: /O1 /MD /GX
//
// Opaque three-vptr destructors tail-calling Rva0049B47C::~Rva0049B47C at
// 0x0049B47C (pinned opaque fold-point dtor; identity unproven). Unlike the
// sibling single-inheritance TU, these bodies store a tertiary vptr at +0x10
// and retail orders that store FIRST (+0x10, +0, +0xC); the opaque model
// below emits (+0, +0xC, +0x10), so the dtors stay unclaimed (see the 0.8
// partial bank). The scalar deleting destructor needs no vptr stores and is
// claimed from the emitted COMDAT. Owner identities are unproven (opaque Rva
// names). One ledger row per destructor, landed one commit at a time.

class Rva0049B47C
{
public:
	virtual ~Rva0049B47C();

private:
	char m_pad04[8];
};

class MiBase1
{
public:
	virtual void f1();
};

class Rva00484EF4_B2
{
public:
	virtual void f2();
};

class Rva00484EF4 : public Rva0049B47C, public MiBase1, public Rva00484EF4_B2
{
public:
	virtual ~Rva00484EF4()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT.
void Rva00484EF4_Anchor(Rva00484EF4 *p)
{
	p->Rva00484EF4::~Rva00484EF4();
}

class Rva004BD763_B2
{
public:
	virtual void f2();
};

class Rva004BD763 : public Rva0049B47C, public MiBase1, public Rva004BD763_B2
{
public:
	virtual ~Rva004BD763()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT.
void Rva004BD763_Anchor(Rva004BD763 *p)
{
	p->Rva004BD763::~Rva004BD763();
}
