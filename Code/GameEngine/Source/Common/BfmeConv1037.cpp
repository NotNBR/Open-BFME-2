// Wait on a handle and log on failure.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeConv1037.cpp); trimmed to the single T1
// body the sweep places. The donor declares bfmeWait1037 but retail reaches
// WaitForSingleObject, so the declaration is renamed to the real import.

class BfmeLog1037
{
public:
	virtual void bfmeV01037();
	virtual void bfmeSay1037(char *m);
};

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void *, unsigned long);
BfmeLog1037 *bfmeGetLog1037(void);
extern char g_bfmeMsg1037[];

class BfmeH1037
{
public:
	void bfmeGo1037H(void);

	char m_bfmePad[4];
	void *m_bfmeHandle;
};

void BfmeH1037::bfmeGo1037H(void)
{
	if (WaitForSingleObject(m_bfmeHandle, (unsigned long)-1) != 0)
		bfmeGetLog1037()->bfmeSay1037(g_bfmeMsg1037);
}
