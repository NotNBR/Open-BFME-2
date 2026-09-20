// cl: /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
// CreateAHeroData identity and 0x140-byte layout are established by the
// independently matched copy constructor and named vtable at VA C38D88.
// RvaVecAscii declares the existing 12-byte string-vector cleanup ABI at
// RVA2CC70. The global STL vector<AsciiString> destructor pin is misidentified
// as string release36410 in an unrelated baseline caller; do not reuse it here.
// WriteNamedHero4074CF opens a wide path with mode w, writes map50 entries
// as "%s = %d\n", closes the file and returns success as a bool.
#include <memory>
#include <vector>
#include <map>
template<class T> class StringBase { void *m_data; void releaseBuffer(); public: StringBase(const StringBase &); protected: __forceinline ~StringBase() { releaseBuffer(); } };
class AsciiString : private StringBase<char> { public: __forceinline AsciiString(const AsciiString &o) : StringBase<char>(o) {} __forceinline ~AsciiString() {} bool isEmpty() const; };
class UnicodeString : private StringBase<unsigned short> { public: __forceinline UnicodeString(const UnicodeString &o) : StringBase<unsigned short>(o) {} __forceinline ~UnicodeString() {} };
class Xfer;
class Snapshot { public: __forceinline virtual ~Snapshot() {} virtual void crc(Xfer *); virtual const char *typeName() const; virtual void xfer(Xfer *); };
typedef _STL::map<int,int> IntegerMap;
struct TreeHintPayload001F8ACB { unsigned int value; };
bool operator<(const AsciiString &, const AsciiString &);
typedef _STL::map<AsciiString,TreeHintPayload001F8ACB> StringPayloadMap;
typedef _STL::vector<bool> BitVector;
typedef _STL::map<int,_STL::vector<unsigned int> > IntegerVectorMap;
class RvaVecAscii { AsciiString *m_begin; AsciiString *m_end; AsciiString *m_capacity; public: ~RvaVecAscii(); };
struct BfmeHeroElement005C39DE { AsciiString text; unsigned int word4, word8; BfmeHeroElement005C39DE(); BfmeHeroElement005C39DE &operator=(const BfmeHeroElement005C39DE &); };
class CreateAHeroData;
extern void __cdecl UnregisterCreateAHeroAtRva0021A624(CreateAHeroData *);
class CreateAHeroData : public Snapshot {
    unsigned int word04; UnicodeString text08; unsigned int word0C, word10;
    IntegerMap map14, map20; unsigned int word2C, word30, word34, word38;
    RvaVecAscii strings3C; unsigned char flag48; AsciiString text4C;
    StringPayloadMap map50; BitVector bits5C; unsigned char flag70, flag71;
    unsigned short pad72; IntegerVectorMap map74; BfmeHeroElement005C39DE elements80[15];
    unsigned int word134, word138, word13C;
public:
    bool WriteNamedHeroAtRva004074CF();
    virtual ~CreateAHeroData();
};
CreateAHeroData::~CreateAHeroData() { if (!text4C.isEmpty()) WriteNamedHeroAtRva004074CF(); UnregisterCreateAHeroAtRva0021A624(this); }

typedef char HeroLayoutSizeCheck[sizeof(CreateAHeroData)==0x140 ? 1 : -1];
typedef char HeroStringVectorSizeCheck[sizeof(RvaVecAscii)==12 ? 1 : -1];
