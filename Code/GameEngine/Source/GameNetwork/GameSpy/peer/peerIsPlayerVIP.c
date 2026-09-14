// cl: /DNDEBUG /MD
/* GameSpy Peer SDK -- peerPing.c */

typedef enum RoomType
{
	TitleRoom,
	GroupRoom,
	StagingRoom
} RoomType;

typedef struct piPlayer
{
	unsigned char pad_0000[0x40];
	int inRoom[3];
	int local;
	unsigned int ip;
	int profileID;
	int gotIPAndProfileID;
	int flags[3];
} piPlayer;

int piIsPlayerVIP(piPlayer *player, RoomType roomType)
{
	if (!player)
		return 0;
	if (!player->inRoom[roomType])
		return 0;
	return (player->flags[roomType] & 0x60) != 0;
}
