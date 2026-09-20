extern void *g_bfmeVftTXA[];

void __stdcall bfmeReleaseATXA(void *place);
void __stdcall bfmeReleaseBTXA(void *place);
void bfmeFreeArrayTXA(void *place);
void bfmeFreeTXA(void *place);

class BfmeThingTXA
{
public:
	void *bfmeDelTXA(unsigned char flags);
	void bfmeDtorTXA(void);
	void *m_bfmeVft;
	char m_bfmePad[8];
	void *m_bfmeBuf;
	char m_bfmePad2[8];
	void *m_bfmeB;
	void *m_bfmeA;
};

// ?bfmeDelTXA@BfmeThingTXA@@QAEPAXE@Z
void *BfmeThingTXA::bfmeDelTXA(unsigned char flags)
{
	m_bfmeVft = g_bfmeVftTXA;
	bfmeDtorTXA();
	if (m_bfmeA)
		bfmeReleaseATXA(m_bfmeA);
	if (m_bfmeB)
		bfmeReleaseBTXA(m_bfmeB);
	if (m_bfmeBuf)
		bfmeFreeArrayTXA(m_bfmeBuf);
	if (flags & 1)
		bfmeFreeTXA(this);
	return this;
}
