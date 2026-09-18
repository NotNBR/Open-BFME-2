// BFME1 byte-identical donor: reference/open-bfme-1/Code/GameEngine/Source/Common/BfmeConv1378.cpp
// Trimmed to the bodies that reproduce game.dat bytes. bfmeGoVIT has no matching
// body here, and bfmeGoVIU's bytes are ICF-folded in lotrbfme.exe across five
// candidate names (sweep T3), so claiming one would be a guess; both stay out
// and every defined function has a ledger row.

class BfmeMsgVIT
{
public:
	void bfmeRunVIT();
	void bfmeSetVIT(const char *k, void *v);
	char m_bfmePad[0x1c];
	int m_bfme1c;
};

extern void *g_bfmeVIV;

void __stdcall bfmeGoVIV(BfmeMsgVIT *m, char *code, char *game, char *platform, char *name, char *password, char *email)
{
	void *g = g_bfmeVIV;
	m->bfmeRunVIT();
	m->m_bfme1c = 0x61636374;
	m->bfmeSetVIT("TXN", g);
	m->bfmeSetVIT("code", code);
	m->bfmeSetVIT("game", game);
	m->bfmeSetVIT("platform", platform);
	if (name && *name)
		m->bfmeSetVIT("name", name);
	if (password && *password)
		m->bfmeSetVIT("password", password);
	if (email && *email)
		m->bfmeSetVIT("encryptedInfo", email);
}
