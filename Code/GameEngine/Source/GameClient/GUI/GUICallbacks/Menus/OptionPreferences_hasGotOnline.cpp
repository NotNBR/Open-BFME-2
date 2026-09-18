// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?hasGotOnline@OptionPreferences@@QAE_NXZ, retail 0x002E49EB,
// 92 bytes. Dedicated TU.
//
// BFME1 OptionPreferences::hasGotOnline verbatim
// (reference/open-bfme-1 Code/GameEngine/Source/Common/OptionPreferencesFlags.cpp:
// key "HasGotOnline", miss-false, _strcmpi against "yes"). Same string
// plumbing as CustomMatchPreferences_getDisallowNonAsianText.cpp (TU-local
// StringBase/AsciiString, real STLport map with the 0x1F8437 find worker
// pinned, StringBase ctor and releaseBuffer pinned, _strcmpi via the 0xBBA518
// import). The AL-width neg/sbb/inc tail needs `register Bool match`, the
// same load-bearing spelling as the Disallow twins.

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

class OptionPreferences : public AsciiPreferenceMap
{
public:
	virtual ~OptionPreferences();
	Bool hasGotOnline();
};

Bool OptionPreferences::hasGotOnline(void)
{
	OptionPreferences::const_iterator it = find("HasGotOnline");
	if (it == end())
		return false;

	register Bool match = (_strcmpi(it->second.str(), "yes") == 0);
	return match;
}
