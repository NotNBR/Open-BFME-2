// cl: /O1 /MD
//
// Opaque destructor tail-calling Rva002D22CA::~Rva002D22CA at 0x002D22CA
// (matched opaque derived dtor in GameEngineDeletingBaseDerived.cpp, itself
// tail-calling GameEngineDeletingBase; only declared here so the tail-call
// resolves to the ledger address instead of a same-TU definition). The
// class below stores its own vtable (0xBC4C20, DIR32 auto-patch) and
// tail-jumps to the base destructor. Owner identity is unproven (opaque
// Rva name). One ledger row per destructor, landed one commit at a time.

class Rva002D22CA
{
public:
	virtual ~Rva002D22CA();
};

class Rva0004CA4C : public Rva002D22CA
{
public:
	virtual ~Rva0004CA4C();
};

Rva0004CA4C::~Rva0004CA4C()
{
}
