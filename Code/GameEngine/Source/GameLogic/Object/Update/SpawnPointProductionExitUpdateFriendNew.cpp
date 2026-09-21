// cl: /O1 /GX /DNDEBUG /MD
//
// ?friend_newModuleInstance@SpawnPointProductionExitUpdate@@SAPAVModule@@PAVThing@@PBVModuleData@@@Z,
// retail 0x00252F39, 59 bytes. Dedicated TU: the ZH header sizes the class at
// 0xF0 but retail news 0x88 (proven by the rowed ctor TU
// SpawnPointProductionExitUpdateCtor.cpp: opaque 0x88-byte base, factory stub
// order). The structural pairing names it SpawnPointProductionExit (dropped
// Update suffix) and is refuted by the object (symbol not found); the true
// class is SpawnPointProductionExitUpdate. TU-local 0x88-byte class plus the
// declared-only ctor (rowed at 0x4CCD7F) reproduces the factory stub;
// operator new and __EH_prolog resolve via their rows.
// Recipe: DozerAIUpdateFriendNew.cpp.

class Thing;
class ModuleData;
class Module;

class SpawnPointProductionExitUpdate
{
public:
	SpawnPointProductionExitUpdate(Thing *thing, const ModuleData *moduleData);
	static Module *friend_newModuleInstance(Thing *thing, const ModuleData *moduleData);

private:
	char m_pad[0x88];
};

// ?friend_newModuleInstance@SpawnPointProductionExitUpdate@@SAPAVModule@@PAVThing@@PBVModuleData@@@Z
Module *SpawnPointProductionExitUpdate::friend_newModuleInstance(Thing *thing, const ModuleData *moduleData)
{
	return reinterpret_cast<Module *>(new SpawnPointProductionExitUpdate(thing, moduleData));
}
