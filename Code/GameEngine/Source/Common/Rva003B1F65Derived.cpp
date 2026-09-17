// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva003B1F65::~
// Rva003B1F65 at 0x003B1F65 (pinned opaque SEH base dtor; identity
// unproven). Each class below stores its own vtable and tail-calls the base
// destructor; the base itself is only declared here (defined nowhere -- it
// resolves via the pin), because a same-TU definition would capture the call
// locally instead of at the ledger address. Owner identities are unproven
// (opaque Rva names). One ledger row per destructor, landed one commit at
// a time.

class Rva003B1F65
{
public:
	virtual ~Rva003B1F65();
};

class Rva002E4272 : public Rva003B1F65
{
public:
	virtual ~Rva002E4272();
};

Rva002E4272::~Rva002E4272()
{
}

class Rva003B1FD4 : public Rva003B1F65
{
public:
	virtual ~Rva003B1FD4();
};

Rva003B1FD4::~Rva003B1FD4()
{
}

class Rva00535776 : public Rva003B1F65
{
public:
	virtual ~Rva00535776();
};

Rva00535776::~Rva00535776()
{
}

class Rva005596EA : public Rva003B1F65
{
public:
	virtual ~Rva005596EA();
};

Rva005596EA::~Rva005596EA()
{
}

class Rva005DF17C : public Rva003B1F65
{
public:
	virtual ~Rva005DF17C();
};

Rva005DF17C::~Rva005DF17C()
{
}
