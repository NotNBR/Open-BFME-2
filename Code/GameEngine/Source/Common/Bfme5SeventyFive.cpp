// A search over eight slots (trimmed from a four-body donor; the other three
// are declared-only here).

class Gen_00752E80
{
public:
	int bfmeFirst(void) const;
};

class Gen_00752EC0
{
public:
	int bfmeSecond(void) const;
};

class Gen_00758630
{
public:
	void bfmeReset(bool flag);
};

class BfmeSlotFB
{
public:
	void *m_bfmeKey;					// +0x00
	int m_bfmeTail[8];					// +0x04
};

class Gen_00800880
{
public:
	BfmeSlotFB *bfmeFind(void *key);

private:
	char m_bfmeHead[0xD4];					// +0x0D4
	BfmeSlotFB m_bfmeSlots[8];				// +0x0D4
};

// ?bfmeFind@Gen_00800880@@QAEPAVBfmeSlotFB@@PAX@Z
BfmeSlotFB *Gen_00800880::bfmeFind(void *key)
{
	for (int index = 0; index < 8; ++index)
	{
		if (m_bfmeSlots[index].m_bfmeKey == key)
			return &m_bfmeSlots[index];
	}

	return 0;
}
