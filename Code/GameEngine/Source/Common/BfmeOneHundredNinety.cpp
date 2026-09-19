// A count handed out as the record is emptied (trimmed from a four-errand
// donor; the other three are declared-only here).

class BfmeTargetDZ
{
public:
	virtual void bfmeGoDZ(int how) = 0;
	virtual void bfmeSpare001DZ(void) = 0;
	virtual void bfmeSpare002DZ(void) = 0;
	virtual void bfmeSpare003DZ(void) = 0;
	virtual void bfmeSpare004DZ(void) = 0;
	virtual void bfmeTellDZ(void *what) = 0;
};

class BfmeThingDZ
{
public:
	void bfmeDropDZ(void *what);
};

class BfmeTargetEA
{
public:
	virtual void bfmeDoEA(int how) = 0;
};

class BfmeThingEA
{
public:
	void bfmeDropEA(int which);
};


class BfmeThingEC
{
public:
	virtual void bfmeSpare000EC(void) = 0;
	virtual void bfmeSpare001EC(void) = 0;
	virtual void bfmeDoEC(void) = 0;

	int bfmeTakeEC(int *out);

private:
	unsigned char m_bfmeHead[0x10];		// 0x04
	int m_bfmeFirst;			// 0x14
	int m_bfmeCount;			// 0x18
	int m_bfmeThird;			// 0x1c
	int m_bfmeFourth;			// 0x20
};

// ?bfmeTakeEC@BfmeThingEC@@QAEHPAH@Z
int BfmeThingEC::bfmeTakeEC(int *out)
{
	*out = m_bfmeCount;

	int keep = m_bfmeFirst;

	m_bfmeFourth = 0;
	m_bfmeThird = 0;
	m_bfmeCount = 0;
	m_bfmeFirst = 0;

	bfmeDoEC();

	return keep;
}


class BfmeMakerEE
{
public:
	virtual void bfmeSpare000EE(void) = 0;
	virtual unsigned char bfmeAskEE(void) = 0;
};

struct BfmeOtherEE
{
	unsigned char m_bfmeHead[0x204];	// 0x000
	BfmeMakerEE *m_bfmeMaker;		// 0x204
};

struct BfmeOwnerEE
{
	unsigned char m_bfmeHead[0x10];		// 0x00
	BfmeOtherEE *m_bfmeOther;		// 0x10
};

struct BfmeThingEE
{
	unsigned char m_bfmeHead[0x1c];		// 0x00
	BfmeOwnerEE *m_bfmeOwner;		// 0x1c
};

unsigned char bfmeAskEE(BfmeThingEE *thing);
