// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva005EE2A0::~
// Rva005EE2A0 at 0x005EE2A0 (row in Rva005EE30CChain.cpp). Each class below
// stores its own vtable and tail-calls the base destructor; the base itself
// is only declared here (defined once in Rva005EE30CChain.cpp), because a
// same-TU definition would capture the call locally instead of at the ledger
// address. Owner identities are unproven (opaque Rva names). One ledger row
// per destructor, landed one commit at a time.

class Rva005EE2A0
{
public:
	virtual ~Rva005EE2A0();
};

class Rva005D719C : public Rva005EE2A0
{
public:
	virtual ~Rva005D719C();
};

Rva005D719C::~Rva005D719C()
{
}

class Rva005D724B : public Rva005EE2A0
{
public:
	virtual ~Rva005D724B();
};

Rva005D724B::~Rva005D724B()
{
}

class Rva005D72FA : public Rva005EE2A0
{
public:
	virtual ~Rva005D72FA();
};

Rva005D72FA::~Rva005D72FA()
{
}
