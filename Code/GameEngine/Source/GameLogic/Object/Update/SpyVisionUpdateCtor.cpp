// cl: /O1 /arch:SSE /MD /DNDEBUG
// ??0SpyVisionUpdate@@QAE@XZ (0x44EB54-base family).
// Default ctor; two trailing ints plus one trailing float. Vtable hand-placed
// late (novtable) after the ints.
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

extern "C" char SpyVisionUpdate_vftable;

class __declspec(novtable) SpyVisionUpdate : public Rva0044EB54
{
public:
	SpyVisionUpdate();
	virtual ~SpyVisionUpdate();

private:
	int m_iC8;
	int m_iCC;
	float m_fD0;
};

static float kZero = 0.0f;

SpyVisionUpdate::SpyVisionUpdate()
	: Rva0044EB54()
{
	m_iC8 = 0;
	m_iCC = 0;
	*reinterpret_cast<char **>(this) = &SpyVisionUpdate_vftable;
	m_fD0 = kZero;
}

SpyVisionUpdate::~SpyVisionUpdate()
{
}
