// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /D_STLP_NO_EXCEPTIONS
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

// Retail466EA7 copies an AsciiString and one raw dword. Its bytes are already
// held under the tree-pair identity; use an independently verified alias.
// Application meaning and scalar signedness are not established.
#include <vector>
struct BfmeAsciiScalarValue8 {
    AsciiString text;
    unsigned int value;
    BfmeAsciiScalarValue8(const BfmeAsciiScalarValue8 &o)
        : text(o.text), value(o.value) {}
};
template _STL::vector<BfmeAsciiScalarValue8>::vector(const _STL::vector<BfmeAsciiScalarValue8>&);
