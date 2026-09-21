// ??0GateOpenAndCloseBehaviorModuleData@@QAE@XZ
// partial score=0.9 date=2026-09-21
// cl: /O1 /GX /MD /DNDEBUG /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// ??0GateOpenAndCloseBehaviorModuleData@@QAE@XZ, retail 0x00498E2E, 280 bytes.
// V1: natural transcription (probe only, no row yet).

#include <vector>

struct BfmeE16 { float x, y, z, w; };

extern int g_unk0xDCB4CC;

template<class T> class StringBase {
	void *m_data;
	StringBase() : m_data(0) {}
	StringBase(const T *);
	void clear();
	friend class GateOpenAndCloseBehaviorModuleData;
};

class AsciiString {
	void *m_data;
	AsciiString(const char *);
	~AsciiString();
	friend class GateOpenAndCloseBehaviorModuleData;
};

class GateOpenAndCloseBehaviorModuleData
{
public:
	GateOpenAndCloseBehaviorModuleData();
	virtual ~GateOpenAndCloseBehaviorModuleData();

private:
	int m_unused04;
	bool m_openByDefault; // +0x8
	int m_resetTime; // +0xC
	int m_percentOpen; // +0x10
	StringBase<char> m_proxy; // +0x14
	bool m_repel; // +0x18
	const char *m_soundOpening; // +0x1C
	const char *m_soundFinished; // +0x20
	const char *m_soundClosing; // +0x24
	int m_unused28; // +0x28
	_STL::vector<BfmeE16> m_geometryForOpen; // +0x2C
	_STL::vector<BfmeE16> m_geometryForClosed; // +0x38
	int m_snap44; // +0x44
	int m_snap48; // +0x48
};

// ??0GateOpenAndCloseBehaviorModuleData@@QAE@XZ @0x498E2E
GateOpenAndCloseBehaviorModuleData::GateOpenAndCloseBehaviorModuleData()
	: m_proxy()
	, m_soundOpening(0)
	, m_soundFinished(0)
	, m_soundClosing(0)
	, m_unused28(0)
{
	m_openByDefault = false;
	m_resetTime = 50;
	m_percentOpen = 50;
	m_proxy.clear();
	m_repel = true;
	AsciiString openLeft("OpenLeft");
	AsciiString openRight("OpenRight");
	AsciiString closed("Closed");
	m_geometryForOpen.erase(m_geometryForOpen.begin(), m_geometryForOpen.end());
	m_geometryForOpen.push_back(reinterpret_cast<const BfmeE16 &>(openLeft));
	m_geometryForOpen.push_back(reinterpret_cast<const BfmeE16 &>(openRight));
	m_geometryForClosed.erase(m_geometryForClosed.begin(), m_geometryForClosed.end());
	m_geometryForClosed.push_back(reinterpret_cast<const BfmeE16 &>(closed));
	m_snap44 = g_unk0xDCB4CC;
	m_snap48 = g_unk0xDCB4CC;
}
