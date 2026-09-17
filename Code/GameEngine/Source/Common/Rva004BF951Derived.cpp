// cl: /O1 /MD
//
// Opaque multiple-inheritance destructors tail-calling Rva004BF951::~
// Rva004BF951 at 0x004BF951 (pinned opaque MI base dtor: SEH; identity
// unproven). Each class below derives (in order) from the opaque base, a
// shared empty polymorphic base, and its own empty polymorphic base, giving
// vptrs at +0x00/+0x0C/+0x10; the empty bases have implicit trivial
// destructors, so the derived destructor stores all three vptrs and
// tail-calls the base destructor. The +0x0C secondary is shared across most
// of the family (0xC5AD78; one body uses 0xC5B770, patched per row).
// Owner identities are unproven (opaque Rva names). One ledger row per
// destructor, landed one commit at a time.

class Rva004BF951
{
public:
	virtual ~Rva004BF951();

private:
	char m_pad04[8];
};

class MiBase1
{
public:
	virtual void f1();
};

class Rva004C07B1_B2
{
public:
	virtual void f2();
};

class Rva004C07B1 : public Rva004BF951, public MiBase1, public Rva004C07B1_B2
{
public:
	virtual ~Rva004C07B1();
};

Rva004C07B1::~Rva004C07B1()
{
}

class Rva004C089E_B2
{
public:
	virtual void f2();
};

class Rva004C089E : public Rva004BF951, public MiBase1, public Rva004C089E_B2
{
public:
	virtual ~Rva004C089E();
};

Rva004C089E::~Rva004C089E()
{
}

class Rva004C0988_B2
{
public:
	virtual void f2();
};

class Rva004C0988 : public Rva004BF951, public MiBase1, public Rva004C0988_B2
{
public:
	virtual ~Rva004C0988();
};

Rva004C0988::~Rva004C0988()
{
}

class Rva004C0A4C_B2
{
public:
	virtual void f2();
};

class Rva004C0A4C : public Rva004BF951, public MiBase1, public Rva004C0A4C_B2
{
public:
	virtual ~Rva004C0A4C();
};

Rva004C0A4C::~Rva004C0A4C()
{
}

class Rva004C131B_B2
{
public:
	virtual void f2();
};

class Rva004C131B : public Rva004BF951, public MiBase1, public Rva004C131B_B2
{
public:
	virtual ~Rva004C131B();
};

Rva004C131B::~Rva004C131B()
{
}
