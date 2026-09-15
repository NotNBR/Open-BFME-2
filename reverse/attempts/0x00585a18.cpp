// ??$copy_backward@U?$_Deque_iterator@UBfmeE12@@U?$_Nonconst_traits@UBfmeE12@@@_STL@@@_STL@@U12@@_STL@@YA?AU?$_Deque_iterator@UBfmeE12@@U?$_Nonconst_traits@UBfmeE12@@@_STL@@@0@U10@00@Z
// partial score=0.95 date=2026-09-15
// cl: /O1 /G7 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
//
// _M_new_elements_at_back/_front for deque<BfmeE12>, retail 0x00585A9A (64B)
// and 0x00585A57 (67B). Same placeholder-element convention as the sibling
// stlport_deque_e12_o1.cpp (BfmeE12 names only the element SIZE). Split into
// its own TU without /EHsc: retail carries no exception-handling frame for
// either function (the _STLP_TRY/catch(...) rollback in vendor/stlport/stl/
// _deque.c compiles to nothing once _STLP_USE_EXCEPTIONS is off), while the
// sibling file needs /EHsc for other members it hosts.
#include <deque>
struct BfmeE12 { float x, y, z; };
template class _STL::deque<BfmeE12, _STL::allocator<BfmeE12 > >;

// ?$copy_backward for deque<BfmeE12> non-const iterators, retail 0x00585A18
// (63B).  Explicit specialization forwards to the matched
// __copy_backward_aux; the element type names only the size.  Spelled as
// a specialization (not an instantiation) so the tag dispatches without
// materializing _BothPtrType::_Ret(), whose empty return retail elides.
namespace _STL
{
template <>
_Deque_iterator<BfmeE12, _Nonconst_traits<BfmeE12> > copy_backward<
	_Deque_iterator<BfmeE12, _Nonconst_traits<BfmeE12> >,
	_Deque_iterator<BfmeE12, _Nonconst_traits<BfmeE12> > >(
	_Deque_iterator<BfmeE12, _Nonconst_traits<BfmeE12> > first,
	_Deque_iterator<BfmeE12, _Nonconst_traits<BfmeE12> > last,
	_Deque_iterator<BfmeE12, _Nonconst_traits<BfmeE12> > result)
{
	return __copy_backward_aux(first, last, result, __false_type());
}
}
