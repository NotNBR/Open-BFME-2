// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
// BFME2 record copies with verified StringBase member operations.
// Layouts are read from the complete retail constructors and their STLport
// placement-copy callers. Application names and scalar meanings are unknown.
// String semantics follow BFME1 AsciiString/UnicodeString: the inline derived
// copies call StringBase<char>0x365F0 or StringBase<unsigned short>0x37050.
#include <memory>
template <typename T> class StringBase {
    friend class AsciiString;
    friend class UnicodeString;
    StringBase(const StringBase &);
    __forceinline ~StringBase() { releaseBuffer(); }
    void releaseBuffer();
    void *m_data;
};
class AsciiString : private StringBase<char> {
public:
    __forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
    __forceinline ~AsciiString() {}
};
class UnicodeString : private StringBase<unsigned short> {
public:
    __forceinline UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
    __forceinline ~UnicodeString() {}
};

// Complete retail record copy at0x00054F57.
struct BfmeStringRecord00054F57 {
    AsciiString ansi; UnicodeString wide;
    BfmeStringRecord00054F57(const BfmeStringRecord00054F57 &o);
};
BfmeStringRecord00054F57::BfmeStringRecord00054F57(const BfmeStringRecord00054F57 &o) : ansi(o.ansi), wide(o.wide) {}
template void _STL::_Construct<BfmeStringRecord00054F57,BfmeStringRecord00054F57>(BfmeStringRecord00054F57*,const BfmeStringRecord00054F57&);

// Complete retail record copy at0x00204A30.
struct BfmeStringRecord00204A30 {
    unsigned int word0; AsciiString text0; unsigned int word1; AsciiString text1; unsigned int word2;
    BfmeStringRecord00204A30(const BfmeStringRecord00204A30 &o);
};
BfmeStringRecord00204A30::BfmeStringRecord00204A30(const BfmeStringRecord00204A30 &o) : word0(o.word0), text0(o.text0), word1(o.word1), text1(o.text1), word2(o.word2) {}
template void _STL::_Construct<BfmeStringRecord00204A30,BfmeStringRecord00204A30>(BfmeStringRecord00204A30*,const BfmeStringRecord00204A30&);

// Complete retail record copy at0x002199C8.
struct BfmeStringRecord002199C8 {
    AsciiString text0, text1, text2; unsigned int word;
    BfmeStringRecord002199C8(const BfmeStringRecord002199C8 &o);
};
BfmeStringRecord002199C8::BfmeStringRecord002199C8(const BfmeStringRecord002199C8 &o) : text0(o.text0), text1(o.text1), text2(o.text2), word(o.word) {}
template void _STL::_Construct<BfmeStringRecord002199C8,BfmeStringRecord002199C8>(BfmeStringRecord002199C8*,const BfmeStringRecord002199C8&);

// Complete retail record copy at0x00219A68.
struct BfmeStringRecord00219A68 {
    unsigned int word0; AsciiString text0, text1; unsigned int word1, word2;
    BfmeStringRecord00219A68(const BfmeStringRecord00219A68 &o);
};
BfmeStringRecord00219A68::BfmeStringRecord00219A68(const BfmeStringRecord00219A68 &o) : word0(o.word0), text0(o.text0), text1(o.text1), word1(o.word1), word2(o.word2) {}
template void _STL::_Construct<BfmeStringRecord00219A68,BfmeStringRecord00219A68>(BfmeStringRecord00219A68*,const BfmeStringRecord00219A68&);
