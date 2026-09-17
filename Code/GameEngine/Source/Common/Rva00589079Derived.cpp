// cl: /O1 /MD
//
// Opaque five-vptr MI destructor tail-calling the pinned 0x24A797 base.
// Retail 0x00589079 (39B) stores four vptrs plus the const 0xC70108 at +0x24,
// then tail-jumps to the 0x24A797 middle. Same model as the landed Rva00494A97
// body (which tail-calls this one); the fifth slot carries a const, not a
// zero. Identity unproven (opaque Rva name); the shape (vptr stores plus a
// tail-jump into a rowed/pinned MI dtor) is the dtor evidence.

class Rva0024A797
{
public:
	virtual ~Rva0024A797();

private:
	char m_pad04[8];
};

class Rva00589079_S1
{
public:
	virtual void f1();
};

class Rva00589079_S2
{
public:
	virtual void f2();

private:
	char m_pad04[12];
};

class Rva00589079_S3
{
public:
	virtual void f3();
};

class Rva00589079_S4
{
public:
	virtual void f4();
};

class Rva00589079 : public Rva0024A797, public Rva00589079_S1, public Rva00589079_S2, public Rva00589079_S3, public Rva00589079_S4
{
public:
	virtual ~Rva00589079()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00589079_Anchor(Rva00589079 *p)
{
	p->Rva00589079::~Rva00589079();
}

class Rva00481F82_S1
{
public:
	virtual void f1();
};

class Rva00481F82_S2
{
public:
	virtual void f2();

private:
	char m_pad04[12];
};

class Rva00481F82_S3
{
public:
	virtual void f3();
};

class Rva00481F82_S4
{
public:
	virtual void f4();
};

class Rva00481F82 : public Rva0024A797, public Rva00481F82_S1, public Rva00481F82_S2, public Rva00481F82_S3, public Rva00481F82_S4
{
public:
	virtual ~Rva00481F82()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00481F82_Anchor(Rva00481F82 *p)
{
	p->Rva00481F82::~Rva00481F82();
}

class Rva00482E96_S1
{
public:
	virtual void f1();
};

class Rva00482E96_S2
{
public:
	virtual void f2();

private:
	char m_pad04[12];
};

class Rva00482E96_S3
{
public:
	virtual void f3();

private:
	char m_pad18[4];
};

class Rva00482E96_S4
{
public:
	virtual void f4();
};

class Rva00482E96 : public Rva0024A797, public Rva00482E96_S1, public Rva00482E96_S2, public Rva00482E96_S3, public Rva00482E96_S4
{
public:
	virtual ~Rva00482E96()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00482E96_Anchor(Rva00482E96 *p)
{
	p->Rva00482E96::~Rva00482E96();
}
