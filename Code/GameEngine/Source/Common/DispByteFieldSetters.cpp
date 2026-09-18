// Disp32 byte setters: thirteen-byte __thiscall members with one shape:
//
//     mov al,[esp+4] / mov [ecx+<DISP>],al / ret 4
//
// One byte is taken from the stack argument slot and stored at a fixed
// displacement from `this`. Ported from Open-BFME-1
// (Code/GameEngine/Source/Common/DispByteFieldSetters.cpp): the
// BFME_DISP_BYTE_SETTER macro is verbatim (unsigned char set over a lead
// array), only the class names follow this tree's Disp* convention
// (address-derived Rva<addr>ByteSlot, identity unrecoverable from 13 bytes).
// Every displacement here is a disp32 (MSVC 7.1 uses disp8 whenever the
// offset fits, so every offset is at least 0x80).
// No // cl: line (defaults match the frameless 13-byte shape).
#define BFME_DISP_BYTE_SETTER(NAME, DISP) \
	class NAME \
	{ \
	public: \
		void set(unsigned char value); \
		char m_lead[DISP]; \
		unsigned char m_value; \
	}; \
	void NAME::set(unsigned char value) \
	{ \
		m_value = value; \
	}

BFME_DISP_BYTE_SETTER(Rva0029A2D1ByteSlot, 0x8BB)
BFME_DISP_BYTE_SETTER(Rva0029A2DEByteSlot, 0x8BC)
BFME_DISP_BYTE_SETTER(Rva0029A2EBByteSlot, 0x8BD)
BFME_DISP_BYTE_SETTER(Rva0029A2F8ByteSlot, 0x8BE)
BFME_DISP_BYTE_SETTER(Rva0029A305ByteSlot, 0x8BF)
BFME_DISP_BYTE_SETTER(Rva0029A312ByteSlot, 0x8C0)
BFME_DISP_BYTE_SETTER(Rva0029A31FByteSlot, 0x8C1)
BFME_DISP_BYTE_SETTER(Rva0029A32CByteSlot, 0x8C2)
BFME_DISP_BYTE_SETTER(Rva0029A290ByteSlot, 0x8B0)
BFME_DISP_BYTE_SETTER(Rva0029A29DByteSlot, 0x8B9)
BFME_DISP_BYTE_SETTER(Rva0029A2AAByteSlot, 0x8B8)
BFME_DISP_BYTE_SETTER(Rva0029A2B7ByteSlot, 0x8BA)
BFME_DISP_BYTE_SETTER(Rva003BA59CByteSlot, 0x99)
BFME_DISP_BYTE_SETTER(Rva00105D7CByteSlot, 0xAD)
BFME_DISP_BYTE_SETTER(Rva00105D89ByteSlot, 0xAE)
BFME_DISP_BYTE_SETTER(Rva003BA5A9ByteSlot, 0x9A)
BFME_DISP_BYTE_SETTER(Rva00262335ByteSlot, 0x3C7)
BFME_DISP_BYTE_SETTER(Rva0026230BByteSlot, 0x3BA)
BFME_DISP_BYTE_SETTER(Rva00262342ByteSlot, 0x3CC)
BFME_DISP_BYTE_SETTER(Rva00042FBABByteSlot, 0x12C)
BFME_DISP_BYTE_SETTER(Rva003BA5B6ByteSlot, 0x9B)
BFME_DISP_BYTE_SETTER(Rva003BA5C3ByteSlot, 0x9F)
BFME_DISP_BYTE_SETTER(Rva003BA5D0ByteSlot, 0x11C)
BFME_DISP_BYTE_SETTER(Rva00087A02ByteSlot, 0x2503)
BFME_DISP_BYTE_SETTER(Rva00087A0FByteSlot, 0x2502)
BFME_DISP_BYTE_SETTER(Rva00087A1CByteSlot, 0x2501)
BFME_DISP_BYTE_SETTER(Rva00087A29ByteSlot, 0x2504)
