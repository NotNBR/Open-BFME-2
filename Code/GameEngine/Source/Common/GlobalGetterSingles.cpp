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
