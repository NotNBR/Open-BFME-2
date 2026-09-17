// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva0025BFE3::~
// Rva0025BFE3 at 0x0025BFE3 (row in FreeMemberDeleters.cpp: null-checked
// free of its member at +0x04). Each class below stores its own vtable and
// tail-calls the base destructor; the base itself is only declared here
// (defined once in FreeMemberDeleters.cpp), because a same-TU definition
// would capture the call locally instead of at the ledger address. Owner
// identities are unproven (opaque Rva names). One ledger row per destructor,
// landed one commit at a time.

class Rva0025BFE3
{
public:
	virtual ~Rva0025BFE3();

private:
	void *m_ptr04;
};

class Rva00596069 : public Rva0025BFE3
{
public:
	virtual ~Rva00596069();
};

Rva00596069::~Rva00596069()
{
}
