// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// BFME2's 64-byte BfmeVectorRecord000BDF17 vector allocation/copy helper at RVA 0xC24A0.
class AsciiString { public: AsciiString(); AsciiString(const AsciiString &); __forceinline ~AsciiString() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; };
#include <vector>
struct BfmeVectorRecord000BDF17 {
    _STL::vector<AsciiString> names;
    AsciiString text0, text1;
    unsigned int word14, word18, word1C, word20, word24, word28;
    unsigned char flag2C, flag2D;
    unsigned int word30, word34, word38;
    unsigned char flag3C;
    BfmeVectorRecord000BDF17();
    BfmeVectorRecord000BDF17(const BfmeVectorRecord000BDF17 &);
};
namespace _STL {
template <> void _Construct<BfmeVectorRecord000BDF17, BfmeVectorRecord000BDF17>(BfmeVectorRecord000BDF17 *, const BfmeVectorRecord000BDF17 &);
}
template class _STL::vector<BfmeVectorRecord000BDF17, _STL::allocator<BfmeVectorRecord000BDF17> >;
