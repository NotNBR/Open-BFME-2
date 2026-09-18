// cl: /DNDEBUG /MD /EHsc
// stlport

// _STL::__unguarded_insertion_sort_aux<S4SortElem8 *, S4SortElem8,
// S4Cmp00625BB0>, retail 0x00625BB0, 84 bytes.  Ascending half of the
// stateful-comparator sort cluster around the AngleFX vector bodies: the
// comparator carries four bytes of state passed onward in ebp, and orders by
// the float key at +4 with an inlined x87 less-than (test ah,5 + jp), the
// same spelling the landed S4SortElem8LessCmp push_heap uses.  The linear
// insert is inline so the whole sort step is one loop with no calls.

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
	S4Cmp00625BB0>(S4SortElem8 *, S4SortElem8 *, S4SortElem8 *,
	S4Cmp00625BB0);

}
