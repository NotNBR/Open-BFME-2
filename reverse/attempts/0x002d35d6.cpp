// ?hasOverrideWindow@RadarWindowOverrideSource@@QBE_NXZ
// partial score=0.85 date=2026-09-14
// cl: /O1
//
// Radar window override accessors, retail 0x002D35CF (7B) and 0x002D35D6 (16B).
// Split into a dedicated TU so RadarNewMap.cpp keeps its matched newMap:
// defining these in the same unit lets MSVC see the callee and changes the
// caller's register save set (docs/matching.md pattern five).

class GameWindow;

struct RadarWindowOverrideInner
{
	char m_pad[ 0x60 ];
	unsigned char m_flags;
	char m_pad61[ 3 ];
	GameWindow *m_window;
};

class RadarWindowOverrideSource
{
public:
	bool hasOverrideWindow( void ) const;
	GameWindow *getOverrideWindow( void ) const;

private:
	char m_pad[ 0x10 ];
	RadarWindowOverrideInner *m_inner;
};

GameWindow *RadarWindowOverrideSource::getOverrideWindow( void ) const
{
	return m_inner->m_window;
}

bool RadarWindowOverrideSource::hasOverrideWindow( void ) const
{
	if ( m_inner->m_flags & 7 )
		return false;
	return true;
}
