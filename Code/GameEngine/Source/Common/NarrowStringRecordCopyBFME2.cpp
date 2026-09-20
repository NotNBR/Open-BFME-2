// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP=
// stlport
// BFME2 record layouts recovered from complete retail copy constructors.
// These use STLport basic_string<char> (12 bytes), copied by 0x9170.
// Application names and scalar meanings remain unknown. Padding is not copied.
#include <memory>
#include <string>

// Complete retail record copy at 0x00079C23.
struct BfmeNarrowRecord00079C23 {
    _STL::basic_string<char> text0, text1, text2; unsigned int word0, word1;
    BfmeNarrowRecord00079C23(const BfmeNarrowRecord00079C23 &o);
};
BfmeNarrowRecord00079C23::BfmeNarrowRecord00079C23(const BfmeNarrowRecord00079C23 &o) : text0(o.text0), text1(o.text1), text2(o.text2), word0(o.word0), word1(o.word1) {}
template void _STL::_Construct<BfmeNarrowRecord00079C23,BfmeNarrowRecord00079C23>(BfmeNarrowRecord00079C23*,const BfmeNarrowRecord00079C23&);

// Complete retail record copy at 0x000BFDC7.
struct BfmeNarrowRecord000BFDC7 {
    unsigned int word0; _STL::basic_string<char> text; unsigned int word1, word2, word3, word4;
    BfmeNarrowRecord000BFDC7(const BfmeNarrowRecord000BFDC7 &o);
};
BfmeNarrowRecord000BFDC7::BfmeNarrowRecord000BFDC7(const BfmeNarrowRecord000BFDC7 &o) : word0(o.word0), text(o.text), word1(o.word1), word2(o.word2), word3(o.word3), word4(o.word4) {}
template void _STL::_Construct<BfmeNarrowRecord000BFDC7,BfmeNarrowRecord000BFDC7>(BfmeNarrowRecord000BFDC7*,const BfmeNarrowRecord000BFDC7&);

// Complete retail record copy at 0x0041A5D2.
struct BfmeNarrowRecord0041A5D2 {
    _STL::basic_string<char> text0; unsigned short short0; _STL::basic_string<char> text1;
    BfmeNarrowRecord0041A5D2(const BfmeNarrowRecord0041A5D2 &o);
};
BfmeNarrowRecord0041A5D2::BfmeNarrowRecord0041A5D2(const BfmeNarrowRecord0041A5D2 &o) : text0(o.text0), short0(o.short0), text1(o.text1) {}
template void _STL::_Construct<BfmeNarrowRecord0041A5D2,BfmeNarrowRecord0041A5D2>(BfmeNarrowRecord0041A5D2*,const BfmeNarrowRecord0041A5D2&);

// Complete retail record copy at 0x0041A617.
struct BfmeNarrowRecord0041A617 {
    _STL::basic_string<char> text; unsigned short short0; unsigned char flag;
    BfmeNarrowRecord0041A617(const BfmeNarrowRecord0041A617 &o);
};
BfmeNarrowRecord0041A617::BfmeNarrowRecord0041A617(const BfmeNarrowRecord0041A617 &o) : text(o.text), short0(o.short0), flag(o.flag) {}
template void _STL::_Construct<BfmeNarrowRecord0041A617,BfmeNarrowRecord0041A617>(BfmeNarrowRecord0041A617*,const BfmeNarrowRecord0041A617&);
