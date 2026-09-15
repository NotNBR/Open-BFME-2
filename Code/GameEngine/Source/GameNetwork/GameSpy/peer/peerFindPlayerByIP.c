// cl: /DNDEBUG /MD -Ireference/shims/gamespy
/* GameSpy Peer SDK -- piFindPlayerByIP and its TableMap2 match callback.
   Finds a player by IP address via TableMap2 over the connection's player
   table. The callback returns 0 to stop (found) and 1 to continue, per
   ArrayMap2's `if(!fn(...)) return pcurr` convention. */

typedef void *PEER;

typedef struct piPlayer
{
	char nick[0x40];
	int inRoom[3];
	int local;
	unsigned int IP; ///< retail +0x50
	int profileID;
	int gotIPAndProfileID; ///< retail +0x58
	int flags[3];
	unsigned int lastPingSend;
	unsigned int lastPingRecv;
	unsigned int lastXping;
	int waitingForPing;
	int pingsReturned;
	int pingsLostConsecutive;
	int pingAverage;
	int pingHistory[4];
	int pingHistoryNum;
	int numPings;
	int xpingSent;
	int inPingRoom;
	int inXpingRoom;
	int mustPing;
	int pingOnce;
} piPlayer;

typedef struct piConnection
{
	unsigned char pad0[0x80];
	char rooms[3][0x101];
	void *enteringRoom[3];
	void *inRoom[3];
	unsigned char pad39C[0xAB0 - 0x39C];
	int stayInTitleRoom;
	void *players; ///< retail +0xAB4
	int numPlayers[3];
	int padAC4;
	int doPings;
	int lastPingTimeMod;
	int pingRoom[3];
	int xpingRoom[3];
	void *xpings;
	int lastXpingSend;
	unsigned char padAF0[0xB44 - 0xAF0];
	int playing;
	unsigned char padB48[0x1828 - 0xB48];
	int away;
} piConnection;

void *TableMap2(void *table, int (*mapFn)(void *, void *), void *clientData);

// TableMap2 match callback for piFindPlayerByIP (retail 0x006A4310, 31B).
// A player without a resolved IP can never match, so either no-match case
// shares the single continue tail.
static int piFindPlayerByIPCallback(void *elem, void *clientData)
{
	piPlayer *player = (piPlayer *)elem;
	unsigned int *targetIP = (unsigned int *)clientData;
	if(!player->gotIPAndProfileID || player->IP != *targetIP)
		return 1;
	return 0;
}

// piFindPlayerByIP (retail 0x006A4330, 30B). Finds a player by IP via
// TableMap2 over the connection's player table.
piPlayer *piFindPlayerByIP(PEER peer, unsigned int IP)
{
	piConnection *connection = (piConnection *)peer;
	return (piPlayer *)TableMap2(connection->players, piFindPlayerByIPCallback, &IP);
}
