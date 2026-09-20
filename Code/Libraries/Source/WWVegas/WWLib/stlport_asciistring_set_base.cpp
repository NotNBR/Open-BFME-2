// cl: /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// STLport 4.5.3 AsciiString set header allocation with BFME's byte allocator.
#include <set>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
template class _STL::set<AsciiString, _STL::less<AsciiString>, _STL::allocator<AsciiString> >;
