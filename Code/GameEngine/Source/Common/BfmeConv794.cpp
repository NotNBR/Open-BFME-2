// A sub-object call followed by its drop (trimmed from a five-body donor;
// the other four are declared-only here).
//
// The T2 body needs one ledger pin (bfmeCallDXH at 0x0070E5D0); the donor's
// dllimport names (bfmeCloseDXK/bfmeCvtDXI) belong to the skipped DXK/DXI
// bodies, so this TU declares no imports.

class BfmeSubDXH
{
	unsigned char m_bfmeHead[4];
};

extern void (__cdecl *g_bfmeDropDXH)(BfmeSubDXH *what);
void __cdecl bfmeCallDXH(BfmeSubDXH *a, void *b, BfmeSubDXH *c);

struct BfmeThingDXH
{
	void bfmeGoDXH(void *a);
	unsigned char m_bfmeHead[0x20];
	BfmeSubDXH m_bfmeSub;
};

// ?bfmeGoDXH@BfmeThingDXH@@QAEXPAX@Z
void BfmeThingDXH::bfmeGoDXH(void *a)
{
	BfmeSubDXH *s = &m_bfmeSub;
	bfmeCallDXH(s, a, s);
	g_bfmeDropDXH(s);
}

struct BfmeThingDXG
{
	void *bfmeGoDXG(unsigned char flags);
	void bfmeDtorDXG();
};

void bfmeGoDXI(void *a);

struct BfmeThingDXK
{
	void bfmeGoDXKa();
	void bfmeGoDXKb();
	void *m_bfmeH;
	void *m_bfmeP;
};
