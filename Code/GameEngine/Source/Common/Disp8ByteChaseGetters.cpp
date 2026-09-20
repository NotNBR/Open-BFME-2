// Disp8 byte-chase getters: seven-byte __thiscall members with one shape:
//
//     mov eax,[ecx+<DISP1>] / mov al,[eax+<DISP2>] / ret
//
// A pointer is read at a fixed displacement from `this`, then a byte is read
// at a second displacement from that pointer and returned in `al` (only the
// low byte is defined; the caller uses `al`). MSVC 7.1 emits the disp8 loads
// `8B 41 XX` + `8A 40 XX`, plus `ret`, for seven bytes total.
// Identity is not recovered: every name is derived from its address.
// No // cl: line (defaults match the frameless seven-byte shape).
#define BFME_DISP8_BYTECHASE_GETTER(NAME, DISP1, DISP2) \
	class NAME \
	{ \
	public: \
		unsigned char get() const; \
		char m_lead[DISP1]; \
		void *m_ptr; \
	}; \
	unsigned char NAME::get() const \
	{ \
		return *(unsigned char *)((char *)m_ptr + DISP2); \
	}

BFME_DISP8_BYTECHASE_GETTER(Rva0007E05FByteChaseField, 0x0C, 0x2C)
BFME_DISP8_BYTECHASE_GETTER(Rva0033F988ByteChaseField, 0x04, 0x24)
BFME_DISP8_BYTECHASE_GETTER(Rva00373CA3ByteChaseField, 0x04, 0x30)
BFME_DISP8_BYTECHASE_GETTER(Rva004551ACByteChaseField, 0x04, 0x74)
