// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi- /arch:SSE
//
// ?parseRGBColor@INI@@SAXPAV1@PAX1PBX@Z, retail 0x002F259, 165 bytes.
// Dedicated TU (same INI verb family as INI_parseAngleReal.cpp, framed).
//
// BFME1 reference (reference/open-bfme-1/Code/GameEngine/Source/Common/INI/INI_stl.cpp,
// INI::parseRGBColor): R/G/B via getNextSubToken + scanInt with 0..255 range
// checks, stored as 1/255-scaled floats. BFME2 deltas (all retail-measured):
// the range failure throws through the shared filler with the retail format
// "color value %s=%i out of range (0..255)" plus _CxxThrowException (bare
// INI_INVALID_DATA in BFME1), and the scale is a multiply by the (1/255)
// reciprocal (retail .rdata 0x7BB8F0) rather than a divide.

class INI
{
public:
	const char *getNextSubToken(const char *expected);
	int scanInt(const char *token);
	static void parseRGBColor(INI *ini, void *instance, void *store, const void *userData);
};

struct RGBColor
{
	float red;
	float green;
	float blue;
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
struct ParseRGBColorThrowInfoAnchor { int a; int b; int c; int d; };
static const ParseRGBColorThrowInfoAnchor parseRGBColorThrowInfoAnchor = { 0, 0, 0, 0 };

// ?parseRGBColor@INI@@SAXPAV1@PAX1PBX@Z
void INI::parseRGBColor(INI *ini, void * /*instance*/, void *store, const void * /*userData*/)
{
	const char *names[3] = { "R", "G", "B" };
	int colors[3];
	for (int i = 0; i < 3; i++) {
		colors[i] = ini->scanInt(ini->getNextSubToken(names[i]));
		if (colors[i] < 0 || colors[i] > 255) {
			INIException e;
			rva002f681_fill(&e, 3, "color value %s=%i out of range (0..255)", names[i], colors[i]);
			_CxxThrowException(&e, (void *)&parseRGBColorThrowInfoAnchor);
		}
	}

	// assign the color components to the "RGBColor" pointer at 'store'
	RGBColor *theColor = (RGBColor *)store;
	theColor->red = colors[0] * (1.0f / 255.0f);
	theColor->green = colors[1] * (1.0f / 255.0f);
	theColor->blue = colors[2] * (1.0f / 255.0f);
}
