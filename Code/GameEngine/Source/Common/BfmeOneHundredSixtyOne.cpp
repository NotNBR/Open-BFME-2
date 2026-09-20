struct BfmeHolderZT
{
	BfmeHolderZT *m_bfmeFirst;		// 0x0
};

struct BfmeNodeZT
{
	unsigned char m_bfmeHead[0x2c];		// 0x00
	BfmeHolderZT *m_bfmeBefore;		// 0x2c
	BfmeNodeZT *m_bfmeAfter;		// 0x30
};

class BfmeListZT
{
public:
	void bfmeFreeZT(BfmeNodeZT *node);

private:
	unsigned char m_bfmeHead[0xadec];	// 0x0000
	BfmeNodeZT *m_bfmeSpare;		// 0xadec
	unsigned char m_bfmeGap[4];		// 0xadf0
	BfmeNodeZT *m_bfmeAt;			// 0xadf4
};

// ?bfmeFreeZT@BfmeListZT@@QAEXPAUBfmeNodeZT@@@Z
void BfmeListZT::bfmeFreeZT(BfmeNodeZT *node)
{
	if (m_bfmeAt == node)
		m_bfmeAt = m_bfmeAt->m_bfmeAfter;

	if (node->m_bfmeAfter != 0)
		node->m_bfmeAfter->m_bfmeBefore = node->m_bfmeBefore;

	node->m_bfmeBefore->m_bfmeFirst = (BfmeHolderZT *)node->m_bfmeAfter;
	node->m_bfmeBefore = 0;
	node->m_bfmeAfter = m_bfmeSpare;
	m_bfmeSpare = node;
}
