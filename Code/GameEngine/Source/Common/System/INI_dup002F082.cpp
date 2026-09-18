// cl: /O1 /Oy- /arch:SSE /DNDEBUG /MD /GX /Oi-
//
// ?dup_002F082@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002F082, 83 bytes.
// Dedicated ebp-frame TU (twin of INI_dup002F02F.cpp with swapped polarity).
//
// Opaque name: stores the scanned float and throws iff it is positive
// (allows zero and negatives; literal "expected <= 0"). No BFME1/ZH donor.
// Field-table user: ClearanceMinHeightFraction (sibling of ClearanceMinHeight,
// which takes the >=0 twin). The Yoda condition is load-bearing: evaluating
// 0.0 first emits fldz ahead of the value dup (fld st(1)), where the twins'
// value-first form emits fld st(0) ahead of fldz.

class INI
{
public:
	const char *getNextToken(const char *seps);
	float scanReal(const char *token);
	static void dup_002F082(INI *ini, void *instance, void *store, const void *userData);
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
struct Dup002F082ThrowInfoAnchor { int a; int b; int c; int d; };
static const Dup002F082ThrowInfoAnchor dup002F082ThrowInfoAnchor = { 0, 0, 0, 0 };

// ?dup_002F082@INI@@SAXPAV1@PAX1PBX@Z
void INI::dup_002F082(INI *ini, void *instance, void *store, const void *userData)
{
	float value = ini->scanReal(ini->getNextToken(0));
	*(float *)store = value;
	if (0.0f < value) {
		INIException e;
		rva002f681_fill(&e, 3, "invalid Real value %1.7f -- expected <= 0", value);
		_CxxThrowException(&e, (void *)&dup002F082ThrowInfoAnchor);
	}
}
