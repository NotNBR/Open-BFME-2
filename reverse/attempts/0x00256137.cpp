// ?friend_newModuleData@SpawnPointProductionExitUpdateModuleData@@SAPAVModuleData@@PAVINI@@@Z
// partial score=0.98 date=2026-09-21
// cl: /O1 /GX /DNDEBUG /MD
//
// STASH (partial 0.98): ?friend_newModuleData@SpawnPointProductionExitUpdateModuleData@@SAPAVModuleData@@PAVINI@@@Z,
// retail 0x00256137, 51 bytes. 50/51 bytes identical; sole wall is the
// vtable/member store order: retail keeps `mov [eax],0xBF3740` ahead of
// `and [eax+8],0`, every shape tried emits the reverse.
//
// Proven scheduler law (20-shape probe matrix, this toolchain, /O1):
// `and [mem],0` zeroings always schedule ahead of `mov [mem],imm32` stores
// in straight-line code, regardless of source order (body, init-list,
// init/body split, virtual/implicit vptr, nested inline member-ctor,
// volatile member, placement new). /O2 and /Ot keep source order but use
// `mov [mem],0` for zeroing (and fold `&=` to `mov`) plus `add esp,4`
// new-cleanup, so the op and the factory shape both break there.
// #pragma optimize("t",on) on caller or callee behaves like /Ot (folds,
// reorders cleanup) or is ignored for inlined code. The (mov-imm, and)
// pair is unreachable straight-line here; retail needs a scheduling
// boundary this toolchain cannot express, or its original patch level.
// Same wall blocks HijackerUpdate (0x25616B, vtable + two ands) and the
// SlavedUpdate ctor (0x2552D7, vtable + and/movss mix).
//
// Class identity is solid: retail INI table 0x00BF22D4 is SpawnPointBoneName
// per ZH SpawnPointProductionExitUpdate.h, factory news 0x0C (vptr + base +
// one AsciiString) and pushes proc 0x25436A (rowed). Retry only with a new
// pop-scheduling lever or toolchain delta.

class ModuleData;
class INI;
class MultiIniFieldParse;

class INI
{
public:
	void initFromINIMultiProc(void *what, void (__cdecl *proc)(MultiIniFieldParse &));
};

class SpawnPointProductionExitUpdateModuleData
{
public:
	SpawnPointProductionExitUpdateModuleData()
	{
		m_boneNameData = 0;
		m_vtable = reinterpret_cast<void *>(0x00BF3740);
	}
	static void buildFieldParse(MultiIniFieldParse &parse);
	static ModuleData *friend_newModuleData(INI *ini);

private:
	void *m_vtable;
	int m_baseField;
	int m_boneNameData;
};

// ?friend_newModuleData@SpawnPointProductionExitUpdateModuleData@@SAPAVModuleData@@PAVINI@@@Z
ModuleData *SpawnPointProductionExitUpdateModuleData::friend_newModuleData(INI *ini)
{
	SpawnPointProductionExitUpdateModuleData *data = new SpawnPointProductionExitUpdateModuleData;
	if (ini)
		ini->initFromINIMultiProc(data, SpawnPointProductionExitUpdateModuleData::buildFieldParse);
	return reinterpret_cast<ModuleData *>(data);
}
