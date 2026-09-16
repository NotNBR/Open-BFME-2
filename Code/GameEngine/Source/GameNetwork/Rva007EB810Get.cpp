// cl: /GX-
// ?Rva007EB810Get@@YAHXZ @ 0x006587A0 (6B): global dword getter reading
// 0x00E09FBC (mov eax,[mem]; ret). Ported from Open-BFME-1
// Code/GameEngine/Source/Common/GlobalDwordGetters.cpp
// (?Rva007EB810Get@@YAHXZ at 0x7EB810, same shape). The diagnostic reporter
// pointer the FESL join fail paths call through; kept in its own TU so the
// Join callers keep their call-through-edx shape (same-TU definition lets
// MSVC inline the load and breaks them).

extern int g_FeslDiagReporter;

int Rva007EB810Get(void)
{
	return g_FeslDiagReporter;
}
