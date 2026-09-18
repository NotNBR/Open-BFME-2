// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?parseTooltipCallback@@YA_NPADPAVWinInstanceData@@0PAX@Z,
// retail 0x00316480, 76 bytes. Dedicated TU.
//
// Clones the landed parseSystemCallback TU.
// - name global AsciiString at 0xE01310, store global at 0xE012FC.
// - registry lookup (pinned 0x2D225F) with index 2.
// - dispatch table at 0x9BE198 pairs 'TOOLTIPCALLBACK' with 0x716480.

typedef int Int;
typedef bool Bool;

#ifndef NULL
#define NULL 0
#endif

enum NameKeyType
{
	NAMEKEY_INVALID = 0
};

template <typename T>
class StringBase
{
	struct Header
	{
		int ref_count;
		unsigned short length;
		unsigned short capacity;
		T data[1];
	};

	Header *m_data;

public:
	void set(const char *s);
};

class AsciiString
{
public:
	void set(const char *s) { m_data.set(s); }

private:
	StringBase<char> m_data;
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const AsciiString &nameString);
};

extern NameKeyGenerator *TheNameKeyGenerator;

class Rva00DFF024Registry
{
public:
	void *lookup(int key, int index);
};

extern Rva00DFF024Registry *TheRva00DFF024Registry;
extern AsciiString g_tooltipCallbackName;
extern void *g_tooltipCallback;

class WinInstanceData;

extern "C" __declspec(dllimport) char *__cdecl strtok(char *str, const char *delimiters);

// ?parseTooltipCallback@@YA_NPADPAVWinInstanceData@@0PAX@Z
static Bool parseTooltipCallback(char *token, WinInstanceData *instData, char *buffer, void *data)
{
	char *c, *ptr;
	char *stringSeps = "\"";

	ptr = buffer;
	while (*ptr != '"')
		ptr++;
	ptr++;
	c = strtok(ptr, stringSeps);
	g_tooltipCallbackName.set(c);

	NameKeyType key = TheNameKeyGenerator->nameToKey(g_tooltipCallbackName);
	g_tooltipCallback = TheRva00DFF024Registry->lookup(key, 2);

	return true;
}

static const void *s_parseTooltipCallbackAnchor = (const void *)parseTooltipCallback;
