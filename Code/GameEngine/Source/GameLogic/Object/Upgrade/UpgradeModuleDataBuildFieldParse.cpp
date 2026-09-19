// ?buildFieldParse@UpgradeModuleData@@SAXAAVMultiIniFieldParse@@@Z
// retail 0x004CEE09, 17 bytes. Dedicated TU.
//
// Transferred from the BFME1 reconstruction (BFME1 0x00122DC0, same bytes):
// register the base upgrade table, then return. Retail adaptations, all
// measured from the target bytes: the callee is the already-rowed
// MultiIniFieldParse::add (zero new pins); retail passes extraOffset 8.
// The pushed table address decodes outside the file image, so its entries
// are unrecoverable from retail; the TU keeps a terminator-only table,
// which is all the 17 body bytes depend on (the push is a masked DIR32).

struct FieldParse
{
	const char *m_name;
	void *m_parse;
	void *m_extra;
	unsigned m_offset;
};

class MultiIniFieldParse
{
public:
	void add(const FieldParse *fields, unsigned extraOffset);
};

class UpgradeModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &p);
};

static const FieldParse dataFieldParse[] =
{
	{ 0, 0, 0, 0 }
};

// ?buildFieldParse@UpgradeModuleData@@SAXAAVMultiIniFieldParse@@@Z
void UpgradeModuleData::buildFieldParse(MultiIniFieldParse &p)
{
	p.add(dataFieldParse, 8);
}
