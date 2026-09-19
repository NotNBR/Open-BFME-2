// Disp8 dword inc/dec: four-byte __thiscall members with one shape:
//
//     inc dword ptr [ecx+<DISP>] / ret        (FF 41 XX C3)
//     dec dword ptr [ecx+<DISP>] / ret        (FF 49 XX C3)
//
// A dword counter at a fixed displacement from `this` is incremented (or
// decremented) in place. Every displacement here fits in a signed byte, so
// MSVC 7.1 emits the disp8 form plus `ret`, for four bytes total. The
// accessed member is spelled as an `int` right after the lead array; the
// bytes cannot distinguish `int` from `unsigned int` or any other
// four-byte-wide incremented slot. Members before the accessed one are
// spelled as a lead array because their types are not witnessed here, only
// their total size.
// Identity is not recovered: every name is derived from its address (the
// disp8 dword-getter family pioneered the same opaque-holder pattern in
// Disp8DwordFieldGetters.cpp).
// No // cl: line (defaults match the frameless four-byte shape).
#define BFME_DISP8_DWORD_INC(NAME, DISP) \
	class NAME \
	{ \
	public: \
		void inc(); \
		char m_lead[DISP]; \
		int m_counter; \
	}; \
	void NAME::inc() \
	{ \
		++m_counter; \
	}

#define BFME_DISP8_DWORD_DEC(NAME, DISP) \
	class NAME \
	{ \
	public: \
		void dec(); \
		char m_lead[DISP]; \
		int m_counter; \
	}; \
	void NAME::dec() \
	{ \
		--m_counter; \
	}

BFME_DISP8_DWORD_INC(Rva002D76B7DwordCounter, 0x08)
