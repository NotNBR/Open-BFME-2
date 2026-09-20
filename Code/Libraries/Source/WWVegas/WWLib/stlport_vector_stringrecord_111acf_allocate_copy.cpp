// cl: /O1 /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS /Ireference/shims/bfmealloc
// stlport
// BFME2's 28-byte BfmeStringRecord00111ACF vector allocation/copy helper at RVA 0x101F5C.
class AsciiString { public: AsciiString(const AsciiString &); __forceinline ~AsciiString() { releaseBuffer(); } protected: void releaseBuffer(); private: void *m_data; };
#include <vector>
struct BfmeStringRecord00111ACF {
    AsciiString first;
    unsigned int word4;
    struct FloatStorage { float values[4]; } middle;
    AsciiString second;
    BfmeStringRecord00111ACF();
    BfmeStringRecord00111ACF(const BfmeStringRecord00111ACF &);
};
namespace _STL {
template <> void _Construct<BfmeStringRecord00111ACF, BfmeStringRecord00111ACF>(BfmeStringRecord00111ACF *, const BfmeStringRecord00111ACF &);
}
template class _STL::vector<BfmeStringRecord00111ACF, _STL::allocator<BfmeStringRecord00111ACF> >;
