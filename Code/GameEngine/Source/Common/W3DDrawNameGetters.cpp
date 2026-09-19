// W3D draw/buffer literal name getters: six-byte const members with one shape
// (mov eax,<offset string literal> / ret). Same shape and verbatim
// BFME_LITERAL_NAME_GETTER macro as
// Code/GameEngine/Source/Common/SubsystemNameGetters.cpp (BFME1
// LiteralNameGetters_01 port); kept as its own unit to keep concurrent
// contributors conflict-free. Each body returns a pointer to a
// NUL-terminated class-name string in .rdata with exactly one vtable (body-VA)
// reference behind a C3 predecessor; verify_string_refs re-reads the string.
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

BFME_LITERAL_NAME_GETTER(Rva000B2214Named, "W3DDefaultDraw")
BFME_LITERAL_NAME_GETTER(Rva000CA83BNamed, "W3DRopeDraw")
BFME_LITERAL_NAME_GETTER(Rva000CAEC0Named, "W3DSupplyDraw")
BFME_LITERAL_NAME_GETTER(Rva000CB5BDNamed, "W3DTruckDraw")
BFME_LITERAL_NAME_GETTER(Rva000CEA33Named, "W3DTankDraw")
BFME_LITERAL_NAME_GETTER(Rva000D0046Named, "W3DStreakDraw")
BFME_LITERAL_NAME_GETTER(Rva000D0810Named, "W3DSailModelDraw")
BFME_LITERAL_NAME_GETTER(Rva000E5A25Named, "W3DFloorBuffer")
BFME_LITERAL_NAME_GETTER(Rva000E6B93Named, "W3DVegetationBufferBase")
BFME_LITERAL_NAME_GETTER(Rva000E9C0FNamed, "W3DShrubBuffer")
BFME_LITERAL_NAME_GETTER(Rva000EDB39Named, "W3DTreeBuffer")
BFME_LITERAL_NAME_GETTER(Rva000EEFE6Named, "W3DPropBuffer")
BFME_LITERAL_NAME_GETTER(Rva000CEB69Named, "W3DTreeDraw")
BFME_LITERAL_NAME_GETTER(Rva000CEE01Named, "W3DBuffDraw")
BFME_LITERAL_NAME_GETTER(Rva000CEEE0Named, "W3DPropDraw")
BFME_LITERAL_NAME_GETTER(Rva000CF14FNamed, "W3DFloorDraw")
BFME_LITERAL_NAME_GETTER(Rva000CFA3CNamed, "W3DLightDraw")
BFME_LITERAL_NAME_GETTER(Rva000D0B63Named, "W3DBoatWakeModelDraw")
BFME_LITERAL_NAME_GETTER(Rva000D1401Named, "W3DProjectileStreamDraw")
BFME_LITERAL_NAME_GETTER(Rva000D1860Named, "W3DTornadoDraw")
BFME_LITERAL_NAME_GETTER(Rva000D1BA0Named, "TBuff")
BFME_LITERAL_NAME_GETTER(Rva00062AF1Named, "W3DTerrainLogic")
BFME_LITERAL_NAME_GETTER(Rva00063415Named, "W3DGhostObject")
BFME_LITERAL_NAME_GETTER(Rva000C1246Named, "W3DScriptedModelDraw")
BFME_LITERAL_NAME_GETTER(Rva000C9C11Named, "W3DLaserDraw")
