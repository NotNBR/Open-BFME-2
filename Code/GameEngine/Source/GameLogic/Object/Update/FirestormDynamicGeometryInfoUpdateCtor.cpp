// cl: /O1 /MD /DNDEBUG
// Trial: ??0FirestormDynamicGeometryInfoUpdate@@QAE@PAVThing@@PBVModuleData@@@Z.
// Base 0x00362EC7 (pinned opaque); and-zeroed slot then hand-placed vtable
// (novtable). Factory stub order names it.
class Thing;
class ModuleData;

extern "C" char FirestormDynamicGeometryInfoUpdate_vftable;

// Opaque intermediate; ctor resolves to the opaque pin at 0x00362EC7.
class Rva00362EC7
{
public:
	Rva00362EC7(Thing *thing, const ModuleData *moduleData);
	virtual ~Rva00362EC7();

protected:
	unsigned char m_pad0[8];
	int m_i0C;
	unsigned char m_pad1[0x20 - 0x10];
};

Rva00362EC7::~Rva00362EC7()
{
}

class __declspec(novtable) FirestormDynamicGeometryInfoUpdate : public Rva00362EC7
{
public:
	FirestormDynamicGeometryInfoUpdate(Thing *thing, const ModuleData *moduleData);
	virtual ~FirestormDynamicGeometryInfoUpdate();
};

FirestormDynamicGeometryInfoUpdate::FirestormDynamicGeometryInfoUpdate(Thing *thing, const ModuleData *moduleData)
	: Rva00362EC7(thing, moduleData)
{
	m_i0C = 0;
	*reinterpret_cast<char **>(this) = &FirestormDynamicGeometryInfoUpdate_vftable;
}

FirestormDynamicGeometryInfoUpdate::~FirestormDynamicGeometryInfoUpdate()
{
}
