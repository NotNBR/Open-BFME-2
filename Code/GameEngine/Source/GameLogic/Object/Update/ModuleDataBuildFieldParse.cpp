// cl: /O1 /DNDEBUG /MD
//
// Five single-field ModuleData::buildFieldParse procs (11 bytes each):
// ?buildFieldParse@CleanupHazardUpdateModuleData@@SAXAAVMultiIniFieldParse@@@Z,
// retail 0x004C9663 (field RadarPulseFrequency), plus PilotFindVehicle (announcement),
// DynamicGeometryInfo (FX), BattlePlan (SoundUpgrade) and RepairDock (ModelCondition)
// sibs, plus LifetimeUpdate (table 0x00C1B0F0, factory 0x24E3A3 pushes its VA).
// Each registers exactly one FieldParse table with
// MultiIniFieldParse::add (pinned at 0x2BC6E). Provenance: the ZH
// MAKE_STANDARD_MODULE_DATA_MACRO_ABC macro passes clsmd::buildFieldParse to
// INI::initFromINIMultiProc, and each landed friend_newModuleData factory in
// this directory pushes its class proc immediate (no pin needed there, none
// needed here: the FieldParse address is a pushed absolute). Recipe: the
// factory TUs (*FriendNew.cpp) name the owning class per stub.

class MultiIniFieldParse;

struct FieldParse;

class MultiIniFieldParse
{
public:
	void add(const FieldParse *parse, unsigned int extraOffset);
};

#define FIELD_PROC(cls, addr, field) \
class cls \
{ \
public: \
	static void buildFieldParse(MultiIniFieldParse &parse); \
}; \
\
void cls::buildFieldParse(MultiIniFieldParse &parse) \
{ \
	parse.add(reinterpret_cast<const FieldParse *>(addr), 0); \
}

FIELD_PROC(CleanupHazardUpdateModuleData, 0x00C5EB94, RadarPulseFrequency)
FIELD_PROC(PilotFindVehicleUpdateModuleData, 0x00C5ECB8, AnnouncementEventEnemy)
FIELD_PROC(DynamicGeometryInfoUpdateModuleData, 0x00C5EA10, FX)
FIELD_PROC(BattlePlanUpdateModuleData, 0x00C5F2DC, SoundUpgrade)
FIELD_PROC(RepairDockUpdateModuleData, 0x00C5F574, ModelCondition)
FIELD_PROC(LifetimeUpdateModuleData, 0x00C1B0F0, LifetimeUpdateTable)
FIELD_PROC(SalvageCrateCollideModuleData, 0x00C4C600, SalvageCrateTable)
FIELD_PROC(PropagandaTowerBehaviorModuleData, 0x00C55638, PropagandaTowerTable)
FIELD_PROC(AnimationSteeringUpdateModuleData, 0x00C5AB48, SteeringTable)
FIELD_PROC(OCLUpdateModuleData, 0x00C50BA8, OCLTable)
FIELD_PROC(AutoPickUpUpdateModuleData, 0x00C4F4B8, EatObjectTable)
FIELD_PROC(ProductionUpdateModuleData, 0x00C517F0, DoorTable)
FIELD_PROC(ProneUpdateModuleData, 0x00C51964, ProneTable)
FIELD_PROC(BoneFXUpdateModuleData, 0x00BF1158, BoneFXTable)
FIELD_PROC(DeletionUpdateModuleData, 0x00BF17BC, DeletionTable)
