// cl: /O1 /Oy- /DNDEBUG /MD /GX /Oi-
//
// ?parseUnsignedByte@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002EE6D, 75 bytes.
// Dedicated ebp-frame TU (same INI scanner family as INI_parseByte.cpp).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/ini_parsers.cpp,
// INI::parseUnsignedByte): range-checked unsigned-byte store. Same BFME2
// deltas as parseByte (explicit NULL seps, member scanInt, filler plus throw).

class INI
{
public:
	const char *getNextToken(const char *seps);
	int scanInt(const char *token);
	static void parseUnsignedByte(INI *ini, void *instance, void *store, const void *userData);
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
struct ParseUnsignedByteThrowInfoAnchor { int a; int b; int c; int d; };
static const ParseUnsignedByteThrowInfoAnchor parseUnsignedByteThrowInfoAnchor = { 0, 0, 0, 0 };

// ?parseUnsignedByte@INI@@SAXPAV1@PAX1PBX@Z
void INI::parseUnsignedByte(INI *ini, void *instance, void *store, const void *userData)
{
	int value = ini->scanInt(ini->getNextToken(0));
	if (value < 0 || value > 0xFF) {
		INIException e;
		rva002f681_fill(&e, 3, "value out of range, expected 0..255");
		_CxxThrowException(&e, (void *)&parseUnsignedByteThrowInfoAnchor);
	}
	*(unsigned char *)store = (unsigned char)value;
}
