// cl: /DNDEBUG /MD /EHsc

// Open-BFME: GameSpyInfo::isDisconnectedAfterGameStart, retail 0x00386104,
// 19 bytes. BFME1 donor is
// Code/GameEngine/Source/GameNetwork/GameSpy/PeerDefs.cpp
// (b1 0x006371D0); the concrete implementation reports whether the local
// peer dropped after the game started, handing the disconnect reason back
// through the out-pointer when the caller provides one.

typedef int Int;
typedef bool Bool;

class GameSpyInfo
{
public:
	virtual Bool isDisconnectedAfterGameStart(Int *reason) const;

private:
	unsigned char m_unmodelled0004;		// +0x04
	Bool m_isDisconAfterGameStart;		// +0x05
	unsigned char m_unmodelled0006[2];	// +0x06..+0x07
	Int m_disconReason;				// +0x08
};

Bool GameSpyInfo::isDisconnectedAfterGameStart(Int *reason) const
{
	if (reason != 0)
		*reason = m_disconReason;
	return m_isDisconAfterGameStart;
}
