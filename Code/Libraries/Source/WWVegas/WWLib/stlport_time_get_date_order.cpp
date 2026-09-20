// cl: /O2 /Ob0 /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// STLport 4.5.3 date-order virtual. Both BFME2 time_get vtables use the
// folded three-byte no_order implementation in slot 1. The vtable identities
// are independently anchored by their matched scalar/default destructors and
// locale-time constructors.

#include <locale>

typedef _STL::istreambuf_iterator<char, _STL::char_traits<char> >
	BfmeNarrowDateOrderIterator;
typedef _STL::istreambuf_iterator<wchar_t, _STL::char_traits<wchar_t> >
	BfmeWideDateOrderIterator;

template class _STL::time_get<char, BfmeNarrowDateOrderIterator>;
template class _STL::time_get<wchar_t, BfmeWideDateOrderIterator>;
