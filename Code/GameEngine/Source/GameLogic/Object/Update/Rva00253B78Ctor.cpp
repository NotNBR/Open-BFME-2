// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0Rva00253B78@@QAE@XZ at retail 0x00253B78 (29B). Opaque 0x40-byte
// ObjectModule-family default ctor over the unidentified SEH intermediate
// base 0x00253510 (pinned opaque as Rva00253510): base call, vtable
// 0x00C4ED70 (slot0 is ??_GObjectModule, slot1 the ret-stub -- the
// ObjectModule vtable family), int member +0x38 = 0x19, byte member
// +0x3C = 0. Factory stub 0x00253BB7 builds size 0x40, matching
// sizeof(Rva00253B78) = 0x38 + 4 + 1 (+pad). The sibling body 0x00253A78
// shares base, vtable and size but stores (and-zero, byte 1) -- a different
// class under the folded vtable, or a different overload; not claimed here.
// The Zero Hour lead (DockUpdateModuleData, 0/TRUE) is REFUTED by the retail
// consts (0x19/0), so the name stays address-derived per the no-guess rule.
class Thing;
class ModuleData;

// Opaque 0x38-byte intermediate; default ctor resolves to the opaque pin at
// 0x00253510. Do NOT declare an explicit vptr member: the hidden one is +0.
class Rva00253510
{
public:
	Rva00253510();
	virtual ~Rva00253510();

protected:
	unsigned char m_pad[0x38 - 4];
};

// ??1Rva00253510@@UAE@XZ present-unmatched
Rva00253510::~Rva00253510()
{
}

class Rva00253B78 : public Rva00253510
{
public:
	Rva00253B78();
	virtual ~Rva00253B78();

protected:
	int m_count;
	unsigned char m_flag;
};

Rva00253B78::Rva00253B78()
	: Rva00253510()
{
	m_count = 0x19;
	m_flag = 0;
}

// ??1Rva00253B78@@UAE@XZ present-unmatched
Rva00253B78::~Rva00253B78()
{
}
