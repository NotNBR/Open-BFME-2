// cl: /O1 /Oy- /arch:SSE /DNDEBUG /MD /GX /Oi-
//
// ?dup_002F02F@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002F02F, 83 bytes.
// Dedicated ebp-frame TU (twin of INI_parsePositiveNonZeroReal.cpp).
//
// Opaque name: the body stores the scanned float and throws iff it is
// negative (allows zero; literal "expected >= 0"), but no BFME1/ZH donor
// names it (their only twin is parsePositiveNonZeroReal, which throws on
// zero too). Field-table users include UnpackingVariation. Static: only
// data-table references (no direct calls to set ecx).

class INI
{
public:
	const char *getNextToken(const char *seps);
	float scanReal(const char *token);
	static void dup_002F02F(INI *ini, void *instance, void *store, const void *userData);
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
struct Dup002F02FThrowInfoAnchor { int a; int b; int c; int d; };
static const Dup002F02FThrowInfoAnchor dup002F02FThrowInfoAnchor = { 0, 0, 0, 0 };

// ?dup_002F02F@INI@@SAXPAV1@PAX1PBX@Z
void INI::dup_002F02F(INI *ini, void *instance, void *store, const void *userData)
{
	float value = ini->scanReal(ini->getNextToken(0));
	*(float *)store = value;
	if (value < 0.0f) {
		INIException e;
		rva002f681_fill(&e, 3, "invalid Real value %1.7f -- expected >= 0", value);
		_CxxThrowException(&e, (void *)&dup002F02FThrowInfoAnchor);
	}
}
