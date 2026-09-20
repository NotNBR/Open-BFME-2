void __cdecl bfmeDelArrVJS(void *place);

extern int g_bfmeVftAVJS[];
extern int g_bfmeVftBVJS[];

class BfmeThingVJS
{
public:
	void bfmeClearVJS(void);
	void *m_bfmeVfptr;
	int m_bfme04;
	int m_bfme08;
	void *m_bfme0c;
	int m_bfme10;
	void *m_bfme14;
	void *m_bfme18;
};

// ?bfmeClearVJS@BfmeThingVJS@@QAEXXZ
void BfmeThingVJS::bfmeClearVJS()
{
	m_bfmeVfptr = g_bfmeVftAVJS;
	m_bfme08 = 0;
	if (m_bfme0c)
	{
		bfmeDelArrVJS(m_bfme0c);
		m_bfme0c = 0;
	}
	m_bfme10 = 0;
	if (m_bfme14)
	{
		bfmeDelArrVJS(m_bfme14);
		m_bfme14 = 0;
	}
	m_bfmeVfptr = g_bfmeVftBVJS;
	if (m_bfme18)
		m_bfme18 = 0;
}
