// cl: /O2 /MD
// Distinct TU for the STLport locale donor's EnumLocalesProcA (retail
// 0x00021470, 242B). The donor path is occupied by the facet family, and this
// body is the only one that calls the import retail binds as undecorated
// "lstrcmpi" (IAT 0x00BBA150), so the TU declares that spelling instead of
// the donor's lstrcmpiA. No other definition is carried: the gate only runs
// over the one body this TU exists to land.

typedef unsigned long LCID;

extern "C" {

__declspec(dllimport) int __stdcall GetLocaleInfoA(
    LCID locale, unsigned long type, char *data, int count);
// Retail imports this name with no A/W suffix (IAT slot 0x00BBA150); the
// donor's lstrcmpiA spelling cannot resolve there.
__declspec(dllimport) int __stdcall lstrcmpi(const char *left, const char *right);

int __stdcall EnumLocalesProcA(char *);

static int __FindFlag;
static LCID __FndLCID;
static const char *__FndLang;
static const char *__FndCtry;

static char __LocaleLanguageBuffer[65];
static char __LocaleCountryBuffer[65];

static LCID LocaleFromHex(const char *locale)
{
    unsigned long result = 0;
    int digit;
    while (*locale)
    {
        result <<= 4;
        digit = (*locale >= '0' && *locale <= '9') ? *locale - '0' :
            (*locale >= 'A' && *locale <= 'F') ? (*locale - 'A') + 10 :
            (*locale - 'a') + 10;
        result += digit;
        locale++;
    }
    return (LCID)result;
}

int __stdcall EnumLocalesProcA(char *locale)
{
    LCID lcid = LocaleFromHex(locale);
    int foundLanguage = 0;
    int foundCountry = (__FndCtry == 0);
    GetLocaleInfoA(lcid, 0x1001, __LocaleLanguageBuffer, 64);
    if (lstrcmpi(__LocaleLanguageBuffer, __FndLang) == 0)
        foundLanguage = 1;
    else {
        GetLocaleInfoA(lcid, 3, __LocaleLanguageBuffer, 64);
        if (lstrcmpi(__LocaleLanguageBuffer, __FndLang) == 0)
            foundLanguage = 1;
    }
    if (__FndCtry != 0) {
        GetLocaleInfoA(lcid, 0x1002, __LocaleCountryBuffer, 64);
        if (lstrcmpi(__LocaleCountryBuffer, __FndCtry) == 0)
            foundCountry = 1;
        else {
            GetLocaleInfoA(lcid, 7, __LocaleCountryBuffer, 64);
            if (lstrcmpi(__LocaleCountryBuffer, __FndCtry) == 0)
                foundCountry = 1;
        }
    }
    if (foundLanguage && foundCountry) {
        __FndLCID = lcid;
        __FindFlag = 1;
        return 0;
    }
    return 1;
}

} // extern "C"
