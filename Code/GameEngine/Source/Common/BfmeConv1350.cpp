// Open-BFME5 conversions, trimmed to the bfmeClearVDB unit.

void bfmeFreeVDB(void *p);

struct BfmeNodeVDB
{
	char m_bfmePad[0x30];
	BfmeNodeVDB *m_bfmeNext;
};

class BfmeThingVDB
{
public:
	void bfmeClearVDB();
	BfmeNodeVDB *m_bfmeTable[0x493];
	BfmeNodeVDB *m_bfmeExtra;
};

void BfmeThingVDB::bfmeClearVDB()
{
	for (unsigned i = 0; i < 0x493; ++i) {
		BfmeNodeVDB *p = m_bfmeTable[i];
		while (p) {
			BfmeNodeVDB *next = p->m_bfmeNext;
			bfmeFreeVDB(p);
			p = next;
		}
	}
	BfmeNodeVDB *p = m_bfmeExtra;
	while (p) {
		BfmeNodeVDB *next = p->m_bfmeNext;
		bfmeFreeVDB(p);
		p = next;
	}
}
