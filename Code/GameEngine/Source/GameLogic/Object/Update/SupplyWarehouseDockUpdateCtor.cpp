// cl: /O1 /MD /DNDEBUG
// ??0SupplyWarehouseDockUpdate@@QAE@XZ at retail 0x004CDFD9.
// Default ctor over the second intermediate base 0x0044EB54 (pinned opaque
// as Rva0044EB54, 0xC8 bytes). No trailing members (factory size 0xC8).
// Factory stub order names it. Do NOT declare an explicit vptr member.
class Rva0044EB54
{
public:
	Rva0044EB54();
	virtual ~Rva0044EB54();

protected:
	unsigned char m_pad[0xC8 - 4];
};

Rva0044EB54::~Rva0044EB54()
{
}

class SupplyWarehouseDockUpdate : public Rva0044EB54
{
public:
	SupplyWarehouseDockUpdate();
	virtual ~SupplyWarehouseDockUpdate();
};

SupplyWarehouseDockUpdate::SupplyWarehouseDockUpdate()
	: Rva0044EB54()
{
}

SupplyWarehouseDockUpdate::~SupplyWarehouseDockUpdate()
{
}
