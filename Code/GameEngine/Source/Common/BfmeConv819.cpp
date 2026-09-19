// Open-BFME5 conversions (trimmed to the placed EMC body; the other seven are
// declared-only here).

struct BfmeSubEMA;
struct BfmeThingEMA;
void bfmeGoEMA(void *a, BfmeThingEMA *b);

struct BfmeThingEMB;
void bfmeGoEMB(BfmeThingEMB *a, void *b);

class BfmeObjEMC
{
public:
	void bfmeCallEMC(void *x, void *b, void *c);
};

extern void *g_bfmeXEMC;

// ?bfmeGoEMC@@YGXPAVBfmeObjEMC@@PAX1@Z
void __stdcall bfmeGoEMC(BfmeObjEMC *o, void *b, void *c)
{
	o->bfmeCallEMC(g_bfmeXEMC, b, c);
}

bool bfmeGoEMEa(void *a);
void *bfmeGoEMEb(void *a);
void __stdcall bfmeGoEMGa(void *a);
void __stdcall bfmeGoEMGb(void *a);

class BfmeThingEMH
{
public:
	void bfmeGoEMHa(void);
	void bfmeGoEMHb(void);
};
