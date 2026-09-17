// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling SEH bases pinned
// elsewhere. Each class below stores its own vtable and tail-calls its base
// destructor; every base is only declared here (defined nowhere -- it
// resolves via its pin), because a same-TU definition would capture the call
// locally instead of at the ledger address. Vtable values are DIR32
// auto-patches. Owner identities are unproven (opaque Rva names). One ledger
// row per destructor, landed one commit at a time.

class Rva0098477
{
public:
	virtual ~Rva0098477();
};

class Rva00984EF : public Rva0098477
{
public:
	virtual ~Rva00984EF();
};

Rva00984EF::~Rva00984EF()
{
}
