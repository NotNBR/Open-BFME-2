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
