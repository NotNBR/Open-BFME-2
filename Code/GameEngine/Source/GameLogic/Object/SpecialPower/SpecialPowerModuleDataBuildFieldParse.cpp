// cl: /O1 /DNDEBUG /MD
//
// SpecialPower-side ModuleData::buildFieldParse procs.
//
// ?buildFieldParse@SpecialPowerModuleData@@SAXAAVMultiIniFieldParse@@@Z,
// retail 0x00493207 (17 bytes): the shared SpecialPower base table at
// 0x00C4E628 (SpecialPowerTemplate, UpdateModuleStartsAttack, StartsPaused,
// InitiateSound, ReEnableAntiCategory, AntiCategory, AntiFX,
// AttributeModifier and siblings). Twenty-one same-family ModuleData procs
// (0x4C238D through 0x4C89CF, including Devastate below) open with
// push dword ptr [esp+4] + call here, proving the base identity; the table
// prefix matches the in-tree SpecialPowerModuleData declaration field for
// field. Registered with MultiIniFieldParse::add (rowed at 0x2BC6E).

class MultiIniFieldParse;

struct FieldParse;

class MultiIniFieldParse
{
public:
	void add(const FieldParse *parse, unsigned int extraOffset);
};

class SpecialPowerModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

void SpecialPowerModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	parse.add(reinterpret_cast<const FieldParse *>(0x00C4E628), 0);
}
