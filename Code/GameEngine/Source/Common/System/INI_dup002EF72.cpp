// cl: /O1 /Oy- /DNDEBUG /MD /GX /Oi-
//
// ?dup_002EF72@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002EF72, 78 bytes.
// Dedicated ebp-frame TU (same INI scanner family as INI_scanUnsignedInt.cpp).
//
// Opaque name: max-bounded unsigned parse (value out of range unless
// userData-max is 0 or value fits; literal "value out of range, expected
// 0..%d" takes the max). No BFME1/ZH donor (their parseUnsignedInt has no
// bound). Six direct callers forward (ini, instance, store, max); static:
// no caller sets ecx. userData stays an inline cast throughout: retail
// reloads [ebp+0x14] at all three uses with no register caching.

class INI
{
public:
	const char *getNextToken(const char *seps);
	unsigned scanUnsignedInt(const char *token);
	static void dup_002EF72(INI *ini, void *instance, void *store, const void *userData);
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
struct Dup002EF72ThrowInfoAnchor { int a; int b; int c; int d; };
static const Dup002EF72ThrowInfoAnchor dup002EF72ThrowInfoAnchor = { 0, 0, 0, 0 };

// ?dup_002EF72@INI@@SAXPAV1@PAX1PBX@Z
void INI::dup_002EF72(INI *ini, void *instance, void *store, const void *userData)
{
	unsigned value = ini->scanUnsignedInt(ini->getNextToken(0));
	if ((unsigned)userData != 0 && value > (unsigned)userData) {
		INIException e;
		rva002f681_fill(&e, 3, "value out of range, expected 0..%d", (int)userData);
		_CxxThrowException(&e, (void *)&dup002EF72ThrowInfoAnchor);
	}
	*(unsigned *)store = value;
}
