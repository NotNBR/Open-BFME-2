// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva0044D56A::~
// Rva0044D56A at 0x0044D56A (pinned opaque SEH base dtor: vptr 0xC3EF60,
// AsciiString member at +0x18, base 0x3B1F65; identity unproven). Each class
// below stores its own vtable (DIR32 auto-patches) and tail-calls the base
// destructor; the base itself is only declared here (defined nowhere -- it
// resolves via the pin), because a same-TU definition would capture the call
// locally instead of at the ledger address. Owner identities are unproven
// (opaque Rva names). One ledger row per destructor, landed one commit at a
// time.

class Rva0044D56A
{
public:
	virtual ~Rva0044D56A();
};

class Rva0044D285 : public Rva0044D56A
{
public:
	virtual ~Rva0044D285();
};

Rva0044D285::~Rva0044D285()
{
}

class Rva0054F508 : public Rva0044D56A
{
public:
	virtual ~Rva0054F508();
};

Rva0054F508::~Rva0054F508()
{
}
