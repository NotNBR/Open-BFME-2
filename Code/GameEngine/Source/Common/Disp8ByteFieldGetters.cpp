// Disp8 byte getters: four-byte __thiscall members with one shape:
//
//     mov al,[ecx+<DISP>] / ret
//
// One BYTE is read at a fixed displacement from `this` and left in al. The
// return type is spelled `unsigned char` because only al is written and the
// upper bytes of eax are left holding whatever the caller had; the bytes
// cannot distinguish it from `signed char`, `bool` or a one-byte enum.
// This is the small-offset sibling of the disp32 family in
// DispByteFieldGetters.cpp (MSVC 7.1 uses disp8 whenever the offset fits,
// so every offset here fits in a signed byte). Members before the accessed
// one are spelled as a lead array because their types are not witnessed
// here, only their total size. Identity is not recovered: every name is
// derived from its address.
// No // cl: line (defaults match the frameless four-byte shape).
#define BFME_DISP8_BYTE_GETTER(NAME, DISP) \
	class NAME \
	{ \
	public: \
		unsigned char get() const; \
		char m_lead[DISP]; \
		unsigned char m_value; \
	}; \
	unsigned char NAME::get() const \
	{ \
		return m_value; \
	}

BFME_DISP8_BYTE_GETTER(Rva000CB12FByteField, 0x49)
BFME_DISP8_BYTE_GETTER(Rva004543C6ByteField, 0x1E)
BFME_DISP8_BYTE_GETTER(Rva0001BC70ByteField, 0x54)
BFME_DISP8_BYTE_GETTER(Rva0009D6EDByteField, 0x24)
BFME_DISP8_BYTE_GETTER(Rva0009D6F1ByteField, 0x25)
BFME_DISP8_BYTE_GETTER(Rva00050D10ByteField, 0x4F)
BFME_DISP8_BYTE_GETTER(Rva0053111DByteField, 0x35)
BFME_DISP8_BYTE_GETTER(Rva00041D5EByteField, 0x11)
BFME_DISP8_BYTE_GETTER(Rva00050CA9ByteField, 0x4A)
BFME_DISP8_BYTE_GETTER(Rva0008BB0AByteField, 0x44)
BFME_DISP8_BYTE_GETTER(Rva00094AD8ByteField, 0x5C)
BFME_DISP8_BYTE_GETTER(Rva000B225AByteField, 0x70)
BFME_DISP8_BYTE_GETTER(Rva000D1A7AByteField, 0x45)
BFME_DISP8_BYTE_GETTER(Rva001DAF7DByteField, 0x08)
BFME_DISP8_BYTE_GETTER(Rva001DBA6DByteField, 0x10)
BFME_DISP8_BYTE_GETTER(Rva001DCD01ByteField, 0x22)
BFME_DISP8_BYTE_GETTER(Rva001EAE43ByteField, 0x78)
BFME_DISP8_BYTE_GETTER(Rva0020354FByteField, 0x0D)
BFME_DISP8_BYTE_GETTER(Rva002035A1ByteField, 0x2B)
BFME_DISP8_BYTE_GETTER(Rva002035A5ByteField, 0x2A)
BFME_DISP8_BYTE_GETTER(Rva002035A9ByteField, 0x4C)
BFME_DISP8_BYTE_GETTER(Rva002259EFByteField, 0x71)
BFME_DISP8_BYTE_GETTER(Rva0023C418ByteField, 0x6E)
