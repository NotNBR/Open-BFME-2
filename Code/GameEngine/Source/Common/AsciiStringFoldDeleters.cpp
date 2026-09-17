// cl: /O1 /MD
//
// Opaque single-member destructors that tail-call the folded AsciiString
// member destructor at 0x0036410, the same shape as Bucket::~Bucket (vtable
// store, this-adjust, tail jump). Each class below is a distinct retail
// vtable whose owner identity is unproven; the member offset is retail
// measured per body. One ledger row per destructor, landed one commit at
// a time; the AsciiStringMember declaration is shared and never defined
// (it resolves to the 0x36410 fold via symbols.csv).

class AsciiStringMember
{
public:
	~AsciiStringMember();
};

class Rva00217537
{
public:
	virtual ~Rva00217537();

private:
	char m_pad04[4];
	AsciiStringMember m_member08;
};

Rva00217537::~Rva00217537()
{
}

class Rva0030714F
{
public:
	virtual ~Rva0030714F();

private:
	char m_pad04[4];
	AsciiStringMember m_member08;
};

Rva0030714F::~Rva0030714F()
{
}

class Rva004E156B
{
public:
	virtual ~Rva004E156B();

private:
	AsciiStringMember m_member04;
};

Rva004E156B::~Rva004E156B()
{
}

class Rva004E194E
{
public:
	virtual ~Rva004E194E();

private:
	char m_pad04[8];
	AsciiStringMember m_member0C;
};

Rva004E194E::~Rva004E194E()
{
}

class Rva004FA830
{
public:
	virtual ~Rva004FA830();

private:
	AsciiStringMember m_member04;
};

Rva004FA830::~Rva004FA830()
{
}
