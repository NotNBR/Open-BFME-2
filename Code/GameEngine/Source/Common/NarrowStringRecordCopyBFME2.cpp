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
