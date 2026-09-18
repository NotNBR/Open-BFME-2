// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?findUpgradeByKey@UpgradeCenter@@QBEPBVUpgradeTemplate@@W4NameKeyType@@@Z,
// retail 0x0026EEB8, 22 bytes. Dedicated TU (Upgrade.cpp itself is
// unstageable: ~20 unmarked defs trip find_declared_unmatched, same wall as
// marker-less meshmdlio.cpp/meshmatdesc.cpp; drain it via new TUs).
//
// Zero Hour reference
// (reference/open-bfme-1/reference/CnC_Generals_Zero_Hour/Generals/Code/GameEngine/Source/Common/System/Upgrade.cpp,
// UpgradeCenter::findUpgradeByKey): const key-compare walk over the template
// list. BFME2 layout measured from retail: list head at UpgradeCenter+0x0C
// (ZH +0x08), name key at UpgradeTemplate+0x0C (same as ZH), next link at
// +0x64 (ZH +0x108). Leaf: no calls, no pins.

typedef int Int;

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

class UpgradeTemplate
{
public:
	NameKeyType getUpgradeNameKey() const { return m_nameKey; }
	const UpgradeTemplate *friend_getNext() const { return m_next; }

private:
	unsigned char m_unreconstructed_000[0x0C];
	NameKeyType m_nameKey; // +0x0C
	unsigned char m_unreconstructed_010[0x64 - 0x10];
	UpgradeTemplate *m_next; // +0x64
};

class UpgradeCenter
{
public:
	const UpgradeTemplate *findUpgradeByKey(NameKeyType key) const;

private:
	unsigned char m_unreconstructed_000[0x0C];
	UpgradeTemplate *m_upgradeList; // +0x0C
};

// ?findUpgradeByKey@UpgradeCenter@@QBEPBVUpgradeTemplate@@W4NameKeyType@@@Z
const UpgradeTemplate *UpgradeCenter::findUpgradeByKey(NameKeyType key) const
{
	const UpgradeTemplate *upgrade;

	// search list
	for (upgrade = m_upgradeList; upgrade; upgrade = upgrade->friend_getNext())
		if (upgrade->getUpgradeNameKey() == key)
			return upgrade;

	// item not found
	return 0;
}
