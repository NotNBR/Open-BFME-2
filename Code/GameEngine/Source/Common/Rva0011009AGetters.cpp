// cl: /GX-
// ?Rva0011009AGet@@YAHXZ @ 0x0011009A (6B): global dword getter reading
// 0x00DB5FD4 (mov eax,[mem]; ret). Ported from Open-BFME-1
// Code/GameEngine/Source/Common/GlobalDwordGetters.cpp (same shape).
// First of an adjacent pair (0x11009A/A0, themselves preceded by an A0-form
// global byte getter); dedicated TU so no caller inlines the load
// (Rva007EB810Get precedent).

extern int g_Va00DB5FD4;

int Rva0011009AGet(void)
{
	return g_Va00DB5FD4;
}
