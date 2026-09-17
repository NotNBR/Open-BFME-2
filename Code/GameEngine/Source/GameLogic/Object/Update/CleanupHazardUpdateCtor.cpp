// cl: /O1 /MD /DNDEBUG
// ??0CleanupHazardUpdate@@QAE@XZ at retail 0x004C964C.
// Root-class default ctor: vtable plus two int members. No base, no calls.
// Factory stub order names it; stub size 0x10 confirms the layout.
class CleanupHazardUpdate
{
public:
	CleanupHazardUpdate();
	virtual ~CleanupHazardUpdate();

private:
	int m_pad04;
	int m_i08;
	int m_i0C;
};

CleanupHazardUpdate::CleanupHazardUpdate()
	: m_i08(0x1E), m_i0C(0x0F)
{
}

CleanupHazardUpdate::~CleanupHazardUpdate()
{
}
