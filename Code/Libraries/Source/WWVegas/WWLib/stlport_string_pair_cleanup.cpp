// cl: /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// Reference STLport4.5.3 two-AsciiString map cleanup. Copy5224E3 uses
// clone522272 and the verified24B node202B4A. Assignment52274D calls
// clear2E44F2 then this same copy chain; clear reaches erase2E44BD.
// Pair copy2C574 constructs temporary ebp-2C at2D4D6; dtor2C0C0
// destroys exactly that temporary at2D4F8. No width-only type inference.
#include <map>
template<class T> class StringBase { void *m_data; void releaseBuffer(); protected: __forceinline ~StringBase() { releaseBuffer(); } };
class AsciiString : private StringBase<char> { public: AsciiString(const AsciiString &); __forceinline ~AsciiString() {} };
bool operator<(const AsciiString &, const AsciiString &);
typedef _STL::pair<const AsciiString,AsciiString> StringPair;
typedef _STL::_Rb_tree<AsciiString,StringPair,_STL::_Select1st<StringPair>,_STL::less<AsciiString>,_STL::allocator<StringPair> > StringPairTree;
template StringPairTree::~_Rb_tree();
