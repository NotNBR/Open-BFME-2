// cl: /O1 /GX /DNDEBUG /MD
//
// ?friend_newModuleData@HordeUpdateModuleData@@SAPAVModuleData@@PAVINI@@@Z,
// retail 0x0024E1AB, 81 bytes. Dedicated TU: the factory news 0x44, runs the
// declared-only ctor (pinned at 0x496FA5, sole caller is this factory), then
// feeds the new data plus the class parse proc (rowed at 0x4976CA, pushed
// immediate, no pin) to INI::initFromINIMultiProc (rowed at
// 0x2DEB5) when ini is non-null. Operator new and __EH_prolog resolve via
// their rows. The TU-local class keeps only size and virtuality (vptr plus
// 0x40 pad). Recipe: BoredUpdateModuleDataFriendNew.cpp. Class identity is
// the rowed HordeUpdateModuleData::buildFieldParse proc (Horde table
// 0x00C4F9E8: IdleSpawnRate MeleeFreeUnitSpawnTime DiedRespawnTime
// BannerMorphFX UnitSpawnFX ReplenishNearbyHorde ScanHordeDistance
// UpgradeRequired) pushed as the factory's proc immediate.
class ModuleData;
class INI;
class MultiIniFieldParse;

class INI
{
public:
	void initFromINIMultiProc(void *what, void (__cdecl *proc)(MultiIniFieldParse &));
};

class HordeUpdateModuleData
{
public:
	HordeUpdateModuleData();
	virtual ~HordeUpdateModuleData();
	static void buildFieldParse(MultiIniFieldParse &parse);
	static ModuleData *friend_newModuleData(INI *ini);

private:
	unsigned char m_pad[0x44 - 4];
};

// ?friend_newModuleData@HordeUpdateModuleData@@SAPAVModuleData@@PAVINI@@@Z
ModuleData *HordeUpdateModuleData::friend_newModuleData(INI *ini)
{
	HordeUpdateModuleData *data = new HordeUpdateModuleData;
	if (ini)
		ini->initFromINIMultiProc(data, HordeUpdateModuleData::buildFieldParse);
	return reinterpret_cast<ModuleData *>(data);
}
