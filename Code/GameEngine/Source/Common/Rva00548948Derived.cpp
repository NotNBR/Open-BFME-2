// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva00548948::~
// Rva00548948 at 0x00548948 (pinned opaque base dtor; identity unproven).
// Each class below stores its own vtable and tail-calls the base destructor;
// the base itself is only declared here (defined nowhere -- it resolves via
// the pin), because a same-TU definition would capture the call locally
// instead of at the ledger address. Owner identities are unproven (opaque
// Rva names). One ledger row per destructor, landed one commit at a time.

class Rva00548948
{
public:
	virtual ~Rva00548948();
};

class Rva00546B29 : public Rva00548948
{
public:
	virtual ~Rva00546B29();
};

Rva00546B29::~Rva00546B29()
{
}
