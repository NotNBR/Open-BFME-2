// cl: /EHsc /MD /D_STLP_USE_STATIC_LIB
// stlport
// ?addSubtitle@SubtitleManager@@QAEXABVAsciiString@@IHHHHH@Z, retail 0x00688AA0 (105B).
// Ported from Open-BFME-1 Code/GameEngine/Source/GameClient/SubtitleManagerAccessors.cpp
// (BFME1 0x0081DDD0). Creates the entry through the manager's factory hook and
// pushes it on the entry vector. The donor defines 7 further siblings the sweep
// did not place, so only the placed body is defined here; the rest stay
// declared-only.

#include <vector>

template <typename T>
class StringBase
{
	friend class AsciiString;

private:
	StringBase(const StringBase<T> &src);

	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};

	Header *m_data;
};

class AsciiString
{
public:
	AsciiString() : m_data(0) {}
	AsciiString(const AsciiString &other)
	{
		((StringBase<char> *)this)->StringBase<char>::StringBase(
			*(const StringBase<char> *)&other);
	}
	~AsciiString();
	AsciiString &operator=(const AsciiString &that);

private:
	void *m_data;
};

union SubtitleEntryBulk
{
	int words[10];
	struct
	{
		unsigned int color;
		char middle[0x14];
		bool displayed;
		char rest[0x0B];
	} fields;
};

class SubtitleEntry
{
public:
	SubtitleEntry(const SubtitleEntry &that);
	AsciiString getText() const;
	SubtitleEntry &operator=(const SubtitleEntry &that)
	{
		m_text = that.m_text;
		m_label = that.m_label;
		m_bulk = that.m_bulk;
		m_tailFirst = that.m_tailFirst;
		m_tailSecond = that.m_tailSecond;
		return *this;
	}

	AsciiString m_text;
	AsciiString m_label;
	SubtitleEntryBulk m_bulk;
	int m_tailFirst;
	int m_tailSecond;
};

typedef SubtitleEntry *(__cdecl *CreateSubtitleEntry)(AsciiString *, int,
	const AsciiString &, unsigned int, int, int, int, int, int);

class SubtitleManager
{
public:
	SubtitleManager(CreateSubtitleEntry createEntry, int second, const AsciiString &name);
	void addSubtitle(const AsciiString &label, unsigned int color, int style,
		int alignment, int line, int startFrame, int endFrame);
	bool hasBeenDisplayed(int index) const;
	AsciiString getText(int index) const;
	void setDisplayedStats(int index);
	unsigned int getColor(int index) const;
	int getStartFrame(int index) const;

private:
	CreateSubtitleEntry m_createEntry;
	int m_second;
	AsciiString m_name;
	AsciiString m_secondaryName;
	int m_count;
	_STL::vector<SubtitleEntry *> m_entries;
	int m_startFrame;
	int m_state[15];
	bool m_enabled;
};

void SubtitleManager::addSubtitle(const AsciiString &label, unsigned int color,
	int style, int alignment, int line, int startFrame, int endFrame)
{
	SubtitleEntry *entry = m_createEntry(&m_secondaryName, m_count, label, color,
		style, alignment, line, startFrame, endFrame);
	m_entries.push_back(entry);
}
