// Three more tiny ones (trimmed to the placed value body; the other two are
// declared-only here).

float __cdecl bfmeScale(float value);

class BfmeLinkCF
{
public:
	int m_bfmeTag;						// +0x00
	int m_bfmeNext;						// +0x04
};

class Gen_0028EF10
{
public:
	int bfmeValue(void) const;

private:
	char m_bfmeHead[0x9C];					// +0x00
	BfmeLinkCF *m_bfmeLink;					// +0x9C
};

// ?bfmeValue@Gen_0028EF10@@QBEHXZ
int Gen_0028EF10::bfmeValue(void) const
{
	BfmeLinkCF *link = m_bfmeLink;

	if (link)
		return *(int *)(link->m_bfmeNext + 4);

	return -1;
}

void __cdecl bfmeCopySecond(void);
