class BfmeSub932C
{
public:
	unsigned char bfmeQuery932C();
};

class BfmeThing932C
{
public:
	int bfmeGo932C();
	char m_bfmePad[0x24];
	BfmeSub932C *m_bfmeSub;
};

int BfmeThing932C::bfmeGo932C()
{
	BfmeSub932C *s = m_bfmeSub;
	if (s)
		return s->bfmeQuery932C();
	return 0;
}

class BfmeThing932E
{
public:
	void bfmeGo932E();
	int bfmeTest932E();
	void bfmeTail932E();
};

void BfmeThing932E::bfmeGo932E()
{
	if (!bfmeTest932E())
		bfmeTail932E();
}
