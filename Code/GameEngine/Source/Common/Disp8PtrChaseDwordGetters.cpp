// Disp8 pointer-chase dword getters: seven-byte __thiscall members with one shape:
//
//     mov eax,[ecx+<DISP1>] / mov eax,[eax+<DISP2>] / ret
//
// A pointer is read at a fixed displacement from `this`, then a dword is read
// at a second displacement from that pointer and returned. MSVC 7.1 emits the
// disp8 loads `8B 41 XX` + `8B 40 XX`, plus `ret`, for seven bytes total.
// Identity is not recovered: every name is derived from its address.
// No // cl: line (defaults match the frameless seven-byte shape).
#define BFME_DISP8_PTRCHASE_DWORD_GETTER(NAME, DISP1, DISP2) \
	class NAME \
	{ \
	public: \
		int get() const; \
		char m_lead[DISP1]; \
		void *m_ptr; \
	}; \
	int NAME::get() const \
	{ \
		return *(int *)((char *)m_ptr + DISP2); \
	}

BFME_DISP8_PTRCHASE_DWORD_GETTER(Rva000425C4PtrChaseField, 0x08, 0x18)
BFME_DISP8_PTRCHASE_DWORD_GETTER(RvaB49A1PtrChaseField, 0x2C, 0x0C)
BFME_DISP8_PTRCHASE_DWORD_GETTER(Rva262193PtrChaseField, 0x04, 0x74)
BFME_DISP8_PTRCHASE_DWORD_GETTER(Rva262FF8PtrChaseField, 0x04, 0x40)
BFME_DISP8_PTRCHASE_DWORD_GETTER(Rva26FFDBPtrChaseField, 0x04, 0x4C)
BFME_DISP8_PTRCHASE_DWORD_GETTER(Rva2D2CD5PtrChaseField, 0x40, 0x08)
BFME_DISP8_PTRCHASE_DWORD_GETTER(Rva0002E05F5PtrChaseField, 0x40, 0x14)
BFME_DISP8_PTRCHASE_DWORD_GETTER(Rva0002E05FCPtrChaseField, 0x40, 0x0C)
BFME_DISP8_PTRCHASE_DWORD_GETTER(Rva000318B17PtrChaseField, 0x40, 0x1C)
BFME_DISP8_PTRCHASE_DWORD_GETTER(Rva00033F25CPtrChaseField, 0x18, 0x14)
BFME_DISP8_PTRCHASE_DWORD_GETTER(Rva00033F91EPtrChaseField, 0x04, 0x34)
