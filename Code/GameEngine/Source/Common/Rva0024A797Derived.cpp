// cl: /O1 /MD
//
// Opaque multiple-inheritance destructors tail-calling Rva0024A797::~
// Rva0024A797 at 0x0024A797 (pinned opaque MI base: three vptrs tail-jumping
// the 0x49B47C fold; identity unproven). Each class below derives (in order)
// from the opaque base, a shared empty polymorphic base, and its own empty
// polymorphic base, giving vptrs at +0x00/+0x0C/+0x10; the empty bases have
// implicit trivial destructors, so the derived destructor stores all three
// vptrs and tail-calls the base destructor. The +0x0C secondary is shared
// across the family (0xBEFF90). Owner identities are unproven (opaque Rva
// names). One ledger row per destructor, landed one commit at a time.

class Rva0024A797
{
public:
	virtual ~Rva0024A797();

private:
	char m_pad04[8];
};

class MiBase1
{
public:
	virtual void f1();
};

class Rva00253E19_B2
{
public:
	virtual void f2();
};

class Rva00253E19 : public Rva0024A797, public MiBase1, public Rva00253E19_B2
{
public:
	virtual ~Rva00253E19();
};

Rva00253E19::~Rva00253E19()
{
}

class Rva00253EF5_B2
{
public:
	virtual void f2();
};

class Rva00253EF5 : public Rva0024A797, public MiBase1, public Rva00253EF5_B2
{
public:
	virtual ~Rva00253EF5();
};

Rva00253EF5::~Rva00253EF5()
{
}

class Rva0033EEC9_B2
{
public:
	virtual void f2();
};

class Rva0033EEC9 : public Rva0024A797, public MiBase1, public Rva0033EEC9_B2
{
public:
	virtual ~Rva0033EEC9();
};

Rva0033EEC9::~Rva0033EEC9()
{
}

class Rva00373CB1_B2
{
public:
	virtual void f2();
};

class Rva00373CB1 : public Rva0024A797, public MiBase1, public Rva00373CB1_B2
{
public:
	virtual ~Rva00373CB1();
};

Rva00373CB1::~Rva00373CB1()
{
}

class Rva003A4322_B2
{
public:
	virtual void f2();
};

class Rva003A4322 : public Rva0024A797, public MiBase1, public Rva003A4322_B2
{
public:
	virtual ~Rva003A4322();
};

Rva003A4322::~Rva003A4322()
{
}
