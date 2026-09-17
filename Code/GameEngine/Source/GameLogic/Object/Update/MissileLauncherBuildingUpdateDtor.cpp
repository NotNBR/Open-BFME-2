// cl: /O1 /GX /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??_GMissileLauncherBuildingUpdate@@UAEPAXI@Z at retail 0x004CDA19 (28B).
// Emitted scalar deleting destructor (flag plus pinned operator delete at
// 0x0002FD60); its dtor call resolves to the pinned
// ??1MissileLauncherBuildingUpdate@@UAE@XZ at 0x004CD9C0. The TU also emits
// that SEH vector-destroying dtor (vtab plus slots plus null-checked 0x30830
// free plus base call) but it is still 0.97 (EH-state order) and stays
// unclaimed; see the banked partial. Unlike the constructor TU (byte storage
// for init order), this TU models the trailing vector as a real member so
// the implicit destruction and SEH states fall out. Do NOT declare an
// explicit vptr member on the base.
#include <vector>

struct BfmeE16 { float x, y, z, w; };

class Thing;
class ModuleData;

static int s_dummy0C;
static int s_dummy10;
static int s_dummy20;

// Opaque 0x88-byte UpdateModule-derived intermediate; dtor resolves to the
// opaque pin at 0x00451F45. Protected slots mirror the retail stores.
class Rva0044EF5E
{
public:
	Rva0044EF5E(Thing *thing, const ModuleData *moduleData);
	virtual ~Rva0044EF5E();

protected:
	unsigned char m_pad0[8];
	const void *m_p0C;
	const void *m_p10;
	unsigned char m_pad1[0x20 - 0x14];
	const void *m_p20;
	unsigned char m_pad2[0x88 - 0x24];
};

class MissileLauncherBuildingUpdate : public Rva0044EF5E
{
public:
	virtual ~MissileLauncherBuildingUpdate();

private:
	_STL::vector<BfmeE16> m_tail;
};

MissileLauncherBuildingUpdate::~MissileLauncherBuildingUpdate()
{
	m_p0C = &s_dummy0C;
	m_p10 = &s_dummy10;
	m_p20 = &s_dummy20;
}
