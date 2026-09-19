// A two-member swap through a helper.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/Bfme5TinyTwentyFive.cpp); trimmed to the
// single T1 body the sweep places.

class Gen_003390D0
{
public:
	void bfmeSwap(Gen_003390D0 *other);

private:
	int m_bfmeHead;						// +0x00
	int m_bfmeFirst;					// +0x04
	int m_bfmeSecond;					// +0x08
};

// Each pair goes through the helper by address, which is what stops the
// second load being hoisted over the first store.
inline void bfmeSwapInt(int *first, int *second)
{
	int value = *first;

	*first = *second;
	*second = value;
}

// ?bfmeSwap@Gen_003390D0@@QAEXPAV1@@Z
void Gen_003390D0::bfmeSwap(Gen_003390D0 *other)
{
	bfmeSwapInt(&m_bfmeFirst, &other->m_bfmeFirst);
	bfmeSwapInt(&m_bfmeSecond, &other->m_bfmeSecond);
}
