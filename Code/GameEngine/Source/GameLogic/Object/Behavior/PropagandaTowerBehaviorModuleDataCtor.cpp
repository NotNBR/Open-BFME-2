// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// PropagandaTowerBehaviorModuleData::PropagandaTowerBehaviorModuleData,
// retail 0x004AEAB7, 53 bytes. Dedicated TU mirroring DieModuleDataCtor: the
// base stays trivially constructible (no base call in retail), the derived
// vptr lands at +0, two 16-byte-element vectors at +0x08/+0x14 construct from
// a one-byte stack allocator temporary (retail lea ebp-1), then an int and
// two bytes zero at +0x20/+0x24/+0x25. Element type is the size stand-in from
// stlport_vector_e16_o1.cpp, whose vector_base copy ctor is retail 0x00211E58.

#include <vector>

struct BfmeE16 { float x, y, z, w; };

class ModuleData
{
private:
	int _pad;
};

class PropagandaTowerBehaviorModuleData : public ModuleData
{
public:
	PropagandaTowerBehaviorModuleData();
	virtual ~PropagandaTowerBehaviorModuleData();

private:
	_STL::vector<BfmeE16> m_a;
	_STL::vector<BfmeE16> m_b;
	int m_c;
	unsigned char m_d;
	unsigned char m_e;
};

PropagandaTowerBehaviorModuleData::PropagandaTowerBehaviorModuleData()
	: m_c(0), m_d(0), m_e(0)
{
}
