// cl: /DNDEBUG /MD /EHsc

// Open-BFME5: peerStopGame, retail 0x00857E50, 65 bytes. The body carried only
// a machine byte-dump row; the symbols.csv pin names it from
// PeerThreadClass::stopHostingAlready, which calls it on the peer.
//
// The word at +0xB44 is cleared, one cdecl helper runs on the peer, and then
// the pointer at +0xAF0 decides whether anything else happens at all. When it
// is set, the field at +0x398 picks between two more helpers: the one at
// 0x008667A0 when it is set, and _piStopReporting when it is not. That second
// address is also the guarded release the ledger carries as Rva00866770, one of
// the seven bodies in R3GuardedReleaseAndClear.cpp -- the one that frees the
// very field at +0xAF0 this branch was taken on.
//
// The peer is pushed once, ahead of the branch, because both arms take it.

// _peerStopGame @ 0x00699410 (65B). Ported from Open-BFME-1
// Code/GameEngine/Source/GameNetwork/GameSpy/peerStopGame.cpp
// (b1 0x00857E50) with BFME2 retail callees: _piSetLocalFlags @ 0x006A4AD0,
// _piSendStateChanged @ 0x006A7610, _piStopReporting @ 0x006A75E0.
// The BFME1 donor calls Rva00863C00/Rva008667A0 aliases at the same addresses;
// BFME2 already matches the _pi* bodies there, so this copy calls the real
// matched names and needs no new pins.

struct PeerGameConnection
{
public:
	unsigned char m_padBeforeSelector[0x398];
	void *m_branchSelector; // +0x398: selects state-changed vs stop-reporting
	unsigned char m_padBeforeQuery[0xAF0 - 0x39C];
	void *m_queryReporting; // +0xAF0: when set, run one of the two helpers
	unsigned char m_padBeforeHostState[0xB44 - 0xAF4];
	int m_hostState; // +0xB44: cleared to zero on stop
};

extern "C" void piSetLocalFlags(PeerGameConnection *peer); // _piSetLocalFlags @ 0x006A4AD0
extern "C" void piSendStateChanged(PeerGameConnection *peer); // _piSendStateChanged @ 0x006A7610
extern "C" void piStopReporting(PeerGameConnection *peer); // _piStopReporting @ 0x006A75E0

// _peerStopGame
extern "C" void peerStopGame(PeerGameConnection *peer)
{
	peer->m_hostState = 0;

	piSetLocalFlags(peer);

	if (peer->m_queryReporting)
	{
		if (peer->m_branchSelector)
			piSendStateChanged(peer);
		else
			piStopReporting(peer);
	}
}
