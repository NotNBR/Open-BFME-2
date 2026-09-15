// cl: /Ireference/shims/bfmealloc /Ireference/shims/bfmehashtable /DNDEBUG /MD /GX- /O2 /Ob2 /EHsc /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP=
// stlport
//
// Add_Prototype thin wrapper (BFME1 Add_Prototype.cpp pattern).
// Null-check the global resource enumerator at VA 0x00E09C0C,
// then thiscall into Add_Prototype_Impl at 0x00621710.
//
// The enumerator itself lives here too: Begin (retail 0x00621480, 69 bytes)
// snapshots the prototype registry's hash table under the enumerator lock,
// entering the critical section at +0x34, copying the begin() iterator of
// the int->int table at +0x4C into the +0x60/+0x64 cursor, recording the
// tag at +0x1F0 and leaving the lock. The table is stlport's raw hashtable
// (retail calls hashtable::begin at 0x00620A80 directly). The imports are
// hand-declared like BfmeDX8ThreadLock.cpp's.

#include <hash_map>

extern "C" {
__declspec(dllimport) void __stdcall EnterCriticalSection(void *section);
__declspec(dllimport) void __stdcall LeaveCriticalSection(void *section);
}

// 24-byte Windows critical section (DebugInfo, LockCount, RecursionCount,
// OwningThread, LockSemaphore, SpinCount).
struct BfmeCriticalSection
{
	void *m_debugInfo;
	long m_lockCount;
	long m_recursionCount;
	void *m_owningThread;
	void *m_lockSemaphore;
	unsigned long m_spinCount;
};

typedef _STL::hashtable<_STL::pair<const int, int>, int, _STL::hash<int>,
	_STL::_Select1st<_STL::pair<const int, int> >, _STL::equal_to<int>,
	_STL::allocator<_STL::pair<const int, int> > > BfmePrototypeTable;

class BfmeResourceEnumerator
{
public:
	void Add_Prototype_Impl(void *prototype);
	void Begin(unsigned tag);

private:
	// +0x00 vptr and +0x04..0x33 unrecovered; the absolute offsets below are
	// what the retail bodies prove.
	unsigned char m_unknown00[0x34];
	BfmeCriticalSection m_lock; // +0x34
	BfmePrototypeTable m_prototypes; // +0x4C
	void *m_cachedNode; // +0x60: begin()._M_cur snapshot
	void *m_cachedTable; // +0x64: begin()._M_ht snapshot
	unsigned char m_unknown68[0x1F0 - 0x68];
	unsigned m_tag; // +0x1F0
};

extern BfmeResourceEnumerator *TheResourceEnumerator;

// ?Add_Prototype@@YAXPAX@Z
void Add_Prototype(void *prototype)
{
	if (TheResourceEnumerator)
		TheResourceEnumerator->Add_Prototype_Impl(prototype);
}

void BfmeResourceEnumerator::Begin(unsigned tag)
{
	EnterCriticalSection(&m_lock);
	BfmePrototypeTable::iterator iter = m_prototypes.begin();
	m_cachedNode = iter._M_cur;
	m_cachedTable = iter._M_ht;
	m_tag = tag;
	LeaveCriticalSection(&m_lock);
}
