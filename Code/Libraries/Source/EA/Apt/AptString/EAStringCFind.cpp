// cl: /O2 /DNDEBUG /MD
// ?Find@EAStringC@@QAEHDH@Z, retail 0x006D38E0 (62B). Ported from Open-BFME-1
// Code/Libraries/Source/EA/Apt/AptString/EAStringCFind.cpp (BFME1 0x0089E230).
// Trimmed to the placed char-find body; the string-find overload is
// declared-only here. Callee strchr resolves via the existing ledger pin.

extern "C" char *__cdecl strchr(const char *, int);

class EAStringC
{
	class StringDataC
	{
	public:
		unsigned short m_uRefCount;
		unsigned short m_uSize;
		unsigned short m_uMaxSize;
		unsigned short m_uHash;
	};

	StringDataC *m_pData;

	char *GetInternalBuffer() const
	{
		return reinterpret_cast<char *>(m_pData) + sizeof(StringDataC);
	}

public:
	int Find(const char *s, int start);
	int Find(char c, int start);
};

// ?Find@EAStringC@@QAEHDH@Z
int EAStringC::Find(char c, int start)
{
	if (start >= (int)m_pData->m_uSize)
		return -1;
	if (start < 0)
		start = 0;
	char *found = strchr(GetInternalBuffer() + start, c);
	if (found)
		return found - GetInternalBuffer();
	return -1;
}
