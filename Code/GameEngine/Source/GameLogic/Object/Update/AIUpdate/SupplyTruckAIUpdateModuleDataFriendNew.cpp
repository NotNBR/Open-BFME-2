// cl: /O1 /GX /DNDEBUG /MD
//
// ?friend_newModuleData@SupplyTruckAIUpdateModuleData@@SAPAVModuleData@@PAVINI@@@Z,
// retail 0x002513E8, 81 bytes. Dedicated TU: the factory news 0x64, runs the
// declared-only nullary ctor (pinned at 0x4BF59F, sole caller is this
// factory), then feeds the new data plus the class parse proc (pinned at
// 0x4BFDF6, pushed immediate) to INI::initFromINIMultiProc (rowed at
// 0x2DEB5) when ini is non-null. Operator new and __EH_prolog resolve via
// their rows. The TU-local class keeps only size and virtuality (vptr plus
// 0x60 pad). Recipe: ToppleUpdateModuleDataFriendNew.cpp. Class identity is
// the pinned SupplyTruckAIUpdateModuleData::buildFieldParse proc (MaxHealth
// plus MaxHealthDamaged plus MaxHealthReallyDamaged plus InitialHealth plus
// RecoveryTime plus DodgePercent per the factory proc table) pushed as the
// factory's proc immediate; the ctor installs vtable 0x00C5AFB8 and fits the
// 0x64 news size and serves as the base of the ChinookAIUpdateModuleData
// ctor.

class ModuleData;
class INI;
class MultiIniFieldParse;

class INI
{
public:
	void initFromINIMultiProc(void *what, void (__cdecl *proc)(MultiIniFieldParse &));
};

class SupplyTruckAIUpdateModuleData
{
public:
	SupplyTruckAIUpdateModuleData();
	virtual ~SupplyTruckAIUpdateModuleData();
	static void buildFieldParse(MultiIniFieldParse &parse);
	static ModuleData *friend_newModuleData(INI *ini);

private:
	unsigned char m_pad[0x64 - 4];
};

// ?friend_newModuleData@SupplyTruckAIUpdateModuleData@@SAPAVModuleData@@PAVINI@@@Z
ModuleData *SupplyTruckAIUpdateModuleData::friend_newModuleData(INI *ini)
{
	SupplyTruckAIUpdateModuleData *data = new SupplyTruckAIUpdateModuleData;
	if (ini)
		ini->initFromINIMultiProc(data, SupplyTruckAIUpdateModuleData::buildFieldParse);
	return reinterpret_cast<ModuleData *>(data);
}
