// Disp8 float-chase getters: seven-byte __thiscall members with one shape:
//
//     mov eax,[ecx+<DISP1>] / fld dword [eax+<DISP2>] / ret
//
// A pointer is read at a fixed displacement from `this`, then a float is read
// at a second displacement from that pointer and returned in ST0. MSVC 7.1
// emits the disp8 loads `8B 41 XX` + `D9 40 XX`, plus `ret`, for seven bytes.
// Identity is not recovered: every name is derived from its address.
// No // cl: line (defaults match the frameless seven-byte shape).
#define BFME_DISP8_FLOATCHASE_GETTER(NAME, DISP1, DISP2) \
	class NAME \
	{ \
	public: \
		float get() const; \
		char m_lead[DISP1]; \
		void *m_ptr; \
	}; \
	float NAME::get() const \
	{ \
		return *(float *)((char *)m_ptr + DISP2); \
	}

BFME_DISP8_FLOATCHASE_GETTER(Rva0007E066FloatChaseField, 0x0C, 0x28)
BFME_DISP8_FLOATCHASE_GETTER(Rva0007E0F1FloatChaseField, 0x40, 0x5C)
BFME_DISP8_FLOATCHASE_GETTER(Rva000910C0FloatChaseField, 0x2C, 0x20)
BFME_DISP8_FLOATCHASE_GETTER(Rva001E3F27FloatChaseField, 0x04, 0x38)
