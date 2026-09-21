// cl: /O1 /MD /GX /DNDEBUG
//
// ??0MoneyCrateCollideModuleData@@QAE@XZ, retail 0x002562FA (22 bytes).
// Frameless ctor over the rowed CrateCollide base (0x4BC657): clears
// m_moneyProvided at +0x5C through an AND-zero (the natural /O1 emission for
// the single-store shape, probe-proven against init-list which is identical)
// then installs the folded vtable 0x00BF3AC0 through the ??_7 pin (Devastate
// precedent: virtual classes with declared-only virtual dtors and no source
// store). Field identity is the chained buildFieldParse table 0x00BEFABC
// (MoneyProvided only) joined to the ZH MoneyCrateCollide.h donor (BFME2
// drops the ZH upgrade-boost list). Sole raw caller is the ModuleData
// factory 0x256310 which news 0x60.

class CrateCollideModuleData
{
public:
	CrateCollideModuleData();
	virtual ~CrateCollideModuleData();

private:
	unsigned char m_pad[0x5C - 4];
};

class MoneyCrateCollideModuleData : public CrateCollideModuleData
{
public:
	MoneyCrateCollideModuleData();
	virtual ~MoneyCrateCollideModuleData();

private:
	unsigned int m_moneyProvided;	// +0x5C
};

MoneyCrateCollideModuleData::MoneyCrateCollideModuleData()
{
	m_moneyProvided = 0;
}
