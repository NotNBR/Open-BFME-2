// A chain asked all the way along (trimmed from a six-errand donor; the
// other five are declared-only here).

struct BfmeThingET
{
	unsigned char m_bfmeHead[0x1f0];	// 0x000
};

int bfmeFindET(BfmeThingET *thing);

class BfmeThingEU
{
public:
	void bfmeClearEU(void);
	void bfmeAlsoEU(void);
};

class BfmeThingEQ
{
public:
	virtual void bfmeSpare000EQ(void) = 0;
	virtual unsigned char bfmeDoEQ(void *what) = 0;

	unsigned char bfmeAskEQ(void *what);

	BfmeThingEQ *m_bfmeNext;		// 0x4
};

// ?bfmeAskEQ@BfmeThingEQ@@QAEEPAX@Z
unsigned char BfmeThingEQ::bfmeAskEQ(void *what)
{
	BfmeThingEQ *at = this;

	while (at != 0)
	{
		if (at->bfmeDoEQ(what) == 0)
			return 0;

		at = at->m_bfmeNext;
	}

	return 1;
}


class BfmeMadeER
{
public:
	unsigned char m_bfmeHead[0x4c];		// 0x00
	void *m_bfmeBack;			// 0x4c
};

class BfmeThingER
{
public:
	BfmeMadeER *bfmeGoER(void);
};

class BfmeThingES
{
public:
	void bfmeDropES(int which);
};
