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

class Rva002B228DDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva002B228DDwordImmSetter::apply()
{
	m_value = 0x00BFDF8C;
}

class Rva002B2294DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva002B2294DwordImmSetter::apply()
{
	m_value = 0x00C77F44;
}

class Rva0007DEA1DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0007DEA1DwordImmSetter::apply()
{
	m_value = 0x00BC6EEC;
}

class Rva0007DEA8DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0007DEA8DwordImmSetter::apply()
{
	m_value = 0x00BC6F04;
}

class Rva0007DE9ADwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0007DE9ADwordImmSetter::apply()
{
	m_value = 0x00BC6EC0;
}

class Rva004EDFF8DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva004EDFF8DwordImmSetter::apply()
{
	m_value = 0x00C62A14;
}

class Rva004EDFFFDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva004EDFFFDwordImmSetter::apply()
{
	m_value = 0x00C62A20;
}

class Rva004EE006DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva004EE006DwordImmSetter::apply()
{
	m_value = 0x00BC6F34;
}

class Rva0057428CDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0057428CDwordImmSetter::apply()
{
	m_value = 0x00C6E350;
}

class Rva00574293DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00574293DwordImmSetter::apply()
{
	m_value = 0x00C6E360;
}

class Rva0057A235DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0057A235DwordImmSetter::apply()
{
	m_value = 0x00C6EE20;
}

class Rva0057A23CDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0057A23CDwordImmSetter::apply()
{
	m_value = 0x00C42518;
}

class Rva0057A243DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0057A243DwordImmSetter::apply()
{
	m_value = 0x00C6EE28;
}

class Rva005CF843DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva005CF843DwordImmSetter::apply()
{
	m_value = 0x00C75284;
}

class Rva005CF84ADwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva005CF84ADwordImmSetter::apply()
{
	m_value = 0x00C7528C;
}

class Rva005E3947DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva005E3947DwordImmSetter::apply()
{
	m_value = 0x00C79544;
}

class Rva005E394EDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva005E394EDwordImmSetter::apply()
{
	m_value = 0x00C77BE8;
}

class Rva000657ACDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva000657ACDwordImmSetter::apply()
{
	m_value = 0;
}

class Rva000723C0DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva000723C0DwordImmSetter::apply()
{
	m_value = 0x00BC64B0;
}

class Rva00072892DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00072892DwordImmSetter::apply()
{
	m_value = 0x00BC650C;
}

class Rva00078246DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00078246DwordImmSetter::apply()
{
	m_value = 0x00BC6730;
}

class Rva0008523ADwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0008523ADwordImmSetter::apply()
{
	m_value = 0x00BC745C;
}

class Rva000E14BDDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva000E14BDDwordImmSetter::apply()
{
	m_value = 0x00BC6F24;
}

class Rva000EF9CFDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva000EF9CFDwordImmSetter::apply()
{
	m_value = 0x00BCEF94;
}

class Rva00104D73DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00104D73DwordImmSetter::apply()
{
	m_value = 0x00BCF7E8;
}

class Rva00108B4DDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00108B4DDwordImmSetter::apply()
{
	m_value = 0x00BCEFA0;
}

class Rva0010EFCDDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0010EFCDDwordImmSetter::apply()
{
	m_value = 0x00BC5128;
}

class Rva0011647BDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0011647BDwordImmSetter::apply()
{
	m_value = 0x00BCFB24;
}

class Rva001A466CDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva001A466CDwordImmSetter::apply()
{
	m_value = 0x00BD6CB4;
}

class Rva001DBAC3DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva001DBAC3DwordImmSetter::apply()
{
	m_value = 0x00BDBC10;
}

class Rva0020E205DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0020E205DwordImmSetter::apply()
{
	m_value = 0x00BE4318;
}

class Rva00210CC5DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00210CC5DwordImmSetter::apply()
{
	m_value = 0x00BE5114;
}

class Rva00270158DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00270158DwordImmSetter::apply()
{
	m_value = 0x00BFAD38;
}

class Rva002A983DDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva002A983DDwordImmSetter::apply()
{
	m_value = 0x00BFDC30;
}

class Rva002BEDA4DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva002BEDA4DwordImmSetter::apply()
{
	m_value = 0x00BFE4EC;
}

class Rva002D24EFDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva002D24EFDwordImmSetter::apply()
{
	m_value = 0x00C02A58;
}

class Rva002D2507DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva002D2507DwordImmSetter::apply()
{
	m_value = 0x00C02A5C;
}

class Rva002D3354DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva002D3354DwordImmSetter::apply()
{
	m_value = 0x00C02A84;
}

class Rva0030D353DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0030D353DwordImmSetter::apply()
{
	m_value = 0x00C089EC;
}

class Rva00330440DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00330440DwordImmSetter::apply()
{
	m_value = 0x00C0DB24;
}

class Rva0037F4C9DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0037F4C9DwordImmSetter::apply()
{
	m_value = 0x00C18DFC;
}

class Rva00381D71DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00381D71DwordImmSetter::apply()
{
	m_value = 0x00C19230;
}

class Rva00388845DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00388845DwordImmSetter::apply()
{
	m_value = 0x00C1980C;
}

class Rva003916A4DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva003916A4DwordImmSetter::apply()
{
	m_value = 0x00C1A074;
}

class Rva003F3F7CDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva003F3F7CDwordImmSetter::apply()
{
	m_value = 0x00C3702C;
}

class Rva003F7BC5DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva003F7BC5DwordImmSetter::apply()
{
	m_value = 0x00C37298;
}

class Rva004059ACDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva004059ACDwordImmSetter::apply()
{
	m_value = 0x00BE5838;
}

class Rva004102A4DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva004102A4DwordImmSetter::apply()
{
	m_value = 0x00C3962C;
}

class Rva00468A3FDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00468A3FDwordImmSetter::apply()
{
	m_value = 0x00C44890;
}

class Rva004BDA05DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva004BDA05DwordImmSetter::apply()
{
	m_value = 0x00C5AEB0;
}

class Rva004CEE78DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva004CEE78DwordImmSetter::apply()
{
	m_value = 0x00C60130;
}

class Rva004D381BDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva004D381BDwordImmSetter::apply()
{
	m_value = 0x00C601DC;
}

class Rva004E1416DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva004E1416DwordImmSetter::apply()
{
	m_value = 0x00C618CC;
}

class Rva004E14E1DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva004E14E1DwordImmSetter::apply()
{
	m_value = 0x00C619A0;
}

class Rva000A8EC2DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva000A8EC2DwordImmSetter::apply()
{
	m_value = 0x00BC93C8;
}

class Rva000A8EEFDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva000A8EEFDwordImmSetter::apply()
{
	m_value = 0x00BC93DC;
}

class Rva00506B28DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00506B28DwordImmSetter::apply()
{
	m_value = 0x00C63F9C;
}

class Rva0052AF77DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0052AF77DwordImmSetter::apply()
{
	m_value = 0x00C37E18;
}

class Rva0054E796DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0054E796DwordImmSetter::apply()
{
	m_value = 0x00C6A894;
}

class Rva005676F4DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva005676F4DwordImmSetter::apply()
{
	m_value = 0x00C6CE84;
}

class Rva00596686DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00596686DwordImmSetter::apply()
{
	m_value = 0x00C70A5C;
}

class Rva0059EB3ADwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0059EB3ADwordImmSetter::apply()
{
	m_value = 0x00C711BC;
}

class Rva00019EC0DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00019EC0DwordImmSetter::apply()
{
	m_value = 0x00BBC8D4;
}

class Rva00035780DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00035780DwordImmSetter::apply()
{
	m_value = 0x00BE2B78;
}

class Rva000141C30DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva000141C30DwordImmSetter::apply()
{
	m_value = 0x00BD3338;
}

class Rva000176930DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva000176930DwordImmSetter::apply()
{
	m_value = 0x00BD4E24;
}

class Rva0005C6317DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0005C6317DwordImmSetter::apply()
{
	m_value = 0x00C74804;
}

class Rva0005CF81FDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0005CF81FDwordImmSetter::apply()
{
	m_value = 0x00C75278;
}

class Rva0005CF86BDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0005CF86BDwordImmSetter::apply()
{
	m_value = 0x00C75290;
}

class Rva0005D23FEDwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0005D23FEDwordImmSetter::apply()
{
	m_value = 0x00C078DC;
}

class Rva0003F320DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0003F320DwordImmSetter::apply()
{
	m_value = 0x00BC0990;
}

class Rva000724560DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva000724560DwordImmSetter::apply()
{
	m_value = 0x00CEFD60;
}

class Rva000724510DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva000724510DwordImmSetter::apply()
{
	m_value = 0x00BC650C;
}

class Rva0006C5930DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva0006C5930DwordImmSetter::apply()
{
	m_value = 0x00BBE7EC;
}

class Rva00066D580DwordImmSetter
{
public:
	void apply();

	unsigned int m_value;
};

void Rva00066D580DwordImmSetter::apply()
{
	m_value = 0x00CE3B38;
}
