// cl: /O1 /GX /MD /DNDEBUG /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0AnimatedParticleSysBoneClientUpdate@@QAE@PAVThing@@PBVModuleData@@@Z at
// retail 0x000D181D (67B). ClientUpdate intermediate base at 0x000B19A1 is
// unidentified (also called by LaserUpdate 0x000CA752), so it is modeled
// opaque (12 bytes: vptr plus pad) and pinned; its ctor resolves through
// that pin. The trailing bone-index list at +0x0C default-constructs through
// the list_base<int> at 0x004EC36C (matched row).
#include <list>

class Thing;
class ModuleData;

// Opaque 12-byte ClientUpdate-derived intermediate; ctor resolves to the
// opaque pin at 0x000B19A1. Single vptr plus pad to the list at +0x0C.
class Rva000B19A1
{
public:
	Rva000B19A1(Thing *thing, const ModuleData *moduleData);
	virtual ~Rva000B19A1();

private:
	unsigned char m_pad04[8];
};

Rva000B19A1::~Rva000B19A1()
{
}

class AnimatedParticleSysBoneClientUpdate : public Rva000B19A1
{
public:
	AnimatedParticleSysBoneClientUpdate(Thing *thing, const ModuleData *moduleData);
	virtual ~AnimatedParticleSysBoneClientUpdate();

private:
	_STL::list<int> m_boneIndices;
};

AnimatedParticleSysBoneClientUpdate::AnimatedParticleSysBoneClientUpdate(Thing *thing, const ModuleData *moduleData)
	: Rva000B19A1(thing, moduleData)
{
}

AnimatedParticleSysBoneClientUpdate::~AnimatedParticleSysBoneClientUpdate()
{
}
