// cl: /O1 /GX /DNDEBUG /MD
//
// ?friend_newModuleData@CrateCollideModuleData@@SAPAVModuleData@@PAVINI@@@Z,
// retail 0x002510DF, 81 bytes. Dedicated TU: the factory news 0x5C, runs the
// declared-only nullary ctor (pinned at 0x4BC657; this factory plus subclass
// base-calls at 0x255A72/0x2562FD), then feeds the new data plus the class
// parse proc (rowed at 0x4BC7FE, pushed immediate, no pin) to
// INI::initFromINIMultiProc (rowed at 0x2DEB5) when ini is non-null. Operator
// new and __EH_prolog resolve via their rows. The TU-local class keeps only
// size and virtuality (vptr plus 0x58 pad for the 0x5C news size). Recipe:
// ToppleUpdateModuleDataFriendNew.cpp. Class identity is the rowed
// CrateCollideModuleData::buildFieldParse proc (RequiredKindOf plus
// ForbiddenKindOf plus ForbidOwnerPlayer plus BuildingPickup plus HumanOnly
// plus PickupScience plus ExecuteFX plus ExecuteAnimation plus
// ExecuteAnimationTime plus ExecuteAnimationZRise plus ExecuteAnimationFades
// per the ZH CrateCollide.cpp donor) pushed as the factory's proc immediate;
// the ctor installs vtable 0x00C5A660 and fits the 0x5C news size.

class ModuleData;
class INI;
class MultiIniFieldParse;

class INI
{
public:
	void initFromINIMultiProc(void *what, void (__cdecl *proc)(MultiIniFieldParse &));
};

class CrateCollideModuleData
{
public:
	CrateCollideModuleData();
	virtual ~CrateCollideModuleData();
	static void buildFieldParse(MultiIniFieldParse &parse);
	static ModuleData *friend_newModuleData(INI *ini);

private:
	unsigned char m_pad[0x5C - 4];
};

// ?friend_newModuleData@CrateCollideModuleData@@SAPAVModuleData@@PAVINI@@@Z
ModuleData *CrateCollideModuleData::friend_newModuleData(INI *ini)
{
	CrateCollideModuleData *data = new CrateCollideModuleData;
	if (ini)
		ini->initFromINIMultiProc(data, CrateCollideModuleData::buildFieldParse);
	return reinterpret_cast<ModuleData *>(data);
}
