// cl: /GX-
// ?Rva00075E36Get@@YAHXZ @ 0x00075E36 (6B): global dword getter reading
// 0x001FDE68 (mov eax,[mem]; ret). Ported from Open-BFME-1
// Code/GameEngine/Source/Common/GlobalDwordGetters.cpp (same shape).
// First of an adjacent pair (0x75E36/3C); dedicated TU so no caller
// inlines the load (Rva007EB810Get precedent).

extern int g_Va001FDE68;

int Rva00075E36Get(void)
{
	return g_Va001FDE68;
}
