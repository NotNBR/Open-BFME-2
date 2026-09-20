// cl: /O1 /DNDEBUG /MD /EHsc

// GameInfo player-count file-unit plus the two GameSlot predicates the
// counts call through. BFME1 GameNetwork/GameInfo.cpp donor shapes, with two
// BFME2 deltas proven by retail bytes: the human slot state moved 5 -> 6 for
// a new fifth state that rides with the AI states, and isOccupied() also
// requires the occupancy byte at +0x1A4. The predicates must live in this TU
// with the counters: same-TU visibility into isOccupied's definition is what
// lets the counters keep the slot pointer in EDX across the call with the
// count/limit in EDI/ESI (calling the pin as an opaque extern instead spills
// the pointer to ESI and the count to EBX).

typedef int Int;

enum { MAX_SLOTS = 8 };

enum SlotState
{
	SLOT_OPEN = 0,
	SLOT_CLOSED = 1,
	SLOT_EASY_AI = 2,
	SLOT_MED_AI = 3,
	SLOT_BRUTAL_AI = 4,
	// Retail compares against state 5 alongside the AI states in both
	// isOccupied and isAI; ZH has no fifth state, so this BFME2 addition
	// keeps a mechanical name until its identity is proven.
	SLOT_AI_5 = 5,
	SLOT_PLAYER = 6
};

enum
{
	PLAYERTEMPLATE_RANDOM = -1,
	PLAYERTEMPLATE_OBSERVER = -2
};

class GameSlot
{
public:
	virtual void reset();
	bool isOccupied() const;
	bool isAI() const;
	Int getPlayerTemplate() const { return m_playerTemplate; }

private:
	Int m_state;                    // +0x04
	char m_pad08[0x10];             // +0x08
	Int m_playerTemplate;           // +0x18
	char m_pad1C[0x188];            // +0x1C
	unsigned char m_occupancy;      // +0x1A4
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

// ?isOccupied@GameSlot@@QBE_NXZ
bool GameSlot::isOccupied() const
{
	return (m_state == SLOT_PLAYER || m_state == SLOT_EASY_AI || m_state == SLOT_MED_AI
		|| m_state == SLOT_BRUTAL_AI || m_state == SLOT_AI_5) && m_occupancy;
}

// ?isAI@GameSlot@@QBE_NXZ
bool GameSlot::isAI() const
{
	return m_state == SLOT_EASY_AI || m_state == SLOT_MED_AI
		|| m_state == SLOT_BRUTAL_AI || m_state == SLOT_AI_5;
}

// ?getNumPlayers@GameInfo@@QBEHXZ
Int GameInfo::getNumPlayers() const
{
	Int numPlayers = 0;
	for (int i = 0; i < MAX_SLOTS; ++i)
	{
		if (m_slot[i] && m_slot[i]->isOccupied())
			numPlayers++;
	}
	return numPlayers;
}

// ?getNumNonObserverPlayers@GameInfo@@QBEHXZ
Int GameInfo::getNumNonObserverPlayers() const
{
	Int numPlayers = 0;
	for (int i = 0; i < MAX_SLOTS; ++i)
	{
		if (m_slot[i] && m_slot[i]->isOccupied()
			&& m_slot[i]->getPlayerTemplate() != PLAYERTEMPLATE_OBSERVER)
			numPlayers++;
	}
	return numPlayers;
}
