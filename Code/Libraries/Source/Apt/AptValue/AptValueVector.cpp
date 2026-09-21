// cl: /O2 /MD
// AptValueVector family: named Apt value containers from
// AptValue/AptValueVector.h. Retail assertion strings name that header
// and its mCurrentNum member. Element entries pair a shared EAStringC
// name with an integer value; the vector adds the element pointer array.
// EAStringC here is the minimal TU-local view the original needs: the
// copy and clear operations resolve via ledger rows while the trivial
// default constructor emits no retail body of its own.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;

class EAStringC
{
public:
	class StringDataC
	{
	public:
		unsigned short m_uRefCount;
		unsigned short m_uSize;
		unsigned short m_uMaxSize;
		unsigned short m_uHash;
	};

	StringDataC *m_pData;

public:
// ??0EAStringC@@QAE@XZ absent-from-retail
	EAStringC() {}
	EAStringC(const EAStringC &other);
	EAStringC &operator=(const EAStringC &other);
	EAStringC &clear();
};

class AptValue;

class AptValueNameEntry
{
public:
	AptValueNameEntry();
	AptValueNameEntry(const EAStringC &name, int value);

	EAStringC m_name;
	int m_value;
};

class AptValueVector
{
public:
	AptValue ***GetData();

	EAStringC m_name;
	int mCurrentNum;
	AptValue **m_data;
};

// ??0AptValueNameEntry@@QAE@ABVEAStringC@@H@Z, retail 0x006CBFE0 (26B).
// Named-value entry constructor: shares the name string through the
// rowed EAStringC copy constructor, then stores the integer value.
// The array pointer lives in the owning vector, so this body touches
// only the 8 bytes it owns.
AptValueNameEntry::AptValueNameEntry(const EAStringC &name, int value) :
	m_name(name),
	m_value(value)
{
}
