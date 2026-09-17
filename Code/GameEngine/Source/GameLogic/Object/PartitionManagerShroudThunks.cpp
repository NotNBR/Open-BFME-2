// cl: /O2 /DNDEBUG /MD
//
// PartitionManager shroud thunks, retail 0x00739790 (8 bytes),
// 0x007397B0 (8 bytes) and 0x007397F0 (8 bytes). Dedicated TU: the caller
// (doBorderSwitch) lives in ScriptActions_doBorderSwitch.cpp, so the bodies
// live here (a TU holding a row must not define that row's callees).
//
// Each body forwards to the shroud manager at +0x10, tail-jumping to the
// pinned ShroudManager method (same semantics, adjusted this).

enum CellShroudStatus
{
	SHROUD_CLEAR = 0
};

struct Coord3D
{
	float x;
	float y;
	float z;
};

class ShroudManager
{
public:
	void revealMapForPlayerPermanently(int playerIndex);
	void undoRevealMapForPlayerPermanently(int playerIndex);
	CellShroudStatus getShroudStatusForPlayer(int playerIndex, const Coord3D *pos) const;
};

class PartitionManager
{
public:
	void revealMapForPlayerPermanently(int playerIndex);
	void undoRevealMapForPlayerPermanently(int playerIndex);
	CellShroudStatus getShroudStatusForPlayer(int playerIndex, const Coord3D *pos) const;

private:
	char m_pad[0x10];
	ShroudManager *m_shroudManager; // +0x10
};

// ?revealMapForPlayerPermanently@PartitionManager@@QAEXH@Z
void PartitionManager::revealMapForPlayerPermanently(int playerIndex)
{
	m_shroudManager->revealMapForPlayerPermanently(playerIndex);
}

// ?undoRevealMapForPlayerPermanently@PartitionManager@@QAEXH@Z
void PartitionManager::undoRevealMapForPlayerPermanently(int playerIndex)
{
	m_shroudManager->undoRevealMapForPlayerPermanently(playerIndex);
}

// ?getShroudStatusForPlayer@PartitionManager@@QBE?AW4CellShroudStatus@@HPBUCoord3D@@@Z
CellShroudStatus PartitionManager::getShroudStatusForPlayer(int playerIndex, const Coord3D *pos) const
{
	return m_shroudManager->getShroudStatusForPlayer(playerIndex, pos);
}
