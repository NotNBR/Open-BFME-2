// cl: /O1 /DNDEBUG /MD /EHsc /Oi
//
// ?parseAudioLODDefinition@INI@@SAXPAV1@@Z, retail 0x00202F8A,
// 153 bytes. Dedicated TU.
//
// BFME1 INI::parseAudioLODDefinition port
// (reference/open-bfme-1 Code/GameEngine/Source/Common/GameLOD.cpp: default
// AsciiString name; token = ini->getNextToken(); name = token; null-checked
// TheGameLODManager->getAudioLODIndex with a fatal INIException(8,
// "Unknown Audio LOD level '%s'") on -1; element at manager + index*8 and
// ini->initFromINI into the audio table). BFME2 adaptations proven by retail:
// - Element stride 8 with base +0x218 (BFME1's comment says +0x170; retail
//   lea says +0x218).
// - name.m_data starts zeroed via the member-init idiom (retail and-zero,
//   not a mov store); name = token goes through the inline operator= into
//   the matched StringBase::set at 0x000055F5; releaseBuffer resolves via
//   its pin.
// - The throw uses the proven AI-kind shape (8-byte INIException filled by
//   the 0x2F681 helper pin, push-imm throwinfo DIR32 at 0x8FE2FC, plain
//   _CxxThrowException call falling through into the store) with a plain
//   `if (index == -1)` (retail checks-then-throws-then-stores); the decl
//   carries __declspec(noreturn) so the index survives in eax for the store
//   without a callee-saved home.
// - getNextToken/initFromINI/getAudioLODIndex resolve via the matched row
//   and committed pins; the FieldParse table is TU-local opaque words (its
//   push is a DIR32 address patch; handler identities never enter .text).
// - Retail carries the __EH_prolog SEH prologue, so no /GX- here (unlike the
//   frameless pref getters): the dtor-temp plus throw earn the scope table.
//   /Oi lets the memset-free zeroing stay inline (without it the zeroing
//   becomes an out-of-line memset call).

#include <string.h>

typedef int Int;
typedef bool Bool;

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
public:
	void set(const char *text);
protected:
	StringBase() : m_data(0) {}
private:
	StringBase(const T *text);
	StringBase(const StringBase<T> &other);
	~StringBase() { releaseBuffer(); }
	void releaseBuffer();
	BfmeStringData<T> *m_data;
};

class AsciiString : public StringBase<char>
{
public:
	AsciiString() {}
	AsciiString(const AsciiString &other);
	AsciiString &operator=(const char *text) { set(text); return *this; }
	~AsciiString() {}
};

struct FieldParse
{
	unsigned long m_words[4];
};

class INI
{
public:
	const char *getNextToken(const char *seps);
	void initFromINI(void *dst, const FieldParse *table);
	static void parseAudioLODDefinition(INI *ini);
};

class GameLODManager
{
public:
	Int getAudioLODIndex(const AsciiString &name);
};

GameLODManager *TheGameLODManager;

static const FieldParse audioLODFieldParseTable[4] = { { 0 }, { 0 }, { 0 }, { 0 } };

struct INIException
{
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);

struct AudioLODThrowInfoAnchor { int a; int b; int c; int d; };
static const AudioLODThrowInfoAnchor audioLODThrowInfoAnchor = { 0, 0, 0, 0 };

// ?parseAudioLODDefinition@INI@@SAXPAV1@@Z
void INI::parseAudioLODDefinition(INI *ini)
{
	AsciiString name;
	const char *token = ini->getNextToken((const char *)0);
	name = token;

	if (TheGameLODManager)
	{
		Int index = TheGameLODManager->getAudioLODIndex(name);
		if (index == -1)
		{
			INIException e;
			rva002f681_fill(&e, 8, "Unknown Audio LOD level '%s'", token);
			_CxxThrowException(&e, (void *)&audioLODThrowInfoAnchor);
		}
		void *lodInfo = (char *)TheGameLODManager + index * 8 + 0x218;
		ini->initFromINI(lodInfo, audioLODFieldParseTable);
	}
}
