// cl: /GX-
// ?Rva00042F6DGet@@YAHXZ @ 0x00042F6D (6B): global dword getter reading
// 0x00DEDA7C (mov eax,[mem]; ret). Ported from Open-BFME-1
// Code/GameEngine/Source/Common/GlobalDwordGetters.cpp (same shape; the
// load address is a .data global). Dedicated TU so no caller inlines the
// load (Rva007EB810Get precedent).

extern int g_Va00DEDA7C;

int Rva00042F6DGet(void)
{
	return g_Va00DEDA7C;
}
