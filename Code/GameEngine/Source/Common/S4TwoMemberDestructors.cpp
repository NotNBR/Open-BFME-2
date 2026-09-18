// Two-member destructor ??1S4Dtor00587B30@@UAE@XZ.
//
// BFME1 donor S4TwoMemberDestructors.cpp shape: compiler-emitted vptr restore,
// then member destruction in reverse declaration order (higher offset first)
// with EH states counting down, then the base destructor. BFME2 repair: the
// first member sits at +0x20 here, not BFME1's +0x18 (near-miss drift at
// +0x35: lea ecx,[esi+0x18] vs [esi+0x20); the second member stays at +0x24.
// B1 0x00587B30 95B -> B2 0x006E96D0 95B, immediate-only drift.
// Both members destroy through 0x006D3010 and the base through 0x006D6470
// (pins, REL32-decoded from retail).

#define S4_MEMBER( ADDR ) struct S4Mem##ADDR { ~S4Mem##ADDR(); };
#define S4_BASE( ADDR ) struct S4Base##ADDR { virtual ~S4Base##ADDR(); };

S4_MEMBER( 005864A0 )
S4_MEMBER( 005879C0 )

S4_BASE( 009A1A40 )

#define S4_TWO_MEMBER_DTOR( NAME, BASE, FIRST, SECOND, OFF1, OFF2 )            \
	struct S4Dtor##NAME : S4Base##BASE                                         \
	{                                                                          \
		char m_padA[ ( OFF1 ) - 4 ];                                           \
		S4Mem##FIRST m_first;                                                  \
		char m_padB[ ( OFF2 ) - ( OFF1 ) - 1 ];                                \
		S4Mem##SECOND m_second;                                                \
		virtual ~S4Dtor##NAME();                                               \
	};                                                                         \
	S4Dtor##NAME::~S4Dtor##NAME()                                              \
	{                                                                          \
	}

// ??1S4Dtor00587B30@@UAE@XZ
S4_TWO_MEMBER_DTOR( 00587B30, 009A1A40, 005864A0, 005879C0, 0x20, 0x24 )
