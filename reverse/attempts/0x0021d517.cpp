// ?RegisterCreateAHeroAtRva0021D517@@YAXPAVCreateAHeroData@@@Z
// partial score=0.95 date=2026-09-20
// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
#include <vector>
#include <algorithm>
class CreateAHeroData;
namespace _STL {
template<> void vector<CreateAHeroData*>::push_back(CreateAHeroData* const&);
template<> CreateAHeroData** vector<CreateAHeroData*>::erase(CreateAHeroData**);
template<> CreateAHeroData** find(CreateAHeroData**,CreateAHeroData**,CreateAHeroData* const&);
}
extern _STL::vector<CreateAHeroData*> g_CreateAHeroRegistry;
void RegisterCreateAHeroAtRva0021D517(CreateAHeroData* hero) {
    _STL::vector<CreateAHeroData*>::iterator finish = g_CreateAHeroRegistry.end();
    if (_STL::find(g_CreateAHeroRegistry.begin(),finish,hero)==finish)
        g_CreateAHeroRegistry.push_back(hero);
}
void UnregisterCreateAHeroAtRva0021A624(CreateAHeroData* hero) {
    _STL::vector<CreateAHeroData*>::iterator found = _STL::find(g_CreateAHeroRegistry.begin(),g_CreateAHeroRegistry.end(),hero);
    if(found != g_CreateAHeroRegistry.end()) g_CreateAHeroRegistry.erase(found);
}
