// Byte one-setters: eight-byte __thiscall members with one shape:
//
//     mov byte ptr [ecx+<DISP>],1 / ret
//
// One byte at a fixed displacement from `this` is set to 1 and nothing is
// read back. Ported from Open-BFME-1's RvaB7F70Offset8ByteOneSetterThunk
// pattern (`void enable() { enabled = 1; }`); only the class names follow
// this tree's Disp* convention (address-derived Rva<addr>ByteOneSetter,
// identity unrecoverable from 8 bytes). Every displacement here is a disp32
// (MSVC 7.1 uses disp8 whenever the offset fits, so every offset is at
// least 0x80).
// No // cl: line (defaults match the frameless 8-byte shape).
class Rva00042F57ByteOneSetter
{
public:
	void enable();

	char m_lead[0x145];
	unsigned char m_enabled;
};

void Rva00042F57ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva00042F5FByteOneSetter
{
public:
	void enable();

	char m_lead[0x146];
	unsigned char m_enabled;
};

void Rva00042F5FByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva000203AD5ByteOneSetter
{
public:
	void enable();

	char m_lead[0x1A4D4];
	unsigned char m_enabled;
};

void Rva000203AD5ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva000203ADDByteZeroSetter
{
public:
	void disable();

	char m_lead[0x1A4D4];
	unsigned char m_enabled;
};

void Rva000203ADDByteZeroSetter::disable()
{
	m_enabled = 0;
}
