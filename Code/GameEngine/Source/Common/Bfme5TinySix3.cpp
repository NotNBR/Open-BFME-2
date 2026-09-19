// Two two-part level tests (trimmed from a five-body donor; the other three
// are declared-only here).

class BfmeHolderBU
{
public:
	char m_bfmeHead[0x126C];				// +0x0000
	int m_bfmeField;					// +0x126C
};

extern BfmeHolderBU *g_bfmeHolderBU;				// retail 0x013377D8

int __cdecl bfmeIsSet(void);

class Gen_0079F3C0
{
public:
	float bfmeValue(void) const;
};

class Gen_006E7B60
{
public:
	int bfmeIsReady(void) const;
};

class Gen_007F57E0
{
public:
	int bfmeIsThree(void) const;
	int bfmeIsFive(void) const;

private:
	int m_bfmeHead[12];					// +0x00
	int m_bfmeLevel;					// +0x30
	unsigned char m_bfmeGap;				// +0x34
	unsigned char m_bfmeReady;				// +0x35
};

// ?bfmeIsThree@Gen_007F57E0@@QBEHXZ
int Gen_007F57E0::bfmeIsThree(void) const
{
	if (m_bfmeReady && m_bfmeLevel >= 3)
		return 1;

	return 0;
}

// ?bfmeIsFive@Gen_007F57E0@@QBEHXZ
int Gen_007F57E0::bfmeIsFive(void) const
{
	if (m_bfmeReady && m_bfmeLevel >= 5)
		return 1;

	return 0;
}
