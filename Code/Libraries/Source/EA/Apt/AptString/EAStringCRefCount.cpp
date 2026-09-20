// cl: /O2 /DNDEBUG /MD
// ?FreeData@EAStringC@@SAXPAVStringDataC@1@@Z, retail 0x006D2EB0 (118B).
// EA refcounted-string release worker: asserts the data refcount is live,
// drops it, and returns while shared; the last release frees the block
// through the sized deallocator at 0x006DB270 unless it is the immortal
// empty singleton at 0x00DDC020 (which trips the empty assertion).
// Assertion strings name .\string\EAString.inl; the empty-singleton
// evidence is the retail "(char *)pData != s_EmptyInternalData" message.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)

class Rva006DB270
{
public:
	void freeBlock(void *block, int blockSize);
};

extern Rva006DB270 *g_pChainBlockAllocator; // 0x00E176E8

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

	static void FreeData(StringDataC *data);

	StringDataC *m_pData;

public:
	EAStringC(const EAStringC &other);
	~EAStringC();
};

// Retail empty singleton at 0x00DDC020. The linker never sees this TU's
// reloc target; DIR32 sites auto-patch from retail at verify time, the
// same idiom as g_pChainBlockAllocator above.
extern EAStringC::StringDataC g_eaEmptyStringData; // 0x00DDC020

// ?FreeData@EAStringC@@SAXPAVStringDataC@1@@Z
void EAStringC::FreeData(StringDataC *data)
{
	if (!(data->m_uRefCount >= 1)) {
		g_bfmeAptAssertAtE17734("pData->m_uRefCount >= 1", ".\\string\\EAString.inl", 0xF9);
		if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
	}
	if (--data->m_uRefCount != 0)
		return;
	if (data == &g_eaEmptyStringData) {
		g_bfmeAptAssertAtE17734("(char *)pData != s_EmptyInternalData", ".\\string\\EAString.inl", 0xFD);
		if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
	}
	g_pChainBlockAllocator->freeBlock(data, (int)(data->m_uMaxSize + 9));
}

// ??1EAStringC@@QAE@XZ, retail 0x006D3010 (10B). Scalar destructor: releases
// the shared data through FreeData. Retail is the bare 10-byte
// load-push-call-cleanup shape with no vtable work (EAStringC is a
// value class); the release call resolves via the FreeData row.
EAStringC::~EAStringC()
{
	FreeData(m_pData);
}

// ??0EAStringC@@QAE@ABV0@@Z, retail 0x006D2FC0 (70B). Copy constructor:
// shares the source data after validating its refcount, then takes its
// own reference. The empty singleton skips validation but still AddRefs.
EAStringC::EAStringC(const EAStringC &other)
{
	StringDataC *otherData = other.m_pData;
	m_pData = otherData;
	if (otherData != &g_eaEmptyStringData) {
		if (!(otherData->m_uRefCount <= 0xFFFE)) {
			g_bfmeAptAssertAtE17734("m_pData->m_uRefCount <= 0xfffe", ".\\string\\EAString.inl", 0xE1);
			if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
		}
	}
	m_pData->m_uRefCount++;
}
