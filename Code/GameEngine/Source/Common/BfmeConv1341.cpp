// Open-BFME5 conversions (trimmed to the placed URC ctor; the other two are
// declared-only here).

class BfmeThingURB
{
public:
	int bfmeGoURB(void);
};

extern char g_bfmeNameURC[];

class BfmeSrcURC
{
public:
	char bfmeFillURC(void *a, char *out, void *n);
};

class BfmeThingURC
{
public:
	BfmeThingURC(BfmeSrcURC *p);
	BfmeSrcURC *m_bfmeOwner;
	char m_bfmeText[4];
};

// ??0BfmeThingURC@@QAE@PAVBfmeSrcURC@@@Z
BfmeThingURC::BfmeThingURC(BfmeSrcURC *p)
{
	m_bfmeOwner = p;
	p->bfmeFillURC(g_bfmeNameURC, m_bfmeText, (void *)0x40);
}

class BfmeThingURD
{
public:
	unsigned bfmeGoURD(void);
};
