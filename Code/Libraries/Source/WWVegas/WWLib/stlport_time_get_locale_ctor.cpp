// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
// Instantiate the protected locale-time overload directly from STLport 4.5.3
// stl/_time_facets.h. The narrow vtable BBBBC0 is independently established by
// the matched default constructor and destructor; _Time_Info starts at +0xC.
#include <locale>

template _STL::time_get<char, _STL::istreambuf_iterator<char, _STL::char_traits<char> > >::time_get(_Locale_time *, size_t);
