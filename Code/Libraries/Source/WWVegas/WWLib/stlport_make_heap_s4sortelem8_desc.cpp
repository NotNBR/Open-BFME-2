// cl: /DNDEBUG /MD /EHsc
// stlport

// _STL::__make_heap<S4SortElem8 *, S4Cmp00625C10, S4SortElem8, int>,
// retail 0x00625FA0, 103 bytes.  Descending twin: same parent schedule,
// each level calls the matched __adjust_heap at 0x00625CF0 (no new pins).

#include <algorithm>

struct S4SortElem8
{
	int m_bfmeA;						// +0x00
	float m_bfmeKey;					// +0x04
};

struct S4Cmp00625C10
{
	void *m_bfmeState;

	bool operator()(const S4SortElem8 &a, const S4SortElem8 &b) const
	{
		return a.m_bfmeKey > b.m_bfmeKey;
	}
};

namespace _STL
{

template void __make_heap<S4SortElem8 *, S4Cmp00625C10, S4SortElem8, int>(
	S4SortElem8 *, S4SortElem8 *, S4Cmp00625C10, S4SortElem8 *, int *);

}
