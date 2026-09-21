// ??0RainOfFireUpdate@@QAE@PAVThing@@PBVModuleData@@@Z
// partial score=0.9 date=2026-09-21
// cl: /O1 /arch:SSE /DNDEBUG /MD
//
// ??0RainOfFireUpdate@@QAE@PAVThing@@PBVModuleData@@@Z, retail 0x004AC0A8,
// 133 bytes. RainOfFireUpdate ctor over the rowed UpdateModule base
// (0x253390): table slot at +0x20 (init literal, reassigned in body),
// next-frame at +0x24 defaulting to 0x3FFFFFFF and refreshed from the
// GameLogic frame when module data is present, float state at
// +0x28/+0x2C/+0x30/+0x34, plus a nonzero DPS-ramp check on the module data
// (+0x24 float per the rowed ModuleData table) raising +0x34 to 1.0f.
// Base-class layout mirrors UpdateModuleCtor.cpp exactly; the secondary
// installs at +0xC/+0x10 come from that chain. Recipe:
// DestroyEnvironmentUpdateCtor.cpp plus the float-compare tail.

class Thing;
class ModuleData;

class BehaviorModuleBase
{
	virtual void unused();

protected:
	const ModuleData *m_moduleData;
	int m_object;
};

class BehaviorModuleOther
{
	virtual void unused();
};

class BehaviorModule : public BehaviorModuleBase, public BehaviorModuleOther
{
public:
	BehaviorModule(Thing *thing, const ModuleData *moduleData);
	const ModuleData *getModuleData() const { return m_moduleData; }
};

class UpdateModuleInterface
{
public:
	virtual void update() = 0;
};

class UpdateModule : public BehaviorModule, public UpdateModuleInterface
{
	unsigned m_nextCallFrameAndPhase;
	int m_indexInLogic;
	int m_bfmeReserved;

public:
	UpdateModule(Thing *thing, const ModuleData *moduleData);
	virtual void update();
};

class GameLogic
{
public:
	unsigned getFrame() const { return m_frame; }

private:
	unsigned char m_reserved[0x40];
	unsigned m_frame;
};

extern GameLogic *TheGameLogic;

class RainOfFireUpdateModuleData
{
public:
	float m_pad00[9];
	float m_dpsRampupTime;
};

class RainOfFireUpdate : public UpdateModule
{
public:
	RainOfFireUpdate(Thing *thing, const ModuleData *moduleData);

private:
	void *m_slot;
	int m_frame;
	float m_state28;
	float m_state2C;
	float m_state30;
	float m_state34;
};

// ??0RainOfFireUpdate@@QAE@PAVThing@@PBVModuleData@@@Z
RainOfFireUpdate::RainOfFireUpdate(Thing *thing, const ModuleData *moduleData)
	: UpdateModule(thing, moduleData),
	  m_slot(reinterpret_cast<void *>(0x00C6FFFC)),
	  m_frame(0x3FFFFFFF),
	  m_state28(0.0f),
	  m_state2C(1.0f),
	  m_state30(0.0f),
	  m_state34(0.0f)
{
	m_slot = reinterpret_cast<void *>(0x00C54BA0);
	const RainOfFireUpdateModuleData *mod =
		reinterpret_cast<const RainOfFireUpdateModuleData *>(getModuleData());
	if (mod != 0) {
		m_frame = TheGameLogic->getFrame();
		if (mod->m_dpsRampupTime != 0.0f)
			m_state34 = 1.0f;
	}
}
