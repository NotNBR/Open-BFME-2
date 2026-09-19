// Disp32 LEA getters: seven-byte __thiscall members with one shape:
//
//     lea eax,[ecx+<DISP>] / ret
//
// The address of a member at a fixed displacement from `this` is returned.
// Spelled as byte-pointer arithmetic from `this`, which MSVC 7.1 folds to
// the same disp32 lea. The pointee type is unwitnessed (only an address is
// produced), so the return is an untyped pointer. Members before the
// accessed one are not spelled at all: unlike the load families, no lead
// array is needed because nothing is read. The disp32 mirror of the disp8
// family in Disp8LeaFieldGetters.cpp (MSVC 7.1 uses disp8 whenever the
// offset fits in a signed byte, so every offset here is at least 0x80).
// Identity is not recovered: every name is derived from its address.
// No // cl: line (defaults match the frameless seven-byte shape).
#define BFME_DISP32_LEA_GETTER(NAME, DISP) \
	class NAME \
	{ \
	public: \
		void *get() const; \
	}; \
	void *NAME::get() const \
	{ \
		return (char *)this + DISP; \
	}

BFME_DISP32_LEA_GETTER(Rva00042280LeaGetter, 0x284)
BFME_DISP32_LEA_GETTER(Rva00042299LeaGetter, 0x3BC)
BFME_DISP32_LEA_GETTER(Rva000425A2LeaGetter, 0x4F0C)
BFME_DISP32_LEA_GETTER(Rva00078922LeaGetter, 0x90)
BFME_DISP32_LEA_GETTER(Rva00098559LeaGetter, 0x84)
BFME_DISP32_LEA_GETTER(Rva000B28F2LeaGetter, 0x9C)
BFME_DISP32_LEA_GETTER(Rva001D96F8LeaGetter, 0x80)
BFME_DISP32_LEA_GETTER(Rva001E3817LeaGetter, 0x544)
BFME_DISP32_LEA_GETTER(Rva001EAE47LeaGetter, 0x13C)
BFME_DISP32_LEA_GETTER(Rva001EAE55LeaGetter, 0x2F0)
BFME_DISP32_LEA_GETTER(Rva001EAE5CLeaGetter, 0x738)
BFME_DISP32_LEA_GETTER(Rva001F4975LeaGetter, 0x1B0)
BFME_DISP32_LEA_GETTER(Rva001F497CLeaGetter, 0x1C0)
BFME_DISP32_LEA_GETTER(Rva001F4983LeaGetter, 0x1BC)
BFME_DISP32_LEA_GETTER(Rva001F49A5LeaGetter, 0xB0)
BFME_DISP32_LEA_GETTER(Rva001F49ACLeaGetter, 0xB8)
BFME_DISP32_LEA_GETTER(Rva001F49B3LeaGetter, 0xC0)
