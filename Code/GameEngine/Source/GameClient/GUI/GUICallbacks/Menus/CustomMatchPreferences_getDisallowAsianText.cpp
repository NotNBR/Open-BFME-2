// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?getDisallowAsianText@CustomMatchPreferences@@QAE_NXZ, retail 0x0054F5DE,
// 92 bytes. Dedicated TU.
//
// ZH/BFME1 CustomMatchPreferences::getDisallowAsianText verbatim shape
// (BFME1 matches it as clean C++); raw stricmp against "1" rather than the
// compareNoCase method the sibling bool getters use. Same string plumbing
// as the OptionPreferences family: TU-local StringBase/AsciiString, real
// STLport map (find worker pinned), StringBase ctor and releaseBuffer
// pinned, stricmp via import.

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

class CustomMatchPreferences : public AsciiPreferenceMap
{
public:
	virtual ~CustomMatchPreferences();
	Bool getDisallowAsianText();
};

Bool CustomMatchPreferences::getDisallowAsianText(void)
{
	CustomMatchPreferences::const_iterator it = find("DisallowAsianText");
	if (it == end())
		return false;

	register Bool match = (_strcmpi(it->second.str(), "1") == 0);
	return match;
}
