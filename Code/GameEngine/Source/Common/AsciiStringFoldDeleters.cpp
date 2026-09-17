// cl: /O1 /MD
//
// Opaque single-member destructors that tail-call the folded AsciiString
// member destructor at 0x0036410, the same shape as Bucket::~Bucket (vtable
// store, this-adjust, tail jump). Each class below is a distinct retail
// vtable whose owner identity is unproven; the member offset is retail
// measured per body. One ledger row per destructor, landed one commit at
// a time; the AsciiStringMember declaration is shared and never defined
// (it resolves to the 0x36410 fold via symbols.csv).

class AsciiStringMember
{
public:
	~AsciiStringMember();
};

class Rva00217537
{
public:
	virtual ~Rva00217537();

private:
	char m_pad04[4];
	AsciiStringMember m_member08;
};

Rva00217537::~Rva00217537()
{
}
