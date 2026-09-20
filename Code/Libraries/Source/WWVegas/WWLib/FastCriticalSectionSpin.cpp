// cl: /DNDEBUG /MD /EHsc
// ?spin@LockClass@FastCriticalSectionClass@@CIXPAX@Z at 0x006C5EF0 (67B).
//
// BFME1's Code/Libraries/Source/WWVegas/WWLib/FastCriticalSectionSpin.cpp
// (b1 0x006D10E0, 48B, there under the unsigned-spelling of this symbol) is
// the direct donor: same framed lock-bts spin loop, same __fastcall (ecx =
// lock word) shape, same inline-asm acquire/retry skeleton. BFME2 only swaps
// the contention yield: where BFME1 calls its Switch_Thread wrapper
// (bfmeGoDWI), BFME2 yields on a startup-created event (CreateEventA,
// all-NULL attributes, stored once at 0x007B6720 into the .data handle read
// here) via WaitForSingleObject(handle, 1), skipping the wait while the
// handle is still NULL. The void spelling below keeps this string-domain
// spin distinct from the pool-domain spin already pinned at 0x0006577F
// under the unsigned spelling; each caller verifies against its own retail
// bytes. Retail callers (0x006C6160, 0x006C6283, ...) pass a .data
// FastCriticalSectionClass global in ecx, the inlined LockClass pattern.

class FastCriticalSectionClass
{
public:
	class LockClass
	{
		static void __fastcall spin(void *lock);
	};
};

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void *handle, unsigned long milliseconds);

// Contention-yield event, created once during startup (see 0x007B6720).
// The address is DIR32-masked; only the null-check shape is verified.
static void *g_spinYieldEvent = 0;

void __fastcall FastCriticalSectionClass::LockClass::spin(void *lock)
{
	unsigned int &flag = *(unsigned int *)lock;
	__asm mov ebx, [flag]
	__asm lock bts dword ptr [ebx], 0
	__asm jc retry
	__asm jmp acquired

retry:
	if (g_spinYieldEvent != 0)
		WaitForSingleObject(g_spinYieldEvent, 1);
	__asm mov ebx, [flag]
	__asm lock bts dword ptr [ebx], 0
	__asm jc retry

acquired:
	;
}
