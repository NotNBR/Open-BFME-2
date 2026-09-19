// A tag test: three markers and something other than a blank behind them.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/Bfme5Ninety.cpp); trimmed to the single T1
// body the sweep places.

extern "C" unsigned int strlen(const char *text);
#pragma intrinsic(strlen)

// Three markers and something other than a blank behind them.
int __fastcall bfmeIsTag(int unused, const char *text)
{
	if (text == 0)
		return 0;
	if (strlen(text) < 4)
		return 0;

	if (text[0] != '@' || text[1] != '@' || text[2] != '@' || text[3] == ' ')
		return 0;
	return 1;
}
