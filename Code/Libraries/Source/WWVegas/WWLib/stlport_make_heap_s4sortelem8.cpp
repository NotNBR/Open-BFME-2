// cl: /DNDEBUG /MD /EHsc
// stlport

// _STL::__make_heap<S4SortElem8 *, S4Cmp00625BB0, S4SortElem8, int>,
// retail 0x00625F30, 103 bytes.  Ascending heap build verbatim (BFME1
// S4StlSortHelpers shape): parent starts at (len-2)/2 and each level calls
// the matched __adjust_heap at 0x00625C70 (no new pins).  Explicit worker
// instantiation; the public three-argument wrappers live at 0x00626090+.

#include <algorithm>

struct S4SortElem8
{
	int m_bfmeA;						// +0x00
	float m_bfmeKey;					// +0x04
};

struct S4Cmp00625BB0
{
	void *m_bfmeState;

	bool operator()(const S4SortElem8 &a, const S4SortElem8 &b) const
	{
		return a.m_bfmeKey < b.m_bfmeKey;
	}
};

namespace _STL
{

template void __make_heap<S4SortElem8 *, S4Cmp00625BB0, S4SortElem8, int>(
	S4SortElem8 *, S4SortElem8 *, S4Cmp00625BB0, S4SortElem8 *, int *);

}
