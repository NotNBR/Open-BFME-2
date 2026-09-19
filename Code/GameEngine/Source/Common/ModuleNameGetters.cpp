// Module literal name getters: six-byte const members with one shape:
//
//     mov eax,<offset string literal> / ret
//
// Each body returns a pointer to a NUL-terminated Behavior/Update/Contain
// class-name string in .rdata. Each body VA carries exactly one .rdata
// reference from its module vtable (descriptor tail closed by the shared
// 0x004B3FD0 pair -- the same family marker as the Subsystem getters).
// Split from Code/GameEngine/Source/Common/SubsystemNameGetters.cpp into a
// contributor-local unit to keep concurrent landings conflict-free; the
// BFME_LITERAL_NAME_GETTER macro is verbatim, only the class names follow
// this tree's address-derived convention (identity unrecoverable from 6
// bytes, string carried in source where verify_string_refs re-reads it).
// No // cl: line (defaults match the frameless 6-byte shape).

#define BFME_LITERAL_NAME_GETTER(NAME, TEXT) \
	class NAME \
	{ \
	public: \
		const char *name() const; \
	}; \
	const char *NAME::name() const \
	{ \
		return TEXT; \
	}

BFME_LITERAL_NAME_GETTER(Rva0058A171Named, "DockUpdate")
BFME_LITERAL_NAME_GETTER(Rva0052BA04Named, "LWPlayerDef")
BFME_LITERAL_NAME_GETTER(Rva004FC55DNamed, "LivingWorldBuildPlot")
BFME_LITERAL_NAME_GETTER(Rva004F5BAANamed, "ResourceGatheringManager")
BFME_LITERAL_NAME_GETTER(Rva004F59ACNamed, "MissionStats")
BFME_LITERAL_NAME_GETTER(Rva004F5617Named, "TunnelTracker")
BFME_LITERAL_NAME_GETTER(Rva004F1116Named, "WorkOrder")
BFME_LITERAL_NAME_GETTER(Rva004EF600Named, "TeamInQueue")
BFME_LITERAL_NAME_GETTER(Rva004E4007Named, "ObjectivesMenu")
BFME_LITERAL_NAME_GETTER(Rva004DEA62Named, "FiringTracker")
BFME_LITERAL_NAME_GETTER(Rva004D86BBNamed, "TurretAI")
BFME_LITERAL_NAME_GETTER(Rva004D73F6Named, "SleepState")
BFME_LITERAL_NAME_GETTER(Rva004D73F0Named, "ContinueState")
BFME_LITERAL_NAME_GETTER(Rva004D73EANamed, "FailureState")
BFME_LITERAL_NAME_GETTER(Rva004C9E19Named, "AnimationSoundClientBehavior")
BFME_LITERAL_NAME_GETTER(Rva004C5013Named, "GrabPassengerSpecialPower")
BFME_LITERAL_NAME_GETTER(Rva004BF88DNamed, "ActiveBody")
BFME_LITERAL_NAME_GETTER(Rva004BB6FCNamed, "FireWeaponCollide")
