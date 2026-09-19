// A search over a counted array (trimmed from a five-body donor; the other
// four are declared-only here).

class BfmeSlotDV
{
public:
	int m_bfmeHead[2];					// +0x00
	void *m_bfmeKey;					// +0x08
	int m_bfmeTail[4];					// +0x0C
};

class Gen_007F7110
{
public:
	BfmeSlotDV *bfmeFind(void *key) const;

private:
	int m_bfmeHead[14];					// +0x00
	BfmeSlotDV *m_bfmeSlots;				// +0x38
	int m_bfmeCount;					// +0x3C
};

// ?bfmeFind@Gen_007F7110@@QBEPAVBfmeSlotDV@@PAX@Z
BfmeSlotDV *Gen_007F7110::bfmeFind(void *key) const
{
	BfmeSlotDV *first = m_bfmeSlots;
	BfmeSlotDV *last = m_bfmeSlots + m_bfmeCount;

	while (first < last)
	{
		if (first->m_bfmeKey == key)
			return first;

		++first;
	}

	return 0;
}

class BfmeThingDV
{
public:
	int m_bfmeHead[16];					// +0x00
	void *m_bfmeSlots[7];					// +0x40
	unsigned int m_bfmeFlags[7];				// +0x5C
};

int __cdecl bfmeHasFlag(const BfmeThingDV *thing, int index);

class Gen_008A0690
{
public:
	int bfmeIndexOf(void *key) const;
};

class Gen_008D2B80
{
public:
	void bfmePop(void);
};

class BfmeHandleCX
{
public:
	void *m_bfmeThing;					// +0x00
};

class Gen_00929260
{
public:
	BfmeHandleCX bfmeGet(int index) const;
};
