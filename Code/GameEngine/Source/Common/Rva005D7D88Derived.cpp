// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva005D7D88::~
// Rva005D7D88 at 0x005D7D88 (row in Rva004D759CDerived.cpp). Each class below
// stores its own vtable and tail-calls the base destructor; the base itself
// is only declared here (defined once in Rva004D759CDerived.cpp), because a
// same-TU definition would capture the call locally instead of at the ledger
// address. Owner identities are unproven (opaque Rva names). One ledger row
// per destructor, landed one commit at a time.

class Rva005D7D88
{
public:
	virtual ~Rva005D7D88();
};

class Rva005D7531 : public Rva005D7D88
{
public:
	virtual ~Rva005D7531();
};

Rva005D7531::~Rva005D7531()
{
}
