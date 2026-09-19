// A flag-gated unlock that clears itself (trimmed from a five-body donor;
// the other four are declared-only here).
//
// The donor names the import bfmeDoDWH, but the retail body reaches the real
// mss32.dll!_AIL_unlock_mutex@0, so the declaration names the real import
// (MSVC adds the leading underscore for __stdcall).

extern "C" __declspec(dllimport) void __stdcall AIL_unlock_mutex();

struct BfmeThingDWH
{
	void bfmeGoDWH();
	char m_bfmeFlag;
};

// ?bfmeGoDWH@BfmeThingDWH@@QAEXXZ
void BfmeThingDWH::bfmeGoDWH()
{
	if (m_bfmeFlag)
	{
		AIL_unlock_mutex();
		m_bfmeFlag = 0;
	}
}

struct BfmeThingDWJ
{
	void bfmeGoDWJ();
	unsigned char m_bfmeHead[0x4e0c];
	char m_bfmeFlag;
};

void bfmeGoDWI();

char bfmeGoDWK(const char *s);

struct BfmeThingDWL
{
	void *bfmeGoDWL(void *a);
	void *m_bfmeVft;
};
