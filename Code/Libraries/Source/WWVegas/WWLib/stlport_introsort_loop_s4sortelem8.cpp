// cl: /DNDEBUG /MD /EHsc
// stlport

// _STL::__introsort_loop<S4SortElem8 *, S4SortElem8, int, S4Cmp00625BB0>,
// retail 0x00626780, 224 bytes.  Ascending quicksort core verbatim (BFME1
// ScoreRowIntrosort.cpp shape, vendored header): inline median-of-three on
// the float key, the matched __unguarded_partition at 0x00625DB0, the
// matched __partial_sort at 0x00626530 on depth exhaustion, direct
// self-recursion.  All callees are matched rows (no new pins).

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

template void __introsort_loop<S4SortElem8 *, S4SortElem8, int,
	S4Cmp00625BB0>(S4SortElem8 *, S4SortElem8 *, S4SortElem8 *, int,
	S4Cmp00625BB0);

}
