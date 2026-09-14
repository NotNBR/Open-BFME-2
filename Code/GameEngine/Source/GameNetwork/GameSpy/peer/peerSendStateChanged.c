// cl: /DNDEBUG /MD
/* GameSpy Peer SDK -- peerMain.c */

typedef void *PEER;

typedef struct piConnection
{
	unsigned char pad_0000[0x0AF0];
	void *queryReporting;
} piConnection;

void qr2_send_statechanged(void *queryReport);

void piSendStateChanged(PEER peer)
{
	piConnection *connection = (piConnection *)peer;

	if (connection->queryReporting)
		qr2_send_statechanged(connection->queryReporting);
}
