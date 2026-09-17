// cl: /O1 /MD
//
// Opaque single-inheritance destructor tail-calling Rva00578C0E::~
// Rva00578C0E at 0x00578C0E (row in FreeMemberDeleters.cpp: null-checked
// free of its member at +0x04). The class below stores its own vtable
// (0xC6EAC0, DIR32 auto-patch) and tail-calls the base destructor; the base itself is only declared here (defined once in
// FreeMemberDeleters.cpp), because a same-TU definition would capture the
// call locally instead of at the ledger address. Owner identity is unproven
// (opaque Rva name). One ledger row per destructor, landed one commit at a
// time.

class Rva00578C0E
{
public:
	virtual ~Rva00578C0E();

private:
	void *m_ptr04;
};

class Rva00578C23 : public Rva00578C0E
{
public:
	virtual ~Rva00578C23();
};

Rva00578C23::~Rva00578C23()
{
}
