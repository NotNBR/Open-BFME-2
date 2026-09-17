// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?getNextToken@INI@@QAEPBDPBD@Z, retail 0x002DF97, 75 bytes.
// Dedicated TU.
//
// Throwing next-token helper: delegates to getNextTokenOrNull (pinned at
// 0x002DEED, whose 168B BFME2 body reads the default separator set at
// this+0x418 just like this body does) and throws INIException(3,
// "Expected additional data after '%s'") through the shared filler (pinned
// at 0x002F681) plus __CxxThrowException when the stream is exhausted.
// BFME1 ini.cpp shape verbatim; the only BFME2 delta is the default-seps
// member sitting at this+0x418 (BFME1: +0x414).

class INI
{
public:
	const char *getNextToken(const char *seps);
	const char *getNextTokenOrNull(const char *seps);
private:
	char _pad[0x418];
	const char *m_seps;
};

struct INIException
{
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);

// Address anchor only: the throw site pushes this object's address as an
// immediate (DIR32, copied from retail's INIException throwinfo at
// 0x8FE2FC — the same chain the AI-kind parsers throw through). Its content
// is never compared; the real chain lives in the retail image.
struct GetNextTokenThrowInfoAnchor { int a; int b; int c; int d; };
static const GetNextTokenThrowInfoAnchor gntThrowInfoAnchor = { 0, 0, 0, 0 };

// ?getNextToken@INI@@QAEPBDPBD@Z
const char *INI::getNextToken(const char *seps)
{
	const char *token = getNextTokenOrNull(seps);
	if (token == 0) {
		INIException e;
		rva002f681_fill(&e, 3, "Expected additional data after '%s'", (seps == 0) ? m_seps : seps);
		_CxxThrowException(&e, (void *)&gntThrowInfoAnchor);
	}
	return token;
}
