// cl: /O1 /GX /arch:SSE /DNDEBUG /MD
//
// ??0SpecialEnemySenseUpdateModuleData@@QAE@XZ, retail 0x0025404A, 65 bytes.
// EH ctor: single state-0 store, vtable 0x00BF1AD8 at +0, filter member at
// +8 built by the pinned nullary ctor, 0.0f at +0xC, 1 at +0x10. Table
// 0xBF1B88 holds SpecialEnemyFilter@8 ScanRange@C ScanInterval@10; factory
// 0x25409C news 0x14; ctor ends where the 17B proc begins. InheritUpgrade
// V4 recipe verbatim: empty CreateModuleData base as the sole unwindable
// (state 0, no transitions, no -1) plus body in retail order with the
// filter driven by the construct-method alias pin.

class Rva003623E5Member
{
public:
	void construct();

private:
	int m_value;
};

class CreateModuleData
{
public:
	CreateModuleData() {}
	~CreateModuleData();

private:
};

class SpecialEnemySenseUpdateModuleData : public CreateModuleData
{
public:
	SpecialEnemySenseUpdateModuleData();

private:
	void *m_vtable;
	unsigned int m_unused04;
	Rva003623E5Member m_filter;
	float m_scanRange;
	int m_scanInterval;
};

// ??0SpecialEnemySenseUpdateModuleData@@QAE@XZ
SpecialEnemySenseUpdateModuleData::SpecialEnemySenseUpdateModuleData()
{
	m_vtable = reinterpret_cast<void *>(0x00BF1AD8);
	m_filter.construct();
	m_scanRange = 0.0f;
	m_scanInterval = 1;
}
