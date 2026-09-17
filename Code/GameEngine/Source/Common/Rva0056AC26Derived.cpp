// cl: /O1 /MD
//
// Opaque multiple-inheritance destructors tail-calling Rva0056AC26::~
// Rva0056AC26 at 0x0056AC26 (pinned opaque MI base dtor: SEH, vptrs at
// +0x00/+0x08; identity unproven). Each class below derives (in order) from
// the opaque base and its own empty polymorphic base, giving vptrs at
// +0x00/+0x08; the empty base has an implicit trivial destructor, so the
// derived destructor stores both vptrs and tail-calls the base destructor.
// Owner identities are unproven (opaque Rva names). One ledger row per
// destructor, landed one commit at a time.

class Rva0056AC26
{
public:
	virtual ~Rva0056AC26();

private:
	char m_pad04[4];
};

class Rva0056AC82_B1
{
public:
	virtual void f1();
};

class Rva0056AC82 : public Rva0056AC26, public Rva0056AC82_B1
{
public:
	virtual ~Rva0056AC82();
};

Rva0056AC82::~Rva0056AC82()
{
}

class Rva0056ACC5_B1
{
public:
	virtual void f1();
};

class Rva0056ACC5 : public Rva0056AC26, public Rva0056ACC5_B1
{
public:
	virtual ~Rva0056ACC5();
};

Rva0056ACC5::~Rva0056ACC5()
{
}

class Rva0056ACDF_B1
{
public:
	virtual void f1();
};

class Rva0056ACDF : public Rva0056AC26, public Rva0056ACDF_B1
{
public:
	virtual ~Rva0056ACDF();
};

Rva0056ACDF::~Rva0056ACDF()
{
}

class Rva0056ACFF_B1
{
public:
	virtual void f1();
};

class Rva0056ACFF : public Rva0056AC26, public Rva0056ACFF_B1
{
public:
	virtual ~Rva0056ACFF();
};

Rva0056ACFF::~Rva0056ACFF()
{
}

class Rva0056AE4A_B1
{
public:
	virtual void f1();
};

class Rva0056AE4A : public Rva0056AC26, public Rva0056AE4A_B1
{
public:
	virtual ~Rva0056AE4A();
};

Rva0056AE4A::~Rva0056AE4A()
{
}
