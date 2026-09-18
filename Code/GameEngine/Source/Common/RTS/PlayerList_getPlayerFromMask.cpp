// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?getPlayerFromMask@PlayerList@@QAEPAVPlayer@@H@Z,
// retail 0x002A7A6F, 49 bytes. Dedicated TU.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/Common/RTS/PlayerList.cpp,
// PlayerList::getPlayerFromMask): linear scan of the player array for a
// matching mask. Retail is the crash-less twin of the findPlayerWithNameKey
// body at 0x002A7A41 (same TU flags, same codegen, only the field offset
// differs: mask at +0x3AC instead of name key at +0x50, hence 3 bytes longer
// for the disp32 load). The retail count sits at +0x14 over an inline player
// pointer array at +0x18, exactly as in the sibling TU.
//
// Identity evidence: five image-wide callers all go through ThePlayerList
// (0x00DFEEE8) passing mask-sized dwords (object +0x14/+0x54 words, one plain
// int parameter); Zero Hour's PlayerList header declares getPlayerFromMask as
// the only other single-key player lookup besides findPlayerWithNameKey; the
// DEBUG_CRASH strings of the Battle for Middle-earth 1 twin ("Player does not
// exist for mask", "Illegal player index") are absent from this binary, which
// is why the retail body is the crash-less direct walk (same simplification
// as the landed getNthPlayer twin). The mask reads as a full dword, so the
// parameter is claimed as 32-bit Int.

typedef int Int;

#define NULL 0

class Player
{
public:
	unsigned int getPlayerMask() const { return m_playerMask; }

private:
	unsigned char m_pad[0x3AC];
	unsigned int m_playerMask; // +0x3AC
};

class PlayerList
{
public:
	Player *getPlayerFromMask(Int mask);

private:
	unsigned char m_pad[0x14];
	Int m_playerCount; // +0x14
	Player *m_players[1]; // +0x18
};

// ?getPlayerFromMask@PlayerList@@QAEPAVPlayer@@H@Z
Player *PlayerList::getPlayerFromMask(Int mask)
{
	for (Int i = 0; i < m_playerCount; i++)
	{
		if (m_players[i]->getPlayerMask() == (unsigned int)mask)
		{
			return m_players[i];
		}
	}
	return NULL;
}
