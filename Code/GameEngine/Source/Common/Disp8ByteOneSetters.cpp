// Disp8 byte flag setters: five-byte __thiscall members with one shape:
//
//     mov byte ptr [ecx+<DISP>],<IMM8> / ret
//
// One byte at a fixed displacement from `this` is set to a hardcoded
// immediate (0 or 1 in every body found so far) and nothing is read back.
// This is the small-offset sibling of the disp32 family in
// DispByteOneSetters.cpp (MSVC 7.1 uses disp8 whenever the offset fits, so
// every offset here fits in a signed byte). Members before the accessed one
// are spelled as a lead array because their types are not witnessed here,
// only their total size. Identity is not recovered: every name is derived
// from its address.
// No // cl: line (defaults match the frameless five-byte shape).
#define BFME_DISP8_BYTE_ONE_SETTER(NAME, DISP) \
	class NAME \
	{ \
	public: \
		void enable(); \
		char m_lead[DISP]; \
		unsigned char m_enabled; \
	}; \
	void NAME::enable() \
	{ \
		m_enabled = 1; \
	}

#define BFME_DISP8_BYTE_ZERO_SETTER(NAME, DISP) \
	class NAME \
	{ \
	public: \
		void disable(); \
		char m_lead[DISP]; \
		unsigned char m_enabled; \
	}; \
	void NAME::disable() \
	{ \
		m_enabled = 0; \
	}

BFME_DISP8_BYTE_ONE_SETTER(Rva000D4A7COneSetter, 0x4D)
BFME_DISP8_BYTE_ONE_SETTER(Rva001DBB82OneSetter, 0x69)
BFME_DISP8_BYTE_ZERO_SETTER(Rva001DBB87ZeroSetter, 0x69)
BFME_DISP8_BYTE_ZERO_SETTER(Rva00420B2AZeroSetter, 0x08)
BFME_DISP8_BYTE_ONE_SETTER(Rva00050D06OneSetter, 0x4F)
BFME_DISP8_BYTE_ZERO_SETTER(Rva00050D0BZeroSetter, 0x4F)
BFME_DISP8_BYTE_ONE_SETTER(Rva000664EFOneSetter, 0x21)
BFME_DISP8_BYTE_ONE_SETTER(Rva00090753OneSetter, 0x52)
BFME_DISP8_BYTE_ONE_SETTER(Rva0009D6E8OneSetter, 0x25)
BFME_DISP8_BYTE_ZERO_SETTER(Rva0009D6F5ZeroSetter, 0x25)
BFME_DISP8_BYTE_ONE_SETTER(Rva00131075OneSetter, 0x0D)
BFME_DISP8_BYTE_ONE_SETTER(Rva00238D92OneSetter, 0x6C)
BFME_DISP8_BYTE_ONE_SETTER(Rva0025DD11OneSetter, 0x38)
BFME_DISP8_BYTE_ZERO_SETTER(Rva0025DD16ZeroSetter, 0x38)
BFME_DISP8_BYTE_ZERO_SETTER(Rva002886A2ZeroSetter, 0x24)
BFME_DISP8_BYTE_ONE_SETTER(Rva0028A813OneSetter, 0x28)
BFME_DISP8_BYTE_ONE_SETTER(Rva0028AA1COneSetter, 0x2C)
BFME_DISP8_BYTE_ONE_SETTER(Rva002B2361OneSetter, 0x75)
BFME_DISP8_BYTE_ONE_SETTER(Rva003860FAOneSetter, 0x04)
BFME_DISP8_BYTE_ZERO_SETTER(Rva0039ABE6ZeroSetter, 0x20)
BFME_DISP8_BYTE_ONE_SETTER(Rva00428DBCOneSetter, 0x51)
BFME_DISP8_BYTE_ONE_SETTER(Rva00433D22OneSetter, 0x54)
BFME_DISP8_BYTE_ZERO_SETTER(Rva0045F37DZeroSetter, 0x30)
BFME_DISP8_BYTE_ONE_SETTER(Rva004A18C0OneSetter, 0x24)
BFME_DISP8_BYTE_ONE_SETTER(Rva00050CDCOneSetter, 0x4C)
BFME_DISP8_BYTE_ONE_SETTER(Rva00050CFCOneSetter, 0x53)
