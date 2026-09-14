// cl: /DNDEBUG /MD
/* GameSpy Peer SDK -- peerOperations.c */

typedef void *PEER;

void piRoomsCleanup(PEER peer);
void piPlayersCleanup(PEER peer);
void piPingCleanup(PEER peer);
void piStopAutoMatch(PEER peer);

void piDisconnectTitle(PEER peer)
{
	piRoomsCleanup(peer);
	piPlayersCleanup(peer);
	piPingCleanup(peer);
	piStopAutoMatch(peer);
}
