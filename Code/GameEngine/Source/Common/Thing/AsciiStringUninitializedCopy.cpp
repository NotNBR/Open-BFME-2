// cl: /O1 /DNDEBUG /MD
//
// _STL::__uninitialized_copy<AsciiString*, AsciiString*>, retail
// 0x0002C4B2, 38 bytes. Dedicated TU so the AsciiString _Construct helper
// at 0x0002C485 stays an out-of-line call inside this loop. Element stride
// is 4 (StringBase m_data model, not the 8-byte Buffer model at 0x142CE0).

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
	void releaseBuffer();
	BfmeStringData<T> *m_data;

public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *text);
	AsciiString(const AsciiString &other);
	~AsciiString();
};

// Opaque helper pinned at 0x0002C485 (StringBase _Construct flavor, whose
// true _STL mangling is spent at 0x00142CC0). Declared with copy-construct
// shape so the loop emits the retail 2-push call to 0x2C485.
void __cdecl AsciiStringCopyConstructAtRva0002C485(AsciiString *dest, const AsciiString &src);

namespace _STL
{

struct __false_type {};

template <class InputIter, class ForwardIter>
ForwardIter __uninitialized_copy(InputIter first, InputIter last,
	ForwardIter result, const __false_type &)
{
	ForwardIter cur = result;
	for (; first != last; ++first, ++cur)
		AsciiStringCopyConstructAtRva0002C485(cur, *first);
	return cur;
}

}

template AsciiString *_STL::__uninitialized_copy(const AsciiString *, const AsciiString *, AsciiString *, const _STL::__false_type &);
