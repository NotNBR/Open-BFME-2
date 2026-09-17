// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?getLastLadderPort@CustomMatchPreferences@@QAEGXZ, retail 0x005DF50A,
// 81 bytes. Dedicated TU.
//
// ZH/BFME1 QuickMatchPreferences::getLastLadderPort verbatim shape (BFME1
// matches both twins as clean C++); claimed here under the CustomMatch name
// because CustomMatchPreferences is the class BFME2's own tree proves
// (WOLGameSetupMenu.cpp) while QuickMatchPreferences has no BFME2 presence.
// Same string plumbing as the OptionPreferences getters: TU-local
// StringBase/AsciiString, real STLport map (find worker pinned), StringBase
// ctor and releaseBuffer pinned, atoi via import.

#include <map>
#include <stdlib.h>

typedef bool Bool;
typedef int Int;
typedef unsigned short UnsignedShort;

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
	UnsignedShort getLastLadderPort();
};

UnsignedShort CustomMatchPreferences::getLastLadderPort(void)
{
	CustomMatchPreferences::const_iterator it = find("LastLadderPort");
	if (it == end()) {
		return 0;
	}
	return atoi(it->second.str());
}
