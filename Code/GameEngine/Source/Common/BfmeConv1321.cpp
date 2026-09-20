extern void *g_bfmeVftTQD[];

class BfmeSinkTQD
{
public:
	virtual void bfmeV0TQD(void) = 0;
	virtual void bfmeV1TQD(void) = 0;
	virtual void bfmeV2TQD(void) = 0;
	virtual void bfmeDropTQD(void *item, int flags) = 0;
};

BfmeSinkTQD *bfmeGetTQD(void);
void bfmeFreeTQD(void *place, int size);

class BfmeThingTQD
{
public:
	void *bfmeDelTQD(unsigned char flags);
	void *m_bfmeVft;
	char m_bfmePad[8];
	void *m_bfmeItem;
};

// ?bfmeDelTQD@BfmeThingTQD@@QAEPAXE@Z
void *BfmeThingTQD::bfmeDelTQD(unsigned char flags)
{
	m_bfmeVft = g_bfmeVftTQD;
	bfmeGetTQD()->bfmeDropTQD(m_bfmeItem, 0);
	if (flags & 1)
		bfmeFreeTQD(this, 0x14);
	return this;
}
