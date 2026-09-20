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

class BfmeObjECI
{
public:
	virtual void bfmeW0(void);
	virtual void bfmeW1(void);
	virtual void bfmeW2(void);
	virtual void bfmeW3(void);
	virtual void bfmeW4(void);
	virtual void bfmeW5(void);
	virtual void bfmeW6(void);
	virtual void bfmeW7(void);
	virtual void bfmeW8(void);
	virtual void bfmeW9(void);
	virtual void bfmeW10(void);
	virtual void bfmeW11(void);
	virtual void bfmeW12(void);
	virtual void bfmeW13(void);
	virtual void bfmeW14(void);
	virtual void bfmeW15(void);
	virtual void bfmeW16(void);
	virtual void bfmeW17(void);
	virtual void bfmeW18(void);
	virtual void bfmeW19(void);
	virtual void bfmeW20(void);
	virtual void bfmeW21(void);
	virtual void bfmeW22(void);
	virtual void bfmeW23(void);
	virtual void bfmeW24(void);
	virtual void bfmeW25(void);
	virtual void bfmeW26(void);
	virtual void bfmeW27(void);
	virtual void bfmeW28(void);
	virtual void bfmeW29(void);
	virtual void bfmeW30(void);
	virtual void bfmeW31(void);
	virtual void bfmeW32(void);
	virtual void bfmeW33(void);
	virtual void bfmeW34(void);
	virtual void bfmeW35(void);
	virtual void bfmeW36(void);
	virtual void bfmeW37(void);
	virtual void bfmeW38(void);
	virtual void bfmeW39(void);
	virtual void bfmeW40(void);
	virtual void bfmeW41(void);
	virtual void bfmeW42(void);
	virtual void bfmeW43(void);
	virtual void bfmeW44(void);
	virtual void bfmeW45(void);
	virtual void bfmeW46(void);
	virtual void bfmeW47(void);
	virtual void bfmeW48(void);
	virtual void bfmeW49(void);
	virtual void bfmeW50(void);
	virtual void bfmeW51(void);
	virtual void bfmeW52(void);
	virtual void bfmeW53(void);
	virtual bool bfmeAsk54ECI(void);
};

extern BfmeObjECI *g_bfmeObjECI;

// ?bfmeGoECI@@YA_NXZ
// Retail tail-jmps vtable slot 54; the BFME1 class stops at slot 46,
// so BFME2 grew eight convention virtuals ahead of the ask.
bool bfmeGoECI(void)
{
	BfmeObjECI *obj = g_bfmeObjECI;
	if (!obj)
		return false;
	return obj->bfmeAsk54ECI();
}
