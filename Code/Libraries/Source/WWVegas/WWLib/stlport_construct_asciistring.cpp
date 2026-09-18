// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
//
// STLport _Construct<AsciiString> placement-copy helper. Retail 0x0002C485
// (45 bytes) is the null-guarded placement-new copy over a single element,
// called per element by the 38B __uninitialized_copy<AsciiString> trio at
// 0x0002C4B2 and by the AsciiString-vector push_back/insert bodies at
// 0x0002D222/0x0002DBF8/0x0001FD696. The AsciiString copy delegates inline to
// the StringBase<char> copy row at 0x000365F0 (AptMap pattern), so no new pin
// is needed for it; __EH_prolog resolves via its matched row.

#include <memory>

template <typename T> struct BfmeStringData
{
	int refCount;
	unsigned short length;
	unsigned short capacity;
	T text[1];
};

template <typename T> class StringBase
{
	friend class AsciiString;
private:
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	__forceinline ~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;

public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *text) : StringBase<char>(text) {}
	__forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	__forceinline ~AsciiString() {}
};

template void _STL::_Construct<AsciiString, AsciiString>(AsciiString *, const AsciiString &);
