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


// Retail copy 0x000B757D: observed scalar fields and string member.
// Original application type and scalar meanings are unknown.
struct BfmeStringRecord000B757D {
    unsigned int word0, word1; AsciiString text; unsigned int word2; unsigned char tail;
    BfmeStringRecord000B757D(const BfmeStringRecord000B757D &o) : word0(o.word0), word1(o.word1), text(o.text), word2(o.word2), tail(o.tail) {}
};
template void _STL::_Construct<BfmeStringRecord000B757D,BfmeStringRecord000B757D>(BfmeStringRecord000B757D*,const BfmeStringRecord000B757D&);

// Retail copy 0x000B950F: observed scalar fields and string member.
// Original application type and scalar meanings are unknown.
struct BfmeStringRecord000B950F {
    unsigned int word0; AsciiString text; unsigned int word1;
    BfmeStringRecord000B950F(const BfmeStringRecord000B950F &o) : word0(o.word0), text(o.text), word1(o.word1) {}
};
template void _STL::_Construct<BfmeStringRecord000B950F,BfmeStringRecord000B950F>(BfmeStringRecord000B950F*,const BfmeStringRecord000B950F&);

// Retail copy 0x000B9534: observed scalar fields and string member.
// Original application type and scalar meanings are unknown.
struct BfmeStringRecord000B9534 {
    AsciiString text; unsigned char flag; unsigned int word0, word1, word2, word3;
    BfmeStringRecord000B9534(const BfmeStringRecord000B9534 &o) : text(o.text), flag(o.flag), word0(o.word0), word1(o.word1), word2(o.word2), word3(o.word3) {}
};
template void _STL::_Construct<BfmeStringRecord000B9534,BfmeStringRecord000B9534>(BfmeStringRecord000B9534*,const BfmeStringRecord000B9534&);

// Retail copy 0x002CF4C6: observed scalar fields and string member.
// Original application type and scalar meanings are unknown.
struct BfmeStringRecord002CF4C6 {
    AsciiString text0, text1; unsigned int word0, word1; unsigned char flag0, flag1;
    BfmeStringRecord002CF4C6(const BfmeStringRecord002CF4C6 &o) : text0(o.text0), text1(o.text1), word0(o.word0), word1(o.word1), flag0(o.flag0), flag1(o.flag1) {}
};
template void _STL::_Construct<BfmeStringRecord002CF4C6,BfmeStringRecord002CF4C6>(BfmeStringRecord002CF4C6*,const BfmeStringRecord002CF4C6&);

// Retail copy 0x002CF5B1: observed scalar fields and string member.
// Original application type and scalar meanings are unknown.
struct BfmeStringRecord002CF5B1 {
    unsigned int word0, word1; AsciiString text;
    BfmeStringRecord002CF5B1(const BfmeStringRecord002CF5B1 &o) : word0(o.word0), word1(o.word1), text(o.text) {}
};
template void _STL::_Construct<BfmeStringRecord002CF5B1,BfmeStringRecord002CF5B1>(BfmeStringRecord002CF5B1*,const BfmeStringRecord002CF5B1&);

// Retail copy 0x00395E75: observed scalar fields and string member.
// Original application type and scalar meanings are unknown.
struct BfmeStringRecord00395E75 {
    AsciiString text0, text1; unsigned int word;
    BfmeStringRecord00395E75(const BfmeStringRecord00395E75 &o) : text0(o.text0), text1(o.text1), word(o.word) {}
};
template void _STL::_Construct<BfmeStringRecord00395E75,BfmeStringRecord00395E75>(BfmeStringRecord00395E75*,const BfmeStringRecord00395E75&);

// Retail copy 0x00568CE0: observed scalar fields and string member.
// Original application type and scalar meanings are unknown.
struct BfmeStringRecord00568CE0 {
    AsciiString text0, text1; unsigned int word0, word1; unsigned char flag;
    BfmeStringRecord00568CE0(const BfmeStringRecord00568CE0 &o) : text0(o.text0), text1(o.text1), word0(o.word0), word1(o.word1), flag(o.flag) {}
};
template void _STL::_Construct<BfmeStringRecord00568CE0,BfmeStringRecord00568CE0>(BfmeStringRecord00568CE0*,const BfmeStringRecord00568CE0&);

// Retail copy 0x000B75AE: observed scalar fields and string member.
// Original application type and scalar meanings are unknown.
struct BfmeStringRecord000B75AE {
    AsciiString text; unsigned int word0, word1, word2, word3, word4, word5; unsigned char flag0, flag1, flag2, flag3;
    BfmeStringRecord000B75AE(const BfmeStringRecord000B75AE &o) : text(o.text), word0(o.word0), word1(o.word1), word2(o.word2), word3(o.word3), word4(o.word4), word5(o.word5), flag0(o.flag0), flag1(o.flag1), flag2(o.flag2), flag3(o.flag3) {}
};
template void _STL::_Construct<BfmeStringRecord000B75AE,BfmeStringRecord000B75AE>(BfmeStringRecord000B75AE*,const BfmeStringRecord000B75AE&);

// Retail copy 0x003B3F78: observed scalar fields and string member.
// Original application type and scalar meanings are unknown.
struct BfmeStringRecord003B3F78 {
    unsigned int word0, word1; AsciiString text; unsigned char flag; unsigned short short0; unsigned int word2;
    BfmeStringRecord003B3F78(const BfmeStringRecord003B3F78 &o) : word0(o.word0), word1(o.word1), text(o.text), flag(o.flag), short0(o.short0), word2(o.word2) {}
};
template void _STL::_Construct<BfmeStringRecord003B3F78,BfmeStringRecord003B3F78>(BfmeStringRecord003B3F78*,const BfmeStringRecord003B3F78&);
