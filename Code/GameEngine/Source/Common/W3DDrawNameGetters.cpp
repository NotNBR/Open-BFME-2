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
