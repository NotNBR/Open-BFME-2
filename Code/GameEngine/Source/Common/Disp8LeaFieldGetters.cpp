// Disp8 LEA getters: four-byte __thiscall members with one shape:
//
//     lea eax,[ecx+<DISP>] / ret
//
// The address of a member at a fixed displacement from `this` is returned.
// Spelled as byte-pointer arithmetic from `this`, which MSVC 7.1 folds to
// the same disp8 lea. The pointee type is unwitnessed (only an address is
// produced), so the return is an untyped pointer. Members before the
// accessed one are not spelled at all: unlike the load families, no lead
// array is needed because nothing is read.
// Identity is not recovered: every name is derived from its address, in the
// same opaque-holder convention as the neighboring Disp* families.
// No // cl: line (defaults match the frameless four-byte shape).
#define BFME_DISP8_LEA_GETTER(NAME, DISP) \
	class NAME \
	{ \
	public: \
		void *get() const; \
	}; \
	void *NAME::get() const \
	{ \
		return (char *)this + DISP; \
	}

// Negative-displacement sibling: the disp8 byte sign-extends, so a disp byte
// above 0x7F addresses *before* `this` (e.g. 9C = -100). Spelled as a
// negative byte offset from `this`, which folds to the same disp8 lea.
#define BFME_DISP8_NEG_LEA_GETTER(NAME, BACK) \
	class NAME \
	{ \
	public: \
		void *get() const; \
	}; \
	void *NAME::get() const \
	{ \
		return (char *)this - BACK; \
	}

BFME_DISP8_NEG_LEA_GETTER(Rva00305927LeaField, 100)
BFME_DISP8_NEG_LEA_GETTER(Rva0030592BLeaField, 116)
BFME_DISP8_LEA_GETTER(Rva00314046LeaField, 0x30)
BFME_DISP8_LEA_GETTER(Rva003EFDD7LeaField, 0x4C)
BFME_DISP8_LEA_GETTER(Rva0049CB82LeaField, 0x28)
BFME_DISP8_LEA_GETTER(Rva005C4AD1LeaField, 0x04)
BFME_DISP8_LEA_GETTER(Rva001D96ECLeaField, 0x50)
