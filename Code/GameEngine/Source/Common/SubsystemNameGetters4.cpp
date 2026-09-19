// Subsystem literal name getters, fourth unit: six-byte const members with one
// shape (mov eax,<offset string literal> / ret). Split to keep concurrent
// contributors conflict-free; the BFME_LITERAL_NAME_GETTER macro is verbatim.
// Each body returns a pointer to a NUL-terminated class-name string in .rdata
// with exactly one vtable (body-VA) reference behind a C3 predecessor;
// verify_string_refs re-reads the string.
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

BFME_LITERAL_NAME_GETTER(Rva00271892Named, "TintEnvelope")
BFME_LITERAL_NAME_GETTER(Rva002B6476Named, "RegionAwardDispute")
BFME_LITERAL_NAME_GETTER(Rva0033F517Named, "AIAttackSquadState")
BFME_LITERAL_NAME_GETTER(Rva0033FB6DNamed, "AttackHordeStateMachine")
BFME_LITERAL_NAME_GETTER(Rva0033FC04Named, "AttackPositionHordeStateMachine")
BFME_LITERAL_NAME_GETTER(Rva00340C27Named, "AIAttackMeleeEngageState")
BFME_LITERAL_NAME_GETTER(Rva00340D6ANamed, "AIFollowPathAsTeamState")
BFME_LITERAL_NAME_GETTER(Rva00345CFANamed, "AIAttackMoveToState")
BFME_LITERAL_NAME_GETTER(Rva00345F70Named, "AIAttackFollowWaypointPathState")
BFME_LITERAL_NAME_GETTER(Rva0034B172Named, "AIAttackState")
BFME_LITERAL_NAME_GETTER(Rva00354EF6Named, "AiOrdersManager")
