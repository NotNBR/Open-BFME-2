// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// STLport 4.5.3 uninitialized_copy over unsigned short, retail 0x0000DF10.
// The five bytes are a direct jump to __copy_trivial at 0x000179B0, which is
// what the vendor inline overload in stl/_uninitialized.h lowers to: the
// element type is trivially copyable, so the whole dispatch chain collapses
// into the memmove-backed worker. Spelled to tail-call it, this TU emits the
// bare jump retail carries. Reached only from basic_string<wchar_t>::reserve
// at 0x0000DED6, which pins this address under the same spelling.

namespace _STL
{

void *__cdecl __copy_trivial(const void *first, const void *last,
		void *result);

unsigned short *__cdecl uninitialized_copy(unsigned short *first,
		unsigned short *last, unsigned short *result)
{
	return (unsigned short *)__copy_trivial(first, last, result);
}

}
