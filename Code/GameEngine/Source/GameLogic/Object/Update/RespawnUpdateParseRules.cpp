// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi- /arch:SSE
// PC RespawnUpdate::iniParseDefaultRule; exact name in retail diagnostics.
// Preview RespawnRules crosswalk selected the family; PC C56270 independently
// registers this callback with the rules tree at module offset10C.
// No clean BFME1 or GeneralsMD RespawnUpdate parser body was found. Reuse the
// existing INI parser/exception idioms and STLport tree semantics; reconstruct
// the sequential field checks as real C++ from the full524B PC body.
// BFME2RespawnRuleTree/RespawnRule/RespawnInsertResult are descriptive facades,
// not asserted original type spellings. The tree starts with its header ptr;
// node+10 is the unsigned level key. Find357180 is the already recovered
// unsigned STL tree lookup. Insert4AFB2B is a35B pair-copy wrapper around
// unique insertion4AF4A6; it returns the node and bool (true iff inserted).
// Throw-info anchor refers to the existing retail INIException chain CFE2FC.
#include <string.h>
class INI {
public:
    const char *getNextToken(const char *);
    const char *getSepsColon() const { return colon; }
    static void parseBool(INI *, void *, void *, const void *);
    static void parseInt(INI *, void *, void *, const void *);
    static void dup_002EF72(INI *, void *, void *, const void *);
    static void parsePercentToReal(INI *, void *, void *, const void *);
    char unused[0x420]; const char *colon;
};
extern "C" __declspec(dllimport) int __cdecl _strcmpi(const char *, const char *);
struct INIException { char *message; int code; };
extern "C" void rva002f681_fill(void *, int, const char *, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *, void *);
struct RespawnThrowInfoAnchor { int a,b,c,d; };
static const RespawnThrowInfoAnchor respawnThrowInfoAnchor = {0,0,0,0};
struct RespawnRule {
    unsigned level, cost; int time; float health; bool autoSpawn;
    RespawnRule():level(1),cost(0),time(0),health(1.0f),autoSpawn(false) {}
};
struct RespawnInsertResult { void *node; bool inserted; };
struct BFME2RespawnRuleTree {
    void *sentinel;
    void *find(const unsigned &) const;
    RespawnInsertResult insert(const RespawnRule &);
};
class RespawnUpdate {
public:
    static void iniParseDefaultRule(INI *, void *, void *, const void *);
};
#define THROW0(message) { INIException e; rva002f681_fill(&e,3,message); _CxxThrowException(&e,(void *)&respawnThrowInfoAnchor); }
#define THROW1(message,token) { INIException e; rva002f681_fill(&e,3,message,token); _CxxThrowException(&e,(void *)&respawnThrowInfoAnchor); }
#define FIELD(key,diagnostic,parser,member) \
    token=ini->getNextToken(ini->getSepsColon()); \
    if(!token || _strcmpi(token,key)!=0) \
        THROW1("RespawnUpdate::iniParseDefaultRule -- RespawnRules entry expecting '" diagnostic "' entry. You specified %s.",token) \
    if(strcmp(token,key)!=0) \
        THROW1("RespawnUpdate::iniParseDefaultRule -- RespawnRules entry for '" diagnostic "' is case sensitive. You specified %s.",token) \
    INI::parser(ini,instance,&rule.member,0);
void RespawnUpdate::iniParseDefaultRule(INI *ini, void *instance, void *store, const void *) {
    RespawnRule rule;
    BFME2RespawnRuleTree *rules=(BFME2RespawnRuleTree *)store;
    if(rules->find(rule.level)!=rules->sentinel)
        THROW0("RespawnUpdate::iniParseDefaultRule -- Duplicate RespawnRules entry.")
    const char *token;
    FIELD("AutoSpawn","AutoSpawn:Yes' or 'AutoSpawn:No",parseBool,autoSpawn)
    FIELD("Cost","Cost",dup_002EF72,cost)
    FIELD("Time","Time",parseInt,time)
    FIELD("Health","Health",parsePercentToReal,health)
    rules->insert(rule);
}
