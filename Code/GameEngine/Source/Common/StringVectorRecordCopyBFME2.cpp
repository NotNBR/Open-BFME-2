// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
// BFME2 records containing AsciiString and STLport vector<AsciiString>.
// The vector copy is the established 93-byte constructor at 0xBC07E.
// Layouts are read from the complete retail constructors and their STLport
// placement-copy callers. Application names and scalar meanings are unknown.
// String semantics follow BFME1 AsciiString/UnicodeString: the inline derived
// copies call StringBase<char>0x365F0 or StringBase<unsigned short>0x37050.
#include <memory>
#include <vector>
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

// Complete retail record copy at 0x000BDF17.
struct BfmeVectorRecord000BDF17 {
    _STL::vector<AsciiString> names; AsciiString text0, text1; unsigned int word14, word18, word1C, word20, word24, word28; unsigned char flag2C, flag2D; unsigned int word30, word34, word38; unsigned char flag3C;
    BfmeVectorRecord000BDF17(const BfmeVectorRecord000BDF17 &o);
};
BfmeVectorRecord000BDF17::BfmeVectorRecord000BDF17(const BfmeVectorRecord000BDF17 &o) : names(o.names), text0(o.text0), text1(o.text1), word14(o.word14), word18(o.word18), word1C(o.word1C), word20(o.word20), word24(o.word24), word28(o.word28), flag2C(o.flag2C), flag2D(o.flag2D), word30(o.word30), word34(o.word34), word38(o.word38), flag3C(o.flag3C) {}
template void _STL::_Construct<BfmeVectorRecord000BDF17,BfmeVectorRecord000BDF17>(BfmeVectorRecord000BDF17*,const BfmeVectorRecord000BDF17&);
