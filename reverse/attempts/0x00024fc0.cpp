// ?bfmeDoPW@@YAXPAD000@Z
// partial score=0.72 date=2026-09-13
// cl: /Od
// stlport

#include <string>

int bfmeMakeOX(void *one);

int bfmeDoPW(char *first, char *last, char *otherFirst, char *otherLast);

struct BfmeThingPW
{
	void bfmeGoPW(char *at);

	char *m_bfmeAt;
	char *m_bfmeEnd;
};

void BfmeThingPW::bfmeGoPW(char *at)
{
	unsigned char spare[0x10];

	bfmeDoPW(m_bfmeAt, m_bfmeEnd, at, at + bfmeMakeOX(at));
}

int bfmeDoPW(char *first, char *last, char *otherFirst, char *otherLast)
{
	int count2;
	int count1;
	int cmp;
	int *minCount;
	int result;

	count1 = last - first;
	count2 = otherLast - otherFirst;
	minCount = count2 < count1 ? &count2 : &count1;
	cmp = _STL::char_traits<char>::compare(first, otherFirst, *minCount);

	if (cmp != 0)
		result = cmp;
	else
		result = count1 < count2 ? -1 : count1 > count2;
	return result;
}
