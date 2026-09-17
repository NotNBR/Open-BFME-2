// cl: /O1 /MD /DNDEBUG
// ??0DeliverPayloadAIUpdate@@QAE@XZ at retail 0x004C72D3.
// Default ctor over opaque intermediate base 0x004930A0 (pinned); vtable
// only, no trailing members. Factory stub order names it.
class Rva004930A0
{
public:
	Rva004930A0();
	virtual ~Rva004930A0();

protected:
	unsigned char m_pad[0x7C - 4];
};

Rva004930A0::~Rva004930A0()
{
}

class DeliverPayloadAIUpdate : public Rva004930A0
{
public:
	DeliverPayloadAIUpdate();
	virtual ~DeliverPayloadAIUpdate();
};

DeliverPayloadAIUpdate::DeliverPayloadAIUpdate()
	: Rva004930A0()
{
}

DeliverPayloadAIUpdate::~DeliverPayloadAIUpdate()
{
}
