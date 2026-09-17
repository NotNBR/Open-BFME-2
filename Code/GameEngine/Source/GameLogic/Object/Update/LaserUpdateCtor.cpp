// cl: /O1 /arch:SSE /MD /DNDEBUG
// Trial: ??0LaserUpdate@@QAE@PAVThing@@PBVModuleData@@@Z (stub ctor).
// Base 0x00362EC7 (pinned opaque); or-word, hand-placed vtable (novtable),
// then float and byte members. Factory stub order names it (93); the
// reloc-named 0xCA752 body is a different overload/shape.
class Thing;
class ModuleData;

extern "C" char LaserUpdate_vftable;

// Opaque intermediate; ctor resolves to the opaque pin at 0x00362EC7.
class Rva00362EC7
{
public:
	Rva00362EC7(Thing *thing, const ModuleData *moduleData);
	virtual ~Rva00362EC7();

protected:
	unsigned char m_pad0[8];
	float m_f0C;
	float m_f10;
	float m_f14;
	float m_f18;
	float m_f1C;
	short m_w20;
	unsigned char m_b22;
	unsigned char m_b23;
	float m_f24;
	float m_f28;
};

Rva00362EC7::~Rva00362EC7()
{
}

class __declspec(novtable) LaserUpdate : public Rva00362EC7
{
public:
	LaserUpdate(Thing *thing, const ModuleData *moduleData);
	virtual ~LaserUpdate();

};

LaserUpdate::LaserUpdate(Thing *thing, const ModuleData *moduleData)
	: Rva00362EC7(thing, moduleData)
{
	m_w20 = -1;
	*reinterpret_cast<char **>(this) = &LaserUpdate_vftable;
	m_f0C = 0.0f;
	m_f10 = 0.0f;
	m_f14 = 0.0f;
	m_f18 = 0.0f;
	m_f1C = 0.0f;
	m_b22 = 1;
	m_b23 = 0;
	m_f24 = 0.0f;
	m_f28 = 0.0f;
}

LaserUpdate::~LaserUpdate()
{
}
