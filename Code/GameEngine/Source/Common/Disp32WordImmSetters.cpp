// Disp32 word immediate setters: ten-byte __thiscall members with one shape:
//
//     mov word ptr [ecx+<DISP>],<IMM16> / ret
//
// One word at a fixed disp32 displacement from `this` is set to a hardcoded
// immediate and nothing is read back. The disp32 mirror of the disp8 word
// family; MSVC 7.1 uses disp32 whenever the offset does not fit in a signed
// byte, so every offset here is at least 0x80. Members before the accessed
// one are spelled as a lead array because their types are not witnessed
// here, only their total size. Identity is not recovered: every name is
// derived from its address.
// No // cl: line (defaults match the frameless ten-byte shape).
class Rva0005159AWordSetter
{
public:
	void set();

	char m_lead[0x69C];
	unsigned short m_value;
};

void Rva0005159AWordSetter::set()
{
	m_value = 2;
}
