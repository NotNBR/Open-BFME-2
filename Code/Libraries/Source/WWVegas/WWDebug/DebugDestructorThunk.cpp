// cl: /DNDEBUG /MD /EHa /Oy-
// ??1Debug@@UAE@XZ, retail 0x00038710 (66B).
// Ported from Open-BFME-1 Code/Libraries/Source/WWVegas/WWDebug/DebugDestructorThunk.cpp
// (BFME1 0x00889620). Debug destructor: store the Debug vtable then destroy the
// member at +0x9E7B. The donor reads it at +0x9E6F; retail's addend is 0x9E7B,
// so the pad is 12 bytes wider here and the bytes decide. The donor also defines the member destructor,
// which the sweep did not place here, so it stays declared-only and the call
// routes through the ledger pin.

class DebugMember
{
public:
	~DebugMember();
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug/debug_debug.h
class Debug
{
public:
	virtual ~Debug();
	char m_pad[0x9E77];
	DebugMember m_member;
};

// ??1Debug@@UAE@XZ
Debug::~Debug()
{
}
