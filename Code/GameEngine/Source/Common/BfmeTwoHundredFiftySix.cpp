// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /D_STLP_USE_STATIC_LIB /Od
// stlport
//
// ?bfmeSetOU@BfmeThingOU@@QAEPAV1@E@Z @ 0x0002A850 (30B). Near-miss donor
// from Open-BFME-1 BfmeTwoHundredFiftySix.cpp (b1 0x00830C30): the frame
// (spare[0x14] plus the saved this, sub esp,0x18) and the return-this shape
// carry over verbatim -- the sole drift is the callee. BFME1 calls its
// opaque bfmeDoOU worker; game.dat calls the matched narrow-string
// push_back at 0x0000C330 with this as the string object (mov ecx, never
// lea), so BfmeThingOU derives from the STLport narrow string here and the
// setter pushes through the base. No new pins.

namespace _STL
{

template <class T>
class char_traits {};

template <class T>
class allocator {};

template <class Pointer, class Value, class Alloc>
class _STLP_alloc_proxy : public Alloc
{
public:
	Pointer _M_data;
};

template <class CharT, class Traits, class Alloc>
class basic_string
{
public:
	typedef unsigned int size_type;
	void reserve(size_type amount);
	void push_back(CharT value);

private:
	CharT *_M_start;
	CharT *_M_finish;
	_STLP_alloc_proxy<CharT *, CharT, Alloc> _M_end_of_storage;
};

}

class BfmeThingOU : public _STL::basic_string<char, _STL::char_traits<char>, _STL::allocator<char> >
{
public:
	BfmeThingOU *bfmeSetOU(unsigned char one);
};

BfmeThingOU *BfmeThingOU::bfmeSetOU(unsigned char one)
{
	unsigned char spare[0x14];

	push_back(one);

	return this;
}
