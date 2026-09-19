// Six more tiny ones (trimmed to the placed swap body; the other five are
// declared-only here).

class BfmeHolderBQ;
extern BfmeHolderBQ *g_bfmeHolderBQ;
void __stdcall bfmeSetOther(unsigned char value);

inline void bfmeSwapInt(int &left, int &right)
{
	int value = left;

	left = right;
	right = value;
}

class Gen_00339020
{
public:
	void bfmeSwap(Gen_00339020 *other);

private:
	int m_bfmeTag;						// +0x00
	int m_bfmeValue;					// +0x04
};

// ?bfmeSwap@Gen_00339020@@QAEXPAV1@@Z
void Gen_00339020::bfmeSwap(Gen_00339020 *other)
{
	bfmeSwapInt(m_bfmeValue, other->m_bfmeValue);
}

class Gen_0037A810
{
public:
	int bfmeFirstIsPositive(int value) const;
	int bfmeSecondIsPositive(int value) const;
};

class Gen_0039B020
{
public:
	unsigned char bfmeFlag(void) const;
};

void __cdecl bfmeCopyTable(void);
