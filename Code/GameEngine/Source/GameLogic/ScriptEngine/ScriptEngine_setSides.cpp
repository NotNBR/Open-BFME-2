// cl: /O1
// Sides-list setter gate at retail 0x00203C21 (89B).
// Decoded from retail bytes (all verified, no E8 calls):
// - App module at [0xDFE158]; SetTheSidesList via kernel32!GetProcAddress
//   import (IAT 0xBBA1F8, dllimport auto).
// - Calls the proc with 11 pushed globals/zeros (caller cleans 0x2C).
// Human-readable names; opaque free function (no this, no stack args).

typedef int HMODULE;

extern "C" __declspec(dllimport) void *__stdcall GetProcAddress(HMODULE module, const char *name);

#define TheAppModule (*(HMODULE *)0x00DFE158)
#define Rva00DFE78C (*(void **)0x00DFE78C)
#define Rva00DFF000 (*(void **)0x00DFF000)
#define Rva00DFEC50 (*(void **)0x00DFEC50)
#define Rva00DFEA3C (*(void **)0x00DFEA3C)
#define Rva00DF36A4 (*(void **)0x00DF36A4)
#define Rva00DFE758 (*(void **)0x00DFE758)
#define Rva00DFE6E8 (*(void **)0x00DFE6E8)
#define Rva00DFE16C (*(void **)0x00DFE16C)
#define Rva00E01D58 (*(void **)0x00E01D58)

void rva00203C21()
{
	HMODULE app = TheAppModule;
	if (!app)
		return;

	typedef void (__cdecl *SetSidesProc)(
		void *a1, void *a2, void *a3, void *a4, void *a5, void *a6,
		void *a7, void *a8, void *a9, void *a10, void *a11);
	SetSidesProc proc = (SetSidesProc)GetProcAddress(app, "SetTheSidesList");
	if (!proc)
		return;

	proc(Rva00E01D58, Rva00DFE16C, Rva00DFE6E8, Rva00DFE758, Rva00DF36A4, 0, 0,
		Rva00DFEA3C, Rva00DFEC50, Rva00DFF000, Rva00DFE78C);
}
