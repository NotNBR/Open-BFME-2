// cl: /DNDEBUG /MD /EHsc
// stlport

// _STL::__adjust_heap<S4SortElem8 *, int, S4SortElem8, S4Cmp00625BB0>,
// retail 0x00625C70, 122 bytes.  Ascending sift-down verbatim (BFME1
// stlport_adjust_heap_s4sortelem8.cpp shape): the child pick is an inlined
// less-than on the float key at +4, and the tail calls __push_heap with the
// value by value.  The tail resolves to the landed 0x00625A70 body via a
// template-name alias pin (same folded sift-up bytes).  No other pins.

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

template <class RandomAccessIterator, class Distance, class Tp, class Compare>
void __push_heap(RandomAccessIterator first, Distance holeIndex,
	Distance topIndex, Tp val, Compare comp);

template <class RandomAccessIterator, class Distance, class Tp, class Compare>
void __adjust_heap(RandomAccessIterator first, Distance holeIndex,
	Distance len, Tp val, Compare comp)
{
	Distance topIndex = holeIndex;
	Distance secondChild = 2 * holeIndex + 2;
	while (secondChild < len)
	{
		if (comp(*(first + secondChild), *(first + (secondChild - 1))))
			secondChild--;
		*(first + holeIndex) = *(first + secondChild);
		holeIndex = secondChild;
		secondChild = 2 * (secondChild + 1);
	}
	if (secondChild == len)
	{
		*(first + holeIndex) = *(first + (secondChild - 1));
		holeIndex = secondChild - 1;
	}
	__push_heap(first, holeIndex, topIndex, val, comp);
}

template void __adjust_heap<S4SortElem8 *, int, S4SortElem8, S4Cmp00625BB0>(
	S4SortElem8 *, int, int, S4SortElem8, S4Cmp00625BB0);

}
