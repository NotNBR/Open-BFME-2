// cl: /O1 /DNDEBUG /MD /EHsc

// ?getControllingPlayer@Team@@QBEPAVPlayer@@XZ, retail 0x0039D7CF (12 bytes).
// Team::getControllingPlayer is `return m_proto ? m_proto->m_owningPlayer :
// NULL`. Retail-measured BFME2 layout: Team::m_proto is at +0x30 here and the
// prototype owner holds m_owningPlayer at +0x08. Dedicated TU so the pin
// (Object::getControllingPlayer tail target) resolves to a row.

class Player;

struct TeamPrototypeOwner
{
	unsigned char m_pad00[ 0x08 ];
	Player *m_owningPlayer;
};

class Team
{
public:
	Player *getControllingPlayer() const;

private:
	unsigned char m_pad00[ 0x30 ];
	TeamPrototypeOwner *m_proto;
};

Player *Team::getControllingPlayer() const
{
	if( !m_proto )
		return 0;
	return m_proto->m_owningPlayer;
}
