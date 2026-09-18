// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?scanUnsignedInt@INI@@QAEIPBD@Z, retail 0x002ED3A, 105 bytes.
// Dedicated TU (ebp frame needs /Oy-).
//
// Unsigned twin of INI::scanInt (INI_scanInt.cpp): macro expansion through the
// pinned preprocessMacro at 0x002D0A9, sscanf %u, INIException(3, ...)
// through the shared filler at 0x002F681 plus _CxxThrowException on failure,
// and the '#' branch evaluating #ADD(/#SUBTRACT( expressions out of line at
// 0x002E299 with scanUnsignedInt itself as the value callback.

class INI
{
public:
	static const char *preprocessMacro(const char *token);
	unsigned parseUnsignedIntMathExpression(const char *text, unsigned (INI::*valueParser)(const char *token));
	unsigned scanUnsignedInt(const char *token);
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
// 0x8FE2FC -- the same chain the scanInt helper throws through). Its
// content is never compared; the real chain lives in the retail image.
struct ScanUnsignedIntThrowInfoAnchor { int a; int b; int c; int d; };
static const ScanUnsignedIntThrowInfoAnchor scanUnsignedIntThrowInfoAnchor = { 0, 0, 0, 0 };

// ?scanUnsignedInt@INI@@QAEIPBD@Z
unsigned INI::scanUnsignedInt(const char *token)
{
	const char *text = preprocessMacro(token);
	if (*text == '#')
		return parseUnsignedIntMathExpression(text, &INI::scanUnsignedInt);
	unsigned value;
	if (sscanf(text, "%u", &value) != 1) {
		INIException e;
		rva002f681_fill(&e, 3, "Expected unsigned integer value, math op, or predefined macro, but found '%s'", text);
		_CxxThrowException(&e, (void *)&scanUnsignedIntThrowInfoAnchor);
	}
	return value;
}
