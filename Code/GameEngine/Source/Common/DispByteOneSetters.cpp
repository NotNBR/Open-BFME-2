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

class Rva0033F971ByteOneSetter
{
public:
	void enable();

	char m_lead[0x3C6];
	unsigned char m_enabled;
};

void Rva0033F971ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva0033F979ByteZeroSetter
{
public:
	void disable();

	char m_lead[0x3C6];
	unsigned char m_enabled;
};

void Rva0033F979ByteZeroSetter::disable()
{
	m_enabled = 0;
}

class Rva0041FDDEByteZeroSetter
{
public:
	void disable();

	char m_lead[0x140];
	unsigned char m_enabled;
};

void Rva0041FDDEByteZeroSetter::disable()
{
	m_enabled = 0;
}

class Rva0041FDE6ByteOneSetter
{
public:
	void enable();

	char m_lead[0x140];
	unsigned char m_enabled;
};

void Rva0041FDE6ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva0004CB16ByteOneSetter
{
public:
	void enable();

	char m_lead[0xA8];
	unsigned char m_enabled;
};

void Rva0004CB16ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva0005116BByteOneSetter
{
public:
	void enable();

	char m_lead[0x6AB];
	unsigned char m_enabled;
};

void Rva0005116BByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva000515ABByteOneSetter
{
public:
	void enable();

	char m_lead[0x6AC];
	unsigned char m_enabled;
};

void Rva000515ABByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva00066517ByteOneSetter
{
public:
	void enable();

	char m_lead[0xD7B5];
	unsigned char m_enabled;
};

void Rva00066517ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva0007DEAFByteOneSetter
{
public:
	void enable();

	char m_lead[0xA0];
	unsigned char m_enabled;
};

void Rva0007DEAFByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva0008BC93ByteOneSetter
{
public:
	void enable();

	char m_lead[0x23D0];
	unsigned char m_enabled;
};

void Rva0008BC93ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva000B2B33ByteOneSetter
{
public:
	void enable();

	char m_lead[0x131C];
	unsigned char m_enabled;
};

void Rva000B2B33ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva000B380CByteOneSetter
{
public:
	void enable();

	char m_lead[0x94];
	unsigned char m_enabled;
};

void Rva000B380CByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva000E0F16ByteOneSetter
{
public:
	void enable();

	char m_lead[0x4FB6D];
	unsigned char m_enabled;
};

void Rva000E0F16ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva000E9C15ByteOneSetter
{
public:
	void enable();

	char m_lead[0x4FB5C];
	unsigned char m_enabled;
};

void Rva000E9C15ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva000EDB3FByteOneSetter
{
public:
	void enable();

	char m_lead[0x44544];
	unsigned char m_enabled;
};

void Rva000EDB3FByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva001EADF7ByteOneSetter
{
public:
	void enable();

	char m_lead[0xC1];
	unsigned char m_enabled;
};

void Rva001EADF7ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva001F3852ByteOneSetter
{
public:
	void enable();

	char m_lead[0x1A3];
	unsigned char m_enabled;
};

void Rva001F3852ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva00203BE1ByteOneSetter
{
public:
	void enable();

	char m_lead[0x1A4D7];
	unsigned char m_enabled;
};

void Rva00203BE1ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva00222479ByteOneSetter
{
public:
	void enable();

	char m_lead[0x310];
	unsigned char m_enabled;
};

void Rva00222479ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva00238D7BByteOneSetter
{
public:
	void enable();

	char m_lead[0x114];
	unsigned char m_enabled;
};

void Rva00238D7BByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva0023CF83ByteOneSetter
{
public:
	void enable();

	char m_lead[0x150];
	unsigned char m_enabled;
};

void Rva0023CF83ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva0025C0F7ByteOneSetter
{
public:
	void enable();

	char m_lead[0x10C];
	unsigned char m_enabled;
};

void Rva0025C0F7ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva002A87F1ByteOneSetter
{
public:
	void enable();

	char m_lead[0x168];
	unsigned char m_enabled;
};

void Rva002A87F1ByteOneSetter::enable()
{
	m_enabled = 1;
}

class Rva00406D5FByteOneSetter
{
public:
	void enable();

	char m_lead[0x1D8];
	unsigned char m_enabled;
};

void Rva00406D5FByteOneSetter::enable()
{
	m_enabled = 1;
}
