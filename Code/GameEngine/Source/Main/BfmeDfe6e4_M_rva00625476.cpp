// cl: /DNDEBUG /MD /EHsc /G7
// ?_M_rva00625476@BfmeDfe6e4@@QAEXXZ
// retail 0x00225476, 28 bytes. Dedicated TU: WinMain.cpp owns the class
// declaration and the two call sites; this unit carries the byte-exact body
// (guarded counter increment under the class critical section). /G7 for the
// add-mem-1 counter (inc-to-add wall; Begin_Scene_Inner precedent — no source
// spelling produces add-mem under /O1, and WinMain.cpp itself must keep its
// own flags for its landed rows).

struct CRITICAL_SECTION
{
    unsigned char data[24];
};

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CRITICAL_SECTION *section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION *section);

class BfmeDfe6e4
{
public:
	void _M_rva00625476();

private:
	// Retail layout: guarded counter at +0x6C, critical section at +0x70
	// (the sibling _M_rva00625699 decrements the counter the same way).
	unsigned char m_unreconstructed_00[0x6C];
	int m_refCount; // +0x6C
	CRITICAL_SECTION m_cs; // +0x70
};

// ?_M_rva00625476@BfmeDfe6e4@@QAEXXZ
void BfmeDfe6e4::_M_rva00625476()
{
	EnterCriticalSection(&m_cs);
	m_refCount += 1;
	LeaveCriticalSection(&m_cs);
}
