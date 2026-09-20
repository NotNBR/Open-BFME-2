// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
// Instantiate the protected locale-time overload directly from STLport 4.5.3
// stl/_time_facets.h. Vtables BBBBC0 (narrow) and BBBBEC (wide) are independently
// established by the matched default constructors and destructors;
// _Time_Info starts at +0xC in both facets.
#include <locale>

template _STL::time_get<char, _STL::istreambuf_iterator<char, _STL::char_traits<char> > >::time_get(_Locale_time *, size_t);
template _STL::time_get<wchar_t, _STL::istreambuf_iterator<wchar_t, _STL::char_traits<wchar_t> > >::time_get(_Locale_time *, size_t);
