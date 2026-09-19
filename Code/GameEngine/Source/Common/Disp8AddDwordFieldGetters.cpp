// Disp8 add dword getters: seven-byte __thiscall members with one shape:
//
//     mov eax,[ecx+<DISP>] / add eax,<IMM8> / ret
//
// One dword is read at a fixed displacement from `this`, a small immediate
// is added, and the result is returned. The immediate fits in a signed
// byte, so MSVC 7.1 emits the `83 C0 XX` form (three bytes) after the disp8
// load `8B 41 XX`, plus `ret`, for seven bytes total. This is the add
// sibling of the sub Disp8SubDwordFieldGetters family; the opcode itself
// is why the two families are kept in separate translation units. Identity
// is not recovered: every name is derived from its address.
// No // cl: line (defaults match the frameless seven-byte shape).
#define BFME_DISP8_ADD_DWORD_GETTER(NAME, DISP, IMM) \
	class NAME \
	{ \
	public: \
		int get() const; \
		char m_lead[DISP]; \
		int m_value; \
	}; \
	int NAME::get() const \
	{ \
		return m_value + IMM; \
	}

BFME_DISP8_ADD_DWORD_GETTER(Rva000B28C8AddDwordField, 0x30, 0x24)
BFME_DISP8_ADD_DWORD_GETTER(Rva002B236EAddDwordField, 0x40, 0x04)
BFME_DISP8_ADD_DWORD_GETTER(Rva0033F272AddDwordField, 0x18, 0x24)
BFME_DISP8_ADD_DWORD_GETTER(Rva0033F94DAddDwordField, 0x30, 0x3C)
BFME_DISP8_ADD_DWORD_GETTER(Rva00464829AddDwordField, 0xE8, 0x38)
