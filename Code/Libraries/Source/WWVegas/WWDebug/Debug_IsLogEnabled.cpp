// cl: /DNDEBUG /MD /EHsc
//
// Debug::isLogEnabled, retail 0x0003B5D0 (109 bytes).
// Ported from Open-BFME-1 WWDebug/Debug_isLogEnabled.cpp: hash lookup with
// miss-allocate via AddFrameEntry(type 4, address as name), lazy
// UpdateFrameStatus when Unknown, true for statuses 2 or 3.
// Dedicated TU with frame pointer (retail has ebp frame) so the matched
// GetFrameEntry TU keeps its frameless codegen.

extern void *DebugAllocMemory(unsigned int size);

#pragma optimize("y", off)

class Debug
{
private:
	struct FrameHashEntry
	{
		FrameHashEntry *next;
		unsigned int frameAddr;
		unsigned int frameType;
		const char *fileOrGroup;
		int line;
		int hits;
		int status;
	};

	enum { FRAME_HASH_SIZE = 10007 };

	char m_prefix[0x18];
	FrameHashEntry *frameHash[FRAME_HASH_SIZE];

	FrameHashEntry *AddFrameEntry(unsigned int addr, unsigned int type,
		const char *fileOrGroup, int line);
	void UpdateFrameStatus(FrameHashEntry &entry);

	__forceinline FrameHashEntry *LookupFrame(unsigned int addr)
	{
		for (FrameHashEntry *entry = frameHash[addr % FRAME_HASH_SIZE]; entry;
			entry = entry->next)
		{
			if (entry->frameAddr == addr)
				return entry;
		}
		return 0;
	}

public:
	bool isLogEnabled(unsigned int addr);
};

// ?isLogEnabled@Debug@@QAE_NI@Z
bool Debug::isLogEnabled(unsigned int addr)
{
	FrameHashEntry *entry = LookupFrame(addr);
	if (!entry)
		entry = AddFrameEntry(addr, 4, (const char *)addr, 0);
	if (entry->status == 0)
		UpdateFrameStatus(*entry);
	return entry->status == 2 || entry->status == 3;
}
