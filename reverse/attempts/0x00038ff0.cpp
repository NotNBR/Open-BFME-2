// ?AddFrameEntry@Debug@@AAEPAUFrameHashEntry@1@IIPBDH@Z
// partial score=0.75 date=2026-09-14
// cl: /DNDEBUG /MD /EHsc /Oy-
//
// Debug::AddFrameEntry, retail 0x00038FF0 (223 bytes).
// Ported from the Zero Hour debug_debug.cpp layout with one BFME2 repair:
// the non-log filename path also folds forward slashes, so the trailing-name
// scan checks both '\\' and '/' in a single pass (retail tests al against
// 0x5C then 0x2F). Table at +0x18, pool pointer at +0x9C74 and count at
// +0x9C78; DebugAllocMemory comes from its matched row, AddLogGroup rides
// the vtable at slot 45 (0xB4).
// Dedicated TU so Debug_GetFrameEntry.cpp keeps its matched GetFrameEntry:
// defining this beside that caller would let MSVC see the callee and change
// the caller's register save set (docs/matching.md pattern five).

#define NULL 0

class Debug
{
public:
	virtual void _M_slot_00();
	virtual void _M_slot_01();
	virtual void _M_slot_02();
	virtual void _M_slot_03();
	virtual void _M_slot_04();
	virtual void _M_slot_05();
	virtual void _M_slot_06();
	virtual void _M_slot_07();
	virtual void _M_slot_08();
	virtual void _M_slot_09();
	virtual void _M_slot_0a();
	virtual void _M_slot_0b();
	virtual void _M_slot_0c();
	virtual void _M_slot_0d();
	virtual void _M_slot_0e();
	virtual void _M_slot_0f();
	virtual void _M_slot_10();
	virtual void _M_slot_11();
	virtual void _M_slot_12();
	virtual void _M_slot_13();
	virtual void _M_slot_14();
	virtual void _M_slot_15();
	virtual void _M_slot_16();
	virtual void _M_slot_17();
	virtual void _M_slot_18();
	virtual void _M_slot_19();
	virtual void _M_slot_1a();
	virtual void _M_slot_1b();
	virtual void _M_slot_1c();
	virtual void _M_slot_1d();
	virtual void _M_slot_1e();
	virtual void _M_slot_1f();
	virtual void _M_slot_20();
	virtual void _M_slot_21();
	virtual void _M_slot_22();
	virtual void _M_slot_23();
	virtual void _M_slot_24();
	virtual void _M_slot_25();
	virtual void _M_slot_26();
	virtual void _M_slot_27();
	virtual void _M_slot_28();
	virtual void _M_slot_29();
	virtual void _M_slot_2a();
	virtual void _M_slot_2b();
	virtual void _M_slot_2c();
	virtual const char *AddLogGroup(const char *fileOrGroup, const char *descr);

private:
	enum FrameStatus
	{
		Unknown,
		Skip,
		NoSkip
	};

	struct FrameHashEntry
	{
		FrameHashEntry *next;
		unsigned int frameAddr;
		unsigned int frameType;
		const char *fileOrGroup;
		int line;
		int hits;
		FrameStatus status;
	};

	enum { FRAME_HASH_SIZE = 10007 };
	enum { FRAME_HASH_ALLOC_COUNT = 100 };

	char m_prefix[0x14];
	FrameHashEntry *frameHash[FRAME_HASH_SIZE];
	FrameHashEntry *nextUnusedFrameHash;
	unsigned int numAvailableFrameHash;

	FrameHashEntry *AddFrameEntry(unsigned int addr, unsigned int type,
		const char *fileOrGroup, int line);
};

void *DebugAllocMemory(unsigned int size);

// ?AddFrameEntry@Debug@@AAEPAUFrameHashEntry@1@IIPBDH@Z
Debug::FrameHashEntry *Debug::AddFrameEntry(unsigned int addr, unsigned int type,
	const char *fileOrGroup, int line)
{
	// get new entry
	if (!numAvailableFrameHash)
	{
		numAvailableFrameHash = FRAME_HASH_ALLOC_COUNT;
		nextUnusedFrameHash = (FrameHashEntry *)DebugAllocMemory(
			numAvailableFrameHash * sizeof(FrameHashEntry));
	}
	FrameHashEntry *entry = nextUnusedFrameHash++;
	--numAvailableFrameHash;

	// fill entry
	entry->next = frameHash[addr % FRAME_HASH_SIZE];
	entry->frameAddr = addr;
	entry->frameType = type;
	entry->line = line;
	entry->status = Unknown;
	entry->hits = 0;

	// log?
	if (type & 4)
	{
		entry->fileOrGroup = AddLogGroup(fileOrGroup, NULL);
	}
	else
	{
		// store trailing name, folding both separators in one pass
		const char *trailingName = fileOrGroup;
		if (fileOrGroup)
		{
			const char *scan = fileOrGroup;
			char cur = *scan;
			if (cur != 0)
			{
				do
				{
					if (cur == '\\' || cur == '/')
						trailingName = scan + 1;
					++scan;
					cur = *scan;
				} while (cur != 0);
			}
		}
		entry->fileOrGroup = trailingName ? trailingName : fileOrGroup;
		(void)trailingName;
	}

	// add to hash
	frameHash[addr % FRAME_HASH_SIZE] = entry;
	return entry;
}
