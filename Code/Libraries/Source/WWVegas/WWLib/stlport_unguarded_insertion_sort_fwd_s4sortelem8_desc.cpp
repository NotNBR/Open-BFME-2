// cl: /DNDEBUG /MD /EHsc
// stlport

// _STL::__unguarded_insertion_sort<S4SortElem8 *, S4Cmp00625C10>,
// retail 0x00625E90, 26 bytes.  Descending unguarded sort entry: forwards to
// the matched __unguarded_insertion_sort_aux at 0x00625C10 with a NULL type
// tag (_VALUE_TYPE spelling) plus the stateful comparator (no new pins).
// Twin of the ascending forwarder at 0x00625E10.

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
void __unguarded_insertion_sort_aux(RandomAccessIter first,
	RandomAccessIter last, Tp *, Compare comp);

template <class RandomAccessIter, class Compare>
void __unguarded_insertion_sort(RandomAccessIter first,
	RandomAccessIter last, Compare comp)
{
	__unguarded_insertion_sort_aux(first, last, (S4SortElem8 *)0, comp);
}

template void __unguarded_insertion_sort<S4SortElem8 *, S4Cmp00625C10>(
	S4SortElem8 *, S4SortElem8 *, S4Cmp00625C10);

}
