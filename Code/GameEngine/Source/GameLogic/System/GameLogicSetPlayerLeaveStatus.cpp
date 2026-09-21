// cl: /O1 /MD /EHsc
// ?setPlayerLeaveStatus@GameLogic@@QAEXHABVAsciiString@@H@Z @0x23D1A5 (62B):
// GameLogic player-leave-status slot setter called once per slot from
// GameLogic::bfmePopulateGameReport at 0x247672. Retail bounds-checks the
// slot, clears the slot's not-present flag, copies the slot display name and
// records the human status. The BFME1 donor
// (GameLogicPopulateGameReport.cpp) inlines these three stores in its slot
// loop over statusName-8 (not-present), statusName->set (name) and
// statusName-4 (human); BFME2 outlines them here. The entry stride is 0x1C
// with the name at +0x18, so AsciiString is the 4-byte pooled handle here.
typedef bool Bool;

class AsciiString
{
public:
	void set(const AsciiString &that);
};

struct PlayerLeaveStatus
{
	int m_status;
	int m_quitFrame;
	int m_defeatFrame;
	int m_victoryFrame;
	Bool m_notPresent;
	unsigned char m_unknown11[3];
	int m_isHuman;
	AsciiString m_playerName;
};

class GameLogic
{
public:
	void setPlayerLeaveStatus(int slotIndex, const AsciiString &playerName, int isHuman);
	PlayerLeaveStatus *getPlayerLeaveStatus(int playerIndex);

private:
	unsigned char m_unknown00[0x1C4];
	PlayerLeaveStatus m_playerLeaveStatus[8];
};

// ?setPlayerLeaveStatus@GameLogic@@QAEXHABVAsciiString@@H@Z
void GameLogic::setPlayerLeaveStatus(int slotIndex, const AsciiString &playerName, int isHuman)
{
	if (slotIndex < 0 || slotIndex >= 8)
		return;
	m_playerLeaveStatus[slotIndex].m_notPresent = false;
	m_playerLeaveStatus[slotIndex].m_playerName.set(playerName);
	m_playerLeaveStatus[slotIndex].m_isHuman = isHuman;
}

// ?getPlayerLeaveStatus@GameLogic@@QAEPAUPlayerLeaveStatus@@H@Z
PlayerLeaveStatus *GameLogic::getPlayerLeaveStatus(int playerIndex)
{
	if (playerIndex >= 0 && playerIndex < 8)
		return &m_playerLeaveStatus[playerIndex];
	return 0;
}
