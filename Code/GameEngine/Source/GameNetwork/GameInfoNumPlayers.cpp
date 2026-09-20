// cl: /O1 /DNDEBUG /MD /EHsc

// GameInfo player counters (retail 0x3FF218..0x3FF267).
// BFME1 GameInfo.cpp donor verbatim: getNumPlayers counts non-null
// occupied slots, getNumNonObserverPlayers additionally skips the observer
// template. Retail compiles the index loops to a pointer walk with a
// push-8 countdown; isOccupied rides the banked 0x3FF0FB pin and the
// template check inlines to a compare against +0x18.

typedef int Int;

enum { MAX_SLOTS = 8 };
enum { PLAYERTEMPLATE_OBSERVER = -2 };

// BFME2 inserts a seventh slot state at 5 between BRUTAL_AI and PLAYER.
// The name is inferred: it fills the gap and counts as occupied (and as AI
// in isAI). Rename on contrary evidence.
enum { SLOT_OPEN = 0 };
enum { SLOT_CLOSED = 1 };
enum { SLOT_EASY_AI = 2 };
enum { SLOT_MED_AI = 3 };
enum { SLOT_BRUTAL_AI = 4 };
enum { SLOT_OBSERVER = 5 };
enum { SLOT_PLAYER = 6 };

class GameSlot
{
public:
	bool isOccupied() const;
	Int getPlayerTemplate() const { return m_playerTemplate; }
private:
	void *m_vtable;
	Int m_state;
	bool m_isAccepted;
	bool m_hasMap;
	bool m_isMuted;
	char m_pad0B;
	Int m_color;
	Int m_startPos;
	char m_pad14[4];
	Int m_playerTemplate;
	// The occupancy byte lives far down at +0x1A4 (retail reads it in
	// isOccupied); the fields between the template and it are not needed
	// here. Canonical prefix layout is documented in GameSlotApparent.cpp.
	char m_pad1C[0x1A4 - 0x1C];
	bool m_occupied;
};

class GameInfo
{
public:
	Int getNumPlayers() const;
	Int getNumNonObserverPlayers() const;
private:
	char m_pad[0x18];
	GameSlot *m_slot[MAX_SLOTS];
};

bool GameSlot::isOccupied() const
{
	return (m_state == SLOT_PLAYER || m_state == SLOT_EASY_AI || m_state == SLOT_MED_AI || m_state == SLOT_BRUTAL_AI || m_state == SLOT_OBSERVER) && m_occupied;
}

Int GameInfo::getNumPlayers() const
{
	Int numPlayers = 0;
	for (Int i = 0; i < MAX_SLOTS; ++i)
	{
		if (m_slot[i] && m_slot[i]->isOccupied())
			numPlayers++;
	}
	return numPlayers;
}
Int GameInfo::getNumNonObserverPlayers() const
{
	Int numPlayers = 0;
	for (Int i = 0; i < MAX_SLOTS; ++i)
	{
		if (m_slot[i] && m_slot[i]->isOccupied() && m_slot[i]->getPlayerTemplate() != PLAYERTEMPLATE_OBSERVER)
			numPlayers++;
	}
	return numPlayers;
}
