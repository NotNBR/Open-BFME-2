// Two hooks let go of at once.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeOneHundredSixtyTwo.cpp); trimmed to the
// single T1 body the sweep places.

class BfmeThingZU;

struct BfmeReachZU
{
	BfmeThingZU *m_bfmeBack;		// 0x0
};

class BfmeThingZU
{
public:
	void bfmeUnhookZU(void);

	unsigned char m_bfmeHead[8];		// 0x00
	BfmeReachZU *m_bfmeFirstOn;		// 0x08
	BfmeThingZU *m_bfmeFirstBack;		// 0x0c
	unsigned char m_bfmeGap[8];		// 0x10
	BfmeReachZU *m_bfmeSecondOn;		// 0x18
	BfmeThingZU *m_bfmeSecondBack;		// 0x1c
};

void BfmeThingZU::bfmeUnhookZU(void)
{
	if (m_bfmeSecondOn != 0)
	{
		if (m_bfmeSecondBack != 0)
			m_bfmeSecondBack->m_bfmeSecondOn = m_bfmeSecondOn;

		m_bfmeSecondOn->m_bfmeBack = m_bfmeSecondBack;
		m_bfmeSecondOn = 0;
	}

	if (m_bfmeFirstBack != 0)
		m_bfmeFirstBack->m_bfmeFirstOn = m_bfmeFirstOn;

	m_bfmeFirstOn->m_bfmeBack = m_bfmeFirstBack;
	m_bfmeFirstOn = 0;
}
