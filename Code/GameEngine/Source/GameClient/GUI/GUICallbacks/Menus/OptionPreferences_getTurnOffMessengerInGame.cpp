// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?getTurnOffMessengerInGame@OptionPreferences@@QAE_NXZ, retail 0x002E4C2B,
// 100 bytes. Dedicated TU.
//
// ZH OptionPreferences getter shape (GeneralsMD/.../GUICallbacks/Menus/
// OptionsMenu.cpp) via the getSendDelay twin (same plumbing; the miss default
// is TheGlobalData's byte retail-measured at +0xB69).

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

class GlobalData
{
public:
	char m_pad[0xB69];
	Bool m_turnOffMessengerInGame;
};

extern GlobalData *TheGlobalData;

class OptionPreferences : public AsciiPreferenceMap
{
public:
	virtual ~OptionPreferences();
	Bool getTurnOffMessengerInGame();
};

// ?getTurnOffMessengerInGame@OptionPreferences@@QAE_NXZ
Bool OptionPreferences::getTurnOffMessengerInGame(void)
{
	OptionPreferences::const_iterator it = find("TurnOffMessengerInGame");
	if (it == end())
		return TheGlobalData->m_turnOffMessengerInGame;

	if (strcmp(it->second.str(), "yes") == 0) {
		return true;
	}
	return false;
}
