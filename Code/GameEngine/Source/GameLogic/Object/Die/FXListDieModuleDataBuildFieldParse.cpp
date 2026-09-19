// FXListDieModuleData::buildFieldParse -- registers the module's INI field
// tables with the shared MultiIniFieldParse walker. Retail (0x50B107, 51B)
// issues three add() calls: two via the DieMuxData table getters
// (pins 0x507552/0x5088C8, each returning a .data table address) and one
// naming a .data FieldParse table directly (0xC64C08, DIR32-patched).

struct FieldParse
{
};

class MultiIniFieldParse
{
public:
	void add(const FieldParse *entry, unsigned int index);
};

struct Rva00507552
{
	static void *opaqueCall();
};

struct Rva005088C8
{
	static void *opaqueCall();
};

static const FieldParse s_extraFieldTable;

class FXListDieModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

void FXListDieModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	parse.add((const FieldParse *)Rva00507552::opaqueCall(), 0);
	parse.add((const FieldParse *)Rva005088C8::opaqueCall(), 0);
	parse.add(&s_extraFieldTable, 0);
}
