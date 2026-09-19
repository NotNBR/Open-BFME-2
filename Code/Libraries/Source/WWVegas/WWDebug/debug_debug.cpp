// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
//
// ??0RepeatChar@Debug@@QAE@DH@Z, retail 0x00038310 (18 bytes).
// Ported from Open-BFME-1 WWDebug debug_debug.h inline (BFME1 0x00889270):
// the repeat-character holder stores the character byte at +0x00 and the
// repeat count dword at +0x04; emitted out-of-line here for the retail body.

class Debug
{
public:
	class RepeatChar
	{
		char m_repeatChar;
		int m_repeatCount;

	public:
		RepeatChar(char ch, int count);
	};
};

// ??0RepeatChar@Debug@@QAE@DH@Z
Debug::RepeatChar::RepeatChar(char ch, int count)
	: m_repeatChar(ch), m_repeatCount(count)
{
}
