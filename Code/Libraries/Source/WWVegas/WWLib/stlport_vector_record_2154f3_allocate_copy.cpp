// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// BFME2's 16-byte BfmeVectorRecord0002154F3 vector allocation/copy helper at RVA 0x215614.
class AsciiString { public: AsciiString(); AsciiString(const AsciiString &); __forceinline ~AsciiString() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; };
#include <vector>
struct BfmeVectorRecord0002154F3 {
    AsciiString text;
    _STL::vector<AsciiString> names;
    BfmeVectorRecord0002154F3();
    BfmeVectorRecord0002154F3(const BfmeVectorRecord0002154F3 &);
};
namespace _STL {
template <> void _Construct<BfmeVectorRecord0002154F3, BfmeVectorRecord0002154F3>(BfmeVectorRecord0002154F3 *, const BfmeVectorRecord0002154F3 &);
}
template class _STL::vector<BfmeVectorRecord0002154F3, _STL::allocator<BfmeVectorRecord0002154F3> >;
