// cl: /O1 /Oy- /DNDEBUG /MD /GX- /Oi-
// ?friend_lookupScience@ScienceStore@@QBE?AW4ScienceType@@PBD@Z @0x1FF65D
// (81B): ScienceStore::friend_lookupScience, ZH Science.cpp verbatim (public
// const): NAMEKEY the name, isValidScience (row) or INIException(3, ...) via
// the shared filler plus _CxxThrowException. DEBUG_CRASH vanishes in NDEBUG.
// Throw-info anchor is TU-local sacrificial (DIR32 auto-patches, content
// unchecked -- INI_scanReal idiom).

enum NameKeyType
{
	NK_UNKNOWN = 0
};

enum ScienceType
{
	SCIENCE_INVALID = -1
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

class ScienceStore
{
public:
	bool isValidScience(ScienceType st) const;
	ScienceType friend_lookupScience(const char *scienceName) const;
};

struct INIException
{
	char *mFailureMessage;
	int mErrorCode;
};

extern "C" void rva002f681_fill(void *dst, int code, const char *fmt, ...);
__declspec(noreturn) void __stdcall _CxxThrowException(void *pExc, void *pInfo);

struct FriendLookupThrowInfoAnchor { int a; int b; int c; int d; };
static const FriendLookupThrowInfoAnchor friendLookupThrowInfoAnchor = { 0, 0, 0, 0 };

// ?friend_lookupScience@ScienceStore@@QBE?AW4ScienceType@@PBD@Z
ScienceType ScienceStore::friend_lookupScience(const char *scienceName) const
{
	NameKeyType nkt = TheNameKeyGenerator->nameToKey(scienceName);
	ScienceType st = (ScienceType)nkt;
	if (!isValidScience(st))
	{
		INIException e;
		rva002f681_fill(&e, 3, "Science name %s not known! (Did you define it in Science.ini?)", scienceName);
		_CxxThrowException(&e, (void *)&friendLookupThrowInfoAnchor);
	}
	return st;
}
