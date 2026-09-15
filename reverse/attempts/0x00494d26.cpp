// ??0DozerAIUpdateModuleData@@QAE@XZ
// partial score=0.9 date=2026-09-14
// cl: /O1 /MD -D_STLP_NO_EXCEPTIONS /EHs-c-
// stlport
//
// ??0DozerAIUpdateModuleData@@QAE@XZ, retail 0x00494D26, 58 bytes.
// Dedicated thunk TU: the class TU builds under /G7 (add-mem), but retail
// uses and-zero stores (/O1). Base AIUpdateModuleData ctor pinned at
// 0x58925D. Derived vtable 0xC4EA88 overwrites base. The bitset lives at
// +0x24 (not +0x10); the trailing memset(&m_bitset, 0, 16) zeroes the
// bitset and the three INI-parsed floats, so retail has no float stores.
// Retail CALLS bitset<8>::reset (ledger row at 0x24CA24) instead of
// inlining it, so the member is explicitly specialized non-inline here.

#include <bitset>
#include <string.h>

namespace _STL {
template<> bitset<8> &bitset<8>::reset();
}

class AIUpdateModuleData
{
public:
	AIUpdateModuleData();

	unsigned char _pad[0x14];
	int m_base18;
	int m_base1C;
	int m_base20;
};

class DozerAIUpdateModuleData : public AIUpdateModuleData
{
public:
	DozerAIUpdateModuleData();
	virtual ~DozerAIUpdateModuleData();

	// _STL::bitset<8> storage as a plain word: retail constructs the
	// member trivially (no inline zeroing) and calls the out-of-line
	// reset body, so the word is held directly and viewed as a bitset
	// only for the reset call below.
	unsigned long m_bitsetWord;
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
	((_STL::bitset<8> *)&m_bitsetWord)->reset();
	memset(&m_bitsetWord, 0, 16);
}

// NOTE 2026-09-14 (HealContain landing): the reset call in this body targets
// the ledger row ?reset@?$bitset@$0IA@@_STL@@ (0x24CA24), and $0IA decodes
// to 128 (cf. ATL CW2AEX<128>), so the member is bitset<128> (16 bytes),
// not bitset<8>. The member-spec and word member in the banked body above
// must move to bitset<128> / unsigned long[4] before the reset REL32 will
// resolve; the vtable-first scheduling gap described above still stands.
