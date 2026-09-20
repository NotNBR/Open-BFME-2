// cl: /O1 /DNDEBUG /MD /EHsc

// GameSlot AI-state predicate, retail 0x003FF127 (30 bytes).
// BFME1 GameInfo.cpp donor
// (reference/open-bfme-1/.../GameNetwork/GameInfo.cpp): GameSlot::isAI
// returns true for the four AI slot states. BFME2 keeps the same shape;
// the slot-state field sits at +0x04 behind the vtable, proven by the
// sibling isOccupied body at 0x003FF0FB and the apparent family in
// GameSlotApparent.cpp. No calls, no globals.

typedef int Int;

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
	bool isAI() const;

private:
	void *m_vtable;
	Int m_state; // +0x04
};

bool GameSlot::isAI() const
{
	return m_state == SLOT_EASY_AI || m_state == SLOT_MED_AI || m_state == SLOT_BRUTAL_AI || m_state == SLOT_OBSERVER;
}
