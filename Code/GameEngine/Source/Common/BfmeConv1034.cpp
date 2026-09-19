class BfmeN1034
{
public:
	int bfmeVal1034(void);
};

class BfmeTab1034
{
public:
	BfmeN1034 *bfmeFind1034F(int k);
};

class BfmeF1034
{
public:
	int bfmeGo1034F(int k);

	char m_bfmePad[8];
	BfmeTab1034 *m_bfmeTab;
};

int BfmeF1034::bfmeGo1034F(int k)
{
	BfmeN1034 *n = m_bfmeTab->bfmeFind1034F(k);

	if (n != 0)
		return n->bfmeVal1034();

	return -1;
}
