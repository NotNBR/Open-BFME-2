// cl: /O1 /DNDEBUG /MD
//
// ?hasRadar@Player@@QBE_NXZ, retail 0x002AA08E, 35 bytes. Dedicated TU.
//
// BFME1 Player::hasRadar logic verbatim
// (reference/open-bfme-1/Code/GameEngine/Source/Common/RTS/Player.cpp:4034):
// disabled plus zero disable-proof count denies radar, otherwise the radar
// count decides. BFME2 keeps the radar fields at +0xA0/+0xA4/+0xA8.

typedef bool Bool;

class Player
{
	char m_pad[0xA0];
	int m_radarCount;
	int m_disableProofRadarCount;
	unsigned char m_radarDisabled;

public:
	Bool hasRadar() const;
};

// ?hasRadar@Player@@QBE_NXZ
Bool Player::hasRadar() const
{
	if (m_radarDisabled && (m_disableProofRadarCount == 0))
		return false;

	return m_radarCount > 0;
}
