// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB

// Twelve-byte CreateAHeroData array element. Its retail default constructor
// zeros an AsciiString and two scalar words; assignment preserves string
// ownership through StringBase::set at 0x366F0. Field meanings are unknown.
template <class T> class StringBase {
    void *data;
public:
    StringBase() : data(0) {}
    void set(const StringBase &);
    __declspec(nothrow) ~StringBase() { releaseBuffer(); }
private:
    void releaseBuffer();
};
class AsciiString : private StringBase<char> {
public:
    AsciiString() : StringBase<char>() {}
    __declspec(nothrow) AsciiString &operator=(const AsciiString &o) { StringBase<char>::set(o); return *this; }
    __declspec(nothrow) ~AsciiString() {}
};
struct BfmeHeroElement005C39DE { AsciiString text; unsigned word4, word8; BfmeHeroElement005C39DE(); BfmeHeroElement005C39DE &operator=(const BfmeHeroElement005C39DE &); };
BfmeHeroElement005C39DE::BfmeHeroElement005C39DE() : text(), word4(0), word8(0) {}
BfmeHeroElement005C39DE &BfmeHeroElement005C39DE::operator=(const BfmeHeroElement005C39DE &o) { if (this != &o) { text=o.text; word4=o.word4; word8=o.word8; } return *this; }
