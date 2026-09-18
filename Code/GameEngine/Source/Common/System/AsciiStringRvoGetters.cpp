// cl: /O1 /Oy- /DNDEBUG /MD /GX
//
// Value-returning AsciiString getters with the RVO idiom proven by
// GlobalDataRva002360DE.cpp (retail 0x002360DE, 30 bytes):
// each returns the string member at its offset via the hidden return
// pointer; the member copy-constructs directly into it (RVO) through
// the StringBase copy body at 0x365F0, and the function returns the
// hidden pointer. Class names are address-derived (identity
// unrecoverable from 30 bytes); member names positional.

typedef int Int;
typedef unsigned short WideChar;

#define NULL 0

template <typename T>
class StringBase
{
	friend class AsciiString;
	friend class UnicodeString;

public:
	StringBase() : m_data(0) {}

private:
	StringBase(const StringBase<T> &that);
	T *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	__forceinline AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString();
};

class UnicodeString : public StringBase<WideChar>
{
public:
	__forceinline UnicodeString(const UnicodeString &other) : StringBase<WideChar>(other) {}
	~UnicodeString();
};

class Rva00274DB6AsciiField
{
public:
	AsciiString get() const;

private:
	char m_pad[0x79C];
	AsciiString m_value; // +0x79C
};

// ?get@Rva00274DB6AsciiField@@QBE?AVAsciiString@@XZ
AsciiString Rva00274DB6AsciiField::get() const
{
	return m_value;
}
