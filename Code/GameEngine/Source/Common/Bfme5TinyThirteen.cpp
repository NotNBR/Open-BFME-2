// Four more tiny ones (trimmed to the placed free-test body; the other three
// are declared-only here).

class BfmeSlotCD
{
public:
	char m_bfmeHead[6];					// +0x00
	short m_bfmeTag;					// +0x06
	char m_bfmeRest[8];					// +0x08
};

class Gen_000EE620
{
public:
	bool bfmeIsFree(int index) const;

private:
	int m_bfmeHead[3];					// +0x00
	BfmeSlotCD *m_bfmeSlots;				// +0x0C
};

// ?bfmeIsFree@Gen_000EE620@@QBE_NH@Z
bool Gen_000EE620::bfmeIsFree(int index) const
{
	BfmeSlotCD *slots = m_bfmeSlots;

	return slots[index].m_bfmeTag == 0;
}

class Gen_000FB880
{
public:
	int bfmeMatches(unsigned char mask) const;
};

class Gen_0014FD90
{
public:
	void bfmeGetPair(int *out) const;
};

class BfmeSourceCD;
class Gen_0016A350
{
public:
	void bfmeTake(BfmeSourceCD *source);
};
