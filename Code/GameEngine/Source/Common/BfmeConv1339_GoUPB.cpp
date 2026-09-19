// bfmeGoUPB: look a value up in the UPB table and format it.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeConv1339.cpp); trimmed to the single T2
// body the sweep places. Lives in its own TU because BfmeConv1339.cpp is
// already occupied by the landed GoUPC body.

extern char g_bfmeFmtUPB[];

void *bfmeFindUPB(void *table, void *a);
void bfmeFormatUPB(void *r, char *out, void *c, const char *fmt);

class BfmeThingUPB
{
public:
	char bfmeGoUPB(void *a, char *out, void *c);
	char m_bfmePad[0x10];
	void *m_bfmeTable;
};

char BfmeThingUPB::bfmeGoUPB(void *a, char *out, void *c)
{
	void *r = bfmeFindUPB(m_bfmeTable, a);
	if (!r) {
		*out = 0;
		return 0;
	}
	bfmeFormatUPB(r, out, c, g_bfmeFmtUPB);
	return 1;
}
