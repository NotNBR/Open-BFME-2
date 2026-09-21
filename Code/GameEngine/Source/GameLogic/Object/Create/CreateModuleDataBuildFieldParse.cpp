// cl: /O1 /DNDEBUG /MD
//
// Single-table CreateModuleData::buildFieldParse procs (11 bytes each).
// First entry:
// ?buildFieldParse@GrantUpgradeCreateModuleData@@SAXAAVMultiIniFieldParse@@@Z,
// retail 0x004B8FF0, registers the table at 0x00C594A0 (UpgradeToGrant plus
// ExemptStatus plus GiveOnBuildComplete) with MultiIniFieldParse::add (rowed
// at 0x2BC6E). Provenance: the BFME1 GrantUpgradeCreate.cpp donor carries
// the UpgradeToGrant plus ExemptStatus table for GrantUpgradeCreateModuleData;
// the BFME2 table extends it with GiveOnBuildComplete. The owning factory
// (0x250B41) pushes this proc immediate. Recipe: the Update-side shared
// ModuleDataBuildFieldParse.cpp FIELD_PROC TU.

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

FIELD_PROC(GrantUpgradeCreateModuleData, 0x00C594A0, GrantUpgradeTable)
FIELD_PROC(ObjectCreationUpgradeModuleData, 0x00C57708, ObjectCreationTable)
