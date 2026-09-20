// Open-BFME5 conversions.
//
// Trimmed port of Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv1082.cpp:
// the B/C shutdown pair only. The donor's A sibling (BfmeQ1082::bfmeGo1082A)
// is unserved so it stays out (the gate refuses unrowed definitions).
//
// WHAT THE BODIES ARE. Global-slot shutdown helpers: each one walks four
// BfmeS1082 slots, invoking virtual slot 1 on every live entry and clearing
// it. B owns slots 0-3, C owns slots 4-7; the eight globals sit contiguous
// (4-byte stride) in both images, in the same order, so B is the lower
// retail body (0x006F1DF0) and C the higher (0x006F25E0).

class BfmeS1082
{
public:
	virtual void bfmeSlot1082S_0(void);
	virtual void bfmeSlot1082S_1(void);
};

extern BfmeS1082 *g_bfmeS1082_0;
extern BfmeS1082 *g_bfmeS1082_1;
extern BfmeS1082 *g_bfmeS1082_2;
extern BfmeS1082 *g_bfmeS1082_3;
extern BfmeS1082 *g_bfmeS1082_4;
extern BfmeS1082 *g_bfmeS1082_5;
extern BfmeS1082 *g_bfmeS1082_6;
extern BfmeS1082 *g_bfmeS1082_7;

void bfmeGo1082B(void)
{
	if (g_bfmeS1082_0) {
		g_bfmeS1082_0->bfmeSlot1082S_1();
		g_bfmeS1082_0 = 0;
	}
	if (g_bfmeS1082_1) {
		g_bfmeS1082_1->bfmeSlot1082S_1();
		g_bfmeS1082_1 = 0;
	}
	if (g_bfmeS1082_2) {
		g_bfmeS1082_2->bfmeSlot1082S_1();
		g_bfmeS1082_2 = 0;
	}
	if (g_bfmeS1082_3) {
		g_bfmeS1082_3->bfmeSlot1082S_1();
		g_bfmeS1082_3 = 0;
	}
}

void bfmeGo1082C(void)
{
	if (g_bfmeS1082_4) {
		g_bfmeS1082_4->bfmeSlot1082S_1();
		g_bfmeS1082_4 = 0;
	}
	if (g_bfmeS1082_5) {
		g_bfmeS1082_5->bfmeSlot1082S_1();
		g_bfmeS1082_5 = 0;
	}
	if (g_bfmeS1082_6) {
		g_bfmeS1082_6->bfmeSlot1082S_1();
		g_bfmeS1082_6 = 0;
	}
	if (g_bfmeS1082_7) {
		g_bfmeS1082_7->bfmeSlot1082S_1();
		g_bfmeS1082_7 = 0;
	}
}
