// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
//
// ?parseAIKindOfList@@YAXPAVINI@@PBDPAH@Z, retail 0x004E8EA6, 88 bytes.
// Dedicated TU.
//
// Parses an AIKINDOF name list from the INI stream into an int array: the
// first token comes from the throwing getNextToken (an empty list is an
// error) and the rest from getNextTokenOrNull. More than 16 entries throws
// INIException ("In an AIKINDOF list, each type may only appear once",
// retail literal at 0x8627B0 — over 16 names necessarily repeats one of the
// 16 kinds). Sibling of getAIKindOfFromName (same directory); BFME2-added.
//
// Shaping notes:
// - Same /O1 /Oy- /GX- recipe as the sibling mapper TU (frame, no funclets).
// - `__declspec(noreturn)` on _CxxThrowException sinks the fail block last
//   with no dead epilogue (the compiler even pads the int3, matching retail).
//   The sibling TU deliberately keeps the plain declaration: noreturn there
//   is unproven against its landed bytes.
// - The middle parameter is never read by retail (both token calls pass NULL;
//   the first call reuses the just-zeroed loop index for its NULL). It is
//   left unnamed beyond its type; the row notes record this.

class INI
{
public:
	const char *getNextToken(const char *seps);
	const char *getNextTokenOrNull(const char *seps);
};

int getAIKindOfFromName(const char *name);

struct INIException
{
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);

// Address anchor only: the throw site pushes this object's address as an
// immediate (DIR32, copied from retail's throwinfo at 0x8FE2FC). Its content
// is never compared; the real chain lives in the retail image.
struct AIKindOfThrowInfoAnchor { int a; int b; int c; int d; };
static const AIKindOfThrowInfoAnchor aikindThrowInfoAnchor = { 0, 0, 0, 0 };

// ?parseAIKindOfList@@YAXPAVINI@@PBDPAH@Z
void parseAIKindOfList(INI *ini, const char * /*seps*/, int *out)
{
	int i = 0;
	const char *token = ini->getNextToken(0);
	while (token != 0) {
		if (i >= 16)
			goto fail;
		out[i] = getAIKindOfFromName(token);
		token = ini->getNextTokenOrNull(0);
		i++;
	}
	return;
fail:
	{
		INIException e;
		rva002f681_fill(&e, 2, "In an AIKINDOF list, each type may only appear once\n");
		_CxxThrowException(&e, (void *)&aikindThrowInfoAnchor);
	}
}
