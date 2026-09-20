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

// Existing WeaponTemplateSetHeadCopyCtor.cpp proves a nonthrowing 0x4C-byte
// memcpy constructor at 0x45455. Preserve the out-of-line helper call.
class WeaponTemplateSetHead {
    char m_bytes[0x4C];
public:
    __declspec(nothrow) WeaponTemplateSetHead(const WeaponTemplateSetHead &);
};

// Complete retail record copy at 0x00048139.
struct BfmeContainerRecord00048139 {
    AsciiString text0, text1; WeaponTemplateSetHead head; unsigned int word54, word58;
    BfmeContainerRecord00048139(const BfmeContainerRecord00048139 &o);
};
BfmeContainerRecord00048139::BfmeContainerRecord00048139(const BfmeContainerRecord00048139 &o) : text0(o.text0), text1(o.text1), head(o.head), word54(o.word54), word58(o.word58) {}
template void _STL::_Construct<BfmeContainerRecord00048139,BfmeContainerRecord00048139>(BfmeContainerRecord00048139*,const BfmeContainerRecord00048139&);

// Complete retail record copy at 0x003A451B.
struct BfmeContainerRecord003A451B {
    AsciiString text; unsigned int word4; WeaponTemplateSetHead head0, head1;
    BfmeContainerRecord003A451B(const BfmeContainerRecord003A451B &o);
};
BfmeContainerRecord003A451B::BfmeContainerRecord003A451B(const BfmeContainerRecord003A451B &o) : text(o.text), word4(o.word4), head0(o.head0), head1(o.head1) {}
template void _STL::_Construct<BfmeContainerRecord003A451B,BfmeContainerRecord003A451B>(BfmeContainerRecord003A451B*,const BfmeContainerRecord003A451B&);
