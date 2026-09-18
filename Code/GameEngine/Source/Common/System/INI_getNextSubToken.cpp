// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?getNextSubToken@INI@@QAEPBDPBD@Z, retail 0x002E06B, 92 bytes.
// Dedicated ebp-frame TU (same INI family as INI_getNextToken.cpp).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/ini_parsers.cpp,
// INI::getNextSubToken): read a token, verify it against the expected
// separator, return the following token. Deltas: the separator set comes
// from the m_sepsColon member at this+0x420 (the getNextAsciiString TU maps
// +0x418/+0x41C/+0x420/+0x424), the compare is msvcr71!_strcmpi (single
// direct FF15 call, no hoist), and failure throws through the shared filler
// plus _CxxThrowException. Plain frame (no temps, no SEH).

class INI
{
public:
	const char *getNextToken(const char *seps);
	const char *getNextSubToken(const char *expected);

private:
	char _pad[0x420];
	const char *m_sepsColon;
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
struct GetNextSubTokenThrowInfoAnchor { int a; int b; int c; int d; };
static const GetNextSubTokenThrowInfoAnchor getNextSubTokenThrowInfoAnchor = { 0, 0, 0, 0 };

// ?getNextSubToken@INI@@QAEPBDPBD@Z
const char *INI::getNextSubToken(const char *expected)
{
	const char *token = getNextToken(m_sepsColon);
	if (_strcmpi(token, expected) != 0) {
		INIException e;
		rva002f681_fill(&e, 3, "Expected '%s' but found '%s'", expected, token);
		_CxxThrowException(&e, (void *)&getNextSubTokenThrowInfoAnchor);
	}
	return getNextToken(m_sepsColon);
}
