// Provenance: adapted from reference/open-bfme-1/Code/GameEngine/Source/
// GameLogic/Object/Contain/HordeContainParseSplitResult.cpp. Donor names are
// descriptive, not recovered PC symbols. PC table C45530 has SplitHorde at
// member +1A4 and callback 46F288. Target allocates 12 bytes; string handles
// are +0/+4 and rank +8. StringBase<char>::set is the matched body at 55F5.
// HordeSplitEntrySlot is a local 4-byte POD ABI wrapper, not a claimed EA type.
// The called vector push_back at 4DFCB0 is independently verified over all
// 49 bytes: three-pointer vector layout, dword construct, +4 end increment,
// overflow 2DFCF6 (140 bytes; dword-distance sizing and copying).
// Error labels end the pointer-slot lifetime before constructing INIException;
// this permits the same stack-slot reuse visible in the 277-byte PC body.
// The throw-info object below is an address anchor only, following the matched
// INI_parsePositiveNonZeroReal.cpp convention; its data is not reconstructed.
// cl: /O1 /Oy- /MD /EHs /Oi- /D_STLP_USE_STATIC_LIB
// stlport
// BFME1 HordeContainParseSplitResult.cpp semantic donor. PC table C45530
// SplitHorde -> 46F288; INI colon separators +420; 12-byte split record.
#include <vector>
extern "C" int __cdecl strcmp(const char *, const char *);
extern "C" __declspec(dllimport) int __cdecl atoi(const char *);
template<class T> class StringBase {
    void *m_data;
public:
    StringBase() { m_data = 0; }
    void set(const T *);
};
class INI {
public:
    char unknown[0x420];
    const char *sepsColon;
    const char *getNextToken(const char *);
    const char *getNextTokenOrNull(const char *);
};
class HordeContainSplitEntry {
public:
    StringBase<char> splitResult;
    StringBase<char> unitType;
    int rankNumber;
};
struct HordeSplitEntrySlot { HordeContainSplitEntry *entry; };
namespace _STL {
template <> void vector<HordeSplitEntrySlot>::push_back(const HordeSplitEntrySlot &);
}
struct INIException { char *message; int code; };
extern "C" void rva002f681_fill(void *, int, const char *, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *, void *);
struct SplitThrowInfoAnchor { int a,b,c,d; };
static const SplitThrowInfoAnchor splitThrowInfoAnchor = {0,0,0,0};
void parseHordeContainSplitResult(INI *ini, void *instance, void *store, const void *userData)
{
  {
    HordeContainSplitEntry *entry = new HordeContainSplitEntry;
    HordeSplitEntrySlot slot;
    slot.entry = entry;
    const char *token = ini->getNextTokenOrNull(ini->sepsColon);
    if (!token || strcmp(token, "SplitResult") != 0) goto invalidTarget;
    entry->splitResult.set(ini->getNextToken(ini->sepsColon));
    token = ini->getNextTokenOrNull(ini->sepsColon);
    if (!token || strcmp(token, "UnitType") != 0) goto invalidResult;
    entry->unitType.set(ini->getNextToken(ini->sepsColon));
    token = ini->getNextTokenOrNull(ini->sepsColon);
    if (token && strcmp(token, "RankNumber") == 0)
        entry->rankNumber = atoi(ini->getNextToken(ini->sepsColon));
    else
        entry->rankNumber = 0;
    ((_STL::vector<HordeSplitEntrySlot> *)store)->push_back(slot);
    return;
  }
invalidResult:
    {
        INIException e;
        rva002f681_fill(&e, 3, "'Result' expected");
        _CxxThrowException(&e, (void *)&splitThrowInfoAnchor);
    }
invalidTarget:
    {
        INIException e;
        rva002f681_fill(&e, 3, "'Target' expected");
        _CxxThrowException(&e, (void *)&splitThrowInfoAnchor);
    }
}
