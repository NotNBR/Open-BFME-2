// bfmeAssignVGO, retail 0x006CDB10 (66B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv1355.cpp
// (BFME1 0x00892B90). Only the placed ref-counted assign is defined here;
// the donor's bfmeGoVGM viewport helper stays out (with it goes the donor's
// __ftol2 declaration), so the unmatched-definition gate passes. The Dec and
// Drop callees already resolve through the ledger; only the Inc pin is new.

unsigned __cdecl bfmeDecVGO(unsigned *p);
unsigned __cdecl bfmeIncVGO(unsigned *p);
void __cdecl bfmeDropVGO(void *p);

class BfmeRefVGO
{
public:
	BfmeRefVGO &bfmeAssignVGO(const BfmeRefVGO &o);
	unsigned *m_bfmeP;
};

// ?bfmeAssignVGO@BfmeRefVGO@@QAEAAV1@ABV1@@Z, retail 0x006CDB10 (66B).
BfmeRefVGO &BfmeRefVGO::bfmeAssignVGO(const BfmeRefVGO &o)
{
	if (&o != this)
	{
		if (m_bfmeP && bfmeDecVGO(m_bfmeP) == 0)
			bfmeDropVGO(m_bfmeP);
		m_bfmeP = o.m_bfmeP;
		if (m_bfmeP)
			bfmeIncVGO(m_bfmeP);
	}
	return *this;
}
