// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// BFME1 donor: reference/open-bfme-1/Code/GameEngine/Source/Common/Rva000B56F0SelectStorage.cpp
// Repair: retail tests the flag at +0xC4 (not the donor's +0x98) and selects
// between +0xC8 and +8, so the inline store runs 0xBC here, not 0x90. The
// flag/external/inline semantics are unchanged.
// Single pick: the same 19B also matches the Rva000B5A10BitSelectPointer
// donor shape; this TU claims the address once, under this name.

struct Rva000B56F0Object
{
	unsigned char m_prefix[8];
	unsigned char m_inlineStorage[0xBC];
	unsigned int m_flags;
	unsigned char m_externalStorage[1];

	void *selectStorage();
};

void *Rva000B56F0Object::selectStorage()
{
	void *result = m_externalStorage;
	if ((m_flags & 1) == 0) {
		result = m_inlineStorage;
	}
	return result;
}
