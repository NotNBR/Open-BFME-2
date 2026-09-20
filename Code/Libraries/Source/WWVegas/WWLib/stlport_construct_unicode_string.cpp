// cl: /O1 /Ob2 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
// STLport UnicodeString placement-copy helper at0x54DF6, full45bytes.
// Semantic donor: the exact AsciiString helper in stlport_construct_asciistring.cpp.
// Its direct callee is the established BFME2 StringBase<unsigned short> copy
// constructor at0x37050. The derived string has the same one-pointer layout.

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
	friend class UnicodeString;
private:
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	__forceinline ~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;

public:
	const T *str() const { static const T empty[1] = { 0 }; return m_data ? &m_data->text[0] : empty; }
};

class UnicodeString : private StringBase<unsigned short>
{
public:
	UnicodeString(const unsigned short *text) : StringBase<unsigned short>(text) {}
	__forceinline UnicodeString(const UnicodeString &other) : StringBase<unsigned short>(other) {}
	__forceinline ~UnicodeString() {}
};

template void _STL::_Construct<UnicodeString, UnicodeString>(UnicodeString *, const UnicodeString &);
