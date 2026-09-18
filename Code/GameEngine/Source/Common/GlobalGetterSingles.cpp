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
