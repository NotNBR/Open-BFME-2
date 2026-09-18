// cl: /GX-
// ?Rva000752BDGet@@YAHXZ @ 0x000752BD (6B): global dword getter reading
// 0x00E08D30 (mov eax,[mem]; ret). Ported from Open-BFME-1
// Code/GameEngine/Source/Common/GlobalDwordGetters.cpp (same shape).
// First of a four-deep adjacent run (0x752BD/C3/C9/CF); dedicated TU so no
// caller inlines the load (Rva007EB810Get precedent).

extern int g_Va00E08D30;

int Rva000752BDGet(void)
{
	return g_Va00E08D30;
}

// ?Rva000752C3Get@@YAHXZ @ 0x000752C3 (6B): same shape over 0x00E08CA8.

extern int g_Va00E08CA8;

int Rva000752C3Get(void)
{
	return g_Va00E08CA8;
}
