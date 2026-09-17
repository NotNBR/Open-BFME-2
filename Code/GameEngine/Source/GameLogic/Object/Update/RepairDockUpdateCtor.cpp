// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0RepairDockUpdate@@QAE@PAVThing@@PBVModuleData@@@Z at retail 0x004CC20A.
// Root class (no base call): vtable plus a trailing E16 vector at +0x08
// default-constructed through the vector_base pinned at retail 0x00211E58,
// with the one-byte allocator temporary at [esp+0x07] (frameless).
// Factory stub order names it; stub size 0x14 confirms the layout.
#include <vector>

struct BfmeE16 { float x, y, z, w; };

class Thing;
class ModuleData;

class RepairDockUpdate
{
public:
	RepairDockUpdate();
	virtual ~RepairDockUpdate();

private:
	int m_unused04;
	_STL::vector<BfmeE16> m_vec08;
};

RepairDockUpdate::RepairDockUpdate()
	: m_vec08()
{
}

RepairDockUpdate::~RepairDockUpdate()
{
}
