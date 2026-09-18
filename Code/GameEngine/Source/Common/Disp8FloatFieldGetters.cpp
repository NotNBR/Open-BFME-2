// Disp8 float getters: four-byte __thiscall members with one shape:
//
//     fld dword ptr [ecx+<DISP>] / ret
//
// One float is read at a fixed displacement from `this` and returned on the
// x87 stack. Every displacement here fits in a signed byte, so MSVC 7.1
// encodes it as a disp8. This is the small-offset sibling of the disp32
// family in DispFloatFieldGetters.cpp, spelled with the same BFME1-pioneered
// lead-array idiom (see
// reference/open-bfme-1/Code/GameEngine/Source/Common/DispFloatFieldGetters.cpp).
// Identity is not recovered: every name is derived from its address.
// No // cl: line (defaults match the frameless 4-byte shape).
#define BFME_DISP8_FLOAT_GETTER(NAME, DISP) \
	class NAME \
	{ \
	public: \
		float get() const; \
		char m_lead[DISP]; \
		float m_value; \
	}; \
	float NAME::get() const \
	{ \
		return m_value; \
	}

BFME_DISP8_FLOAT_GETTER(Rva0015DF10FloatField, 0x1C)
BFME_DISP8_FLOAT_GETTER(Rva0015DF20FloatField, 0x18)
BFME_DISP8_FLOAT_GETTER(Rva0015DF30FloatField, 0x24)
BFME_DISP8_FLOAT_GETTER(Rva0015DF40FloatField, 0x28)
BFME_DISP8_FLOAT_GETTER(Rva0015DF50FloatField, 0x2C)
BFME_DISP8_FLOAT_GETTER(Rva00178FB0FloatField, 0x34)
BFME_DISP8_FLOAT_GETTER(Rva0018D340FloatField, 0x4C)
BFME_DISP8_FLOAT_GETTER(Rva0018F180FloatField, 0x50)
BFME_DISP8_FLOAT_GETTER(Rva006BD45DFloatField, 0x08)
BFME_DISP8_FLOAT_GETTER(Rva006C03E0FloatField, 0x0C)
BFME_DISP8_FLOAT_GETTER(Rva00723490FloatField, 0x08)
BFME_DISP8_FLOAT_GETTER(Rva0073A1C0FloatField, 0x20)
