// cl: /O1 /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS
//
// ModuleData::ModuleData, retail 0x006024FD (70 bytes).
//
// Battle for Middle-earth II gave every module data object an INI source
// location: the file name lives in a string member at +0x04 (defaulting to
// "<no file>"), followed by an int at +0x08, two flag bytes at +0x0C/+0x0D
// and an int at +0x10. The string member is value-initialized to null and
// then assigned through StringBase::set (matched 0x000055F5); the call can
// throw, so the member's destruction unwinds through the SEH prolog. True
// member names are unrecovered, so the layout keeps descriptive holders.

template <typename T>
class StringBase
{
public:
	StringBase() : m_data(0) {}
	void set(const T *text);
	~StringBase();

	void *m_data;
};

class ModuleData
{
public:
	ModuleData();
	virtual ~ModuleData();

private:
	StringBase<char> m_sourceFile; // +0x04, defaults to "<no file>"
	int m_sourceLine; // +0x08
	unsigned char m_sourceFlags0; // +0x0C
	unsigned char m_sourceFlags1; // +0x0D
	int m_moduleTagNameKey; // +0x10
};

// ??0ModuleData@@QAE@XZ
ModuleData::ModuleData()
	: m_sourceFile(), m_sourceLine(0), m_sourceFlags0(0), m_sourceFlags1(0), m_moduleTagNameKey(0)
{
	m_sourceFile.set("<no file>");
}
