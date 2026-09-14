// cl: /DNDEBUG /MD
/* GameSpy Peer SDK -- peerMain.c */

typedef void *PEER;

typedef struct piConnection
{
	unsigned char pad_0000[0x1798];
	void *operationList;
} piConnection;

void ArrayFree(void *array);

void piOperationsCleanup(PEER peer)
{
	piConnection *connection = (piConnection *)peer;

	if (connection->operationList)
		ArrayFree(connection->operationList);
	connection->operationList = 0;
}
