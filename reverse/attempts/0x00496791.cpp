// ??0BoredUpdate@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.94 date=2026-09-21
// ??0BoredUpdate@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.94 date=2026-09-21
// cl: /O1 /GX /DNDEBUG /MD
//
// ??0BoredUpdate@@QAE@PAVThing@@PBVModuleData@@@Z, retail 0x00496791, 98 bytes.
// 92/98 bytes identical (all relocs masked); SOLE WALL is a register-allocation
// swap of the two post-base-call temps: retail homes the owner load in EAX
// (8B 46 04) and the shared zero in ECX (33 C9, reused for the +0x20 member
// store, the [ebp-4] EH state store and the lo push), while every compiled
// variant homes owner in ECX and zero in EAX (8B 4E 04 / 33 C0 and the three
// downstream reg bits). Frame, EH prolog, vtable stores, pushes, line-70 file
// literal and tail are all exact. REFUTED variants (all identical 6-byte wall):
// unsigned-max, inline-getter (40B worse), body-zero-assign, /EHsc, /O2 and /Ox
// (both disasters), /G6, /G7, member renames, trailing pad member (7B worse),
// false-init, no-virtuals reshape, member-as-lo forwarding. Base ctor rowed
// 0x253390, GetGameLogicRandomValue rowed 0x233FF4, ~UpdateModule alias-pinned
// 0x24A797 (tail target of rowed BoredUpdate dtor 0x49669A). Needs an
// allocation-context lever, not more spelling variants. t=30 muse-spark.

// cl: /O1 /GX /DNDEBUG /MD
//
// ??0BoredUpdate@@QAE@PAVThing@@PBVModuleData@@@Z, retail 0x00496791, 98 bytes.
// Update half of the Bored file-unit (rowed 0x24E0EA factory news 0x24 here).
// UpdateModule base (rowed 0x253390) owns thing at +0x04, max at thing +0x08.
// File literal is byte-copied from retail VA 0xC4F678; the random call below
// sits on line 70 to pin __LINE__ 70. ~UpdateModule is alias-pinned at
// 0x24A797 (tail target of rowed BoredUpdate dtor 0x49669A) for the EH state.
class ModuleData;
class Thing
{
public:
	int m_pad08[2];
	int m_maxDelay; // +0x08 (retail push shape)
};
class BehaviorModuleBase
{
public:
	virtual void unusedBase();
protected:
	Thing *m_thing; // +0x04
	int m_b; // +0x08
};
class BehaviorModuleOther
{
public:
	virtual void unusedOther();
};
class BehaviorModule : public BehaviorModuleBase, public BehaviorModuleOther
{
public:
	BehaviorModule(Thing *thing, const ModuleData *moduleData);
};
class UpdateModuleInterface
{
public:
	virtual void update() = 0;
};
class UpdateModule : public BehaviorModule, public UpdateModuleInterface
{
public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	~UpdateModule();
	virtual void update();
private:
	unsigned m_nextCallFrameAndPhase; // +0x14
	int m_indexInLogic; // +0x18
	int m_bfmeReserved; // +0x1C
};
class BoredUpdate : public UpdateModule
{
public:
	BoredUpdate(Thing *thing, const ModuleData *moduleData);
	~BoredUpdate();
	virtual void update();
private:
	int m_nextScanDelay; // +0x20
};
int GetGameLogicRandomValue(int lo, int hi, char *file, int line);
// (padding to land the random call on line 70)
// (padding to land the random call on line 70)
// (padding to land the random call on line 70)
// (padding to land the random call on line 70)
// (padding to land the random call on line 70)
// (padding to land the random call on line 70)
BoredUpdate::BoredUpdate(Thing *thing, const ModuleData *moduleData)
	: UpdateModule(thing, moduleData)
	, m_nextScanDelay(0)
{
	m_nextScanDelay += GetGameLogicRandomValue(0, m_thing->m_maxDelay, (char *)"C:\\projects\\bfme2patch103\\bfme2\\Code\\GameEngine\\Source\\GameLogic\\Object\\Update\\BoredUpdate.cpp", __LINE__);
}
BoredUpdate::~BoredUpdate()
{
}
void BoredUpdate::update()
{
}
