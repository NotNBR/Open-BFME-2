// ??0CrateCollideModuleData@@QAE@XZ
// partial score=0.82 date=2026-09-21
// cl: /O1 /arch:SSE /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS

// ??0CrateCollideModuleData@@QAE@XZ at retail 0x004BC657 (cycles: the two
// 0x1C mask members construct through the shared memset helper pinned at
// 0x24C7B3, vtable immediate 0x00C5A660 modelled as an explicit first member
// so no vtable is emitted and no dtor row is owed). Field identity is
// retail's own INI table at 0x00C5A7A8 (landed buildFieldParse row) joined to
// the Zero Hour CrateCollide.cpp donor (m_isForbidOwnerPlayer,
// m_isBuildingPickup, m_isHumanOnlyPickup, m_pickupScience = SCIENCE_INVALID,
// m_executeFX, m_executionAnimationTemplate = TheEmptyString, the two display
// reals, m_executeAnimationFades). V1: donor init-list order; retail order
// check decides the body/init split.
class Rva0024C7B3Member
{
public:
	Rva0024C7B3Member();
	unsigned char m_data[0x1C];
};

class AsciiString
{
public:
	AsciiString() : m_data(0) {}
	AsciiString(const AsciiString &that) throw();
	~AsciiString();

private:
	void *m_data;
};

extern const AsciiString TheEmptyString;

// Retail inits the pickup-science slot with `or [esi+0x44],-1` (a
// read-modify-write of the fresh slot) ahead of the template copy below. An
// init-listed int can only emit `mov`, and a body `|=` sorts after the copy
// call, so the slot is modelled as a TU-local holder whose inline default
// ctor performs the `|=`; init-listed in declaration order it reproduces the
// RMW in position with no extra code. (Zero Hour spells the field
// ScienceType m_pickupScience = SCIENCE_INVALID; the RMW is this toolchain's
// shape for the same default.)
struct InvalidScienceDefault
{
	InvalidScienceDefault() { m_value |= -1; }
	int m_value;
};

class CollideModuleData
{
public:
	CollideModuleData() {}
	~CollideModuleData();

private:
};

class CrateCollideModuleData : public CollideModuleData
{
public:
	CrateCollideModuleData();

private:
	const void *m_vtable;				// +0x00
	unsigned int m_unused04;				// +0x04
	Rva0024C7B3Member m_kindof;			// +0x08
	Rva0024C7B3Member m_kindofnot;			// +0x24
	bool m_isForbidOwnerPlayer;			// +0x40
	bool m_isBuildingPickup;			// +0x41
	bool m_isHumanOnlyPickup;			// +0x42
	InvalidScienceDefault m_pickupScience;		// +0x44
	void *m_executeFX;				// +0x48
	AsciiString m_executionAnimationTemplate;	// +0x4C
	float m_executeAnimationDisplayTimeInSeconds;	// +0x50
	float m_executeAnimationZRisePerSecond;		// +0x54
	bool m_executeAnimationFades;			// +0x58
};

CrateCollideModuleData::CrateCollideModuleData()
	: m_vtable(reinterpret_cast<const void *>(0x00C5A660))
	, m_kindof()
	, m_kindofnot()
	, m_pickupScience()
	, m_executionAnimationTemplate(TheEmptyString)
{
	m_executeAnimationDisplayTimeInSeconds = 0.0f;
	m_executeAnimationZRisePerSecond = 0.0f;
	m_executeAnimationFades = true;
	m_isForbidOwnerPlayer = false;
	m_isBuildingPickup = false;
	m_isHumanOnlyPickup = false;
	m_executeFX = 0;
}
