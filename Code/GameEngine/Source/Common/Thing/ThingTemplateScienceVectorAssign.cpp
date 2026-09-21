// cl: /O1
//
// vector assign, retail 0x0021C21B, 175 bytes, rowed as ?dup_0021c21b (the
// body is folded across 4-byte-POD vectors: 27 image-wide callers, so no
// single element type is claimed; the callees used here are the ScienceType
// spellings).
//
// Standard assign shape: reallocate when the source outgrows capacity (with
// a null-checked _free of the old start), shift the tail down with
// __copy_ptrs when it fits, otherwise copy the overlapped prefix and fill
// the remainder with __uninitialized_copy. All three paths converge on a
// shared finish update. Callee map: _M_allocate_and_copy via the new pin at
// 0x0031B9EB, __copy_ptrs via the row at 0x0025BF40, __uninitialized_copy
// via the pin at 0x001DD10D, _free via the row at 0x00030830.

enum ScienceType
{
	SCIENCE_NONE = 0
};

namespace _STL
{

struct __false_type
{
	__false_type()
	{
	}
};

template <class Type>
class allocator
{
};

template <class Type, class Allocator>
class vector
{
public:
	typedef Type *pointer;
	typedef const Type *const_pointer;
	typedef unsigned int size_type;

	vector &operator=(const vector &x);

	pointer begin() { return m_start; }
	const_pointer begin() const { return m_start; }
	pointer end() { return m_finish; }
	const_pointer end() const { return m_finish; }
	size_type size() const { return size_type(m_finish - m_start); }
	size_type capacity() const { return size_type(m_endOfStorage - m_start); }

protected:
	template <class ForwardIter>
	pointer _M_allocate_and_copy(size_type n, ForwardIter first,
		ForwardIter last);

private:
	pointer m_start;
	pointer m_finish;
	pointer m_endOfStorage;
};

template <class InputIter, class OutputIter>
OutputIter __copy_ptrs(InputIter first, InputIter last, OutputIter result,
	const __false_type &tag);

template <class InputIter, class OutputIter>
OutputIter __uninitialized_copy(InputIter first, InputIter last,
	OutputIter result, const __false_type &tag);

}

extern "C" void _free(void *);

_STL::vector<ScienceType, _STL::allocator<ScienceType> > &
_STL::vector<ScienceType, _STL::allocator<ScienceType> >::operator=(
	const vector &x)
{
	if (&x != this)
	{
		size_type xsize = x.size();
		if (xsize > capacity())
		{
			pointer tmp = _M_allocate_and_copy(xsize, x.begin(), x.end());
			if (m_start != 0)
				_free(m_start);
			m_start = tmp;
			m_endOfStorage = tmp + xsize;
		}
		else if (size() >= xsize)
		{
			__copy_ptrs(x.begin(), x.end(), m_start, __false_type());
		}
		else
		{
			__copy_ptrs(x.begin(), x.begin() + size(), m_start,
				__false_type());
			__uninitialized_copy(x.begin() + size(), x.end(), m_finish,
				__false_type());
		}
		m_finish = m_start + xsize;
	}
	return *this;
}
