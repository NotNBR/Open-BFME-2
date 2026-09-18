// Disp32 byte getters: seven-byte __thiscall members with one shape:
//
//     mov al,[ecx+<DISP>] / ret
//
// One BYTE is read at a fixed displacement from `this` and left in al. The
// return type is spelled `unsigned char` because only al is written and the
// upper bytes of eax are left holding whatever the caller had; the bytes
// cannot distinguish it from `signed char`, `bool` or a one-byte enum.
//
// Every displacement here is a disp32 (MSVC 7.1 uses disp8 whenever the
// offset fits, so every offset is at least 0x80), which is why this family
// is separable from the far larger disp8 one. Members before the accessed
// one are spelled as a lead array because their types are not witnessed
// here, only their total size. Identity is not recovered: every name is
// derived from its address (BFME1 pioneered the same family in
// reference/open-bfme-1/Code/GameEngine/Source/Common/DispByteFieldGetters.cpp).
// No // cl: line (defaults match the frameless 7-byte shape).
#define BFME_DISP_BYTE_GETTER(NAME, DISP) \
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

BFME_DISP_BYTE_GETTER(Rva0002BAF1ByteField, 0x430)
BFME_DISP_BYTE_GETTER(Rva00038CB0ByteField, 0x9F64)
BFME_DISP_BYTE_GETTER(Rva000421F6ByteField, 0x9B)
BFME_DISP_BYTE_GETTER(Rva00044235ByteField, 0xD8)
BFME_DISP_BYTE_GETTER(Rva000515A4ByteField, 0x6A6)
BFME_DISP_BYTE_GETTER(Rva00051896ByteField, 0x6A3)
BFME_DISP_BYTE_GETTER(Rva0006520BByteField, 0x15E)
BFME_DISP_BYTE_GETTER(Rva0006E002ByteField, 0x1914)
BFME_DISP_BYTE_GETTER(Rva0006E024ByteField, 0x440)
BFME_DISP_BYTE_GETTER(Rva0006E02BByteField, 0xE4)
BFME_DISP_BYTE_GETTER(Rva0006E04AByteField, 0xBC)
