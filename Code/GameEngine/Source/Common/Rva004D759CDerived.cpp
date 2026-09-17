// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva004D759C::~
// Rva004D759C at 0x004D759C (pinned opaque MI base dtor: SEH, vptrs, list
// walk; identity unproven). Each class below stores its own vtable and
// tail-calls the base destructor; the base itself is only declared here
// (defined nowhere -- it resolves via the pin), because a same-TU definition
// would capture the call locally instead of at the ledger address. Owner
// identities are unproven (opaque Rva names). One ledger row per destructor,
// landed one commit at a time.

class Rva004D759C
{
public:
	virtual ~Rva004D759C();
};

class Rva0033FAE9 : public Rva004D759C
{
public:
	virtual ~Rva0033FAE9();
};

Rva0033FAE9::~Rva0033FAE9()
{
}
