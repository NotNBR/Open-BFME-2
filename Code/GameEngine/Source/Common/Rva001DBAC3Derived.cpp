// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva001DBAC3::~
// Rva001DBAC3 at 0x001DBAC3 (pinned opaque leaf base dtor: vtable store
// plus ret; identity unproven). Each class below stores its own vtable
// (DIR32 auto-patches) and tail-calls the base destructor; the base itself
// is only declared here (defined nowhere -- it resolves via the pin),
// because a same-TU definition would capture the call locally instead of at
// the ledger address. Owner identities are unproven (opaque Rva names). One
// ledger row per destructor, landed one commit at a time.

class Rva001DBAC3
{
public:
	virtual ~Rva001DBAC3();
};

class Rva0035D0D1 : public Rva001DBAC3
{
public:
	virtual ~Rva0035D0D1();
};

Rva0035D0D1::~Rva0035D0D1()
{
}

class Rva0035D352 : public Rva001DBAC3
{
public:
	virtual ~Rva0035D352();
};

Rva0035D352::~Rva0035D352()
{
}
