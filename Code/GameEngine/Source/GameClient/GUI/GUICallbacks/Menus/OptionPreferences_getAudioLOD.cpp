// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?getAudioLOD@OptionPreferences@@QAEHXZ, retail 0x002E4767,
// 73 bytes. Dedicated TU.
//
// BFME1 OptionPreferences::getAudioLOD verbatim
// (reference/open-bfme-1 Code/GameEngine/Source/GameClient/GUI/GUICallbacks/Menus/OptionPreferencesGetAudioLOD.cpp:
// key "AudioLOD"; miss -1; hit forwards the stored text to
// TheGameLODManager->getAudioLODIndex). Same string plumbing as
// OptionPreferences_hasSeenLogoMovies.cpp (TU-local StringBase/AsciiString;
// real STLport map with the 0x1F8437 find worker pinned; StringBase ctor and
// releaseBuffer pinned). The manager call resolves via the new
// getAudioLODIndex pin at 0x00202C76 (BFME1-attested mangling; thiscall on
// the TU-local TheGameLODManager global whose DIR32 patches from retail).

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

class GameLODManager
{
public:
	Int getAudioLODIndex(const AsciiString &name);
};

GameLODManager *TheGameLODManager;

class OptionPreferences : public AsciiPreferenceMap
{
public:
	virtual ~OptionPreferences();
	Int getAudioLOD();
};

Int OptionPreferences::getAudioLOD(void)
{
	OptionPreferences::const_iterator it = find("AudioLOD");
	if (it == end())
		return -1;

	return TheGameLODManager->getAudioLODIndex(it->second);
}
