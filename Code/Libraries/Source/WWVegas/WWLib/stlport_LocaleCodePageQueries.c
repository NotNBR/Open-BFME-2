// cl: /O2 /MD
// STLport 4.5.3 Win32 locale code-page helpers.
// Trimmed to the five bodies game.dat keeps: the default-locale and
// ctype-name entry points plus the three static workers they inline or call
// (__GetLocaleName, __ConvertToCP, __GetDefaultCP). The donor's Rva* probe
// wrappers and T3 guess bodies stay out: their names are this sweep's pick
// among ICF twins, so they get no row and no definition here.
// __intGetACP/__intGetOCP are static here (extern in the donor) so the only
// out-of-line defs are the two rowed entry points; inlining into the callers
// is unchanged, which is what the byte match checks.

typedef unsigned long LCID;
typedef unsigned int bfme_size_t;

#define LOCALE_IDEFAULTCODEPAGE 0x0000000b
#define LOCALE_IDEFAULTANSICODEPAGE 0x00001004

__declspec(dllimport) int __stdcall GetLocaleInfoA(
    LCID locale, unsigned long type, char *data, int count);
__declspec(dllimport) int __cdecl atoi(const char *text);
__declspec(dllimport) void *__cdecl malloc(unsigned int size);
__declspec(dllimport) void __cdecl free(void *memory);
__declspec(dllimport) char *__cdecl strcpy(char *destination, const char *source);
__declspec(dllimport) char *__cdecl strcat(char *destination, const char *source);
__declspec(dllimport) unsigned int __cdecl strlen(const char *text);
__declspec(dllimport) void *__cdecl memcpy(void *destination, const void *source,
    unsigned int count);
__declspec(dllimport) int __stdcall lstrcmpiA(const char *left, const char *right);
__declspec(dllimport) int __stdcall EnumSystemLocalesA(
    int (__stdcall *callback)(char *), unsigned long flags);
__declspec(dllimport) int __stdcall MultiByteToWideChar(
    unsigned int codePage, unsigned long flags, const char *source, int sourceCount,
    unsigned short *destination, int destinationCount);
__declspec(dllimport) int __stdcall WideCharToMultiByte(
    unsigned int codePage, unsigned long flags, const unsigned short *source,
    int sourceCount, char *destination, int destinationCount,
    const char *defaultChar, int *usedDefaultChar);

typedef struct _Locale_ctype_t
{
    LCID lcid;
    int cp;
} _Locale_ctype_t;

static void my_ltoa(long value, char *buf)
{
    char reverse[64];
    char *ptr = reverse;
    if (value == 0)
        *ptr++ = '0';
    else
    {
        for (; value != 0; value /= 10)
            *ptr++ = (int)(value % 10) + '0';
    }
    while (ptr > reverse)
        *buf++ = *--ptr;
    *buf = '\0';
}

static int __intGetACP(LCID lcid);
static int __intGetOCP(LCID lcid);

static int __intGetACP(LCID lcid)
{
    char cp[6];
    GetLocaleInfoA(lcid, LOCALE_IDEFAULTANSICODEPAGE, cp, 6);
    return atoi(cp);
}

static int __intGetOCP(LCID lcid)
{
    char cp[6];
    GetLocaleInfoA(lcid, LOCALE_IDEFAULTCODEPAGE, cp, 6);
    return atoi(cp);
}

static int __GetDefaultCP(LCID lcid)
{
    int cp = __intGetACP(lcid);
    if (cp == 0)
        return __intGetOCP(lcid);
    return cp;
}

// The donor calls this worker from two Rva* probe wrappers that game.dat
// does not keep. Two static shims preserve the dual-caller shape that emits
// the worker out of line; both shims are unreferenced and leave the object.
static char *__ConvertToCP(int fromCP, int toCP, const char *from,
    bfme_size_t size, bfme_size_t *resultSize)
{
    int wideSize;
    int bufferSize;
    unsigned short *wideBuffer;
    char *buffer;

    wideSize = MultiByteToWideChar(fromCP, 1, from, size, 0, 0);
    wideBuffer = (unsigned short *)malloc(sizeof(unsigned short) * wideSize);
    MultiByteToWideChar(fromCP, 1, from, size, wideBuffer, wideSize);

    bufferSize = WideCharToMultiByte(toCP, 0x220, wideBuffer, wideSize,
        0, 0, 0, 0);
    buffer = (char *)malloc(bufferSize);
    WideCharToMultiByte(toCP, 0x220, wideBuffer, wideSize,
        buffer, bufferSize, 0, 0);

    free(wideBuffer);
    *resultSize = bufferSize;
    return buffer;
}

static char *__ConvertToCPKeepAliveA(int fromCP, int toCP, const char *from,
    bfme_size_t size, bfme_size_t *resultSize)
{
    return __ConvertToCP(fromCP, toCP, from, size, resultSize);
}

static char *__ConvertToCPKeepAliveB(int fromCP, int toCP, const char *from,
    bfme_size_t size, bfme_size_t *resultSize)
{
    return __ConvertToCP(fromCP, toCP, from, size, resultSize);
}

static int __GetDefaultCPKeepAliveA(LCID lcid)
{
    return __GetDefaultCP(lcid);
}

static int __GetDefaultCPKeepAliveB(LCID lcid)
{
    return __GetDefaultCP(lcid);
}

static char *__GetLocaleName(LCID lcid, const char *cp, char *buf)
{
    char lang[65];
    char country[65];
    GetLocaleInfoA(lcid, 0x1001, lang, 64);
    GetLocaleInfoA(lcid, 0x1002, country, 64);
    strcpy(buf, lang);
    strcat(buf, "_");
    strcat(buf, country);
    strcat(buf, ".");
    return strcat(buf, cp);
}

// __Locale_common_default
char *_Locale_common_default(char *buf)
{
    char cp[6];
    int codePage = __intGetACP(0x400);
    if (!codePage)
        codePage = __intGetOCP(0x400);
    my_ltoa(codePage, cp);
    return __GetLocaleName(0x400, cp, buf);
}

// __Locale_ctype_name
char *_Locale_ctype_name(const void *loc, char *buf)
{
    char cpBuf[6];
    _Locale_ctype_t *ctype = (_Locale_ctype_t *)loc;
    my_ltoa(ctype->cp, cpBuf);
    return __GetLocaleName(ctype->lcid, cpBuf, buf);
}
