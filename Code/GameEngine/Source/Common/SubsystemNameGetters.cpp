// Subsystem literal name getters: six-byte const members with one shape:
//
//     mov eax,<offset string literal> / ret
//
// Each body returns a pointer to a NUL-terminated class-name string in
// .rdata. The vtable at each site carries the body at slot 2 (offset 8)
// behind a shared pair (slot 0 varies, slot 1 is 0xA9E440) and ahead of
// class-specific tails, closed by 0x5B5384 -- the Subsystem/Snapshot family
// pattern. Ported from Open-BFME-1
// (Code/GameEngine/Source/Common/LiteralNameGetters_01.cpp): the
// BFME_LITERAL_NAME_GETTER macro is verbatim; only the class names follow
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

BFME_LITERAL_NAME_GETTER(Rva006254A0Named, "PartitionManager")
BFME_LITERAL_NAME_GETTER(Rva00065212Named, "ModuleData")
BFME_LITERAL_NAME_GETTER(Rva00041FC9Named, "GameLogic")
BFME_LITERAL_NAME_GETTER(Rva000420D6Named, "ModuleFactory")
BFME_LITERAL_NAME_GETTER(Rva0004C457Named, "GameClient")
BFME_LITERAL_NAME_GETTER(Rva0004CE28Named, "FXParticleSystemManager")
BFME_LITERAL_NAME_GETTER(Rva0004FA11Named, "Radar")
BFME_LITERAL_NAME_GETTER(Rva00063531Named, "W3DGhostObjectManager")
BFME_LITERAL_NAME_GETTER(Rva000647CENamed, "W3DBuffLogic")
BFME_LITERAL_NAME_GETTER(Rva000665B9Named, "TScorch")
BFME_LITERAL_NAME_GETTER(Rva0006CE6BNamed, "UNNAMED")
