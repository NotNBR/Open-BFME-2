// cl: /O1 /GX- /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// Fold-duplicate of OptionPreferences_getCampaignDifficulty.cpp (same class,
// same body, same flags): the getCampaignDifficulty definition folds
// byte-identical with its landed row, while this TU additionally claims the
// map<AsciiString,AsciiString> _Rb_tree _M_find worker (78B @0x1F8437) that
// every getter TU emits via odr-use of find but none rows. The worker's two
// less<> calls resolve through the primitive operator< pin at 0x5598C (23B
// compare+setl); the pair-lexicographic helper at 0x206BCF is a different
// function (it calls operator< thrice) and is pinned under its own name.

#include <map>
#include <stdlib.h>

typedef bool Bool;
typedef int Int;
typedef float Real;

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

enum GameDifficulty
{
	DIFFICULTY_EASY,
	DIFFICULTY_NORMAL,
	DIFFICULTY_HARD,

	DIFFICULTY_COUNT
};

class ScriptEngine
{
	char m_pad[0x1A4C4];
	GameDifficulty m_gameDifficulty;

public:
	GameDifficulty getGlobalDifficulty() const { return m_gameDifficulty; }
};

extern ScriptEngine *TheScriptEngine;

typedef _STL::map<AsciiString, AsciiString> AsciiPreferenceMap;

class OptionPreferences : public AsciiPreferenceMap
{
public:
	virtual ~OptionPreferences();
	Int getCampaignDifficulty();
};

// ?getCampaignDifficulty@OptionPreferences@@QAEHXZ
Int OptionPreferences::getCampaignDifficulty(void)
{
	OptionPreferences::const_iterator it = find("CampaignDifficulty");
	if (it == end())
		return TheScriptEngine->getGlobalDifficulty();

	Int factor = atoi(it->second.str());
	if (factor < DIFFICULTY_EASY)
		factor = DIFFICULTY_EASY;
	if (factor > DIFFICULTY_HARD)
		factor = DIFFICULTY_HARD;

	return factor;
}
