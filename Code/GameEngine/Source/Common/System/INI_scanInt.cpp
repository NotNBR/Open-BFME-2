// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?scanInt@INI@@QAEHPBD@Z, retail 0x002ECCF, 104 bytes.
// Dedicated TU (ebp frame needs /Oy-).
//
// Int twin of INI::scanReal (INI_scanReal.cpp): macro expansion through the
// pinned preprocessMacro at 0x002D0A9, sscanf %d, INIException(3, ...)
// through the shared filler at 0x002F681 plus _CxxThrowException on failure,
// and the BFME2-only '#' branch evaluating #ADD(/#SUBTRACT( expressions out
// of line at 0x002E0C9 with scanInt itself as the value callback.

class INI
{
public:
	static const char *preprocessMacro(const char *token);
	int parseIntMathExpression(const char *text, int (INI::*valueParser)(const char *token));
	int scanInt(const char *token);
};

struct INIException
{
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);
extern "C" __declspec(dllimport) int __cdecl sscanf(const char *buf, const char *fmt, ...);

// Address anchor only: the throw site pushes this object's address as an
// immediate (DIR32, copied from retail's INIException throwinfo at
// 0x8FE2FC -- the same chain the scanReal helper throws through). Its
// content is never compared; the real chain lives in the retail image.
struct ScanIntThrowInfoAnchor { int a; int b; int c; int d; };
static const ScanIntThrowInfoAnchor scanIntThrowInfoAnchor = { 0, 0, 0, 0 };

// ?scanInt@INI@@QAEHPBD@Z
int INI::scanInt(const char *token)
{
	const char *text = preprocessMacro(token);
	if (*text == '#')
		return parseIntMathExpression(text, &INI::scanInt);
	int value;
	if (sscanf(text, "%d", &value) != 1) {
		INIException e;
		rva002f681_fill(&e, 3, "Expected signed integer value, math op, or predefined macro, but found '%s'", text);
		_CxxThrowException(&e, (void *)&scanIntThrowInfoAnchor);
	}
	return value;
}
