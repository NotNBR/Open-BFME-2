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

// SaveGameInfo's name getter at 0x22CEF1 identifies this class. Its destructor
// at 0x2DD1E9 restores Snapshot's established vtable (VA 0xBBB554), proving
// the state-free polymorphic base and the extra constructor unwind state.
// Retain the address-derived name already used by the enclosing map record.
// BFME1 SaveGameInfo supplies the three-string/date prefix; BFME2 adds the
// following fields. Unresolved application field names remain offset-based.
class Xfer;
class Snapshot {
public:
    __forceinline virtual ~Snapshot() {}
    virtual void crc(Xfer *);
    virtual const char *typeName() const;
    virtual void xfer(Xfer *);
};
struct BfmeSaveDate { unsigned short values[8]; };
// Complete copy at 0x22C55B is 71 bytes: allocate a vector range of 20-byte
// elements and copy it through 0x2DBEFF. Destructor 0x22CAC4 owns the range.
struct BfmeVector0022C55B {
    void *begin, *end, *capacity;
    BfmeVector0022C55B(const BfmeVector0022C55B &);
    ~BfmeVector0022C55B();
};
// Complete copy at 0x229875 is 141 bytes: vptr 0xBE7460; eight 0x1AC-byte
// elements at +4; blocks at +0xD64/+0xD74; byte +0xD9C; dword +0xDA0.
// Its destructor is the direct +0x44 member cleanup at 0x2DC62C.
// The callbacks are absolute VAs 0x6295D7/0x6294FD, hence RVAs
// 0x2295D7 (271-byte copy) and 0x2294FD (90-byte destructor).
// Both independently prove the Snapshot base and 0x1AC element extent.
struct BfmeSaveElement002295D7 : Snapshot {
    unsigned char fields[0x1A8];
    BfmeSaveElement002295D7(const BfmeSaveElement002295D7 &);
    virtual ~BfmeSaveElement002295D7();
};
struct BfmeSaveBlock4 { unsigned int values[4]; };
struct BfmeSaveBlock10 { unsigned int values[10]; };
struct BfmeSubobject00229875 : Snapshot {
    virtual ~BfmeSubobject00229875();
    virtual void crc(Xfer *);
    virtual const char *typeName() const;
    virtual void xfer(Xfer *);
    BfmeSaveElement002295D7 elements[8];
    BfmeSaveBlock4 blockD64;
    BfmeSaveBlock10 blockD74;
    unsigned char flagD9C;
    unsigned int wordDA0;
};
typedef char BfmeSaveElementSizeCheck[sizeof(BfmeSaveElement002295D7)==0x1AC ? 1 : -1];
struct BfmeSubobject0022CE19 : Snapshot {
    virtual ~BfmeSubobject0022CE19();
    virtual void crc(Xfer *);
    virtual const char *typeName() const;
    virtual void xfer(Xfer *);
    AsciiString text04, text08, text0C;
    BfmeSaveDate date10;
    UnicodeString text20;
    unsigned int word24, word28;
    AsciiString text2C;
    UnicodeString text30, text34;
    BfmeVector0022C55B range38;
    BfmeSubobject00229875 object44;
    BfmeSubobject0022CE19(const BfmeSubobject0022CE19 &);
};
typedef char BfmeSaveSizeCheck[sizeof(BfmeSubobject0022CE19)==0xDE8 ? 1 : -1];
typedef char BfmeSaveOffsetsCheck[(offsetof(BfmeSubobject0022CE19,range38)==0x38 && offsetof(BfmeSubobject0022CE19,object44)==0x44) ? 1 : -1];
BfmeSubobject0022CE19::BfmeSubobject0022CE19(const BfmeSubobject0022CE19 &o)
    : Snapshot(o), text04(o.text04), text08(o.text08), text0C(o.text0C),
      date10(o.date10), text20(o.text20), word24(o.word24), word28(o.word28),
      text2C(o.text2C), text30(o.text30), text34(o.text34),
      range38(o.range38), object44(o.object44) {}

BfmeSubobject0022CE19::~BfmeSubobject0022CE19() {}
