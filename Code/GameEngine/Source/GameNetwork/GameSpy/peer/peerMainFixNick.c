// cl: /DNDEBUG /MD
// Upstream: GameSpy Peer SDK peerMain.c, 2007 release.
// BFME1 names the sanitize callee for the address it holds in their image
// (Rva00860620); it holds 0x006A1520 here, matched from chat/Rva006A1520FixNick.cpp.

void Rva006A1520FixNick(char *newNick, const char *oldNick);

void peerFixNickA(char *newNick, const char *oldNick)
{
	Rva006A1520FixNick(newNick, oldNick);
}
