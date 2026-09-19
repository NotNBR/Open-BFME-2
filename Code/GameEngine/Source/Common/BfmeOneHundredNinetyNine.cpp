// An item woken and noted.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeOneHundredNinetyNine.cpp); trimmed to the
// single T1 body the sweep places.

class BfmeItemFU
{
public:
	virtual void bfmeDoFU(void) = 0;
};

class BfmeThingFU
{
public:
	void bfmeKeepFU(BfmeItemFU *item);

private:
	unsigned char m_bfmeHead[0x20];		// 0x00
	BfmeItemFU *m_bfmeItem;			// 0x20
};

void BfmeThingFU::bfmeKeepFU(BfmeItemFU *item)
{
	item->bfmeDoFU();

	m_bfmeItem = item;
}
