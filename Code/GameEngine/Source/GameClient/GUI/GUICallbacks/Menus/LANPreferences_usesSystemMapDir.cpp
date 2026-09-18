// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?usesSystemMapDir@LANPreferences@@QAE_NXZ, retail 0x0043C32A,
// 90 bytes. Dedicated TU.
//
// ZH LANPreferences::usesSystemMapDir verbatim shape
// (GeneralsMD/.../LanLobbyMenu.cpp:148: miss returns TRUE, compares the
// stored value case-insensitively against "yes"). Same string plumbing
// as the OptionPreferences family: TU-local StringBase/AsciiString, real
// STLport map (find worker pinned at 0x1F8437), StringBase ctor and
// releaseBuffer pinned, _strcmpi via import (slot 0xBBA518).
//
// The key temporary is built by a LANPreferences helper (pinned opaquely
// at 0x43BB6A, 7 same-cluster callers) that returns the key AsciiString
// by value: the hidden return pointer rides the stack under the literal,
// so the call reads push-literal/push-temp and find takes the returned
// eax. Probe-proven byte-identical on the first spelling.

#include <map>
#include <stdlib.h>
#include <string.h>

typedef bool Bool;
typedef int Int;

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
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;

public:
	const T *str() const { return m_data ? &m_data->text[0] : (const T *)""; }
};

class AsciiString : private StringBase<char>
{
public:
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other);
	~AsciiString() {}
};

bool operator<(const AsciiString &left, const AsciiString &right);

namespace _STL
{
template <> struct less<AsciiString>
{
	bool operator()(const AsciiString &left, const AsciiString &right) const
	{
		return left < right;
	}
};
}

typedef _STL::map<AsciiString, AsciiString> AsciiPreferenceMap;

class LANPreferences : public AsciiPreferenceMap
{
public:
	virtual ~LANPreferences();
	AsciiString Rva0043BB6ABuildKey(const char *src);
	Bool usesSystemMapDir();
};

Bool LANPreferences::usesSystemMapDir(void)
{
	LANPreferences::const_iterator it = find(Rva0043BB6ABuildKey("UseSystemMapDir"));
	if (it == end())
		return true;

	register Bool match = (_strcmpi(it->second.str(), "yes") == 0);
	return match;
}
