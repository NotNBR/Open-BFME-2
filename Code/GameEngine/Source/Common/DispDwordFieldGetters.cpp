// Disp32 dword getters: seven-byte __thiscall members with one shape:
//
//     mov eax,[ecx+<DISP>] / ret
//
// One dword is read at a fixed displacement from `this` and returned. Every
// displacement here is a multiple of four, so the accessed member is spelled
// as an `int` right after the lead array. The bytes cannot distinguish `int`
// from `unsigned int`, a pointer, or anything else four bytes wide moved
// with a plain load. Members before the accessed one are spelled as a lead
// array because their types are not witnessed here, only their total size.
// Identity is not recovered: every name is derived from its address (BFME1
// pioneered the same family in
// reference/open-bfme-1/Code/GameEngine/Source/Common/DispDwordFieldGetters.cpp).
// No // cl: line (defaults match the frameless 7-byte shape).
#define BFME_DISP_DWORD_GETTER(NAME, DISP) \
	class NAME \
	{ \
	public: \
		int get() const; \
		char m_lead[DISP]; \
		int m_value; \
	}; \
	int NAME::get() const \
	{ \
		return m_value; \
	}

BFME_DISP_DWORD_GETTER(Rva00042292DwordField, 0x2EC)
BFME_DISP_DWORD_GETTER(Rva00042321DwordField, 0x1768)
BFME_DISP_DWORD_GETTER(Rva00042328DwordField, 0x1774)
BFME_DISP_DWORD_GETTER(Rva0004251FDwordField, 0x1A4C4)
BFME_DISP_DWORD_GETTER(Rva00042F98DwordField, 0x3878)
BFME_DISP_DWORD_GETTER(Rva00042F9FDwordField, 0x387C)
BFME_DISP_DWORD_GETTER(Rva00042FA6DwordField, 0x37C0)
BFME_DISP_DWORD_GETTER(Rva00050E99DwordField, 0x1770)
BFME_DISP_DWORD_GETTER(Rva0005155EDwordField, 0x9D0)
