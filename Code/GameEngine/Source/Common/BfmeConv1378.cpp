// BFME1 byte-identical donor: reference/open-bfme-1/Code/GameEngine/Source/Common/BfmeConv1378.cpp
// Trimmed to the bodies that reproduce game.dat bytes. bfmeGoVIT has no matching
// body here. bfmeGoVIU's bytes ARE claimed: the five lotrbfme.exe fold-twins
// collapse to one pick by call-arity -- retail 0x65F250 ends `ret 0x10`
// (4 args: msg + 3 void*), which fits only ?bfmeGoVIU@@YGXPAVBfmeMsgVIT@@PAX11@Z;
// the bfmeSetupPair twins take (record*, int) and Rva007F2B70 takes 7 args.

class BfmeMsgVIT
{
public:
	void bfmeRunVIT();
	void bfmeSetVIT(const char *k, void *v);
	char m_bfmePad[0x1c];
	int m_bfme1c;
};

extern void *g_bfmeVIV;
extern void *g_bfmeVIU;

void __stdcall bfmeGoVIU(BfmeMsgVIT *m, void *sessionId, void *key, void *value)
{
	void *g = g_bfmeVIU;
	m->bfmeRunVIT();
	m->m_bfme1c = 0x72616e6b;
	m->bfmeSetVIT("TXN", g);
	m->bfmeSetVIT("sessionId", sessionId);
	m->bfmeSetVIT("key", key);
	m->bfmeSetVIT("value", value);
}

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
