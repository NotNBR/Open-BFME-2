// ??0DozerAIUpdateModuleData@@QAE@XZ
// partial score=0.93 date=2026-09-20
// cl: /O1 /MD -D_STLP_NO_EXCEPTIONS /EHs-c-
// stlport
//
// ??0DozerAIUpdateModuleData@@QAE@XZ at retail 0x00494D26 (58 bytes).
// Dedicated thunk TU: the class TU (DozerAIUpdate.cpp) builds the donor
// float-zeroing shape under its own flags, but retail uses and-zero
// stores (/O1) for the inherited +0x18/+0x1C slots and a plain 5 for
// +0x20. Base AIUpdateModuleData ctor pinned at 0x58925D; the derived
// vtable overwrites the base one. The flag set at +0x24 is a 16-byte
// bitset<128>: retail constructs it trivially (no inline zeroing) and
// calls the out-of-line reset body rowed at 0x24CA24, so the words are
// held directly and viewed as a bitset only for the reset call. The
// trailing 16-byte memset clears the same words through the _memset
// import thunk at 0x6291AE. The three INI-parsed floats keep their donor
// names for layout but retail leaves them uninitialized.

#include <bitset>
#include <string.h>

namespace _STL {
template<> bitset<128> &bitset<128>::reset();
}

class AIUpdateModuleData
{
public:
	AIUpdateModuleData();
	virtual ~AIUpdateModuleData();

	unsigned char _pad[0x14];
	int m_base18;
	int m_base1C;
	int m_base20;
};

class DozerAIUpdateModuleData : public AIUpdateModuleData
{
public:
	DozerAIUpdateModuleData();

	// bitset<128> storage as plain words: retail constructs the member
	// trivially and calls the out-of-line reset body, then memsets the
	// same 16 bytes.
	unsigned long m_bitsetWord[4];
	float m_repairHealthPercentPerSecond;
	float m_boredTime;
	float m_boredRange;
};

// ??0DozerAIUpdateModuleData@@QAE@XZ
DozerAIUpdateModuleData::DozerAIUpdateModuleData() : AIUpdateModuleData()
{
	// RMW spelling: retail emits and-zero stores, and the compound form
	// keeps the two clears anchored where the scheduler expects them.
	m_base18 &= 0;
	m_base1C &= 0;
	m_base20 = 5;
	((_STL::bitset<128> *)m_bitsetWord)->reset();
	memset(m_bitsetWord, 0, 16);
}
