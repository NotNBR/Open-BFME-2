// Three guarded setters.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/S3GuardedSetters.cpp); trimmed to the three
// T1 bodies the sweep places.

typedef bool Bool;

struct Gen_00750550Impl
{
	char m_bfmeHead[0x4];
	Bool m_bfmeField;						// +0x4
};

class Gen_00750550
{
public:
	void bfmeSet(Bool value);

private:
	char m_bfmeHead[0x44];
	Gen_00750550Impl *m_bfmeImpl;					// +0x44
};

struct Gen_00750570Impl
{
	char m_bfmeHead[0x5];
	Bool m_bfmeField;						// +0x5
};

class Gen_00750570
{
public:
	void bfmeSet(Bool value);

private:
	char m_bfmeHead[0x44];
	Gen_00750570Impl *m_bfmeImpl;					// +0x44
};

struct Gen_0092D450Impl
{
	char m_bfmeHead[0x1C];
	Bool m_bfmeField;						// +0x1C
};

class Gen_0092D450
{
public:
	void bfmeSet(Bool value);

private:
	char m_bfmeHead[0xC4];
	Gen_0092D450Impl *m_bfmeImpl;					// +0xC4
};

// ?bfmeSet@Gen_00750550@@QAEX_N@Z
void Gen_00750550::bfmeSet(Bool value)
{
	if (m_bfmeImpl)
		m_bfmeImpl->m_bfmeField = value;
}

// ?bfmeSet@Gen_00750570@@QAEX_N@Z
void Gen_00750570::bfmeSet(Bool value)
{
	if (m_bfmeImpl)
		m_bfmeImpl->m_bfmeField = value;
}

// ?bfmeSet@Gen_0092D450@@QAEX_N@Z
void Gen_0092D450::bfmeSet(Bool value)
{
	if (m_bfmeImpl)
		m_bfmeImpl->m_bfmeField = value;
}
