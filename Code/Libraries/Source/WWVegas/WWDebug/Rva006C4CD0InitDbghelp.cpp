// cl: /O2 /DNDEBUG /MD
// ?initDbghelp@Rva006C4CD0Helper@@QAEXXZ
// retail 0x006C4CD0, 124 bytes. Dedicated TU.
//
// Opaque helper-class row: loads DbgHelp.dll once and resolves seven dbghelp
// entry points (SymInitialize, SymCleanup, StackWalk, SymFunctionTableAccess,
// SymGetModuleBase, SymGetSymFromAddr, SymGetLineFromAddr) into slots
// +8..+0x20, with the module handle at +0. Same-cluster callers at
// 0x6C4D8F/0x6C4FBC/0x6C5108; the cleanup sibling (~0x6C4D80) reads the flag
// at +4 and SymCleanup at +0xC before freeing the library. The true class
// name is unknown, so the RvaHelper name claims nothing beyond the address;
// the method name describes the proven behavior. Imports resolve by name
// (LoadLibraryA, GetProcAddress).

#ifndef NULL
#define NULL 0
#endif

typedef void *HMODULE;

extern "C" __declspec(dllimport) HMODULE __stdcall LoadLibraryA(const char *name);
extern "C" __declspec(dllimport) void *__stdcall GetProcAddress(HMODULE module, const char *name);

class Rva006C4CD0Helper
{
public:
	void initDbghelp(void);

	HMODULE m_hLib;			// +0x00
	int m_flag;			// +0x04 (read by the cleanup sibling)
	void *m_symInitialize;		// +0x08
	void *m_symCleanup;		// +0x0C
	void *m_stackWalk;		// +0x10
	void *m_symFunctionTableAccess;	// +0x14
	void *m_symGetModuleBase;	// +0x18
	void *m_symGetSymFromAddr;	// +0x1C
	void *m_symGetLineFromAddr;	// +0x20
};

// ?initDbghelp@Rva006C4CD0Helper@@QAEXXZ
void Rva006C4CD0Helper::initDbghelp(void)
{
	if (m_hLib != NULL) {
		return;
	}
	m_hLib = LoadLibraryA("DbgHelp.dll");
	if (m_hLib == NULL) {
		return;
	}
	m_symInitialize = GetProcAddress(m_hLib, "SymInitialize");
	m_symCleanup = GetProcAddress(m_hLib, "SymCleanup");
	m_stackWalk = GetProcAddress(m_hLib, "StackWalk");
	m_symFunctionTableAccess = GetProcAddress(m_hLib, "SymFunctionTableAccess");
	m_symGetModuleBase = GetProcAddress(m_hLib, "SymGetModuleBase");
	m_symGetSymFromAddr = GetProcAddress(m_hLib, "SymGetSymFromAddr");
	m_symGetLineFromAddr = GetProcAddress(m_hLib, "SymGetLineFromAddr");
}
