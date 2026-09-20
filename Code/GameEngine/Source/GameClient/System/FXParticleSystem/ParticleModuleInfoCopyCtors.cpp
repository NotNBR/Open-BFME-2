// cl: /O2 /Os /DNDEBUG /MD /EHs-c-
// Particle module-info copy constructors (retail 0x003AE465..0x003AF50D).
// One 59-byte base plus per-class trivial bodies: each derived calls the
// base with (this, other) and then installs its own vftables.  The extra
// bases are DEFAULT-constructed, not copied: the third-base vptr stored
// first is the base's own, overwritten by the derived stores below.
//
// Identity: every body calls the base at 0x003AF50D (19 call sites across
// 0x003AE465..0x00561D94); the stored vftables sit beside their ModuleInfo
// name strings in .rdata; the 0x003AE336 name getter returns
// "ParticleTerrainCollisionModuleInfo" for the 0x003AE465 body; the second
// base vptr 0x00C1C780 is shared with the rowed FXParticleSystem
// CategoryModuleTemplate constructors.  The member at +0x04 copies through
// the pinned 12-byte smart-pointer copy at 0x0004CC19.  All vftable dwords
// are DIR32 sites the gate takes from the target.  /O2 over /Os: the
// straight-line bodies need speed-optimizer inlining plus size-optimizer
// argument passing; the head copy is forceinline so the size optimizer
// still absorbs it (a plain implicit copy outlines to a HeadBase::copy
// call under /Os, and picks ecx for the int scratch under /O2 where
// retail uses eax).

class RvaSmartPtr12
{
public:
	RvaSmartPtr12(const RvaSmartPtr12 &that);
	~RvaSmartPtr12();

private:
	void *m_ptr; // +0x0
	int m_pad04; // +0x4
	int m_pad08; // +0x8
};

// Shared second base at +0x14: vptr 0x00C1C780.
class ModuleInfoSecondBase
{
public:
	virtual ~ModuleInfoSecondBase();
};

// Head base: vptr 0x00C1B590, smart member at +0x04, int at +0x10.
// Explicit forceinline copy (see header note).
class ModuleInfoHeadBase
{
public:
	__forceinline ModuleInfoHeadBase(const ModuleInfoHeadBase &other)
		: m_smart(other.m_smart)
		, m_int10(other.m_int10)
	{
	}
	virtual ~ModuleInfoHeadBase();

	RvaSmartPtr12 m_smart; // +0x04
	int m_int10; // +0x10
};

#define MODULE_INFO_THIRD_BASE(NAME) \
	class NAME \
	{ \
	public: \
		virtual ~NAME(); \
	};

MODULE_INFO_THIRD_BASE(ModuleInfoThirdBAC0)
MODULE_INFO_THIRD_BASE(ModuleInfoThirdBD10)
MODULE_INFO_THIRD_BASE(ModuleInfoThirdBD30)
MODULE_INFO_THIRD_BASE(ModuleInfoThirdBD50)

// Retail 0x003AF50D, 59 bytes: the shared base copy constructor.
// noinline: the derived bodies below call it; inlining would absorb the
// straight-line body into each caller (the BFME1 donor marks its shared
// node copy the same way).
class Rva003AF50D : public ModuleInfoHeadBase, public ModuleInfoSecondBase
{
public:
	__declspec(noinline) Rva003AF50D(const Rva003AF50D &other);
	virtual ~Rva003AF50D();
};

Rva003AF50D::Rva003AF50D(const Rva003AF50D &other)
	: ModuleInfoHeadBase(other)
{
}
