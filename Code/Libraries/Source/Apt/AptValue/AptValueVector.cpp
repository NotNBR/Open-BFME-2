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

class Rva006DB160
{
public:
	void *allocBlock(int blockSize);
};

// Pool allocator instance at 0x00E176E8 (same global the string
// Reserve path uses; DIR32 sites auto-patch from retail at verify).
extern Rva006DB160 *g_aptPoolAllocator; // 0x00E176E8

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
	static void *Allocate(int size);
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

// ??0AptValueNameEntry@@QAE@XZ, retail 0x006CC000 (19B). Default entry
// constructor: resets the name through the rowed EAStringC clear and
// zeroes the value. Retail leaves the owning vector's array pointer to
// the caller; array construction drives this body per element through
// the 0x00629512 helper, which is why it also serves as the element
// initializer callback.
AptValueNameEntry::AptValueNameEntry()
{
	m_name.clear();
	m_value = 0;
}

// ?GetData@AptValueVector@@QAEPAPAPAVAptValue@@XZ, retail 0x006CBFD0 (4B).
// Returns the address of the element pointer array so callers can reseat
// it; the bare lea eax,[ecx+8] shape carries no call or data references.
AptValue ***AptValueVector::GetData()
{
	return &m_data;
}

// ?Allocate@AptValueVector@@SAPAXH@Z, retail 0x006CC020 (17B). Pool
// allocation entry: forwards the byte size to the global Apt pool
// allocator instance. Static (no this use); the global load and the
// allocator call both resolve as relocs at verify time.
void *AptValueVector::Allocate(int size)
{
	return g_aptPoolAllocator->allocBlock(size);
}
