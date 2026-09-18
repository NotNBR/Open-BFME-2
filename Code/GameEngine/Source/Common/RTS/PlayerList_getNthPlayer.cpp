// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?getNthPlayer@PlayerList@@QAEPAVPlayer@@H@Z,
// retail 0x002A7A29, 22 bytes. Dedicated TU.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/Common/RTS/PlayerList.cpp,
// PlayerList::getNthPlayer): bounds-checked indexed accessor over the player
// array. Battle for Middle-earth 2 caps the index at 20 (retail cmp eax,0x14;
// the five 0x2A7AB6-family loop bodies and the 0x2A79A9 init body all iterate
// the same 0x14 count, and the count lives at +0x14 over the inline player
// pointer array at +0x18 per the landed findPlayerWithNameKey row), where the
// reference uses 32. Leaf, no pins.

typedef int Int;

#define NULL 0

class Player
{
};

class PlayerList
{
public:
	Player *getNthPlayer(Int i);

private:
	unsigned char m_pad[0x14];
	Int m_playerCount; // +0x14
	Player *m_players[1]; // +0x18
};

// ?getNthPlayer@PlayerList@@QAEPAVPlayer@@H@Z
Player *PlayerList::getNthPlayer(Int i)
{
	if (i < 0 || i >= 20)
	{
		return NULL;
	}
	return m_players[i];
}
