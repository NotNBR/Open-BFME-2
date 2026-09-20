// Open-BFME5 conversions.

class BfmeF1033;

class BfmeSub1033
{
public:
	int bfmeTry1033(BfmeF1033 *o);
	void bfmeFail1033(void);
};

struct BfmeG1033
{
	char m_bfmePad[0x2c];
	BfmeSub1033 m_bfmeSub;
};

class BfmeF1033
{
public:
	void bfmeGo1033F(BfmeG1033 *g);
};

void BfmeF1033::bfmeGo1033F(BfmeG1033 *g)
{
	if (g->m_bfmeSub.bfmeTry1033(this) == 0)
		g->m_bfmeSub.bfmeFail1033();
}
