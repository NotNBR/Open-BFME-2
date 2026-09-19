// A counted-handle getter and a doubly-linked unlink.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/Bfme5ThirtyFour.cpp); trimmed to the two T1
// bodies the sweep places.

class BfmeRefDB
{
public:
	int m_bfmeCount;					// +0x00
};

class BfmeHolderDB
{
public:
	BfmeHolderDB(void)
	{
		m_bfmeRef = 0;
	}

	BfmeHolderDB(const BfmeHolderDB &other)
	{
		BfmeRefDB *ref = other.m_bfmeRef;

		m_bfmeRef = ref;

		if (ref)
			++ref->m_bfmeCount;
	}

	~BfmeHolderDB(void)
	{
		if (m_bfmeRef)
			--m_bfmeRef->m_bfmeCount;
	}

	BfmeRefDB *m_bfmeRef;					// +0x00
};

class Gen_00895650
{
public:
	BfmeHolderDB bfmeGet(void) const;

private:
	int m_bfmeHead;						// +0x00
	BfmeHolderDB m_bfmeHolder;				// +0x04
};

// ?bfmeGet@Gen_00895650@@QBE?AVBfmeHolderDB@@XZ
BfmeHolderDB Gen_00895650::bfmeGet(void) const
{
	return m_bfmeHolder;
}

class Gen_008F7AC0
{
public:
	void bfmeUnlink(void);

private:
	int m_bfmeHead[5];					// +0x00
	Gen_008F7AC0 **m_bfmePrev;				// +0x14
	Gen_008F7AC0 *m_bfmeNext;				// +0x18
};

// ?bfmeUnlink@Gen_008F7AC0@@QAEXXZ
void Gen_008F7AC0::bfmeUnlink(void)
{
	*m_bfmePrev = m_bfmeNext;

	Gen_008F7AC0 *next = m_bfmeNext;

	if (next != 0)
		next->m_bfmePrev = m_bfmePrev;

	m_bfmePrev = 0;
}
