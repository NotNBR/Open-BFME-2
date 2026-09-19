// ?disconnectLocalPlayer@ConnectionManager@@QAEXXZ, retail 0x004D15F7 (31B).
// Ported from Open-BFME-1 Code/GameEngine/Source/GameNetwork/Network_update.cpp
// (BFME1 0x00665E90). Trimmed to the placed local-player disconnect loop; the
// rest of the network update is declared-only here. Callee disconnectPlayer
// resolves via the new ledger pin at 0x004D13F8 (same-class member, BFME1
// same-name target, worktree DEF in ConnectionManager.cpp).

enum PlayerLeaveCode
{
	PLAYER_LEAVE_CODE_CLIENT
};

class ConnectionManager
{
public:
	PlayerLeaveCode disconnectPlayer(int slot);
	void disconnectLocalPlayer(void);

private:
	unsigned char m_unmodelled_00000[0x12028];
	int m_localSlot;
};

// ?disconnectLocalPlayer@ConnectionManager@@QAEXXZ
void ConnectionManager::disconnectLocalPlayer(void)
{
	for (int slot = 0; slot < 8; ++slot)
	{
		if (slot != m_localSlot)
			disconnectPlayer(slot);
	}
}
