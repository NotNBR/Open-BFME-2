// cl: /O2 /MD
// STLport 4.5.3 _Locale_toupper/_Locale_tolower (retail 0x000219E0/0x00021B10).
// Distinct TU under WWLib: Code/stlport/ is not an allowed root for a new
// source, so these donor bodies live here like stlport_LocaleStrcmp.c.
// Trimmed to the two T1 bodies game.dat keeps; the donor's _Locale_strcmp
// already lives in stlport_LocaleStrcmp.c and the KeepDefault helpers are
// unserved (no row, no definition). Static workers stay static exactly
// like the donor.
typedef unsigned long LCID;
typedef unsigned int UINT;

__declspec(dllimport) int __stdcall GetLocaleInfoA(
    LCID locale, unsigned long type, char *data, int count);
__declspec(dllimport) int __cdecl atoi(const char *text);
__declspec(dllimport) int __stdcall LCMapStringA(
    LCID locale, unsigned long flags, const char *src, int srcCount,
    char *dest, int destCount);
__declspec(dllimport) int __stdcall MultiByteToWideChar(
    unsigned int codePage, unsigned long flags, const char *source, int sourceCount,
    unsigned short *destination, int destinationCount);
__declspec(dllimport) int __stdcall WideCharToMultiByte(
    unsigned int codePage, unsigned long flags, const unsigned short *source,
    int sourceCount, char *destination, int destinationCount,
    const char *defaultChar, int *usedDefaultChar);

typedef struct _Locale_ctype_t {
    LCID lcid;
    UINT cp;
} _Locale_ctype_t;

static int __intGetACP(LCID lcid)
{
    char cp[6];
    GetLocaleInfoA(lcid, 0x1004, cp, 6);
    return atoi(cp);
}

static int __intGetOCP(LCID lcid)
{
    char cp[6];
    GetLocaleInfoA(lcid, 0xb, cp, 6);
    return atoi(cp);
}

static int __GetDefaultCP(LCID lcid)
{
    int cp = __intGetACP(lcid);
    if (cp == 0)
        return __intGetOCP(lcid);
    return cp;
}

int _Locale_toupper(_Locale_ctype_t *ltype, int c)
{
    char buf[2], out_buf[2];
    buf[0] = (char)c;
    buf[1] = 0;
    if ((UINT)__GetDefaultCP(ltype->lcid) == ltype->cp) {
        LCMapStringA(ltype->lcid, 0x01000200, buf, 2, out_buf, 2);
        return (signed char)out_buf[0];
    } else {
        unsigned short wbuf[2];
        MultiByteToWideChar(ltype->cp, 1, buf, 2, wbuf, 2);
        WideCharToMultiByte(__GetDefaultCP(ltype->lcid), 0x220, wbuf, 2, buf, 2, 0, 0);
        LCMapStringA(ltype->lcid, 0x01000200, buf, 2, out_buf, 2);
        MultiByteToWideChar(__GetDefaultCP(ltype->lcid), 1, out_buf, 2, wbuf, 2);
        WideCharToMultiByte(ltype->cp, 0x220, wbuf, 2, out_buf, 2, 0, 0);
        return (signed char)out_buf[0];
    }
}

int _Locale_tolower(_Locale_ctype_t *ltype, int c)
{
    char buf[2], out_buf[2];
    buf[0] = (char)c;
    buf[1] = 0;
    if ((UINT)__GetDefaultCP(ltype->lcid) == ltype->cp) {
        LCMapStringA(ltype->lcid, 0x01000100, buf, 2, out_buf, 2);
        return (signed char)out_buf[0];
    } else {
        unsigned short wbuf[2];
        MultiByteToWideChar(ltype->cp, 1, buf, 2, wbuf, 2);
        WideCharToMultiByte(__GetDefaultCP(ltype->lcid), 0x220, wbuf, 2, buf, 2, 0, 0);
        LCMapStringA(ltype->lcid, 0x01000100, buf, 2, out_buf, 2);
        MultiByteToWideChar(__GetDefaultCP(ltype->lcid), 1, out_buf, 2, wbuf, 2);
        WideCharToMultiByte(ltype->cp, 0x220, wbuf, 2, out_buf, 2, 0, 0);
        return (signed char)out_buf[0];
    }
}
