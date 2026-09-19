// Open-BFME5 conversions (trimmed to the placed 936B body; the other three
// are declared-only here).

void __stdcall bfmeElem936B(void *p);
void __stdcall bfmeVecDtor936B(void *p, unsigned int size, int count, void (__stdcall *dtor)(void *));

class BfmeThing936B
{
public:
	void bfmeGo936B(void);
};

// ?bfmeGo936B@BfmeThing936B@@QAEXXZ
void BfmeThing936B::bfmeGo936B(void)
{
	bfmeVecDtor936B(this, 4, 0x80, bfmeElem936B);
}

class BfmeThing936F
{
public:
	void bfmeGo936F(void);
};

void bfmeGo936C(void);

class BfmeThing936G
{
public:
	BfmeThing936G *bfmeGo936G(void);
	void bfmeInit936G(void);
};

extern void *g_bfme936GlobG;

// ?bfmeGo936G@BfmeThing936G@@QAEPAV1@XZ, retail 0x00016AA0 (21B).
BfmeThing936G *BfmeThing936G::bfmeGo936G(void)
{
	if (!g_bfme936GlobG)
		bfmeInit936G();
	return this;
}
