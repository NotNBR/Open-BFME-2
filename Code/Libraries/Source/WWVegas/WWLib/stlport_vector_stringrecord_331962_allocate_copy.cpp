// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// BFME2's 12-byte BfmeStringRecord000331962 vector allocation/copy helper at RVA 0x331CE3.
class AsciiString { public: AsciiString(const AsciiString &); __forceinline ~AsciiString() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; };
struct BfmeStringRecord000331962 {
    unsigned int word;
    AsciiString text;
    unsigned char flag;
    BfmeStringRecord000331962();
    BfmeStringRecord000331962(const BfmeStringRecord000331962 &o) : word(o.word), text(o.text), flag(o.flag) {}
};
#include <memory>
template void _STL::_Construct<BfmeStringRecord000331962,BfmeStringRecord000331962>(BfmeStringRecord000331962*,const BfmeStringRecord000331962&);
#include <vector>
template class _STL::vector<BfmeStringRecord000331962, _STL::allocator<BfmeStringRecord000331962> >;
