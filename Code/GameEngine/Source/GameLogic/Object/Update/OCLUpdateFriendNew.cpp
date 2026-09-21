// cl: /O1 /GX /DNDEBUG /MD
//
// ?friend_newModuleInstance@OCLUpdate@@SAPAVModule@@PAVThing@@PBVModuleData@@@Z,
// retail 0x00253057, 59 bytes. Dedicated TU: the rowed ctor TU
// OCLUpdateCtor.cpp proves the class news 0x88 (opaque 0x88-byte base, no
// trailing members, factory stub order). TU-local 0x88-byte class plus the
// declared-only ctor (rowed at 0x4CD3A4) reproduces the factory stub; operator
// new and __EH_prolog resolve via their rows. Recipe:
// DozerAIUpdateFriendNew.cpp.

class Thing;
class ModuleData;
class Module;

class OCLUpdate
{
public:
	OCLUpdate(Thing *thing, const ModuleData *moduleData);
	static Module *friend_newModuleInstance(Thing *thing, const ModuleData *moduleData);

private:
	char m_pad[0x88];
};

// ?friend_newModuleInstance@OCLUpdate@@SAPAVModule@@PAVThing@@PBVModuleData@@@Z
Module *OCLUpdate::friend_newModuleInstance(Thing *thing, const ModuleData *moduleData)
{
	return reinterpret_cast<Module *>(new OCLUpdate(thing, moduleData));
}
