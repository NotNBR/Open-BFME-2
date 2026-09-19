// Trimmed port of reference/open-bfme-1/Code/GameEngine/Source/Common/
// Bfme5SetupPairs.cpp: only the 007E9860 stub is carried; sibling stubs stay
// with the donor until rows land.

struct BfmeSetupRecord
{
	void bfmeBegin(void);					// retail 0x00655B50
	void bfmeWrite(const char *text, int value);		// retail 0x00655AA0
	void bfmeWriteAlt(const char *text, int value);		// retail 0x00655960

	char m_bfmeHead[0x1C];
	unsigned int m_bfmeTag;					// +0x1C
};

extern const char TheBfmeSetupFirstText[];
extern const char TheBfmeSetupSecondText007E9860[];
extern int TheBfmeSetupGlobal007E9860;

// ?bfmeSetupPair_007E9860@@YGXPAUBfmeSetupRecord@@H@Z
void __stdcall bfmeSetupPair_007E9860(BfmeSetupRecord *record, int second)
{
	int value = TheBfmeSetupGlobal007E9860;

	record->bfmeBegin();

	record->m_bfmeTag = 0x61636374;					// 'acct'

	record->bfmeWrite(TheBfmeSetupFirstText, value);
	record->bfmeWrite(TheBfmeSetupSecondText007E9860, second);
}
