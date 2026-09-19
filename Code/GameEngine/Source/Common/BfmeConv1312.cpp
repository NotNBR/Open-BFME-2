// BfmeThingTFC::bfmeGoTFC, retail 0x0066D710 (26B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv1312.cpp
// (BFME1 0x008013C0). Only the placed go is defined here; the donor's
// TFA/TFB/TFD helpers stay out, so the unmatched-definition gate passes.
// Retail runs virtual slot 20 (bfmeStartTFC), then issues the sink call with
// this = m_bfmeSink(+4), pushing m_bfmeFirst(+8) before m_bfmeSecond(+0xC),
// through the single pinned call site.

class BfmeSinkTFC
{
public:
	void bfmeUseTFC(void *a, void *b);
};

class BfmeThingTFC
{
public:
	virtual void bfmeV0TFC() = 0;
	virtual void bfmeV1TFC() = 0;
	virtual void bfmeV2TFC() = 0;
	virtual void bfmeV3TFC() = 0;
	virtual void bfmeV4TFC() = 0;
	virtual void bfmeV5TFC() = 0;
	virtual void bfmeV6TFC() = 0;
	virtual void bfmeV7TFC() = 0;
	virtual void bfmeV8TFC() = 0;
	virtual void bfmeV9TFC() = 0;
	virtual void bfmeV10TFC() = 0;
	virtual void bfmeV11TFC() = 0;
	virtual void bfmeV12TFC() = 0;
	virtual void bfmeV13TFC() = 0;
	virtual void bfmeV14TFC() = 0;
	virtual void bfmeV15TFC() = 0;
	virtual void bfmeV16TFC() = 0;
	virtual void bfmeV17TFC() = 0;
	virtual void bfmeV18TFC() = 0;
	virtual void bfmeV19TFC() = 0;
	virtual void bfmeStartTFC() = 0;
	void bfmeGoTFC();
	BfmeSinkTFC *m_bfmeSink;
	void *m_bfmeFirst;
	void *m_bfmeSecond;
};

// ?bfmeGoTFC@BfmeThingTFC@@QAEXXZ, retail 0x0066D710 (26B).
void BfmeThingTFC::bfmeGoTFC()
{
	bfmeStartTFC();
	m_bfmeSink->bfmeUseTFC(m_bfmeSecond, m_bfmeFirst);
}
