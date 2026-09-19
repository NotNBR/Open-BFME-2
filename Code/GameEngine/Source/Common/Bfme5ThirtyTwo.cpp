// A bounded element read, a colour built from a flag, and a constructor.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/Bfme5ThirtyTwo.cpp); trimmed to the three T1
// bodies the sweep places. The donor's sibling bfmeCurrent (under 16B) and
// bfmeLookup are declared, never defined.

class BfmeThingCX
{
public:
	int m_bfmeHead;						// +0x00
	unsigned short m_bfmeRefs;				// +0x04
};

class BfmeHandleCX
{
public:
	BfmeHandleCX(void)
	{
		m_bfmeThing = 0;
	}

	BfmeHandleCX(const BfmeHandleCX &other)
	{
		BfmeThingCX *thing = other.m_bfmeThing;

		m_bfmeThing = thing;

		if (thing)
			++thing->m_bfmeRefs;
	}

	~BfmeHandleCX(void)
	{
		if (m_bfmeThing)
			--m_bfmeThing->m_bfmeRefs;
	}

	BfmeThingCX *m_bfmeThing;				// +0x00
};

class BfmeSlotCZ
{
public:
	int *m_bfmePointer;					// +0x00
	int m_bfmeTag;						// +0x04
};

class BfmeVecCZ
{
public:
	BfmeSlotCZ *m_bfmeStart;				// +0x00
	int m_bfmeCount;					// +0x04
};

// The out-of-range slot stays null and is read anyway, which is what puts the
// load in both paths.
// ?bfmeAt@@YGPAHPAVBfmeVecCZ@@H@Z
int * __stdcall bfmeAt(BfmeVecCZ *vector, int index)
{
	BfmeSlotCZ *slot;

	if (index >= vector->m_bfmeCount)
		slot = 0;
	else
		slot = vector->m_bfmeStart + index;

	return slot->m_bfmePointer;
}

class BfmeThingCZ
{
public:
	int m_bfmeHead[10];					// +0x00
	int m_bfmeColor;					// +0x28
};

// ?bfmeColor@@YGHPBVBfmeThingCZ@@H_N@Z
int __stdcall bfmeColor(const BfmeThingCZ *thing, int unused, bool bright)
{
	int color = thing->m_bfmeColor & 0xFFFFFF;

	color = color | 0x80000000;

	if (bright)
		color = color | 0x30000000;

	return color;
}

extern int g_bfmeVtableCZ[];					// retail 0x0112D210

class Gen_0081E480
{
public:
	Gen_0081E480(int first, int second);

private:
	int *m_bfmeVtable;					// +0x00
	int m_bfmeCount;					// +0x04
	int m_bfmeFirst;					// +0x08
	int m_bfmeSecond;					// +0x0C
	int m_bfmeFlags;					// +0x10
};

// ??0Gen_0081E480@@QAE@HH@Z
Gen_0081E480::Gen_0081E480(int first, int second)
{
	m_bfmeVtable = g_bfmeVtableCZ;
	m_bfmeCount = 0;
	m_bfmeFirst = first;
	m_bfmeSecond = second;
	m_bfmeFlags = 0;
}
