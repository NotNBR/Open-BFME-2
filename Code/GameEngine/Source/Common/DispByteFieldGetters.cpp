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
BFME_DISP_BYTE_GETTER(Rva000788DAByteField, 0x441)
BFME_DISP_BYTE_GETTER(Rva0008550FByteField, 0x37D4)
BFME_DISP_BYTE_GETTER(Rva000879FBByteField, 0x2500)
BFME_DISP_BYTE_GETTER(Rva0008BC9BByteField, 0x23D0)
BFME_DISP_BYTE_GETTER(Rva0008BCCCByteField, 0x2449)
BFME_DISP_BYTE_GETTER(Rva0008E180ByteField, 0x1A13C)
BFME_DISP_BYTE_GETTER(Rva0008EF95ByteField, 0x811)
BFME_DISP_BYTE_GETTER(Rva0008EF9CByteField, 0x98C)
BFME_DISP_BYTE_GETTER(Rva0008EFA3ByteField, 0x8C6)
BFME_DISP_BYTE_GETTER(Rva0008EFC5ByteField, 0x810)
BFME_DISP_BYTE_GETTER(Rva000930D9ByteField, 0x2A9)
BFME_DISP_BYTE_GETTER(Rva00094ADCByteField, 0x90)
BFME_DISP_BYTE_GETTER(Rva00094AE3ByteField, 0x91)
BFME_DISP_BYTE_GETTER(Rva000B2294ByteField, 0x184)
BFME_DISP_BYTE_GETTER(Rva000B229BByteField, 0xE18)
BFME_DISP_BYTE_GETTER(Rva000B22A2ByteField, 0x33B)
BFME_DISP_BYTE_GETTER(Rva000B238BByteField, 0x442)
BFME_DISP_BYTE_GETTER(Rva000B28D6ByteField, 0x632)
BFME_DISP_BYTE_GETTER(Rva000B28DDByteField, 0x5ED)
BFME_DISP_BYTE_GETTER(Rva000B28E4ByteField, 0x5EE)
BFME_DISP_BYTE_GETTER(Rva000B28EBByteField, 0x5EF)
BFME_DISP_BYTE_GETTER(Rva000FB9CDByteField, 0x2A8)
BFME_DISP_BYTE_GETTER(Rva0011C680ByteField, 0x13A)
BFME_DISP_BYTE_GETTER(Rva00129460ByteField, 0x13B)
BFME_DISP_BYTE_GETTER(Rva0013106EByteField, 0x13C)
BFME_DISP_BYTE_GETTER(Rva001386B0ByteField, 0x138)
BFME_DISP_BYTE_GETTER(Rva001432D0ByteField, 0xBD)
BFME_DISP_BYTE_GETTER(Rva00143470ByteField, 0xE4)
BFME_DISP_BYTE_GETTER(Rva00188080ByteField, 0x248)
BFME_DISP_BYTE_GETTER(Rva001A1520ByteField, 0x11C)
BFME_DISP_BYTE_GETTER(Rva001E33F0ByteField, 0x249)
BFME_DISP_BYTE_GETTER(Rva001EADFFByteField, 0xC0)
BFME_DISP_BYTE_GETTER(Rva001EAE06ByteField, 0xC1)
BFME_DISP_BYTE_GETTER(Rva001F3513ByteField, 0x1A4)
BFME_DISP_BYTE_GETTER(Rva001F351AByteField, 0x1A6)
BFME_DISP_BYTE_GETTER(Rva001FD190ByteField, 0x150)
BFME_DISP_BYTE_GETTER(Rva001FD197ByteField, 0x151)
BFME_DISP_BYTE_GETTER(Rva002026C7ByteField, 0x17AA)
BFME_DISP_BYTE_GETTER(Rva00203533ByteField, 0x1A2)
BFME_DISP_BYTE_GETTER(Rva00203541ByteField, 0x3CA)
BFME_DISP_BYTE_GETTER(Rva0020E2EBByteField, 0xAB)
BFME_DISP_BYTE_GETTER(Rva00210CBEByteField, 0xA8)
BFME_DISP_BYTE_GETTER(Rva00210CCCByteField, 0xE8)
BFME_DISP_BYTE_GETTER(Rva00219154ByteField, 0xFF4)
BFME_DISP_BYTE_GETTER(Rva0023C529ByteField, 0x5E5)
BFME_DISP_BYTE_GETTER(Rva0023C53EByteField, 0x5EB)
BFME_DISP_BYTE_GETTER(Rva0023C545ByteField, 0x5EC)
BFME_DISP_BYTE_GETTER(Rva0023C607ByteField, 0xF7C)
BFME_DISP_BYTE_GETTER(Rva00248D0DByteField, 0x8C)
BFME_DISP_BYTE_GETTER(Rva002622BEByteField, 0x3BD)
BFME_DISP_BYTE_GETTER(Rva002622CFByteField, 0x3B1)
BFME_DISP_BYTE_GETTER(Rva0026FFE9ByteField, 0x7A4)
BFME_DISP_BYTE_GETTER(Rva0027C2C2ByteField, 0x3CF)
BFME_DISP_BYTE_GETTER(Rva002885ECByteField, 0x102)
BFME_DISP_BYTE_GETTER(Rva002885F3ByteField, 0x101)
BFME_DISP_BYTE_GETTER(Rva0028A650ByteField, 0x435)
BFME_DISP_BYTE_GETTER(Rva0028A657ByteField, 0x248)
BFME_DISP_BYTE_GETTER(Rva0028A961ByteField, 0x5FA)
