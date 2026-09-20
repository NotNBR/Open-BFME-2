// stlport
// cl: /MD /O1 /GX /DNDEBUG /DWIN32 /D_WINDOWS /D_STLP_USE_STATIC_LIB /D_CRTIMP= /D_STLP_USE_MALLOC /D_STLP_NO_EXCEPTIONS
// Retail RVA 0x00360BB8, 70 bytes.
// ArmorStore::ArmorStore: base SubsystemInterface init (retail 0x001B4E63,
// which installs vtable 0xBD77A0 and zeroes +4/+8, proving the BFME2 base is
// 0xC bytes, not the ZH 8), derived vtable 0xC16988, member hash_map default
// construction (retail 0x00360B99) then hashtable clear (rowed 0x001DBCDC).
// Shard: Armor.cpp sees the ZH 8-byte SubsystemInterface, which puts the map
// at +0x8; the TU-local base below carries the retail-proven extra members.

#include <hash_map>
#include <cstddef>

enum NameKeyType
{
	NAMEKEY_INVALID = 0,
	NAMEKEY_MAX = 1 << 23,
	FORCE_NAMEKEYTYPE_LONG = 0x7fffffff
};

namespace rts
{

template <typename T> struct hash
{
	size_t operator()(const T &value) const;
};

}

class ArmorTemplate
{
public:
	float m_damageCoefficient[38]; // DAMAGE_NUM_TYPES, ZH count
};

class SubsystemInterface
{
public:
	SubsystemInterface();
	virtual ~SubsystemInterface();
	virtual void init() = 0;
	virtual void reset() = 0;
	virtual void update() = 0;

private:
	unsigned char m_bfme04[8]; // retail ctor zeroes byte@4 and dword@8
};

typedef std::hash_map<
	NameKeyType,
	ArmorTemplate,
	rts::hash<NameKeyType>,
	std::equal_to<NameKeyType> > ArmorTemplateMap;

class ArmorStore : public SubsystemInterface
{
public:
	ArmorStore();
	void init() { }
	void reset() { }
	void update() { }

private:
	ArmorTemplateMap m_armorTemplates; // +0x0C
};

ArmorStore::ArmorStore()
{
	m_armorTemplates.clear();
}
