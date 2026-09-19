// Open-BFME5 conversions.
//
// Trimmed port of Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv1379.cpp
// (near-miss donor). Only the AVIW/EVIW pair served for BFME2 is carried
// here; the donor's B/C/D siblings are unserved so they stay out (the gate
// refuses unrowed definitions in a staged TU).
//
// WHAT THE BODY IS. A stdcall Fesl transaction-message filler: it snapshots
// the per-kind global, stamps the message kind dword, then adds its string
// fields through the shared BfmeMsgVIW setters. Retail calls bfmeRunVIW at
// 0x00655B50, bfmeSetVIW at 0x00655AA0 and bfmeSet2VIW at 0x00655F00 (all
// pre-pinned); the string pushes and the global load are DIR32 slots the
// patcher fills, so the donor compiles unchanged.

class BfmeMsgVIW
{
public:
	void bfmeRunVIW();
	void bfmeSetVIW(const char *k, void *v);
	void bfmeSet2VIW(const char *k, void *a, void *b);
	char m_bfmePad[0x1c];
	int m_bfme1c;
};

extern void *g_bfmeAVIW;
extern void *g_bfmeEVIW;

void __stdcall bfmeGoAVIW(BfmeMsgVIW *m, void *a, void *b)
{
	void *g = g_bfmeAVIW;
	m->bfmeRunVIW();
	m->m_bfme1c = 0x626c6f62;
	m->bfmeSetVIW("TXN", g);
	m->bfmeSet2VIW("blobId", a, b);
}

// Retail stamps 0x61636374 and sets password/newPassword through the same
// bfmeSetVIW at 0x00655AA0 the TXN call uses: BFME2 routes all three through
// the one pinned setter, so the donor's distinct bfmeSet4VIW name (a second
// address in BFME1, pinned at 0x00655A10 for other bodies) is not referenced
// here. String contents are DIR32 slots; the retail words are kept for
// readability.
void __stdcall bfmeGoEVIW(BfmeMsgVIW *m, void *a, void *b)
{
	void *g = g_bfmeEVIW;
	m->bfmeRunVIW();
	m->m_bfme1c = 0x61636374;
	m->bfmeSetVIW("TXN", g);
	m->bfmeSetVIW("password", a);
	m->bfmeSetVIW("newPassword", b);
}
