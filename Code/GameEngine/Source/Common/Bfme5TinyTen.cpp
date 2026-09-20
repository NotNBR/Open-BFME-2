// A destructor that unhooks itself from a global head.
//
// Trimmed from the Open-BFME-1 Bfme5TinyTen.cpp donor (their retail 0x004902A0,
// same 23 bytes): the file's other two bodies (bfmeIsClear, bfmeBit) have no
// unique placement in game.dat, so only this one is claimed here.
//
// game.dat keeps the list head at 0x00E01E1C (BFME1: 0x012F3350), read from the
// two DIR32 slots of the retail body.

class Gen_004902A0;

#define g_bfmeHeadCA (*(Gen_004902A0 **)0x00E01E1C)

class Gen_004902A0
{
public:
	virtual ~Gen_004902A0(void);				// slot +0x00

	Gen_004902A0 *m_bfmeNext;				// +0x04
};

// ??1Gen_004902A0@@UAE@XZ
Gen_004902A0::~Gen_004902A0(void)
{
	if (g_bfmeHeadCA == this)
		g_bfmeHeadCA = m_bfmeNext;
}
