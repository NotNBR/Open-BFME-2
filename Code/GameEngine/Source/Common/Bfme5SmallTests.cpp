// Four more small ones (trimmed to the placed push body; the other three are
// declared-only here).

class Gen_0015A260
{
public:
	void bfmePush(int value);

private:
	int m_bfmeCount;					// +0x00
	int m_bfmeItems[6];					// +0x04
};

// ?bfmePush@Gen_0015A260@@QAEXH@Z
void Gen_0015A260::bfmePush(int value)
{
	int count = m_bfmeCount;

	if (count < 6)
	{
		m_bfmeItems[count] = value;

		++m_bfmeCount;
	}
}

class Gen_0015E750
{
public:
	bool bfmeIsAlone(void) const;
};

class Gen_001604C0
{
public:
	unsigned char bfmeHasRoom(void) const;
};

void __cdecl bfmeMarkDirty(int bits);
