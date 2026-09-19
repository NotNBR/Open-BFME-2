// BfmeThingDXB::bfmeGoDXB, retail 0x00628D20 (22B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv793.cpp
// (BFME1 0x009F69D3). Only the placed go is defined here; the donor's
// DXC/DXD/DXE/DXF helpers stay out, so the unmatched-definition gate passes.
// Retail inits the CS struct through the dllimport slot, then tail-jumps to
// the pinned sub call.

struct BfmeCsDXB
{
	unsigned char m_bfmeHead[0x18];
};

class BfmeSubDXB
{
public:
	void bfmeCallDXB();
};

// Retail's import slot 0xBBA158 is kernel32!DeleteCriticalSection, not a game
// helper: the donor's bfmeInitDXB alias is renamed to the real import. The
// 0x18-byte CS struct is a CRITICAL_SECTION; this go is its teardown path.
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(void *cs);

struct BfmeThingDXB
{
	void bfmeGoDXB();
	unsigned char m_bfmeHead[0x18];
	BfmeCsDXB m_bfmeCs;
	BfmeSubDXB m_bfmeSub;
};

// ?bfmeGoDXB@BfmeThingDXB@@QAEXXZ, retail 0x00628D20 (22B).
void BfmeThingDXB::bfmeGoDXB()
{
	DeleteCriticalSection(&m_bfmeCs);
	m_bfmeSub.bfmeCallDXB();
}
