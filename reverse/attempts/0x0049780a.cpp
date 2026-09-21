// ??0BattlePlanUpdateModuleData@@QAE@XZ
// partial score=0.88 date=2026-09-21
// cl: /O1 /arch:SSE /DNDEBUG /MD /EHsc

// ??0BattlePlanUpdateModuleData@@QAE@XZ at retail 0x0049780A (153 bytes).
// The module-data half of BattlePlanUpdate: vtable immediate 0x00C4FB00
// modelled as an explicit first member (DemoTrapUpdateModuleDataCtor
// precedent, so no vtable is emitted and no dtor row is owed), 19 zeroed
// scalar slots at +0x08..+0x50, the ValidMemberKindOf/InvalidMemberKindOf
// masks at +0x54/+0x70 constructed through the shared 0x1C-byte memset helper
// pinned at 0x24C7B3 (Rva0024C7B3Member spelling reused, the pin claims only
// the address), then the strategy-center scalars: three 1.0f reals, the
// detects-stealth flag, max-health scalar, max-health-change-type and the
// vision name. Init-list order is load-bearing and follows retail (vtable,
// zeros, member constructions); the body holds the trailing scalars. Field
// identity is retail's own INI table at 0x00C4FF58 joined to the BFME1
// BattlePlanUpdate donor (BombardmentPlan/HoldTheLinePlan/
// SearchAndDestroyPlan times, TransitionIdleTime, unpack/pack/message/
// announcement names, ValidMember/InvalidMemberKindOf, paralyze time,
// armor/sight scalars, strategy-center scalars, VisionObjectName). The 13
// unpack/pack/message/announcement slots are zeroed dwords retail never
// constructs, so they are modelled as name pointers (NULL) rather than the
// donor's AsciiString: target evidence over donor provenance.
class Rva0024C7B3Member
{
public:
	Rva0024C7B3Member();
	unsigned char m_data[0x1C];
};

inline void *operator new(unsigned int, void *place) { return place; }

class BattlePlanUpdateModuleData
{
public:
	BattlePlanUpdateModuleData();

private:
	const void *m_vtable;							// +0x00
	unsigned int m_unused04;						// +0x04 retail never stores
	const void *m_specialPowerTemplate;				// +0x08
	unsigned int m_bombardmentPlanAnimationFrames;	// +0x0C
	unsigned int m_holdTheLinePlanAnimationFrames;	// +0x10
	unsigned int m_searchAndDestroyPlanAnimationFrames; // +0x14
	unsigned int m_transitionIdleFrames;			// +0x18
	const char *m_bombardmentUnpackName;			// +0x1C
	const char *m_bombardmentPackName;				// +0x20
	const char *m_bombardmentMessageLabel;			// +0x24
	const char *m_bombardmentAnnouncementName;		// +0x28
	const char *m_searchAndDestroyUnpackName;		// +0x2C
	const char *m_searchAndDestroyIdleName;			// +0x30
	const char *m_searchAndDestroyPackName;			// +0x34
	const char *m_searchAndDestroyMessageLabel;		// +0x38
	const char *m_searchAndDestroyAnnouncementName;	// +0x3C
	const char *m_holdTheLineUnpackName;			// +0x40
	const char *m_holdTheLinePackName;				// +0x44
	const char *m_holdTheLineMessageLabel;			// +0x48
	const char *m_holdTheLineAnnouncementName;		// +0x4C
	unsigned int m_battlePlanParalyzeFrames;		// +0x50
	Rva0024C7B3Member m_validMemberKindOf;			// +0x54
	Rva0024C7B3Member m_invalidMemberKindOf;		// +0x70
	float m_holdTheLineArmorDamageScalar;			// +0x8C
	float m_searchAndDestroySightRangeScalar;		// +0x90
	float m_strategyCenterSearchAndDestroySightRangeScalar; // +0x94
	bool m_strategyCenterSearchAndDestroyDetectsStealth; // +0x98
	float m_strategyCenterHoldTheLineMaxHealthScalar; // +0x9C
	int m_strategyCenterHoldTheLineMaxHealthChangeType; // +0xA0 (PRESERVE_RATIO == 1)
	const char *m_visionObjectName;					// +0xA4
};

BattlePlanUpdateModuleData::BattlePlanUpdateModuleData()
	: m_vtable( reinterpret_cast<const void *>(0x00C4FB00) )
	, m_specialPowerTemplate( 0 )
	, m_bombardmentPlanAnimationFrames( 0 )
	, m_holdTheLinePlanAnimationFrames( 0 )
	, m_searchAndDestroyPlanAnimationFrames( 0 )
	, m_transitionIdleFrames( 0 )
	, m_bombardmentUnpackName( 0 )
	, m_bombardmentPackName( 0 )
	, m_bombardmentMessageLabel( 0 )
	, m_bombardmentAnnouncementName( 0 )
	, m_searchAndDestroyUnpackName( 0 )
	, m_searchAndDestroyIdleName( 0 )
	, m_searchAndDestroyPackName( 0 )
	, m_searchAndDestroyMessageLabel( 0 )
	, m_searchAndDestroyAnnouncementName( 0 )
	, m_holdTheLineUnpackName( 0 )
	, m_holdTheLinePackName( 0 )
	, m_holdTheLineMessageLabel( 0 )
	, m_holdTheLineAnnouncementName( 0 )
	, m_battlePlanParalyzeFrames( 0 )
	, m_validMemberKindOf()
	, m_invalidMemberKindOf()
{
	m_holdTheLineArmorDamageScalar = 1.0f;
	m_searchAndDestroySightRangeScalar = 1.0f;
	m_strategyCenterSearchAndDestroySightRangeScalar = 1.0f;
	m_strategyCenterSearchAndDestroyDetectsStealth = true;
	m_strategyCenterHoldTheLineMaxHealthScalar = 1.0f;
	m_strategyCenterHoldTheLineMaxHealthChangeType = 1;
	m_visionObjectName = 0;
}
