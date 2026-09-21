// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?getLocalPlayerStartWaypointName@GameLogic@@QAEXPAVAsciiString@@@Z @0x0024822B (77B):
// GameLogic helper: refresh the start-game report to learn the local slot,
// then write that slot's 1-based "Player_%d_Start" waypoint name into `name`
// when the slot is human. The report builder is the BFME1
// GameLogicPopulateGameReport.cpp donor (GameLogic::bfmePopulateGameReport,
// pinned at 0x00247378: same (GameInfo*, int*) shape and the same
// dashes/BuildType literals; BFME2 GameLogic carries its vtable at +0 so its
// m_gameReport sits at +0x54 not +0x50). getSlot/isHuman/format are rows.

class GameInfo;
class GameSlot;
class AsciiString;

class GameInfo
{
public:
	GameSlot *getSlot(int slot);
};

class GameSlot
{
public:
	bool isHuman() const;
	int getStartPos() const { return m_startPos; }

private:
	unsigned char m_pad[0x10];
	int m_startPos;
};

class AsciiString
{
public:
	void __cdecl format(const char *format, ...);
};

class GameLogic
{
public:
	void bfmePopulateGameReport(GameInfo *game, int *localSlot);
	void getLocalPlayerStartWaypointName(AsciiString *name);
};

extern GameInfo *TheGameInfo;

void GameLogic::getLocalPlayerStartWaypointName(AsciiString *name)
{
	if (!TheGameInfo)
		return;
	int slotIndex;
	bfmePopulateGameReport(TheGameInfo, &slotIndex);
	GameSlot *slot = TheGameInfo->getSlot(slotIndex);
	if (slot->isHuman())
		name->format("Player_%d_Start", slot->getStartPos() + 1);
}
