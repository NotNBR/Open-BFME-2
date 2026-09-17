// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// Trial: ??0DynamicGeometryInfoUpdate@@QAE@XZ.
// Root class with two trailing E16 vectors plus a trailing int zeroed in
// the body (calls anchor it after the vector constructions). Factory stub.
#include <vector>

struct BfmeE16 { float x, y, z, w; };

class DynamicGeometryInfoUpdate
{
public:
	DynamicGeometryInfoUpdate();
	virtual ~DynamicGeometryInfoUpdate();

private:
	int m_unused04;
	_STL::vector<BfmeE16> m_a08;
	_STL::vector<BfmeE16> m_b14;
	int m_i20;
};

DynamicGeometryInfoUpdate::DynamicGeometryInfoUpdate()
	: m_a08(), m_b14()
{
	m_i20 = 0;
}

DynamicGeometryInfoUpdate::~DynamicGeometryInfoUpdate()
{
}
