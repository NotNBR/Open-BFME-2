// cl: /O1
// ScriptEngine app-continuation gate at retail 0x00203B47 (106B).
// Decoded from retail bytes (all verified):
// - TheGameLogic->isGamePaused() row gate (matched 7B leaf at 0x23CD97).
// - GlobalData byte flag at [0xDFE758]+0xBBD.
// - App module handle at [0xDFE158]; RunAppFast/CanAppContinue via
//   kernel32!GetProcAddress import (IAT 0xBBA1F8, dllimport auto).
// - Latch at [0xDFE168]: set on proc success, cleared on next failure.
// Human-readable names; opaque host (caller sets ecx, body ignores this).

typedef int HMODULE;

extern "C" __declspec(dllimport) void *__stdcall GetProcAddress(HMODULE module, const char *name);

class GameLogic
{
public:
	unsigned char isGamePaused();
};

#define TheGameLogic (*(GameLogic **)0x00DFE78C)
#define TheGlobalData (*(unsigned char **)0x00DFE758)
#define TheAppModule (*(HMODULE *)0x00DFE158)
#define AppFastLatch (*(unsigned char *)0x00DFE168)

class Rva00203B47Host
{
public:
	bool rva00203B47();
};

bool Rva00203B47Host::rva00203B47()
{
	if (!TheGameLogic->isGamePaused())
	{
		if (TheGlobalData[0xBBD] != 0)
			return true;
	}

	if (!TheAppModule)
		return false;

	GetProcAddress(TheAppModule, "CanAppContinue");
	void *runFast = GetProcAddress(TheAppModule, "RunAppFast");

	typedef bool (__stdcall *AppProc)();
	if (!runFast || !((AppProc)runFast)())
		goto latchFail;

	AppFastLatch = 1;
	return true;

latchFail:
	if (AppFastLatch)
		AppFastLatch = 0;
	return false;
}
