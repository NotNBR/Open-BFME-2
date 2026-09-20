class BfmeS1019
{
public:
	virtual void bfmeVS01019(void);
	virtual void bfmeVS11019(void);
	virtual void *bfmeDoB1019(int a, int b);
	virtual void bfmeDoC1019(int a, int b);
};

extern BfmeS1019 *g_bfmeS1019;
extern char g_bfmeName1019[];
void bfmeInit1019(char *name);

// ?bfmeGo1019C@@YAXH@Z
void bfmeGo1019C(int a)
{
	if (g_bfmeS1019 == 0)
		bfmeInit1019(g_bfmeName1019);

	g_bfmeS1019->bfmeDoC1019(a, 0);
}
