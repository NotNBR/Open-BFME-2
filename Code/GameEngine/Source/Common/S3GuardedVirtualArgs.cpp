// Four guarded virtual delegates that take arguments (trimmed to the placed
// 008F7B50 body; the other three are declared-only here).

class Gen_000C9510
{
public:
	void bfmeForward(void *a0);
};

class Gen_00382CC0
{
public:
	void bfmeForward(void *a0);
};

class Gen_0075B730
{
public:
	void bfmeForward(void *a0, void *a1);
};

class Gen_008F7B50Target
{
public:
	virtual void bfmeSlot0(void);
	virtual void bfmeSlot1(void);
	virtual void bfmeVirtual(void *a0);		// slot 2, vtable+0x08
};

class Gen_008F7B50
{
public:
	void bfmeForward(void *a0);

private:
	char m_bfmeHead[0x8];
	Gen_008F7B50Target *m_bfmeImpl;				// +0x8
};

// ?bfmeForward@Gen_008F7B50@@QAEXPAX@Z
void Gen_008F7B50::bfmeForward(void *a0)
{
	if (m_bfmeImpl)
		m_bfmeImpl->bfmeVirtual(a0);
}
