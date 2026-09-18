// Disp32 dword setters: thirteen-byte __thiscall members with one shape:
//
//     mov eax,[esp+4] / mov [ecx+<DISP>],eax / ret 4
//
// One dword is taken from the stack argument slot and stored at a fixed
// displacement from `this`. Ported from Open-BFME-1
// (Code/GameEngine/Source/Common/DispDwordFieldSetters.cpp): the
// BFME_DISP_DWORD_SETTER macro is verbatim (void set over a lead array),
// only the class names follow this tree's Disp* convention
// (address-derived Rva<addr>DwordSlot, identity unrecoverable from 13 bytes).
// Every displacement here is a disp32 (MSVC 7.1 uses disp8 whenever the
// offset fits, so every offset is at least 0x80).
// No // cl: line (defaults match the frameless 13-byte shape).
#define BFME_DISP_DWORD_SETTER(NAME, DISP) \
	class NAME \
	{ \
	public: \
		void set(int value); \
		char m_lead[DISP]; \
		int m_value; \
	}; \
	void NAME::set(int value) \
	{ \
		m_value = value; \
	}

BFME_DISP_DWORD_SETTER(Rva0029A2C4DwordSlot, 0x8B4)
BFME_DISP_DWORD_SETTER(Rva005AE60BDwordSlot, 0x1C0)
BFME_DISP_DWORD_SETTER(Rva005AE618DwordSlot, 0xFE0)
BFME_DISP_DWORD_SETTER(Rva005AE625DwordSlot, 0xFF0)
BFME_DISP_DWORD_SETTER(Rva005AE632DwordSlot, 0x100C)
BFME_DISP_DWORD_SETTER(Rva005AE63FDwordSlot, 0x1010)
BFME_DISP_DWORD_SETTER(Rva005AE64CDwordSlot, 0x1014)
BFME_DISP_DWORD_SETTER(Rva00376CA2DwordSlot, 0xA4)
BFME_DISP_DWORD_SETTER(Rva00376CAFDwordSlot, 0x110)
BFME_DISP_DWORD_SETTER(Rva00376CBCDwordSlot, 0x114)
BFME_DISP_DWORD_SETTER(Rva004FD9EADwordSlot, 0x1AC)
BFME_DISP_DWORD_SETTER(Rva004FD9F7DwordSlot, 0x1C8)
BFME_DISP_DWORD_SETTER(Rva004FDA04DwordSlot, 0x1CC)
BFME_DISP_DWORD_SETTER(Rva00049F66DwordSlot, 0xF4)
BFME_DISP_DWORD_SETTER(Rva00049F73DwordSlot, 0xF8)
BFME_DISP_DWORD_SETTER(Rva002B23EBDwordSlot, 0x2BC)
BFME_DISP_DWORD_SETTER(Rva002B23F8DwordSlot, 0x2C4)
BFME_DISP_DWORD_SETTER(Rva0031ED12DwordSlot, 0x22C)
