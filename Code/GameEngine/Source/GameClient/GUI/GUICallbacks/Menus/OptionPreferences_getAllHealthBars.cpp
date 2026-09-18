// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?getAllHealthBars@OptionPreferences@@QAE_NXZ, retail 0x002E4CF3,
// 91 bytes. Dedicated TU.
//
// ZH OptionPreferences getter shape (GeneralsMD/.../GUICallbacks/Menus/
// OptionsMenu.cpp) via the getTurnOffMessengerInGame twin (same plumbing;
// the miss default is false; the yes/no test calls strcmp through the CRT
// thunk at 0x006291C6).

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
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
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
	Bool getAllHealthBars();
};

// ?getAllHealthBars@OptionPreferences@@QAE_NXZ
Bool OptionPreferences::getAllHealthBars(void)
{
	OptionPreferences::const_iterator it = find("AllHealthBars");
	if (it == end())
		return false;

	if (strcmp(it->second.str(), "yes") == 0) {
		return true;
	}
	return false;
}
