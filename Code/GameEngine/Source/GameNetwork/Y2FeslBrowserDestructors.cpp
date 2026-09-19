// cl: /EHs-c-
// EA FESL client SDK ("jabba") -- the 00802380 gamebrowser owner destructor.
// Trimmed from the Open-BFME-1 Y2FeslBrowserDestructors donor: this TU carries
// only the 00802380 section. The other three sections (00802EC0, 00802CA0,
// 00802680) stay in the donor until their BFME2 addresses are served.
//
// WHY THIS FILE CARRIES ITS OWN FLAG.  The base command line spells `-EHsc-`,
// which cl parses as EHs ON: every destructor here then gets an EH frame
// (`push -1 / push <handler> / mov eax,fs:[0]`) that retail's bodies do not
// have.  /EHs-c- turns both halves off and is what the bytes force.
//
// WHAT THE BYTES SHOW.  The row opens by storing one address over [this] and
// closes by storing a DIFFERENT address over the same slot.  Two vptr writes in
// one body is a derived destructor with its base's destructor inlined: the
// derived vptr is installed on entry, the body runs, and the base destructor
// then reinstalls the base vptr.  So the class has a virtual destructor and a
// base with an EMPTY inline one -- and because the base destructor's own body
// is empty, nothing survives of it but that store.
//
// The member call between the two stores is NOT a destructor call: it enters
// the body the ledger already names `clear` (0x0066CA50), so it is an ordinary
// member call written in the destructor body.
//
// 0x0066E750 is the `??_G` scalar-deleting wrapper MSVC emits beside the
// virtual destructor: same body, then `test byte ptr [esp+8],1` and a
// one-argument global release that the tree already names ??3@YAXPAX@Z.  It is
// claimed here because writing the destructor is what produces it; nothing
// about it is written by hand.
//
// IDENTITY IS NOT RECOVERED.  Every class and member name is derived from an
// address.  The vtable addresses are DIR32 the patcher fills; they are used
// here only as the evidence for "two classes", not as names.

// The base class exists only to produce the SECOND vptr store; its destructor
// is empty and inline, so retail has no separate body for it and none for the
// deleting wrapper MSVC emits beside it.  The labels below are copied out of
// this file's own object symbol table, not written by hand.
//
// ??1Rva00802380Base@@UAE@XZ absent-from-retail
// ??_GRva00802380Base@@UAEPAXI@Z absent-from-retail

// ---------------------------------------------------------------- callees
class Rva00800630Owner
{
public:
	void clear();                       // 0x0066CA50

	void *m_block;
	int   m_field4;
	int   m_field8;
};

// ------------------------ 0x00802380 + its wrapper 0x00802510, one embedded
//                          three-field owner and two trailing dwords
class Rva00802380Base
{
public:
	virtual ~Rva00802380Base() {}

	int m_field4;
	int m_field8;
};

class Rva00802380Owner : public Rva00802380Base
{
public:
	virtual ~Rva00802380Owner();

	char              m_pad00C[ 0x0C ];
	Rva00800630Owner  m_owner;      // +0x18
	int               m_field24;
	int               m_field28;
};

Rva00802380Owner::~Rva00802380Owner()
{
	m_field4 = 0;
	m_field24 = 0;
	m_field28 = 0;
	m_owner.clear();
}
