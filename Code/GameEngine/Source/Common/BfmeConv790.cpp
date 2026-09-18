// cl: /O1
struct BfmeCsDWD
{
	unsigned char m_bfmeHead[0x18];
};

// BFME1 wraps these in bfmeEnterDWD/bfmeLeaveDWD helpers; retail IAT slots
// (Enter 0xBBA200 / Leave 0xBBA204) are kernel32 Enter/LeaveCriticalSection,
// so this TU names the real imports (import-ref verify keys on PE names).
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(BfmeCsDWD *cs);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(BfmeCsDWD *cs);

struct BfmeThingDWD
{
	int bfmeLockDWD();
	void bfmeUnlockDWD();
	void bfmeReleaseDWD();
	BfmeCsDWD *m_bfmeCs;
	char m_bfmeHeld;
};

int BfmeThingDWD::bfmeLockDWD()
{
	EnterCriticalSection(m_bfmeCs);
	m_bfmeHeld = 1;
	return 0;
}

void BfmeThingDWD::bfmeReleaseDWD()
{
	if (m_bfmeHeld)
	{
		LeaveCriticalSection(m_bfmeCs);
		m_bfmeHeld = 0;
	}
}
