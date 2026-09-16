// cl: /O1 /MD -D_STLP_NO_EXCEPTIONS /EHs-c-
// ??0OpenContainModuleData@@QAE@XZ @ 0x00253487 (21B): base ctor installing
// the folded vtable 0x00BF2558 (shared with derived HealContainModuleData,
// whose 36B ctor is matched in HealContainModuleDataCtorThunk.cpp) then
// constructing the member at +8.
// The +8 member's semantic identity is unproven: ZH OpenContain.h says the
// first member is DieMuxData and DieModule.cpp already carries a
// ??0DieMuxData@@ present-unmatched marker for the concept, but the body at
// 0x0025342C has no independent identity yet, so the callee keeps an
// address-derived name here (pinned) instead of a guessed class name.
class Rva0025342CMember
{
public:
	void construct();
};

class __declspec(novtable) OpenContainModuleData
{
public:
	OpenContainModuleData();
	virtual ~OpenContainModuleData();

private:
	// +0x00 vptr (installed explicitly below; novtable suppresses the
	// compiler's own install so the folded 0x00BF2558 is the only store).
	// +0x04 UpdateModuleData tail per ZH OpenContain.h hierarchy
	// (trivially constructed — retail makes no base call).
	unsigned m_pad04;
	Rva0025342CMember m_member08;
};

// ??0OpenContainModuleData@@QAE@XZ
OpenContainModuleData::OpenContainModuleData()
{
	*(unsigned int *)this = 0x00BF2558;
	m_member08.construct();
}
