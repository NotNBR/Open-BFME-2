// cl: /O1 /DNDEBUG /MD /EHsc

// ?isNeutralControlled@Object@@QBE_NXZ, retail 0x0028B091 (23 bytes).
// Object::isNeutralControlled is `return getControllingPlayer() ==
// ThePlayerList->getNeutralPlayer()`. Retail-measured BFME2 layout:
// PlayerList::m_neutralPlayer is at +0x18 here (local is at +0x10);
// ThePlayerList is 0x00DFEEE8 and bakes to its absolute (no ledger pin).
// Object::getControllingPlayer (0x0028AFA9) is rowed; the decl-only call
// keeps the out-of-line E8. /O1 keeps the sub-neg-sbb-inc bool shape.

class Player;

class PlayerList
{
public:
	Player *getNeutralPlayer() const { return m_neutralPlayer; }

private:
	unsigned char m_pad00[ 0x18 ];
	Player *m_neutralPlayer;
};

extern PlayerList *ThePlayerList;

class Object
{
public:
	Player *getControllingPlayer() const;
	bool isNeutralControlled() const;
};

bool Object::isNeutralControlled() const
{
	return getControllingPlayer() == ThePlayerList->getNeutralPlayer();
}
