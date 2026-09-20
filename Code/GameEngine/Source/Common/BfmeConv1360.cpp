class BfmeMsgVHC
{
public:
	void *bfmeGetVHC(void *key, void *def);
	char bfmeGetStrVHC(void *key, char *buf, int size);
};

extern int g_bfmeKeyAVHC;
extern int g_bfmeKeyBVHC;

class BfmeThingVHC
{
public:
	BfmeThingVHC *bfmeInitVHC(BfmeMsgVHC *msg);
	void bfmeBaseVHC(BfmeMsgVHC *msg);
	int m_bfme00;
	int m_bfme04;
	void *m_bfme08;
	void *m_bfme0c;
};

// ?bfmeInitVHC@BfmeThingVHC@@QAEPAV1@PAVBfmeMsgVHC@@@Z
BfmeThingVHC *BfmeThingVHC::bfmeInitVHC(BfmeMsgVHC *msg)
{
	bfmeBaseVHC(msg);
	m_bfme08 = msg->bfmeGetVHC(&g_bfmeKeyAVHC, 0);
	m_bfme0c = msg->bfmeGetVHC(&g_bfmeKeyBVHC, 0);
	return this;
}
