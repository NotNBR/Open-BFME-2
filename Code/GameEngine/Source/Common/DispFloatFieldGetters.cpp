// Disp32 float getters: seven-byte __thiscall members with one shape:
//
//     fld dword ptr [ecx+<DISP>] / ret
//
// One dword is loaded onto the x87 stack and left there, which is the return
// convention for `float`. BFME1 pioneered the same family in
// reference/open-bfme-1/Code/GameEngine/Source/Common/DispFloatFieldGetters.cpp.
// No // cl: line (defaults match the frameless 7-byte shape).
#define BFME_DISP_FLOAT_GETTER(NAME, DISP) \
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

BFME_DISP_FLOAT_GETTER(Rva00050F61FloatField, 0x90)
BFME_DISP_FLOAT_GETTER(Rva00050F68FloatField, 0x94)
BFME_DISP_FLOAT_GETTER(Rva00050F76FloatField, 0xA8)
BFME_DISP_FLOAT_GETTER(Rva0006E032FloatField, 0x358)
BFME_DISP_FLOAT_GETTER(Rva000788F8FloatField, 0x4E8)
BFME_DISP_FLOAT_GETTER(Rva000788FFFloatField, 0x4EC)
BFME_DISP_FLOAT_GETTER(Rva00078906FloatField, 0x4F0)
BFME_DISP_FLOAT_GETTER(Rva0007890DFloatField, 0x4F4)
BFME_DISP_FLOAT_GETTER(Rva00078914FloatField, 0x500)
BFME_DISP_FLOAT_GETTER(Rva0007891BFloatField, 0x504)
BFME_DISP_FLOAT_GETTER(Rva00085516FloatField, 0xF0)
BFME_DISP_FLOAT_GETTER(Rva000879EDFloatField, 0x24F8)
BFME_DISP_FLOAT_GETTER(Rva000879F4FloatField, 0x24FC)
BFME_DISP_FLOAT_GETTER(Rva0008BC64FloatField, 0xA4)
BFME_DISP_FLOAT_GETTER(Rva0008E179FloatField, 0x1A148)
BFME_DISP_FLOAT_GETTER(Rva00091A48FloatField, 0x4D4)
BFME_DISP_FLOAT_GETTER(Rva00091A4FFloatField, 0x4D8)
BFME_DISP_FLOAT_GETTER(Rva0009533CFloatField, 0xD0)
