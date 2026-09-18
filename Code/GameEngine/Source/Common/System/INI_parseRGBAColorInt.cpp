// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi- /arch:SSE
//
// ?parseRGBAColorInt@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002F2FF, 254 bytes.
// Dedicated TU (same INI verb family as INI_parseRGBColor.cpp, framed).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/INI_stl.cpp,
// INI::parseRGBAColorInt): R/G/B/A via getNextTokenOrNull plus stricmp match,
// getNextToken plus scanInt on hit, 0..255 range checks, A defaulting to 255
// when omitted, stored as four ints. BFME2 deltas (all retail-measured): the
// separator is the m_sepsColon member at this+0x420 (direct read, as in
// INI_getNextSubToken.cpp), and each of the three failures (omitted value,
// mismatched name, out-of-range component) throws through the shared filler
// with its own retail format ("can't omit value for color %s", "expected
// '%s'", "color value %s=%i out of range (0..255)") plus _CxxThrowException
// (bare INI_INVALID_DATA in BFME1).

#define NULL 0

class INI
{
public:
	const char *getNextToken(const char *seps);
	const char *getNextTokenOrNull(const char *seps);
	int scanInt(const char *token);
	const char *getSepsColon() { return m_sepsColon; }
	static void parseRGBAColorInt(INI *ini, void *instance, void *store, const void *userData);

private:
	char _pad[0x420];
	const char *m_sepsColon;
};

struct RGBAColorInt
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	unsigned int alpha;
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
struct ParseRGBAColorIntThrowInfoAnchor { int a; int b; int c; int d; };
static const ParseRGBAColorIntThrowInfoAnchor parseRGBAColorIntThrowInfoAnchor = { 0, 0, 0, 0 };

// ?parseRGBAColorInt@INI@@SAXPAV1@PAX1PBX@Z
void INI::parseRGBAColorInt(INI *ini, void * /*instance*/, void *store, const void * /*userData*/)
{
	const char *names[4] = { "R", "G", "B", "A" };
	int colors[4];
	for (int i = 0; i < 4; i++) {
		const char *token = ini->getNextTokenOrNull(ini->getSepsColon());
		if (token == NULL) {
			if (i < 3) {
				INIException e;
				rva002f681_fill(&e, 3, "can't omit value for color %s", names[i]);
				_CxxThrowException(&e, (void *)&parseRGBAColorIntThrowInfoAnchor);
			} else {
				// it's ok for A to be omitted.
				colors[i] = 255;
			}
		} else {
			// if present, the token must match.
			if (_strcmpi(token, names[i]) != 0) {
				INIException e;
				rva002f681_fill(&e, 3, "expected '%s'", names[i]);
				_CxxThrowException(&e, (void *)&parseRGBAColorIntThrowInfoAnchor);
			}
			colors[i] = ini->scanInt(ini->getNextToken(ini->getSepsColon()));
		}
		if (colors[i] < 0 || colors[i] > 255) {
			INIException e;
			rva002f681_fill(&e, 3, "color value %s=%i out of range (0..255)", names[i], colors[i]);
			_CxxThrowException(&e, (void *)&parseRGBAColorIntThrowInfoAnchor);
		}
	}

	//
	// assign the color components to the "RGBAColorInt" pointer at 'store', keep
	// the numbers as between 0 and 255
	//
	RGBAColorInt *theColor = (RGBAColorInt *)store;
	theColor->red = colors[0];
	theColor->green = colors[1];
	theColor->blue = colors[2];
	theColor->alpha = colors[3];
}
