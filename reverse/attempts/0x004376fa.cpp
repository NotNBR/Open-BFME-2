// ??0StatsCollector@@QAE@XZ
// partial score=0.98 date=2026-09-20
// cl: /DNDEBUG /MD /EHsc

// ??0StatsCollector@@QAE@XZ, retail 0x004376FA (91 bytes).
// BFME1 StatsCollector.cpp donor, trimmed to the constructor; the remaining
// file bodies live at other game.dat addresses and land separately.
// Retail-measured BFME2 repairs:
// - GameLogic::m_frame is at +0x40 here (Zero Hour donor has +0x3C).
// - TheGameLogic bakes to its absolute (no ledger pin for the global).

typedef int Int;
typedef unsigned int UnsignedInt;
typedef int Bool;

#define FALSE 0

class AsciiString
{
public:
	AsciiString() : m_data( 0 ) {}

private:
	char *m_data;
};

struct GameLogicFrame
{
	UnsignedInt getFrame() const { return m_frame; }

	char m_pad00[ 0x40 ];
	UnsignedInt m_frame;
};

extern void *TheGameLogic;

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/Common/StatsCollector.h
class StatsCollector
{
public:
	StatsCollector();

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
	UnsignedInt frame = static_cast<GameLogicFrame *>( TheGameLogic )->getFrame();
	m_startFrame = frame;
}
