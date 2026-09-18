// cl: /O1 /Oy- /DNDEBUG /MD /GX /Oi-
//
// ?parseUnsignedShort@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002EF09, 76 bytes.
// Dedicated ebp-frame TU (same INI scanner family as INI_parseShort.cpp).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/ini_parsers.cpp,
// INI::parseUnsignedShort): range-checked unsigned-half store. Same BFME2
// deltas as parseShort (explicit NULL seps, member scanInt, filler plus throw).

class INI
{
public:
	const char *getNextToken(const char *seps);
	int scanInt(const char *token);
	static void parseUnsignedShort(INI *ini, void *instance, void *store, const void *userData);
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
struct ParseUnsignedShortThrowInfoAnchor { int a; int b; int c; int d; };
static const ParseUnsignedShortThrowInfoAnchor parseUnsignedShortThrowInfoAnchor = { 0, 0, 0, 0 };

// ?parseUnsignedShort@INI@@SAXPAV1@PAX1PBX@Z
void INI::parseUnsignedShort(INI *ini, void *instance, void *store, const void *userData)
{
	int value = ini->scanInt(ini->getNextToken(0));
	if (value < 0 || value > 0xFFFF) {
		INIException e;
		rva002f681_fill(&e, 3, "value out of range, expected 0..65535");
		_CxxThrowException(&e, (void *)&parseUnsignedShortThrowInfoAnchor);
	}
	*(unsigned short *)store = (unsigned short)value;
}
