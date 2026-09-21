// cl: /O1 /DNDEBUG /MD
//
// ?buildFieldParse@UnitCrateCollideModuleData@@SAXAAVMultiIniFieldParse@@@Z,
// retail 0x002511F3 (27 bytes). Chained leaf: registers the base CrateCollide
// table through the rowed base proc (0x004BC7FE, kept outlined by living in
// its own TU), then its own UnitCount/UnitName table 0x00BEFAF4. Provenance:
// the ZH UnitCrateCollide.h donor (CrateCollideModuleData::buildFieldParse
// plus UnitCount/UnitName entries). MultiIniFieldParse::add is pinned at
// 0x2BC6E.

class MultiIniFieldParse;

struct FieldParse;

class MultiIniFieldParse
{
public:
	void add(const FieldParse *parse, unsigned int extraOffset);
};

class CrateCollideModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

class UnitCrateCollideModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

// ?buildFieldParse@UnitCrateCollideModuleData@@SAXAAVMultiIniFieldParse@@@Z
void UnitCrateCollideModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	CrateCollideModuleData::buildFieldParse(parse);
	parse.add(reinterpret_cast<const FieldParse *>(0x00BEFAF4), 0);
}
