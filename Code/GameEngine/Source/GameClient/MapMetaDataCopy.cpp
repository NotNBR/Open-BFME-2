// cl: /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// Reference: BFME1 GameClient/MapMetaData_ctor.cpp, MapMetaData_assign.cpp,
// MapMetaData_dtor.cpp and ZH GeneralsMD MapUtil.h; BFME2 has a new word at F4.
// Named BFME2 GUI methods independently prove fields0/4/20/50/F8/FC.
// Retail copy3039E8 is257B and copies this entire256B record member by member.
// Waypoint copy303359 copies the typed tree plus count at C; its tree-copy
// chain3025A5->301F9B->301BBF->3012CE preserves the verified coordinate payload.
// List copy2820DD allocates20B nodes:8B links plus Coord3D; members48/4C
// are the reference supply/tech-position lists. Player copy303374 uses eight
// records of20B, with real copy302CE2 and dtor22D920 callbacks. Their three
// flags/team/map layout also agrees with the matched MPPositionInfo writer.
// Unknown BFME2 wordF4 remains opaque; no extra meaning is inferred.
#include <list>
#include <map>
#include <set>
template<class T> class StringBase { void *m_data; void releaseBuffer(); public: StringBase(const StringBase &); protected: __forceinline ~StringBase() { releaseBuffer(); } };
class UnicodeString : private StringBase<unsigned short> { public: __forceinline UnicodeString(const UnicodeString &o) : StringBase<unsigned short>(o) {} __forceinline ~UnicodeString() {} };
class AsciiString : private StringBase<char> { public: __forceinline AsciiString(const AsciiString &o) : StringBase<char>(o) {} __forceinline ~AsciiString() {} };
struct Coord3D { float x,y,z; };
struct Region3D { Coord3D lo,hi; Region3D(const Region3D &); };
typedef _STL::list<Coord3D> Coord3DList;
// Instantiate the reference coordinate-list copy and its typed helpers.
class WaypointMap : public _STL::map<AsciiString,Coord3D> { int numStartSpots; public: WaypointMap(const WaypointMap &); };
// The copy chain301EF6->301A3E->3012B0->2C552 proves a string-only20B node:
// these faction names form a set, not a map with an unobserved mapped value.
struct PlayerPosition { unsigned char human,computer,loadAIScripts; int forceTeam; _STL::set<AsciiString> factions; ~PlayerPosition(); };
// Implicit copy emits the real EH array-copy helper: eight20B records.
// Callback302CE2 copies three flags/team/map; callback22D920 destroys map+8.
struct MapPlayers { PlayerPosition items[8]; };
class MapMetaData {
    UnicodeString displayName,description; Region3D extent; int numPlayers;
    unsigned char isMultiplayer,isScenarioMP,isOfficial;
    unsigned int filesize,crc,timestampLo,timestampHi;
    WaypointMap waypoints; Coord3DList supplyPositions,techPositions;
    AsciiString fileName; MapPlayers players; unsigned int wordF4;
    UnicodeString cachedDisplayName,cachedDescription;
public: MapMetaData(const MapMetaData &); ~MapMetaData();
};
MapMetaData::MapMetaData(const MapMetaData &o)
    : displayName(o.displayName), description(o.description), extent(o.extent), numPlayers(o.numPlayers),
      isMultiplayer(o.isMultiplayer), isScenarioMP(o.isScenarioMP), isOfficial(o.isOfficial),
      filesize(o.filesize), crc(o.crc), timestampLo(o.timestampLo), timestampHi(o.timestampHi),
      waypoints(o.waypoints), supplyPositions(o.supplyPositions), techPositions(o.techPositions),
      fileName(o.fileName), players(o.players), wordF4(o.wordF4),
      cachedDisplayName(o.cachedDisplayName), cachedDescription(o.cachedDescription) {}
typedef char SizeCheck[sizeof(MapMetaData)==0x100?1:-1];

// The tree at3025A5 is already byte-verified under its earlier opaque-payload
// model; the metadata reference and its coordinate copy chain prove this alias.
WaypointMap::WaypointMap(const WaypointMap &o)
    : _STL::map<AsciiString,Coord3D>(o), numStartSpots(o.numStartSpots) {}

// Retail faction-tree destruction uses the BFME null-checked header free.
typedef _STL::_Rb_tree<AsciiString,AsciiString,_STL::_Identity<AsciiString>,_STL::less<AsciiString>,_STL::allocator<AsciiString> > FactionSetTree;
template FactionSetTree::~_Rb_tree();

PlayerPosition::~PlayerPosition() {}

// Reference member destruction; retail22DBC6 is the complete156B body.
// POD coordinate-list cleanup is shared with the already-held integer list.
MapMetaData::~MapMetaData() {}
