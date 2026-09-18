// cl: /O1 /DNDEBUG /MD /D_STLP_USE_STATIC_LIB
// stlport
//
// ?setCampaignDifficulty@OptionPreferences@@QAEXH@Z, retail 0x002E4F1F,
// 121 bytes. Dedicated TU.
//
// ZH OptionPreferences::setCampaignDifficulty shape (format + operator[] +
// assign) with two scheduling-critical splits: the key is a NAMED local
// constructed after text (retail destroys key before text so key is built
// second) and the slot is a NAMED reference. The single-statement temp form
// hoists the text push above the op[] call under /O1; the slot split sinks it
// back below. Naming the key as well keeps the dtor order exact and keeps the
// slot in eax (temp-key split homes it to esi). Same string plumbing as the
// landed getter siblings: TU-local StringBase/AsciiString with real STLport
// map and pinned operator[]/assign/ctor/release/format callees. Retail keeps
// default EH (two live temps under __EH_prolog).

#include <map>

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
	StringBase() {}
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
	AsciiString() { m_data = 0; }
	AsciiString(const char *text) : StringBase<char>(text) {}
	AsciiString(const AsciiString &other) : StringBase<char>(other) {}
	~AsciiString() {}
	AsciiString &operator=(const AsciiString &other);
	void format(const char *fmt, ...);
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

namespace _STL
{
template <> AsciiString &map<AsciiString, AsciiString, less<AsciiString>, allocator<pair<const AsciiString, AsciiString> > >::operator[](const AsciiString &key);
}

class OptionPreferences : public AsciiPreferenceMap
{
public:
	virtual ~OptionPreferences();
	void setCampaignDifficulty(Int value);
};

// ?setCampaignDifficulty@OptionPreferences@@QAEXH@Z
void OptionPreferences::setCampaignDifficulty(Int value)
{
	AsciiString text;
	text.format("%d", value);
	AsciiString key("CampaignDifficulty");
	AsciiString &slot = (*this)[key];
	slot = text;
}
