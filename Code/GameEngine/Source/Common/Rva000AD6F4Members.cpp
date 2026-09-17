// cl: /O1 /MD
//
// Opaque destructors that call Rva000AD6F4::clear at 0x000AD6F4 (pinned
// opaque guarded-delete helper: nulls its pointer at +0 then ::deletes it;
// exact method unproven) on a member at +0x04. Each class below stores its
// own vtable, adjusts this to the member, and tail-calls the helper; the
// helper type is only declared here (defined nowhere -- it resolves via the
// pin). Owner identities are unproven (opaque Rva names). One ledger row per
// destructor, landed one commit at a time.

class Rva000AD6F4
{
public:
	void clear();

private:
	char m_pad[8];
};

class Rva00328A75
{
public:
	virtual ~Rva00328A75();

private:
	Rva000AD6F4 m_member04;
};

Rva00328A75::~Rva00328A75()
{
	m_member04.clear();
}

class Rva00577936
{
public:
	virtual ~Rva00577936();

private:
	Rva000AD6F4 m_member04;
};

Rva00577936::~Rva00577936()
{
	m_member04.clear();
}

class Rva005F83DF
{
public:
	virtual ~Rva005F83DF();

private:
	Rva000AD6F4 m_member04;
};

Rva005F83DF::~Rva005F83DF()
{
	m_member04.clear();
}
