// cl: /GX-
// Scattered global dword getters, each `mov eax,[mem]; ret` (6B), ported from
// Open-BFME-1 Code/GameEngine/Source/Common/GlobalDwordGetters.cpp.
// Unlike the adjacent runs (Rva000752BDGetters etc.), these stand alone with
// ret/pad on both sides; each lands as its own row in this shared TU
// (dedicated per run would be eight files for one shape).

// ?Rva0001D1C0Get@@YAHXZ @ 0x0001D1C0 (6B) over 0x00DA6CC8.

extern int g_Va00DA6CC8;

int Rva0001D1C0Get(void)
{
	return g_Va00DA6CC8;
}

// ?Rva00020E80Get@@YAHXZ @ 0x00020E80 (6B) over 0x00DA7188.

extern int g_Va00DA7188;

int Rva00020E80Get(void)
{
	return g_Va00DA7188;
}

// ?Rva00020E90Get@@YAHXZ @ 0x00020E90 (6B) over 0x00DA718C.

extern int g_Va00DA718C;

int Rva00020E90Get(void)
{
	return g_Va00DA718C;
}

// ?Rva0003C0F0Get@@YAHXZ @ 0x0003C0F0 (6B) over 0x00DE08AC.

extern int g_Va00DE08AC;

int Rva0003C0F0Get(void)
{
	return g_Va00DE08AC;
}

// ?Rva0002BACFGet@@YAHXZ @ 0x0002BACF (6B) over 0x00DDF578.

extern int g_Va00DDF578;

int Rva0002BACFGet(void)
{
	return g_Va00DDF578;
}

// ?Rva0006E16FGet@@YAHXZ @ 0x0006E16F (6B) over 0x00DB5FA0.

extern int g_Va00DB5FA0;

int Rva0006E16FGet(void)
{
	return g_Va00DB5FA0;
}

// ?Rva000A8F36Get@@YAHXZ @ 0x000A8F36 (6B) over 0x00DB5FC8.

extern int g_Va00DB5FC8;

int Rva000A8F36Get(void)
{
	return g_Va00DB5FC8;
}

// ?Rva000EDF40Get@@YAHXZ @ 0x000EDF40 (6B) over 0x00DEDA24.

extern int g_Va00DEDA24;

int Rva000EDF40Get(void)
{
	return g_Va00DEDA24;
}

// ?Rva00171660Get@@YAHXZ @ 0x00171660 (6B) over 0x00DB5F90.

extern int g_Va00DB5F90;

int Rva00171660Get(void)
{
	return g_Va00DB5F90;
}

// ?Rva000B29C3Get@@YAHXZ @ 0x000B29C3 (6B) over 0x00DE1B40.

extern int g_Va00DE1B40;

int Rva000B29C3Get(void)
{
	return g_Va00DE1B40;
}

// ?Rva000B29C9Set@@YAXH@Z @ 0x000B29C9 (10B): global dword setter over
// 0x00DB3BDC (mov eax,[esp+4]; mov [mem],eax; ret 4). Same honest
// address-derived naming as the getters above.

extern int g_Va00DB3BDC;

void Rva000B29C9Set(int value)
{
	g_Va00DB3BDC = value;
}

// ?Rva006CD220Get@@YAHXZ @ 0x006CD220 (6B) over 0x00E17724.

extern int g_Va00E17724;

int Rva006CD220Get(void)
{
	return g_Va00E17724;
}

// ?Rva006C53B0Get@@YAHXZ @ 0x006C53B0 (6B) over 0x00E0C1F4.

extern int g_Va00E0C1F4;

int Rva006C53B0Get(void)
{
	return g_Va00E0C1F4;
}

// ?Rva0058AEB6Get@@YAHXZ @ 0x0058AEB6 (6B) over 0x00E063A4.

extern int g_Va00E063A4;

int Rva0058AEB6Get(void)
{
	return g_Va00E063A4;
}

// ?Rva00658200Get@@YAHXZ @ 0x00658200 (6B) over 0x00E09FA4.

extern int g_Va00E09FA4;

int Rva00658200Get(void)
{
	return g_Va00E09FA4;
}

// ?Rva0043C969Get@@YAHXZ @ 0x0043C969 (6B) over 0x00E03314.

extern int g_Va00E03314;

int Rva0043C969Get(void)
{
	return g_Va00E03314;
}

// ?Rva00062AC4Get@@YAHXZ @ 0x00062AC4 (6B) over 0x00DFEC54.

extern int g_Va00DFEC54;

int Rva00062AC4Get(void)
{
	return g_Va00DFEC54;
}

// ?Rva00452D86Get@@YAHXZ @ 0x00452D86 (6B) over 0x00DC908C.

extern int g_Va00DC908C;

int Rva00452D86Get(void)
{
	return g_Va00DC908C;
}
