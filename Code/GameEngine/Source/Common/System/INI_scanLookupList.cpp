// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?scanLookupList@INI@@QAEHPBDPBULookupListRec@@@Z, retail 0x002BD85, 108 bytes.
// Dedicated TU (same INI family as INI_parseBitString32.cpp, framed).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/INI_stl.cpp,
// INI::scanLookupList): linear case-insensitive walk over the name/value
// records, returning the hit value. BFME2 deltas (all retail-measured): the
// static is a thiscall member (ecx carries INI through, ret 8; BFME2
// member-ifies BFME1's static), and both failures (null table, missed token)
// throw through the shared filler plus _CxxThrowException (DEBUG_CRASH/throw
// pairs in BFME1) with the retail formats ("INTERNAL ERROR! scanLookupList:
// No name list provided!", "Token '%s' is not a valid member of the lookup
// list"), which prove the name outright.

#define NULL 0

struct LookupListRec
{
	const char *name;
	int value;
};

class INI
{
public:
	int scanLookupList(const char *token, const LookupListRec *lookupList);
};

struct INIException
{
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);
extern "C" __declspec(dllimport) int __cdecl _strcmpi(const char *a, const char *b);

// Address anchor only: the throw site pushes this object's address as an
// immediate (DIR32, copied from retail's throwinfo at 0xCFE2FC). Content is
// never compared; the real chain lives in the retail image.
struct ScanLookupListThrowInfoAnchor { int a; int b; int c; int d; };
static const ScanLookupListThrowInfoAnchor scanLookupListThrowInfoAnchor = { 0, 0, 0, 0 };

// ?scanLookupList@INI@@QAEHPBDPBULookupListRec@@@Z
int INI::scanLookupList(const char *token, const LookupListRec *lookupList)
{
	INIException e;

	if (lookupList == NULL || lookupList[0].name == NULL) {
		rva002f681_fill(&e, 2, "INTERNAL ERROR! scanLookupList: No name list provided!");
		_CxxThrowException(&e, (void *)&scanLookupListThrowInfoAnchor);
	}

	// search for matching name
	for (const LookupListRec *lookup = &lookupList[0]; lookup->name; lookup++) {
		if (_strcmpi(lookup->name, token) == 0) {
			return lookup->value;
		}
	}

	rva002f681_fill(&e, 3, "Token '%s' is not a valid member of the lookup list", token);
	_CxxThrowException(&e, (void *)&scanLookupListThrowInfoAnchor);
}
