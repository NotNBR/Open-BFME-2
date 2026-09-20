// cl: /DNDEBUG /MD /EHsc

// LifetimeUpdateModuleData's constructor, retail 0x00297E90. No base constructor call at
// all - the class writes its own vftable pointer at +0x00 and leaves the base's
// word at +0x04 alone, which is what an implicit base constructor looks like.
// Everything from +0x08 is this class's own.

// BFME2 retail stores the immediate 0x00C4ED70 as this instance's vftable pointer.

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/GameLogic/Module/LifetimeUpdate.h
class LifetimeUpdateModuleData
{
public:
	LifetimeUpdateModuleData();

private:
	const char *m_vtable;
	int m_unmodelled_04;
	int m_unmodelled_08;					// +0x08
	int m_unmodelled_0C;					// +0x0C
	bool m_unmodelled_10;					// +0x10
	bool m_unmodelled_11;					// +0x11
	int m_unmodelled_14;					// +0x14
};

LifetimeUpdateModuleData::LifetimeUpdateModuleData()
	: m_vtable( (const char *)0x00C4ED70 ),
	  m_unmodelled_08( 0 ),
	  m_unmodelled_0C( 0 ),
	  m_unmodelled_10( false ),
	  m_unmodelled_11( false ),
	  m_unmodelled_14( 0 )
{
}
