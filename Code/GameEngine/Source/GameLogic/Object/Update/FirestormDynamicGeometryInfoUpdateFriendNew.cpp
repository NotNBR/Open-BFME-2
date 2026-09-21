// cl: /O1 /GX /DNDEBUG /MD
//
// ?friend_newModuleInstance@FirestormDynamicGeometryInfoUpdate@@SAPAVModule@@PAVThing@@PBVModuleData@@@Z,
// retail 0x00252957, 56 bytes. Dedicated TU: retail news 0x10 (push-imm8; the
// rowed ctor TU FirestormDynamicGeometryInfoUpdateCtor.cpp builds the
// opaque-base layout). TU-local 0x10-byte class plus the declared-only ctor
// (rowed at 0x4C8FE8) reproduces the factory stub; operator new and
// __EH_prolog resolve via their rows. Recipe:
// PointDefenseLaserUpdateFriendNew.cpp.

class Thing;
class ModuleData;
class Module;

class FirestormDynamicGeometryInfoUpdate
{
public:
	FirestormDynamicGeometryInfoUpdate(Thing *thing, const ModuleData *moduleData);
	static Module *friend_newModuleInstance(Thing *thing, const ModuleData *moduleData);

private:
	char m_pad[0x10];
};

// ?friend_newModuleInstance@FirestormDynamicGeometryInfoUpdate@@SAPAVModule@@PAVThing@@PBVModuleData@@@Z
Module *FirestormDynamicGeometryInfoUpdate::friend_newModuleInstance(Thing *thing, const ModuleData *moduleData)
{
	return reinterpret_cast<Module *>(new FirestormDynamicGeometryInfoUpdate(thing, moduleData));
}
