// cl: /O1 /MD
//
// Opaque multiple-inheritance destructors tail-calling DieModule::~DieModule
// at 0x0045CE54. Each class below derives (in order) from DieModule, a shared
// empty polymorphic base, and its own empty polymorphic base, giving vptrs at
// +0x00/+0x0C/+0x10; the empty bases have implicit trivial destructors (no
// code, no calls), so the derived destructor stores all three vptrs and
// tail-calls the DieModule destructor. The +0x0C secondary is shared across
// the family (none of them override the shared base), the other two are
// per-class. Owner identities are unproven (opaque Rva names). One ledger row
// per destructor, landed one commit at a time.

class DieModule
{
protected:
	virtual ~DieModule();

private:
	char m_pad04[8];
};

class MiBase1
{
public:
	virtual void f1();
};

class Rva0045CE6D_B2
{
public:
	virtual void f2();
};

class Rva0045CE6D : public DieModule, public MiBase1, public Rva0045CE6D_B2
{
public:
	virtual ~Rva0045CE6D();
};

Rva0045CE6D::~Rva0045CE6D()
{
}

class Rva004851FE_B2
{
public:
	virtual void f2();
};

class Rva004851FE : public DieModule, public MiBase1, public Rva004851FE_B2
{
public:
	virtual ~Rva004851FE();
};

Rva004851FE::~Rva004851FE()
{
}

class Rva00485425_B2
{
public:
	virtual void f2();
};

class Rva00485425 : public DieModule, public MiBase1, public Rva00485425_B2
{
public:
	virtual ~Rva00485425();
};

Rva00485425::~Rva00485425()
{
}
