// cl: /O1 /DNDEBUG /MD
//
// Chained W3D draw ModuleData::buildFieldParse procs: each calls its
// base-class buildFieldParse, then registers its own FieldParse table with
// MultiIniFieldParse::add (rowed at 0x2BC6E). The base
// (W3DModelDrawModuleData::buildFieldParse, rowed at 0xC9240) is declared
// here but defined in W3DModelDrawModuleDataBuildFieldParse.cpp, so the base
// call stays an out-of-line E8 exactly like retail. Bodies:
// ?buildFieldParse@W3DSupplyDrawModuleData@@SAXAAVMultiIniFieldParse@@@Z,
// retail 0x000CAE28, 27 bytes (field SupplyBonePrefix at 0x188; donor
// reference: BFME1 W3DSupplyDraw.cpp keeps the same single-field table).
// ?buildFieldParse@W3DTruckDrawModuleData@@SAXAAVMultiIniFieldParse@@@Z,
// retail 0x000CB133, 27 bytes (table 0xBCC358: Dust, DirtSpray,
// PowerslideSpray plus tire/cab/trailer bones through CabRotationMultiplier
// at 0x1DC; donor reference: BFME1 W3DTruckDrawModuleData_buildFieldParse.cpp
// describes the same table).

class MultiIniFieldParse;

struct FieldParse;

class MultiIniFieldParse
{
public:
	void add(const FieldParse *parse, unsigned int extraOffset);
};

class W3DModelDrawModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

class W3DSupplyDrawModuleData : public W3DModelDrawModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

void W3DSupplyDrawModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	W3DModelDrawModuleData::buildFieldParse(parse);
	parse.add(reinterpret_cast<const FieldParse *>(0x00BCBED8), 0);
}

class W3DTruckDrawModuleData : public W3DModelDrawModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

void W3DTruckDrawModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	W3DModelDrawModuleData::buildFieldParse(parse);
	parse.add(reinterpret_cast<const FieldParse *>(0x00BCC358), 0);
}

class W3DTankDrawModuleData : public W3DModelDrawModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

void W3DTankDrawModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	W3DModelDrawModuleData::buildFieldParse(parse);
	parse.add(reinterpret_cast<const FieldParse *>(0x00BCCAD0), 0);
}
