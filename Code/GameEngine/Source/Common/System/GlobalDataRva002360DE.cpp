// cl: /O1 /Oy- /DNDEBUG /MD /GX
//
// ?rva002360DE@GlobalData@@QBE?AVAsciiString@@XZ,
// retail 0x002360DE, 30 bytes. Dedicated TU.
//
// Value-returning AsciiString getter on GlobalData: returns the AsciiString
// member at +0x1240. The stack arg is the hidden return pointer; the member
// copy-constructs directly into it (RVO) through the StringBase copy body
// at 0x365F0, and the function returns the hidden pointer. Sole caller
// today is the FileSystem Art-directory setup at 0x00786BD, which passes a
// stack temp and reads the string out of it. The class name is load-bearing
// (the call resolves via the ledger row); the member name is positional.

typedef int Int;

#define NULL 0

template <typename T>
class StringBase
{
	friend class AsciiString;

public:
	StringBase() : m_data(0) {}

private:
	StringBase(const StringBase<T> &that);
	T *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString();
};

class GlobalData
{
public:
	AsciiString rva002360DE() const;

private:
	char m_pad[0x1240];
	AsciiString m_string1240; // +0x1240
};

// ?rva002360DE@GlobalData@@QBE?AVAsciiString@@XZ
AsciiString GlobalData::rva002360DE() const
{
	return m_string1240;
}
