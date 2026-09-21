// ?parseAllowedFactions@@YAXPAVINI@@PAX1PBX@Z
// partial score=0.8357142857142857 date=2026-09-21
// cl: /O1 /Oy- /EHs /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP=
// stlport
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
class INI { public: static void parseAsciiStringVector(INI *,void *,void *,const void *); };
struct SideFlags { unsigned char human,computer,ai; int team; _STL::set<AsciiString> factions; };
void parseAllowedFactions(INI *ini, void *instance, void *, const void *)
{
    _STL::vector<AsciiString> names;
    INI::parseAsciiStringVector(ini,0,&names,0);
    _STL::set<AsciiString> factions;
    _STL::copy(names.begin(),names.end(),_STL::inserter(factions,factions.begin()));
    ((SideFlags *)instance)->factions.swap(factions);
}
