// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?getFirewallNeedToRefresh@OptionPreferences@@QAE_NXZ, retail 0x002E4928,
// 103 bytes. Dedicated TU.
//
// ZH OptionPreferences::getFirewallNeedToRefresh verbatim. Same string
// plumbing as its siblings, plus the AsciiString copy ctor (pinned) and the
// StringBase compareNoCase import (already pinned).

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
	int compareNoCase(const char *s) const;
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
	Bool getFirewallNeedToRefresh();
};

// ?getFirewallNeedToRefresh@OptionPreferences@@QAE_NXZ
Bool OptionPreferences::getFirewallNeedToRefresh()
{
	OptionPreferences::const_iterator it = find("FirewallNeedToRefresh");
	if (it == end()) {
		return false;
	}

	Bool retval = false;
	AsciiString str = it->second;
	if (str.compareNoCase("TRUE") == 0) {
		retval = true;
	}
	return retval;
}
