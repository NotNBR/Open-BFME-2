// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
// Reference-first: BFME1 Common/INI/ini.cpp parseDamageTypeFlags, itself from
// GeneralsMD Common/INI/INI.cpp. PC deltas: member scanIndexList and the
// established INIException filler/throw ABI. PC FieldParse DamageTypes and
// DamageFXTypes callbacks identify this full 192-byte body at RVA 0x338CD0.
// BFME2DamageTypeNames is a descriptive alias of the verified FORCE..POISON
// pointer array at VA 0xDBE858, not fabricated source data. Exception throwinfo
// anchor denotes the existing INIException chain at VA 0xCFE2FC.
class INI {
public:
    const char *getNextToken(const char *seps);
    const char *getNextTokenOrNull(const char *seps);
    int scanIndexList(const char *token, const char * const *names);
    static void parseDamageTypeFlags(INI *, void *, void *, const void *);
    static void parseDeathTypeFlags(INI *, void *, void *, const void *);
};
extern const char * const BFME2DamageTypeNames[];
extern const char * const BFME2DeathTypeNames[];
extern "C" __declspec(dllimport) int __cdecl _strcmpi(const char *, const char *);
struct INIException { char *message; int code; };
extern "C" void rva002f681_fill(void *, int, const char *, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *, void *);
struct FlagsThrowInfoAnchor { int a,b,c,d; };
static const FlagsThrowInfoAnchor flagsThrowInfoAnchor = {0,0,0,0};

void INI::parseDamageTypeFlags(INI *ini, void *, void *store, const void *)
{
    unsigned int flags = 0xFFFFFFFF;
    for (const char *token=ini->getNextToken(0); token; token=ini->getNextTokenOrNull(0)) {
        if (_strcmpi(token,"ALL")==0) { flags=0xFFFFFFFF; continue; }
        if (_strcmpi(token,"NONE")==0) { flags=0; continue; }
        if (token[0]=='+') {
            int bit=ini->scanIndexList(token+1,BFME2DamageTypeNames);
            flags |= 1 << (bit-1);
            continue;
        }
        if (token[0]=='-') {
            int bit=ini->scanIndexList(token+1,BFME2DamageTypeNames);
            flags &= ~(1 << (bit-1));
            continue;
        }
        INIException e;
        rva002f681_fill(&e,5,"ALL, NONE, + or - expected");
        _CxxThrowException(&e,(void *)&flagsThrowInfoAnchor);
    }
    *(unsigned int *)store=flags;
}

// PC RVA 0x338D91; DeathTypes table and NORMAL..SLAUGHTERED names at VA 0xDBE8D8.
void INI::parseDeathTypeFlags(INI *ini, void *, void *store, const void *)
{
    unsigned int flags = 0xFFFFFFFF;
    for (const char *token=ini->getNextToken(0); token; token=ini->getNextTokenOrNull(0)) {
        if (_strcmpi(token,"ALL")==0) { flags=0xFFFFFFFF; continue; }
        if (_strcmpi(token,"NONE")==0) { flags=0; continue; }
        if (token[0]=='+') {
            int bit=ini->scanIndexList(token+1,BFME2DeathTypeNames);
            flags |= 1 << (bit-1);
            continue;
        }
        if (token[0]=='-') {
            int bit=ini->scanIndexList(token+1,BFME2DeathTypeNames);
            flags &= ~(1 << (bit-1));
            continue;
        }
        INIException e;
        rva002f681_fill(&e,5,"ALL, NONE, +, or - expected");
        _CxxThrowException(&e,(void *)&flagsThrowInfoAnchor);
    }
    *(unsigned int *)store=flags;
}
