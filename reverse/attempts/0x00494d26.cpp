// ??0DozerAIUpdateModuleData@@QAE@XZ
// partial score=0.86 date=2026-09-14
// cl: /O1 /MD -D_STLP_NO_EXCEPTIONS /EHs-c-
// stlport
//
// DozerAIUpdateModuleData ctor, retail 0x00494D26 (58 bytes).
// Dedicated TU. Base AIUpdateModuleData ctor pinned at 0x58925D;
// bitset reset resolves via the ledger; memset via import.
// Derived vtable 0xC4EA88 overwrites base.

#include <bitset>
#include <string.h>

class AIUpdateModuleData
{
public:
	AIUpdateModuleData();
	virtual ~AIUpdateModuleData();

	int m_base18;
	int m_base1C;
	int m_base20;
	_STL::bitset<8> m_bitset;
};

class DozerAIUpdateModuleData : public AIUpdateModuleData
{
public:
	DozerAIUpdateModuleData();

	float m_repairHealthPercentPerSecond;
	float m_boredTime;
	float m_boredRange;
};

// ??0DozerAIUpdateModuleData@@QAE@XZ
DozerAIUpdateModuleData::DozerAIUpdateModuleData() : AIUpdateModuleData()
{
	m_base18 = 0;
	m_base1C = 0;
	m_base20 = 5;
	m_bitset.reset();
	memset(&m_bitset, 0, 16);
}
