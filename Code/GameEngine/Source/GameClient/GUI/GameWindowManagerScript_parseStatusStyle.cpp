// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?parseStatus@@YA_NPADPAVWinInstanceData@@0PAX@Z, retail 0x00314FDC, 31 bytes.
// ?parseStyle@@YA_NPADPAVWinInstanceData@@0PAX@Z, retail 0x00314FFB, 31 bytes.
// Dedicated TU (both verbs share the parseBitString callee and tables).
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/GameClient/GUI/GameWindowManagerScript.cpp,
// parseStatus/parseStyle): zero the bits, then parseBitString over the
// window flag-name table. Verbatim.
// BFME2 facts (all retail-measured):
// - parseBitString is the free function at 0x00314D4D
//   (declared-not-defined here; resolves via pin, out-of-line call).
// - WindowStatusNames lives at 0x9BE0D8 (ACTIVE, TOGGLE, DRAGABLE,
//   ENABLED, ...); WindowStyleNames at 0x9BE150 (PUSHBUTTON,
//   RADIOBUTTON, ...). Both are TU-local externs (DIR32 auto-patches
//   from retail, no pins).
// - m_style sits at instData+0x0C, m_status at instData+0x10 (retail
//   add eax,0xC / add eax,0x10 plus and-mem-0).
// - Identity: the .data dispatch table at 0x9BE198 pairs 'STATUS' with
//   0x714FDC and 'STYLE' with 0x714FFB (entries are name@+0/fn@+4; the
//   walker at 0x31701C compares names and calls [eax+4]).

typedef int Int;
typedef unsigned int UnsignedInt;
typedef bool Bool;

#ifndef NULL
#define NULL 0
#endif

class WinInstanceData
{
public:
	char m_pad[0x0C];
	UnsignedInt m_style;  // +0x0C
	UnsignedInt m_status;  // +0x10
};

// parseBitString lives in GameWindowManagerScript.cpp (free function at
// 0x00314D4D). Declared extern with the BFME1 signature; the decoration
// matches and the pin resolves the address.
void parseBitString(const char *inBuffer, UnsignedInt *bits, const char **flagList);

extern const char *WindowStatusNames[];
extern const char *WindowStyleNames[];

// ?parseStatus@@YA_NPADPAVWinInstanceData@@0PAX@Z
static Bool parseStatus(char *token, WinInstanceData *instData, char *buffer, void *data)
{
	instData->m_status = 0;
	parseBitString(buffer, &instData->m_status, WindowStatusNames);

	return true;
}

// ?parseStyle@@YA_NPADPAVWinInstanceData@@0PAX@Z
static Bool parseStyle(char *token, WinInstanceData *instData, char *buffer, void *data)
{
	instData->m_style = 0;
	parseBitString(buffer, &instData->m_style, WindowStyleNames);

	return true;
}

static const void *s_parseStatusStyleAnchor = (const void *)parseStatus;
static const void *s_parseStatusStyleAnchor2 = (const void *)parseStyle;
