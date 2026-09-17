// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva0049B47C::~
// Rva0049B47C at 0x0049B47C (pinned opaque fold-point dtor: 25 destructors
// fold there including FX infos, Snapshot and ObjectModule; identity
// unproven). Each class below stores its own vtable and tail-calls the base
// destructor; the base itself is only declared here (defined nowhere -- it
// resolves via the pin), because a same-TU definition would capture the call
// locally instead of at the ledger address. Owner identities are unproven
// (opaque Rva names). One ledger row per destructor, landed one commit at
// a time.

class Rva0049B47C
{
public:
	virtual ~Rva0049B47C();
};

class Rva000CEB6F : public Rva0049B47C
{
public:
	virtual ~Rva000CEB6F();
};

Rva000CEB6F::~Rva000CEB6F()
{
}

class Rva00254C4B : public Rva0049B47C
{
public:
	virtual ~Rva00254C4B();
};

Rva00254C4B::~Rva00254C4B()
{
}
