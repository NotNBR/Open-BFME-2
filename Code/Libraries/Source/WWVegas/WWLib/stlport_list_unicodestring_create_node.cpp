// cl: /Ireference/shims/bfmelist /O1 /EHsc /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB /Ireference/shims/bfmealloc
// stlport
//
// No-TRY twin of stlport_list_unicodestring_insert.cpp. Retail's
// _M_create_node at 0x00433B1E is frameless (34 bytes: allocate plus
// copy-construct, no __EH_prolog) because the bfmelist shim declares it
// __forceinline without TRY/UNWIND (same recipe as the int family's
// stlport_list_int_o1.cpp); the vendor header emits a 94-byte EH frame.
// Everything else here is the same wide UnicodeString/list context, so only
// this member is rowed from here.
#include <list>

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
	StringBase() {}
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	void releaseBuffer();
	BfmeStringData<T> *m_data;

public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)L""; }
};

class UnicodeString : private StringBase<wchar_t>
{
public:
	UnicodeString() { m_data = 0; }
	UnicodeString(const wchar_t *text);
	UnicodeString(const UnicodeString &other);
	~UnicodeString() { releaseBuffer(); }
};

bool operator==(const UnicodeString &a, const UnicodeString &b);
bool operator<(const UnicodeString &a, const UnicodeString &b);

template class _STL::list<UnicodeString, _STL::allocator<UnicodeString> >;
