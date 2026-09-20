// Disp32 dword getters: seven-byte __thiscall members with one shape:
//
//     mov eax,[ecx+<DISP32>] / ret
//
// One dword is read at a 32-bit displacement from `this` and returned. The
// displacement does not fit in a signed byte, so MSVC 7.1 emits the disp32
// load `8B 81 <imm32>`, plus `ret`, for seven bytes total. This is the disp32
// sibling of the disp8 Disp8DwordFieldGetters family (four bytes per body);
// the wider displacement is why the two families are kept in separate
// translation units. Identity is not recovered: every name is derived from
// its address.
// No // cl: line (defaults match the frameless seven-byte shape).
#define BFME_DISP32_DWORD_GETTER(NAME, DISP) \
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

BFME_DISP32_DWORD_GETTER(Rva000515C7DwordField, 0x68C)
BFME_DISP32_DWORD_GETTER(Rva0007E00FDwordField, 0x1784)
BFME_DISP32_DWORD_GETTER(Rva0009DC5ADwordField, 0x22C)
BFME_DISP32_DWORD_GETTER(Rva000B23B7DwordField, 0x360)
