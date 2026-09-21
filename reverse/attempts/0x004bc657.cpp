// ??0CrateCollideModuleData@@QAE@XZ
// partial score=0.95 date=2026-09-21
// cl: /O1 /arch:SSE /DNDEBUG /MD /GX
typedef int Int;
#define NULL 0

template <typename T>
class StringBase
{
	friend class AsciiString;
public:
	StringBase() : m_data(0) {}
private:
	StringBase(const StringBase<T> &that);
	T *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	__forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
};

class KindMask
{
public:
	KindMask();
	unsigned char m_data[0x1C];
};

struct ScienceSlot
{
	ScienceSlot() { m_value |= -1; }
	int m_value;
};

extern AsciiString g_emptyString;

class CrateCollideModuleDataBase
{
public:
	CrateCollideModuleDataBase() {}
	~CrateCollideModuleDataBase();
};

class CrateCollideModuleData : public CrateCollideModuleDataBase
{
public:
	CrateCollideModuleData();
private:
	const void *m_vtable;
	unsigned int m_unused04;
	KindMask m_requiredKindOf;
	KindMask m_forbiddenKindOf;
	bool m_forbidOwnerPlayer;
	bool m_buildingPickup;
	bool m_humanOnlyPickup;
	unsigned char m_pad43;
	ScienceSlot m_pickupScience;
	const char *m_executeFX;
	AsciiString m_executeAnimation;
	float m_executeAnimationTime;
	float m_executeAnimationZRise;
	bool m_flag58;
};

CrateCollideModuleData::CrateCollideModuleData()
	: CrateCollideModuleDataBase()
	, m_vtable(reinterpret_cast<const void *>(0x00C5A660))
	, m_forbidOwnerPlayer(false)
	, m_buildingPickup(false)
	, m_humanOnlyPickup(false)
	, m_executeFX(NULL)
	, m_executeAnimation(g_emptyString)
{
	m_executeAnimationTime = 0.0f;
	m_executeAnimationZRise = 0.0f;
	m_flag58 = true;
}
