// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?parseBitString32@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002EB38, 277 bytes.
// Dedicated TU (same INI verb family as INI_parseRGBColor.cpp, framed).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/INI_stl.cpp,
// INI::parseBitString32): zero the dword, loop tokens via getNextTokenOrNull:
// NONE clears (and must stand alone), +/- names set/clear single bits, plain
// names clear-then-set; mixing the styles throws. BFME2 deltas (all
// retail-measured): the name lookup is the member scanIndexList(token, table)
// (pinned at 0x2BD39; BFME2 member-ifies BFME1's static), and every failure
// throws through the shared filler (code 2) with its own retail format
// ("INTERNAL ERROR! parseBitString32: No flag list provided!",
// "you may not mix normal and +- ops in bitstring lists") plus
// _CxxThrowException (DEBUG_CRASH/throw pairs in BFME1).

#define NULL 0

typedef int Int;
typedef unsigned int UnsignedInt;
typedef bool Bool;
typedef const char *ConstCharPtr;
typedef const ConstCharPtr *ConstCharPtrArray;

class INI
{
public:
	const char *getNextTokenOrNull(const char *seps);
	int scanIndexList(const char *token, ConstCharPtrArray flagList);
	static void parseBitString32(INI *ini, void *instance, void *store, const void *userData);
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
struct ParseBitString32ThrowInfoAnchor { int a; int b; int c; int d; };
static const ParseBitString32ThrowInfoAnchor parseBitString32ThrowInfoAnchor = { 0, 0, 0, 0 };

// ?parseBitString32@INI@@SAXPAV1@PAX1PBX@Z
void INI::parseBitString32(INI *ini, void * /*instance*/, void *store, const void *userData)
{
	ConstCharPtrArray flagList = (ConstCharPtrArray)userData;
	UnsignedInt *bits = (UnsignedInt *)store;

	if (flagList == NULL || flagList[0] == NULL) {
		INIException e;
		rva002f681_fill(&e, 2, "INTERNAL ERROR! parseBitString32: No flag list provided!");
		_CxxThrowException(&e, (void *)&parseBitString32ThrowInfoAnchor);
	}

	Bool foundNormal = false;
	Bool foundAddOrSub = false;

	// loop through all tokens
	for (const char *token = ini->getNextTokenOrNull(NULL); token != NULL; token = ini->getNextTokenOrNull(NULL)) {
		if (_strcmpi(token, "NONE") == 0) {
			if (foundNormal || foundAddOrSub) {
				INIException e;
				rva002f681_fill(&e, 2, "you may not mix normal and +- ops in bitstring lists");
				_CxxThrowException(&e, (void *)&parseBitString32ThrowInfoAnchor);
			}
			*bits = 0;
			break;
		}

		if (token[0] == '+') {
			if (foundNormal) {
				INIException e;
				rva002f681_fill(&e, 2, "you may not mix normal and +- ops in bitstring lists");
				_CxxThrowException(&e, (void *)&parseBitString32ThrowInfoAnchor);
			}
			Int bitIndex = ini->scanIndexList(token + 1, flagList);
			*bits |= (1 << bitIndex);
			foundAddOrSub = true;
		} else if (token[0] == '-') {
			if (foundNormal) {
				INIException e;
				rva002f681_fill(&e, 2, "you may not mix normal and +- ops in bitstring lists");
				_CxxThrowException(&e, (void *)&parseBitString32ThrowInfoAnchor);
			}
			Int bitIndex = ini->scanIndexList(token + 1, flagList);
			*bits &= ~(1 << bitIndex);
			foundAddOrSub = true;
		} else {
			if (foundAddOrSub) {
				INIException e;
				rva002f681_fill(&e, 2, "you may not mix normal and +- ops in bitstring lists");
				_CxxThrowException(&e, (void *)&parseBitString32ThrowInfoAnchor);
			}

			if (!foundNormal)
				*bits = 0;

			Int bitIndex = ini->scanIndexList(token, flagList);
			*bits |= (1 << bitIndex);
			foundNormal = true;
		}
	}
}
