// A global list lookup.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/Bfme5NinetyTwo.cpp); trimmed to the single T1
// body the sweep places.

class BfmeRecJD
{
public:
	int m_bfmeWords[7];
};

extern BfmeRecJD *g_bfmeBeginJD;
extern BfmeRecJD *g_bfmeEndJD;

BfmeRecJD * __stdcall bfmeSlotAt(int index)
{
	if (index >= 0 && index < (int)(g_bfmeEndJD - g_bfmeBeginJD))
		return g_bfmeBeginJD + index;
	return 0;
}
