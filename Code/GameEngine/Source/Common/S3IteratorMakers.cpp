// Two iterator makers (trimmed from a four-maker donor; the other two are
// declared-only here).
//
// Each returns an eight-byte record through a hidden pointer. The record is
// built by a constructor in the return expression so the compiler writes
// through the return slot directly.

struct BfmeIterator
{
	BfmeIterator(void *node, void *owner)
	{
		m_bfmeNode = node;
		m_bfmeOwner = owner;
	}

	void *m_bfmeNode;					// +0x00
	void *m_bfmeOwner;					// +0x04
};


class Gen_000CBB80
{
public:
	BfmeIterator bfmeMake(void);
};

extern char TheBfmeOwner_00161290[];

class Gen_00161290
{
public:
	BfmeIterator bfmeMake(void);

private:
	char m_bfmeHead[0x4];
	void *m_bfmeNode;					// +0x4
};

extern char TheBfmeOwner_001612B0[];

class Gen_001612B0
{
public:
	BfmeIterator bfmeMake(void);

private:
	char m_bfmeHead[0x8];
	void *m_bfmeNode;					// +0x8
};

class Gen_004C14F0
{
public:
	BfmeIterator bfmeMake(void);
};

// ?bfmeMake@Gen_00161290@@QAE?AUBfmeIterator@@XZ
BfmeIterator Gen_00161290::bfmeMake(void)
{
	return BfmeIterator(m_bfmeNode, TheBfmeOwner_00161290);
}

// ?bfmeMake@Gen_001612B0@@QAE?AUBfmeIterator@@XZ
BfmeIterator Gen_001612B0::bfmeMake(void)
{
	return BfmeIterator(m_bfmeNode, TheBfmeOwner_001612B0);
}
