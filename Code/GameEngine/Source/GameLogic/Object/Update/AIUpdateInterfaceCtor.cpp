// cl: /O1 /arch:SSE /MD /DNDEBUG
// Trial: ??0AIUpdateInterface@@QAE@XZ.
// Default ctor over opaque intermediate base 0x004930A0 (pinned); vtable
// plus one trailing float. Factory stub order names it.
class Rva004930A0
{
public:
	Rva004930A0();
	virtual ~Rva004930A0();

protected:
	unsigned char m_pad0[0x7C - 4];
	float m_f7C;
};

Rva004930A0::~Rva004930A0()
{
}

class AIUpdateInterface : public Rva004930A0
{
public:
	AIUpdateInterface();
	virtual ~AIUpdateInterface();

};

static float kF7C = 0.0f;

AIUpdateInterface::AIUpdateInterface()
	: Rva004930A0()
{
	m_f7C = kF7C;
}

AIUpdateInterface::~AIUpdateInterface()
{
}
