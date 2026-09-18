// cl: /O1 /Oy- /DNDEBUG /MD /GX /Oi-
//
// ?scanBool@INI@@QAE_NPBD@Z, retail 0x002D14A, 101 bytes.
// Dedicated TU (same INI scanner family as INI_scanReal.cpp).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/ini_parsers.cpp,
// INI::scanBool): macro-expand the token, accept yes/no case-insensitively,
// else throw INIException(3, ...) over the ORIGINAL token. BFME2 deltas: the
// compare is msvcr71!_strcmpi through the IAT slot 0xBBA518 (NOT _stricmp),
// and the throw runs through the shared filler at 0x002F681 plus
// _CxxThrowException. Member (not static): every caller derives an INI* into
// ecx ahead of the single push (0x2E860/0x2E87D/0x1E194A/0xBD565), which would
// be dead loads under a static spelling.

class INI
{
public:
	static const char *preprocessMacro(const char *token);
	bool scanBool(const char *token);
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
struct ScanBoolThrowInfoAnchor { int a; int b; int c; int d; };
static const ScanBoolThrowInfoAnchor scanBoolThrowInfoAnchor = { 0, 0, 0, 0 };

// ?scanBool@INI@@QAE_NPBD@Z
bool INI::scanBool(const char *token)
{
	const char *text = preprocessMacro(token);
	if (_strcmpi(text, "yes") == 0)
		return true;
	if (_strcmpi(text, "no") == 0)
		return false;
	INIException e;
	rva002f681_fill(&e, 3, "invalid boolean token %s -- expected Yes or No", token);
	_CxxThrowException(&e, (void *)&scanBoolThrowInfoAnchor);
}
