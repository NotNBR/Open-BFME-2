void bfmeFreeVMN(void *place);

struct BfmeNodeVMN
{
	char m_bfmePad00[0x30];
	BfmeNodeVMN *m_bfme30;
};

class BfmeTableVMN
{
public:
	void bfmeClearVMN(void);
	BfmeNodeVMN *m_bfme00[0x2b7b];
	BfmeNodeVMN *m_bfmeadec;
};

// ?bfmeClearVMN@BfmeTableVMN@@QAEXXZ
void BfmeTableVMN::bfmeClearVMN()
{
	unsigned i;
	BfmeNodeVMN *p;

	for (i = 0; i < 0x2b7b; ++i)
	{
		p = m_bfme00[i];
		while (p != 0)
		{
			BfmeNodeVMN *n = p->m_bfme30;

			bfmeFreeVMN(p);
			p = n;
		}
	}

	p = m_bfmeadec;
	while (p != 0)
	{
		BfmeNodeVMN *n = p->m_bfme30;

		bfmeFreeVMN(p);
		p = n;
	}
}
