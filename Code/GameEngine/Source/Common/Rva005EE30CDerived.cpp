// cl: /O1 /MD
//
// Opaque destructors deriving from Rva005EE30C (whose row at 0x005EE30C
// resolves the tail calls). Each class below stores its own vtable and
// tail-calls the base destructor; the base itself is only declared here and
// defined once in Rva005EE30CChain.cpp, because a same-TU definition would
// capture the call locally instead of at the ledger address. Owner
// identities are unproven (opaque Rva names). One ledger row per destructor,
// landed one commit at a time.

class Rva005EE30C
{
public:
	virtual ~Rva005EE30C();
};

class Rva005D736E : public Rva005EE30C
{
public:
	virtual ~Rva005D736E();
};

Rva005D736E::~Rva005D736E()
{
}

class Rva005D7706 : public Rva005EE30C
{
public:
	virtual ~Rva005D7706();
};

Rva005D7706::~Rva005D7706()
{
}

class Rva005D7855 : public Rva005EE30C
{
public:
	virtual ~Rva005D7855();
};

Rva005D7855::~Rva005D7855()
{
}

class Rva005D7A1B : public Rva005EE30C
{
public:
	virtual ~Rva005D7A1B();
};

Rva005D7A1B::~Rva005D7A1B()
{
}

class Rva005D7AC5 : public Rva005EE30C
{
public:
	virtual ~Rva005D7AC5();
};

Rva005D7AC5::~Rva005D7AC5()
{
}
