// cl: /O1 /DNDEBUG /MD /EHsc

// ??0StatsCollector@@QAE@XZ, retail 0x004376FA (91 bytes).
// BFME1 StatsCollector.cpp donor, trimmed to the constructor; the remaining
// file bodies live at other game.dat addresses and land separately.
// Retail-measured BFME2 repairs:
// - GameLogic::m_frame is at +0x40 here (Zero Hour donor has +0x3C).
// - TheGameLogic bakes to its absolute (no ledger pin for the global).
// - /O1: the size-optimized allocator reuses ecx for the frame value where
//   /O2 spends edx.

typedef int Int;
typedef unsigned int UnsignedInt;
typedef int Bool;

#define FALSE 0

template <typename T> class StringBase
{
public:
	int compare(const char *other) const;

protected:
	char *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() { m_data = 0; }
};

class Object;
class Player;

struct GameLogic
{
	Object *getFirstObject();
	UnsignedInt getFrame() const { return m_frame; }

	char m_pad00[ 0x40 ];
	UnsignedInt m_frame;
};

extern void *TheGameLogic;

class ThingTemplate
{
public:
	Bool isKindOf(Int kind) const { return (m_kindOf & (1U << kind)) != 0; }

private:
	void *m_vtable;
	void *m_nextOverride;
	unsigned char m_pad08[ 0x108 - 8 ];
	UnsignedInt m_kindOf;
};

class Player
{
public:
	bool isLocalPlayer() const;
	const AsciiString &getSide() const { return m_side; }

private:
	void *m_vtable;
	unsigned char m_pad04[ 0x58 - 4 ];
	AsciiString m_side;
};

class Object
{
public:
	const ThingTemplate *getTemplate() const { return m_thingTemplate; }
	Bool isKindOf(Int kind) const { return getTemplate()->isKindOf(kind); }
	bool isNeutralControlled() const;
	Player *getControllingPlayer() const;
	Object *getNextObject() const { return m_nextObject; }

private:
	void *m_vtable;
	ThingTemplate *m_thingTemplate;
	unsigned char m_pad08[ 0x8c - 8 ];
	Object *m_nextObject;
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/Common/StatsCollector.h
class StatsCollector
{
public:
	StatsCollector();
	void collectUnitCountStats();

private:
	AsciiString m_statsFileName;
	UnsignedInt m_moneyWithdrawn;
	UnsignedInt m_moneyDeposited;
	UnsignedInt m_buildCommands;
	UnsignedInt m_moveCommands;
	UnsignedInt m_attackCommands;
	UnsignedInt m_scrollMapCommands;
	UnsignedInt m_aiUnits;
	UnsignedInt m_playerUnits;
	UnsignedInt m_alliesKilled;
	UnsignedInt m_neutralsKilled;
	UnsignedInt m_enemiesKilled;
	UnsignedInt m_scoreKeeperMoneySpent;
	UnsignedInt m_scoreKeeperMoneyEarned;
	UnsignedInt m_scoreKeeperUnitsDestroyed;
	UnsignedInt m_scoreKeeperUnitsBuilt;
	UnsignedInt m_scoreKeeperUnitsLost;
	UnsignedInt m_scoreKeeperBuildingsDestroyed;
	UnsignedInt m_scoreKeeperBuildingsBuilt;
	UnsignedInt m_scoreKeeperBuildingsLost;
	UnsignedInt m_scrollBeginTime;
	UnsignedInt m_scrollTime;
	bool m_isScrolling;
	Int m_timeCount;
	Int m_lastUpdate;
	Int m_startFrame;
};

StatsCollector::StatsCollector()
{
	m_moneyWithdrawn = 0;
	m_moneyDeposited = 0;
	m_buildCommands = 0;
	m_moveCommands = 0;
	m_attackCommands = 0;
	m_scrollMapCommands = 0;
	m_aiUnits = 0;
	m_playerUnits = 0;
	m_alliesKilled = 0;
	m_neutralsKilled = 0;
	m_enemiesKilled = 0;
	m_scoreKeeperMoneySpent = 0;
	m_scoreKeeperMoneyEarned = 0;
	m_scoreKeeperUnitsDestroyed = 0;
	m_scoreKeeperUnitsBuilt = 0;
	m_scoreKeeperUnitsLost = 0;
	m_scoreKeeperBuildingsDestroyed = 0;
	m_scoreKeeperBuildingsBuilt = 0;
	m_scoreKeeperBuildingsLost = 0;
	m_scrollBeginTime = 0;
	m_scrollTime = 0;
	m_isScrolling = FALSE;
	m_timeCount = 0;
	m_lastUpdate = 0;
	UnsignedInt frame = static_cast<GameLogic *>( TheGameLogic )->getFrame();
	m_startFrame = frame;
}

// ?collectUnitCountStats@StatsCollector@@QAEXXZ, retail 0x00437B4D (105 bytes).
// BFME1 StatsCollector.cpp donor (StatsCollector::collectUnitCountStats) with
// BFME2 layout repairs; anchored by the "Civilian" literal plus the
// getFirstObject/getControllingPlayer/compare/isLocalPlayer call chain.
// Retail-measured BFME2 repairs vs the BFME1 donor:
// - Object::m_nextObject is at +0x8c here (BFME1 donor has +0x88).
// - ThingTemplate::m_kindOf is at +0x108 here; isKindOf(8)||isKindOf(9) folds
//   to a single `test byte [eax+0x109],3`.
// - Object::getTemplate is direct here (no m_nextOverride check); the donor
//   override walk would emit extra branches.
// - StringBase<char>::compare (0x000069B1), Object::getControllingPlayer
//   (0x0028AFA9) and GameLogic::getFirstObject (0x0023CAD2) are rowed; the
//   minimal AsciiString stand-in above keeps the out-of-line call instead of
//   folding compare inline like the BFME1 donor does.
// - Object::isNeutralControlled (0x0028B091) and Player::isLocalPlayer
//   (0x002A9D89) are pinned; ThePlayerList is 0x00DFEEE8 with local at +0x10
//   and neutral at +0x18.
// - Player::m_side (AsciiString) is at +0x58 here.
// - /O1 (TU flags) keeps the frameless push-esi/push-edi loop with the shared
//   counting tail.
void StatsCollector::collectUnitCountStats()
{
	for( Object *obj = static_cast<GameLogic *>( TheGameLogic )->getFirstObject(); obj; obj = obj->getNextObject() )
	{
		if( !(obj->isKindOf( 8 ) || obj->isKindOf( 9 )) ||
			obj->isNeutralControlled() ||
			obj->getControllingPlayer()->getSide().compare( "Civilian" ) == 0 )
			continue;

		if( obj->getControllingPlayer()->isLocalPlayer() )
			++m_playerUnits;
		else
			++m_aiUnits;
	}
}
