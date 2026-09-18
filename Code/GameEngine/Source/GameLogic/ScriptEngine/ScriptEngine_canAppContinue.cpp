// cl: /O1
// ScriptEngine CanAppContinue gate at retail 0x00204806 (55B).
// Decoded from retail bytes (all verified):
// - Opaque host byte at this+0x1A4D9 gates everything (cmp/je shape).
// - Calls rva00204094 frame-setter row (matched 83B at 0x204094).
// - App module handle at [0xDFE158]; CanAppContinue via
//   kernel32!GetProcAddress import (IAT 0xBBA1F8, dllimport auto).
// - Latch byte at [0xDFE15C]: proc result, or 1 when the module is null;
//   untouched when the proc lookup fails.
// Human-readable names; opaque host (caller sets ecx, body ignores this).

typedef int HMODULE;

extern "C" __declspec(dllimport) void *__stdcall GetProcAddress(HMODULE module, const char *name);

#define TheAppModule (*(HMODULE *)0x00DFE158)
#define AppContinueLatch (*(unsigned char *)0x00DFE15C)

void rva00204094();

class Rva00204806Host
{
public:
	unsigned char m_pad[0x1A4D9];
	unsigned char m_gateFlag;
	void rva00204806();
};

void Rva00204806Host::rva00204806()
{
	if (m_gateFlag == 0)
	{
		rva00204094();
		if (TheAppModule)
		{
			typedef bool (__stdcall *AppProc)();
			AppProc proc = (AppProc)GetProcAddress(TheAppModule, "CanAppContinue");
			if (!proc)
				return;
			AppContinueLatch = proc();
			return;
		}
		AppContinueLatch = 1;
	}
}
