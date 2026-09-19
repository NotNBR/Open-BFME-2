// A handle closed and cleared (trimmed from a three-body donor; the other
// two are declared-only here).
//
// The donor names the import bfmeCloseDWE, but the body reaches the real
// DeleteObject, so the declaration names the real import.

typedef void *HGDIOBJ;

extern "C" __declspec(dllimport) int __stdcall DeleteObject(HGDIOBJ object);

struct BfmeThingDWE
{
	void bfmeGoDWE();
	unsigned char m_bfmeHead[0x48];
	void *m_bfmeH;
};

// ?bfmeGoDWE@BfmeThingDWE@@QAEXXZ
void BfmeThingDWE::bfmeGoDWE()
{
	if (m_bfmeH)
	{
		DeleteObject(m_bfmeH);
		m_bfmeH = 0;
	}
}

struct BfmeNodeDWF
{
	unsigned char m_bfmeHead[4];
	BfmeNodeDWF *m_bfmeNext;
};

struct BfmeThingDWF
{
	void bfmeGoDWF();
	BfmeNodeDWF *m_bfmeHead;
};

void bfmeGoDWG();
