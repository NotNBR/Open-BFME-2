// cl: /O1 /Ob2 /DNDEBUG /MD /EHsc
// ??1TransportContainModuleData@@UAE@XZ @0x1DFA48 (60B): virtual destructor.
// Installs vtable 0x7DC940 then destroys the two pool-aware members at +0xC
// and +0x8 (reverse order) through the 13B forwarder at 0x360D26. Identity is
// triple-proven: reloc name, vtable install, and the ??_G scalar-deleting
// destructor at 0x1DFA87 tail-calling here. The member type is unrecovered
// (not a string: strings route to releaseBuffer, this forwards to a pool op),
// so it keeps an address-derived name with an opaque pin; the dtor row itself
// spends the real identity. No base call is emitted (trivial base).

// The pool-aware member at +0x8/+0xC; only its address and non-virtual dtor
// are proven. It occupies four bytes (the two call sites are four apart).
class Rva00360D26Member
{
public:
	~Rva00360D26Member();

private:
	unsigned m_unknown;
};

class TransportContainModuleData
{
public:
	virtual ~TransportContainModuleData();

private:
	unsigned m_04;				// +0x04 (unrecovered; pads the members to retail offsets)
	Rva00360D26Member m_08;			// +0x08
	Rva00360D26Member m_0C;			// +0x0C
};

// ??1TransportContainModuleData@@UAE@XZ
TransportContainModuleData::~TransportContainModuleData()
{
}
