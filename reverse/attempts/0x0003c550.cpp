// _d_0088d240
// partial score=0.5 date=2026-09-15
// cl: /DNDEBUG /MD /EHs-c- /Oy-

#include <windows.h>

extern "C" __declspec(dllimport) int __cdecl _snprintf(char *buffer, unsigned int count, char const *format, ...);
extern "C" __declspec(dllimport) int __stdcall OpenThreadToken(void *threadHandle, unsigned long desiredAccess, int openAsSelf, void **tokenHandle);
extern "C" __declspec(dllimport) int __stdcall OpenProcessToken(void *processHandle, unsigned long desiredAccess, void **tokenHandle);
extern "C" __declspec(dllimport) int __stdcall LookupPrivilegeValueA(char const *systemName, char const *name, void *luid);
extern "C" __declspec(dllimport) int __stdcall AdjustTokenPrivileges(void *tokenHandle, int disableAll, void *newState, unsigned long newStateLength, void *prevState, unsigned long *returnLength);

#define TOKEN_ADJUST_PRIVILEGES 0x20
#define TOKEN_QUERY 0x08
#define SE_PRIVILEGE_ENABLED 0x02
#define ERROR_NO_TOKEN 0x3F0
#define ERROR_NOT_ALL_ASSIGNED 0x514

struct BfmeTokenPrivileges
{
	unsigned long PrivilegeCount;
	unsigned long PrivilegeLuidLow;
	unsigned long PrivilegeLuidHigh;
	unsigned long PrivilegeAttributes;
};

struct BfmeMinidumpExceptionInfo
{
	unsigned long ThreadId;
	void *ExceptionPointers;
	int ClientPointers;
};

typedef int (__stdcall *MiniDumpWriteDumpFunc)(void *hProcess, void *hFile,
	unsigned long dumpType, void *exceptionParam, void *userStreamParam, void *callbackParam);

// Debug-global vtable slots retail calls for the dump filename parts.  The
// identities behind +0xA0/+0xA4 are unrecovered, so this is a bare slot
// table, not a class replica; nothing here is compared.
struct BfmeDebugVtable
{
	void *m_slots[40];
	char const *(__fastcall *m_slotA0)(void *self);
	char const *(__fastcall *m_slotA4)(void *self);
};

struct BfmeDebugObject
{
	BfmeDebugVtable *m_vtable;
};

extern void *g_dbghelpHandle;
extern BfmeDebugObject *g_debugObject;

// Scaffolding: retail calls GetCurrentThreadId indirectly through a
// register (mov ebx,[import]; call ebx), which MSVC only emits when the
// address flows through a variable it cannot fold.  A TU-scoped pointer
// initialized to the import reproduces the shape; the slot is DIR32-filled
// from retail at claim time like any other address.
unsigned long (__stdcall * volatile g_threadIdProc)(void) = GetCurrentThreadId;

extern "C" void d_0088d240(void *a, void *b);

int d_00889760(void *a, void *b, void *c)
{
	d_0088d240(b, c);
	return 1;
}

// ?d_0088d240 — minidump writer at 0x003C550 (465 bytes)
extern "C" void d_0088d240(void *a, void *b)
{
	void *dbghelp = g_dbghelpHandle;
	if (dbghelp == 0) {
		return;
	}
	MiniDumpWriteDumpFunc writeDump = (MiniDumpWriteDumpFunc)GetProcAddress((HMODULE)dbghelp, "MiniDumpWriteDump");
	if (writeDump == 0) {
		return;
	}

	SYSTEMTIME now;
	GetLocalTime(&now);
	char const *dumpTag = g_debugObject->m_vtable->m_slotA4(g_debugObject);
	char const *dumpName = g_debugObject->m_vtable->m_slotA0(g_debugObject);
	char filename[0x106];
	_snprintf(filename, 0x106, "DUMP_%s_%04d%02d%02d-%02d%02d%02d_%s_%ld_%ld.dmp",
		dumpName, now.wYear, now.wMonth, now.wDay, now.wHour, now.wMinute, now.wSecond,
		dumpTag, GetCurrentProcessId(), g_threadIdProc());

	void *hFile = CreateFileA(filename, 0xC0000000, 3, 0, 2, 0, 0);
	if (hFile == (void *)-1) {
		return;
	}

	void *hToken = 0;
	if (OpenThreadToken(GetCurrentThread(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, 1, &hToken) == 0) {
		if (GetLastError() != ERROR_NO_TOKEN) {
			return;
		}
		if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken) == 0) {
			return;
		}
	}

	BfmeTokenPrivileges newState;
	unsigned long returnLength = 0x10;
	BfmeTokenPrivileges prevState;
	newState.PrivilegeCount = 1;
	newState.PrivilegeAttributes = SE_PRIVILEGE_ENABLED;
	LookupPrivilegeValueA(0, "SeDebugPrivilege", &newState.PrivilegeLuidLow);

	int needRevert = 1;
	if (AdjustTokenPrivileges(hToken, 0, &newState, 0x10, &prevState, &returnLength) == 0) {
		needRevert = 0;
	}
	else if (GetLastError() == ERROR_NOT_ALL_ASSIGNED) {
		needRevert = 0;
	}

	BfmeMinidumpExceptionInfo exceptionInfo = { 0 };
	exceptionInfo.ExceptionPointers = a;
	exceptionInfo.ClientPointers = 1;
	writeDump(GetCurrentProcess(), hFile, b ? 2 : 1, &exceptionInfo, 0, 0);

	if (needRevert != 0) {
		AdjustTokenPrivileges(hToken, 0, &newState, 0x10, &prevState, &returnLength);
	}
	CloseHandle(hToken);
	CloseHandle(hFile);
}
