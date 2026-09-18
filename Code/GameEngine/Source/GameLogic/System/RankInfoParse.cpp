// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
// stlport
//
// ?friend_parseRankDefinition@RankInfoStore@@SAXPAVINI@@@Z,
// retail 0x0020038E, 269 bytes. Dedicated TU.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/GameLogic/System/RankInfoParse.cpp,
// RankInfoStore::friend_parseRankDefinition, static): parse one Rank block.
// The retail body follows the reference source exactly: null-store guard,
// rank number through getNextToken plus the token-to-int member, override
// versus monotonic path on the load type, per-rank bounds checks, fresh
// RankInfo through operator new plus the constructor, final-override chase,
// copy, next-override link, override mark, field-table parse, and vector
// push-back on the new path. Throws funnel through the INIException filler
// plus CxxThrow. Member names come from the reference Overridable layout
// (m_nextOverride +0x04, m_isAllocatedOverride +0x08); the three string
// literals and the field-table address are retail-measured.

#include <vector>

typedef int Int;

#define NULL 0

enum INILoadType
{
	INI_LOAD_INVALID = 0,
	INI_LOAD_OVERWRITE = 1,
	INI_LOAD_CREATE_OVERRIDES = 2
};

struct FieldParse;

class INI
{
public:
	const char *getNextToken(const char *seps);
	int scanInt(const char *token);
	void initFromINI(void *what, const FieldParse *table);
	INILoadType getLoadType() const { return m_loadType; }

private:
	unsigned char m_pad[8];
	INILoadType m_loadType; // +0x08
};

class Overridable
{
public:
	virtual void overridableAnchor();
	Overridable *friend_getFinalOverride();

public:
	Overridable *m_nextOverride; // +0x04
	unsigned char m_isAllocatedOverride; // +0x08
};

class RankInfo : public Overridable
{
public:
	RankInfo();
	RankInfo &operator=(const RankInfo &that);
	void setNextOverride(RankInfo *o) { m_nextOverride = o; }
	void markAsOverride() { m_isAllocatedOverride = true; }

private:
	// +0x0C..+0x43: retail-measured but unmapped (int -1 at +0x0C in the ctor;
	// UnicodeString assigned at +0x10, nine ints +0x14..+0x34, vector at +0x38
	// per the operator= body). Only the total size (0x44) is consumed here.
	unsigned char m_pad[0x44 - 0x0C];
};

class RankInfoStore
{
public:
	static void friend_parseRankDefinition(INI *ini);

private:
	unsigned char m_pad[0x0C];
	_STL::vector<RankInfo *> m_rankInfos; // +0x0C
};

extern RankInfoStore *TheRankInfoStore;

extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);

// Address anchor only: each throw site pushes this object's address as an
// immediate (DIR32, copied from retail's throwinfo at 0xCFE2FC). Its content
// is never compared; the real chain lives in the retail image.
struct RankInfoThrowInfoAnchor { int a; int b; int c; int d; };
static const RankInfoThrowInfoAnchor rankInfoThrowInfoAnchor = { 0, 0, 0, 0 };

// ?friend_parseRankDefinition@RankInfoStore@@SAXPAVINI@@@Z
void RankInfoStore::friend_parseRankDefinition(INI *ini)
{
	if (TheRankInfoStore)
	{
		Int rank = ini->scanInt(ini->getNextToken(NULL));

		if (ini->getLoadType() == INI_LOAD_CREATE_OVERRIDES)
		{
			// we aren't allowed to add ranks in overrides, only to override existing ones.
			// NOTE: unsigned comparison against size() (retail ja, not jg).
			if (rank < 1 || (unsigned int)rank > TheRankInfoStore->m_rankInfos.size())
			{
				char exc[8];
				rva002f681_fill(exc, 3, "Rank not found in map.ini");
				_CxxThrowException(exc, (void *)&rankInfoThrowInfoAnchor);
			}

			RankInfo *info = TheRankInfoStore->m_rankInfos[rank - 1];
			if (!info)
			{
				char exc[8];
				rva002f681_fill(exc, 3, "Rank not found in map.ini");
				_CxxThrowException(exc, (void *)&rankInfoThrowInfoAnchor);
			}

			RankInfo *newInfo = new RankInfo;

			// copy data from final override to 'newInfo' as a set of initial default values
			Overridable *nextOverride = info->m_nextOverride;
			if (nextOverride)
				info = (RankInfo *)nextOverride->friend_getFinalOverride();

			*newInfo = *info;
			info->setNextOverride(newInfo);
			newInfo->markAsOverride(); // must do AFTER the copy

			ini->initFromINI(newInfo, reinterpret_cast<const FieldParse *>(0x00BE2870));
			//TheRankInfoStore->m_rankInfos.push_back(newInfo);	// NO, BAD, WRONG -- don't add in this case.
		}
		else
		{
			if (rank != (Int)TheRankInfoStore->m_rankInfos.size() + 1)
			{
				char exc[8];
				rva002f681_fill(exc, 3, "Ranks must increase monotonically");
				_CxxThrowException(exc, (void *)&rankInfoThrowInfoAnchor);
			}
			// NOTE: the push_back argument rides a copy, not `info` itself.
			// `info` stays register-held (push eax, xor-eax null path) while
			// the copy's home store sinks below the initFromINI argument
			// setup (push TABLE, push eax, mov ecx) to just before the call.
			// Passing `info` directly homes it up front in both new-arms
			// instead (verified by probe grid v1-v11: a defining store for
			// an address-taken variable pins early, a copy sinks late).
			RankInfo *info = new RankInfo;
			RankInfo *const storedInfo = info;
			ini->initFromINI(info, reinterpret_cast<const FieldParse *>(0x00BE2870));
			TheRankInfoStore->m_rankInfos.push_back(storedInfo);		}
	}
}
