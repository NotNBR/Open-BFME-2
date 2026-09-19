// Open-BFME5 conversions - BfmeThing912C list walk.
// Near-miss donor from Open-BFME-1 BfmeConv912.cpp (bfmeGo912C @0x009F4F80):
// retail member m_bfmeHead is at +0x114 (not +0xE4).

struct BfmeNode912C
{
	char m_bfmePad[0xc];
	BfmeNode912C *m_bfmeNext;
};

class BfmeThing912C
{
public:
	void bfmeGo912C();
	void bfmeDo912C(BfmeNode912C *n);
	char m_bfmePad[0x114];
	BfmeNode912C *m_bfmeHead;
};

void BfmeThing912C::bfmeGo912C()
{
	BfmeNode912C *n = m_bfmeHead;
	while (n) {
		bfmeDo912C(n);
		n = n->m_bfmeNext;
	}
}
