// cl: /O1 /arch:SSE /MD /DNDEBUG /DWIN32 /D_WINDOWS
//
// ??0AISpecialPowerUpdateModuleData@@QAE@XZ, retail 0x004B2FCD, 38 bytes.
// Frameless trivial ctor for the AISpecialPowerUpdate behavior's module
// data (see the pool key at 0x4B2ED4 ending where the rowed buildFieldParse
// proc begins, BoredUpdateModuleData precedent). Layout: explicit vtable
// slot at +0 (factory-TU precedent, so no vtable is emitted), untouched
// word at +4, command-button name pointer at +8, undefaulted AI-type int at
// +0xC, radius and range floats at +0x10/+0x14 defaulting to -1.0f, and flag
// bytes at +0x18/+0x19. The TU-local class keeps plain-data members, so the
// body statements reproduce retail order: vtable literal 0x00C56F48, name
// null, the two -1.0f loads, then the byte stores (/arch:SSE keeps the
// float loads as movss per the DemoTrap precedent; /O1 keeps the integer
// zero as the compact mov form). Size 0x1C matches the free 0x24FD76
// factory news.

class AISpecialPowerUpdateModuleData
{
public:
	AISpecialPowerUpdateModuleData();

private:
	void *m_vtable; // +0
	int m_baseTail; // +4
	const char *m_commandButtonName; // +8
	int m_specialPowerAIType; // +0xC
	float m_specialPowerRadius; // +0x10
	float m_specialPowerRange; // +0x14
	bool m_randomizeTargetLocation; // +0x18
	bool m_spellMakesAStructure; // +0x19
};

// ??0AISpecialPowerUpdateModuleData@@QAE@XZ @0x4B2FCD
AISpecialPowerUpdateModuleData::AISpecialPowerUpdateModuleData()
{
	m_vtable = reinterpret_cast<void *>(0x00C56F48);
	m_commandButtonName = 0;
	m_specialPowerRadius = -1.0f;
	m_specialPowerRange = -1.0f;
	m_randomizeTargetLocation = false;
	m_spellMakesAStructure = false;
}
