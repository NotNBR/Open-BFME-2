// cl: /O1 /Oy- /arch:SSE /DNDEBUG /MD /GX /Oi-
//
// ?parsePositiveNonZeroReal@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002EFDC, 83 bytes.
// Dedicated ebp-frame TU (same INI scanner family as INI_scanBool.cpp).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/ini_parsers.cpp,
// INI::parsePositiveNonZeroReal): verbatim logic (store, throw iff <= 0).
// BFME2 deltas: explicit NULL seps, member scanReal, filler plus throw. The
// named value is load-bearing: it keeps the scan result on the x87 stack
// (fld-dup for the store, fld-dup plus fldz plus fcompi for the check) where
// the reference's store-reload form would emit an fld from memory.

class INI
{
public:
	const char *getNextToken(const char *seps);
	float scanReal(const char *token);
	static void parsePositiveNonZeroReal(INI *ini, void *instance, void *store, const void *userData);
};

struct INIException
{
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);

// Address anchor only: the throw site pushes this object's address as an
// immediate (DIR32, copied from retail's throwinfo at 0xCFE2FC). Content is
// never compared; the real chain lives in the retail image.
struct ParsePositiveNonZeroRealThrowInfoAnchor { int a; int b; int c; int d; };
static const ParsePositiveNonZeroRealThrowInfoAnchor parsePositiveNonZeroRealThrowInfoAnchor = { 0, 0, 0, 0 };

// ?parsePositiveNonZeroReal@INI@@SAXPAV1@PAX1PBX@Z
void INI::parsePositiveNonZeroReal(INI *ini, void *instance, void *store, const void *userData)
{
	float value = ini->scanReal(ini->getNextToken(0));
	*(float *)store = value;
	if (value <= 0.0f) {
		INIException e;
		rva002f681_fill(&e, 3, "invalid Real value %1.7f -- expected > 0", value);
		_CxxThrowException(&e, (void *)&parsePositiveNonZeroRealThrowInfoAnchor);
	}
}
