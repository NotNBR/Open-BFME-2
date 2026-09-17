// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?getSendDelay@OptionPreferences@@QAE_NXZ, retail 0x002E47B0,
// 101 bytes. Dedicated TU.
//
// ZH OptionPreferences::getSendDelay verbatim
// (GeneralsMD/.../GUICallbacks/Menus/OptionsMenu.cpp:427). Same string
// plumbing as its siblings; the miss default is TheGlobalData's firewall
// send-delay byte (retail-measured at +0xA50).

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
	char m_pad[0xA50];
	Bool m_firewallSendDelay;
};

extern GlobalData *TheGlobalData;

class OptionPreferences : public AsciiPreferenceMap
{
public:
	virtual ~OptionPreferences();
	Bool getSendDelay();
};

// ?getSendDelay@OptionPreferences@@QAE_NXZ
Bool OptionPreferences::getSendDelay(void)
{
	OptionPreferences::const_iterator it = find("SendDelay");
	if (it == end())
		return TheGlobalData->m_firewallSendDelay;

	if (_strcmpi(it->second.str(), "yes") == 0) {
		return true;
	}
	return false;
}
