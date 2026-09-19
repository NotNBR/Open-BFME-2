// ?get@Rva004C1160@@QAEHXZ, retail 0x004059BE (17B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/R2GuardedFieldGetters.cpp
// (BFME1 0x004C1160). Guarded field read: null pointee returns zero, else one
// int field at +0x1C8 of the pointee reached via the pointer at +0x08.
// The donor defines 22 further siblings the sweep did not place, so only the
// placed body is instantiated here.

struct IntAt1C8h { char m_leading[ 0x1C8 ]; int m_value; };

#define R2_GUARDED_FIELD_GET( NAME, OFF, POINTEE, TYPE )  \
	class NAME                                          \
	{                                                   \
	public:                                             \
		char m_leading[ OFF ];                          \
		POINTEE *m_pointee;                             \
		TYPE get();                                     \
	};                                                  \
	TYPE NAME::get()                                    \
	{                                                   \
		if ( m_pointee )                                \
		{                                               \
			return m_pointee->m_value;                  \
		}                                               \
		return 0;                                       \
	}

R2_GUARDED_FIELD_GET( Rva004C1160, 0x8, IntAt1C8h, int )
