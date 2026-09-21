// cl: /O1 /GX /DNDEBUG /MD
//
// ?friend_newModuleData@BattlePlanUpdate@@SAPAVModuleData@@PAVINI@@@Z,
// retail 0x00252C64, 81 bytes. Dedicated TU: the rowed no-arg ctor TU
// BattlePlanUpdateCtor.cpp proves a 0x14-byte root class (vtable plus a
// trailing E16 vector); the factory news 0x14, runs the declared-only ctor
// (rowed at 0x4CB9F3), then feeds the new data plus the class parse proc at
// 0x4CBBB4 (pushed immediate, no pin) to INI::initFromINIMultiProc (rowed at
// 0x2DEB5) when ini is non-null. Operator new and __EH_prolog resolve via
// their rows. Recipe: CleanupHazardUpdateFriendNew.cpp.

class ModuleData;
class INI;
class MultiIniFieldParse;

void BattlePlanUpdateParse(MultiIniFieldParse &parse);

class INI
{
public:
	void initFromINIMultiProc(void *what, void (__cdecl *proc)(MultiIniFieldParse &));
};

class BattlePlanUpdate
{
public:
	BattlePlanUpdate();
	virtual ~BattlePlanUpdate();
	static ModuleData *friend_newModuleData(INI *ini);

private:
	int m_unused04;
	unsigned char m_vec08[12];
};

// ?friend_newModuleData@BattlePlanUpdate@@SAPAVModuleData@@PAVINI@@@Z
ModuleData *BattlePlanUpdate::friend_newModuleData(INI *ini)
{
	BattlePlanUpdate *data = new BattlePlanUpdate;
	if (ini)
		ini->initFromINIMultiProc(data, BattlePlanUpdateParse);
	return reinterpret_cast<ModuleData *>(data);
}
