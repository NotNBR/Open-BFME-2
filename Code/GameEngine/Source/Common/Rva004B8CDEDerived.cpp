// cl: /O1 /MD
//
// Opaque multiple-inheritance destructors tail-calling Rva004B8CDE::~
// Rva004B8CDE at 0x004B8CDE (pinned opaque MI base: three vptrs tail-jumping
// the 0x49B47C fold; identity unproven). Each class below derives (in order)
// from the opaque base, a shared empty polymorphic base, and its own empty
// polymorphic base, giving vptrs at +0x00/+0x0C/+0x10; the empty bases have
// implicit trivial destructors, so the derived destructor stores all three
// vptrs and tail-calls the base destructor. The +0x0C secondary is shared
// across the family (0xBEF9C0). Owner identities are unproven (opaque Rva
// names). One ledger row per destructor, landed one commit at a time.

class Rva004B8CDE
{
public:
	virtual ~Rva004B8CDE();

private:
	char m_pad04[8];
};

class MiBase1
{
public:
	virtual void f1();
};

class Rva004B8C3E_B2
{
public:
	virtual void f2();
};

class Rva004B8C3E : public Rva004B8CDE, public MiBase1, public Rva004B8C3E_B2
{
public:
	virtual ~Rva004B8C3E();
};

Rva004B8C3E::~Rva004B8C3E()
{
}

class Rva004B8DB1_B2
{
public:
	virtual void f2();
};

class Rva004B8DB1 : public Rva004B8CDE, public MiBase1, public Rva004B8DB1_B2
{
public:
	virtual ~Rva004B8DB1();
};

Rva004B8DB1::~Rva004B8DB1()
{
}
