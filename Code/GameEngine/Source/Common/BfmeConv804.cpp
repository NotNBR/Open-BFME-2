struct BfmeObjECF;

struct BfmeVtblECF
{
	void (__stdcall *m_bfmeF0)(BfmeObjECF *obj);
	void (__stdcall *m_bfmeF1)(BfmeObjECF *obj);
	void (__stdcall *m_bfmeF2)(BfmeObjECF *obj);
};

struct BfmeObjECF
{
	BfmeVtblECF *m_bfmeVtbl;
};

extern BfmeObjECF *g_bfmeObjECF;

// ?bfmeGoECF@@YAXXZ
void bfmeGoECF(void)
{
	BfmeObjECF *obj = g_bfmeObjECF;
	if (obj)
		obj->m_bfmeVtbl->m_bfmeF2(obj);
}
