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

class Rva004B96CC_B2
{
public:
	virtual void f2();
};

class Rva004B96CC : public Rva0049B47C, public MiBase1, public Rva004B96CC_B2
{
public:
	virtual ~Rva004B96CC()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT.
void Rva004B96CC_Anchor(Rva004B96CC *p)
{
	p->Rva004B96CC::~Rva004B96CC();
}

class Rva004BB68E_B2
{
public:
	virtual void f2();
};

class Rva004BB68E : public Rva0049B47C, public MiBase1, public Rva004BB68E_B2
{
public:
	virtual ~Rva004BB68E()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT.
void Rva004BB68E_Anchor(Rva004BB68E *p)
{
	p->Rva004BB68E::~Rva004BB68E();
}

class Rva00462151_B2
{
public:
	virtual void f2();
};

class Rva00462151 : public Rva0049B47C, public MiBase1, public Rva00462151_B2
{
public:
	virtual ~Rva00462151()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT.
void Rva00462151_Anchor(Rva00462151 *p)
{
	p->Rva00462151::~Rva00462151();
}

class Rva00484F5D : public Rva00484EF4
{
public:
	virtual ~Rva00484F5D();
};

Rva00484F5D::~Rva00484F5D()
{
}
