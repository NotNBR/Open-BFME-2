// ??0DevastateSpecialPowerModuleData@@QAE@XZ
// partial score=0.75 date=2026-09-21
// cl: /O1 /MD /GX /arch:SSE /DNDEBUG
//
// ??0DevastateSpecialPowerModuleData@@QAE@XZ, retail 0x004C84BD (94 bytes):
// SpecialPower-side ModuleData for the Devastate (earthquake) power. The
// table at 0x00C5E3D0 (Radius, FX, TreeValueMultiplier, TreeValueTotalCap,
// FireWeapon at +0x7C through +0x8C) sizes the class at 0x90 bytes over a
// 0x7C-byte base built by the out-of-line 0x004930A0 constructor (pinned as
// Rva004930A0, shared with DeliverPayload/AIUpdateInterface ctors). The base
// carries the vtable slot at +0, re-installed here as 0x00C5E518.
// FireWeapon defaults to the empty string through the rowed StringBase
// const-char constructor at 0x37BA0; the member's declared (pinned 0x36410)
// destructor is the TU's sole unwindable, which is what arms retail's EH
// frame with its single state-0 store (HordeContainUnitSlot precedent for
// the TU-local StringBase idiom).

class Rva004930A0
{
public:
	Rva004930A0();
	~Rva004930A0() {}

protected:
	void *m_vtable;

private:
	unsigned char m_pad[0x78];
};

template<class T> class StringBase {
	void *m_data;
	StringBase(const T *);
	~StringBase();
	friend class DevastateSpecialPowerModuleData;
};

class DevastateSpecialPowerModuleData : public Rva004930A0
{
public:
	DevastateSpecialPowerModuleData();

private:
	float m_radius;
	void *m_fx;
	float m_treeValueMultiplier;
	float m_treeValueTotalCap;
	StringBase<char> m_fireWeapon;
};

// ??0DevastateSpecialPowerModuleData@@QAE@XZ
DevastateSpecialPowerModuleData::DevastateSpecialPowerModuleData()
	: Rva004930A0()
	, m_fx(0)
	, m_radius(0.0f)
	, m_treeValueMultiplier(0.0f)
	, m_treeValueTotalCap(0.0f)
	, m_fireWeapon("")
{
	m_vtable = reinterpret_cast<void *>(0x00C5E518);
}
