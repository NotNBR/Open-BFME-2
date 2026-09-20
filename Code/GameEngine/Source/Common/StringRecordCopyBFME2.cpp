// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
// BFME2 record copy at0x63BE4: seven words, an AsciiString, two tail bytes.
// The original application class and field meanings are unknown.
// The36-byte layout and memberwise copy are read directly from the complete
// retail body. Its string member calls the established copy at0x365F0.
// The placement-copy caller at0x63C8F independently links the same value.
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
struct BfmeStringRecord00063BE4 {
    unsigned int word0, word1, word2, word3, word4, word5, word6;
    AsciiString text;
    unsigned char tail0, tail1;
    BfmeStringRecord00063BE4(const BfmeStringRecord00063BE4 &o)
      : word0(o.word0), word1(o.word1), word2(o.word2), word3(o.word3), word4(o.word4), word5(o.word5), word6(o.word6), text(o.text), tail0(o.tail0), tail1(o.tail1) {}
};
#include <memory>
template void _STL::_Construct<BfmeStringRecord00063BE4,BfmeStringRecord00063BE4>(BfmeStringRecord00063BE4*,const BfmeStringRecord00063BE4&);

