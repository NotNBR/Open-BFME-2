// Disp0 dword immediate setters: seven-byte __thiscall members with one shape:
//
//     mov dword ptr [ecx],<IMM32> / ret
//
// The dword at `this` itself is set to a hardcoded immediate and nothing is
// read back. The zero-displacement member of the disp8 family
// (Disp8DwordImmSetters.cpp) and the disp32 family
// (DispDwordImmSetters.cpp); MSVC 7.1 uses the C7-01 form when the offset is
// zero, so there is no lead array. Only the class names follow this tree's
// Disp* convention (address-derived Rva<addr>DwordImmSetter, identity
// unrecoverable from 7 bytes). Retail cleans none (`ret`, not `ret 4`), so
// the members take no parameters.
// No // cl: line (defaults match the frameless 7-byte shape).
class Rva00238D97DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00238D97DwordImmSetter::apply()
{
	m_value = 0xBED658;
}
