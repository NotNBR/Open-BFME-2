// cl: /DNDEBUG /MD -Ireference/shims/gamespy
/* GameSpy Peer SDK -- TableMap2 match callback for piFindPlayerByIP.
   Returns 0 to stop (found) and 1 to continue, per ArrayMap2's
   `if(!fn(...)) return pcurr` convention. */

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

// TableMap2 match callback for piFindPlayerByIP (retail 0x006A4310, 31B).
// A player without a resolved IP can never match, so either no-match case
// shares the single continue tail. Non-static so the standalone body emits
// without its TableMap2 caller; the wrapper commit makes it static like the
// other MapFn callbacks in this family.
int piFindPlayerByIPCallback(void *elem, void *clientData)
{
	piPlayer *player = (piPlayer *)elem;
	unsigned int *targetIP = (unsigned int *)clientData;
	if(!player->gotIPAndProfileID || player->IP != *targetIP)
		return 1;
	return 0;
}
