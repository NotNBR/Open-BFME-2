// ChinookAIUpdateModuleData::buildFieldParse -- registers the module's INI
// field tables with the shared MultiIniFieldParse walker. Retail (0x4C1B80,
// 43B) issues a parent call plus two add() calls: one via the shared
// table getter (pin 0x4CE29D) at index 0x64 and one naming a TU-local
// FieldParse table directly (DIR32-patched). The ZH Rope table in
// ChinookAIUpdate.cpp does not reproduce these bytes, and that TU cannot host
// this body either: it includes the SupplyTruck header whose inline
// SupplyTruckAIUpdateModuleData::buildFieldParse gets inlined (parent call
// plus SupplyTruck table) instead of calling the retail 0x4BFDF6 leaf. This
// shard declares SupplyTruck's parse without defining it so the call stays a
// REL32 the pin resolves.
//
// /O1 for the pop-ecx cdecl cleanup retail uses after the parent call.

// cl: /O1 /DNDEBUG /MD /EHsc

struct FieldParse
{
};

class MultiIniFieldParse
{
public:
	void add(const FieldParse *entry, unsigned int index);
};

class SupplyTruckAIUpdateModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

class ChinookAIUpdateModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

int Rva004CE29DGet();

static const FieldParse s_chinookFieldTable;

// ?buildFieldParse@ChinookAIUpdateModuleData@@SAXAAVMultiIniFieldParse@@@Z @0x4C1B80
/*static*/ void ChinookAIUpdateModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	SupplyTruckAIUpdateModuleData::buildFieldParse(parse);
	parse.add((const FieldParse *)Rva004CE29DGet(), 0x64);
	parse.add(&s_chinookFieldTable, 0);
}
