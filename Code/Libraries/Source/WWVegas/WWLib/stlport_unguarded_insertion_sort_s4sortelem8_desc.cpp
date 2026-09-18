// cl: /DNDEBUG /MD /EHsc
// stlport

// _STL::__unguarded_insertion_sort_aux<S4SortElem8 *, S4SortElem8,
// S4Cmp00625C10>, retail 0x00625C10, 84 bytes.  Descending twin of the
// 0x00625BB0 body: same stateful-comparator cluster, greater-than on the
// float key at +4 (test ah,0x41 + jne), inline linear insert, one loop.

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

template <class RandomAccessIter, class Tp, class Compare>
inline void __unguarded_linear_insert(RandomAccessIter last, Tp val,
	Compare comp)
{
	RandomAccessIter next = last;
	--next;
	while (comp(val, *next))
	{
		*last = *next;
		last = next;
		--next;
	}
	*last = val;
}

template <class RandomAccessIter, class Tp, class Compare>
void __unguarded_insertion_sort_aux(RandomAccessIter first,
	RandomAccessIter last, Tp *, Compare comp)
{
	for (RandomAccessIter i = first; i != last; ++i)
		__unguarded_linear_insert(i, *i, comp);
}

template void __unguarded_insertion_sort_aux<S4SortElem8 *, S4SortElem8,
	S4Cmp00625C10>(S4SortElem8 *, S4SortElem8 *, S4SortElem8 *,
	S4Cmp00625C10);

}
