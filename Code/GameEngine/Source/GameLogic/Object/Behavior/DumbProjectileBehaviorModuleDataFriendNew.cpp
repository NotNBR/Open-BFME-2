// cl: /O1 /GX /DNDEBUG /MD
//
// ?friend_newModuleData@DumbProjectileBehaviorModuleData@@SAPAVModuleData@@PAVINI@@@Z,
// retail 0x0024E774, 81 bytes. Dedicated TU: the factory news 0x5C, runs the
// declared-only ctor (pinned at 0x390119, frameless SSE body with retail
// float literals still unrowed), then feeds the new data plus the class parse
// proc (rowed at 0x3901C9, pushed immediate, no pin) to
// INI::initFromINIMultiProc (rowed at 0x2DEB5) when ini is non-null. Operator
// new and __EH_prolog resolve via their rows. The TU-local class keeps only
// size and virtuality (vptr plus 0x58 pad). Recipe:
// SupplyWarehouseDockUpdateModuleDataFriendNew.cpp. Class identity is
// retail's own INI table at 0x00C19DE8 (TumbleRandomly/AllowBouncing/
// GravityMult/OrientToFlightPath/ShockStunned*/FirstHeight/Bounce*/...,
// donor-backed by the BFME1 DumbProjectileBehavior ModuleData header).
class ModuleData;
class INI;
class MultiIniFieldParse;

class INI
{
public:
	void initFromINIMultiProc(void *what, void (__cdecl *proc)(MultiIniFieldParse &));
};

class DumbProjectileBehaviorModuleData
{
public:
	DumbProjectileBehaviorModuleData();
	virtual ~DumbProjectileBehaviorModuleData();
	static void buildFieldParse(MultiIniFieldParse &parse);
	static ModuleData *friend_newModuleData(INI *ini);

private:
	unsigned char m_pad[0x5C - 4];
};

// ?friend_newModuleData@DumbProjectileBehaviorModuleData@@SAPAVModuleData@@PAVINI@@@Z
ModuleData *DumbProjectileBehaviorModuleData::friend_newModuleData(INI *ini)
{
	DumbProjectileBehaviorModuleData *data = new DumbProjectileBehaviorModuleData;
	if (ini)
		ini->initFromINIMultiProc(data, DumbProjectileBehaviorModuleData::buildFieldParse);
	return reinterpret_cast<ModuleData *>(data);
}
