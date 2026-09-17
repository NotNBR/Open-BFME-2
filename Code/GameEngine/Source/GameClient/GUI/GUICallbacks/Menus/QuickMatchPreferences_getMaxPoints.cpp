// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?getMaxPoints@QuickMatchPreferences@@QAEHXZ, retail 0x005DF5AB, 83 bytes.
// Dedicated TU.
//
// ZH QuickMatchPreferences::getMaxPoints shape, except BFME2 returns 1000
// when the key is missing. Same string plumbing as the OptionPreferences
// family: TU-local StringBase/AsciiString, real STLport map (find worker
// pinned), StringBase ctor and releaseBuffer pinned, atoi via import.

#include <map>
#include <stdlib.h>

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

class QuickMatchPreferences : public AsciiPreferenceMap
{
public:
	virtual ~QuickMatchPreferences();
	Int getMaxPoints();
};

Int QuickMatchPreferences::getMaxPoints(void)
{
	QuickMatchPreferences::const_iterator it = find("MaxPoints");
	if (it == end()) {
		return 1000;
	}
	return atoi(it->second.str());
}
