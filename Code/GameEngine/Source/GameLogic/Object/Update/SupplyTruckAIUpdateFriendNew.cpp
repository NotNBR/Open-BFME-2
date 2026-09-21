// cl: /O1 /GX /DNDEBUG /MD
//
// ?friend_newModuleInstance@SupplyTruckAIUpdate@@SAPAVModule@@PAVThing@@PBVModuleData@@@Z,
// retail 0x00252845, 56 bytes. Dedicated TU: the factory news 0x34 (ground
// truth for sizeof, against the 0x88 modeled in the rowed ctor TU whose body
// only touches the +0x0C/+0x10 slots); TU-local 0x34-byte class plus the
// declared-only ctor (rowed at 0x4C89E6) reproduces the factory stub;
// operator new and __EH_prolog resolve via their rows. Recipe:
// POWTruckAIUpdateFriendNew.cpp.

class Thing;
class ModuleData;
class Module;

class SupplyTruckAIUpdate
{
public:
	SupplyTruckAIUpdate(Thing *thing, const ModuleData *moduleData);
	static Module *friend_newModuleInstance(Thing *thing, const ModuleData *moduleData);

private:
	char m_pad[0x34];
};

// ?friend_newModuleInstance@SupplyTruckAIUpdate@@SAPAVModule@@PAVThing@@PBVModuleData@@@Z
Module *SupplyTruckAIUpdate::friend_newModuleInstance(Thing *thing, const ModuleData *moduleData)
{
	return reinterpret_cast<Module *>(new SupplyTruckAIUpdate(thing, moduleData));
}
