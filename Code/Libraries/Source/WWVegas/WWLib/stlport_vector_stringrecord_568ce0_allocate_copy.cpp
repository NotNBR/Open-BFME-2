// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// BFME2's 20-byte BfmeStringRecord00568CE0 vector allocation/copy helper at RVA 0x56930C.
class AsciiString { public: AsciiString(const AsciiString &); __forceinline ~AsciiString() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; };
struct BfmeStringRecord00568CE0 {
    AsciiString text0, text1;
    unsigned int word0, word1;
    unsigned char flag;
    BfmeStringRecord00568CE0();
    BfmeStringRecord00568CE0(const BfmeStringRecord00568CE0 &o) : text0(o.text0), text1(o.text1), word0(o.word0), word1(o.word1), flag(o.flag) {}
};
#include <memory>
template void _STL::_Construct<BfmeStringRecord00568CE0,BfmeStringRecord00568CE0>(BfmeStringRecord00568CE0*,const BfmeStringRecord00568CE0&);
#include <vector>
template class _STL::vector<BfmeStringRecord00568CE0, _STL::allocator<BfmeStringRecord00568CE0> >;
