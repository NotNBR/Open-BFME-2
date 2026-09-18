// cl: /O1 /Oy- /DNDEBUG /MD /EHsc
// stlport
//
// Version-block table search helpers for the lookup at 0x00427EDA.
// The worker at 0x00427DEA binary-searches 0x18-byte records by key and
// resolves the matching range; the wrapper below forwards the parser
// call with a zero sixth argument and returns the output slot. Worker
// address read from the wrapper REL32; every byte below is retail.
// Semantic class membership is unproven beyond the lookup pins so the
// helpers ride a TU-local VersionBlockParser scope; opaque behavior.

class VersionBlockParser
{
public:
	static const void *searchEntries(const void *found, const void *first, const void *last, const char *const *key, const void *match, int flags);
	static const void *findEntry(const void *found, const void *first, const void *last, const char *const *key, const void *match);
};

// ?findEntry@VersionBlockParser@@SAPBXPBX00PBQBD0@Z
const void *VersionBlockParser::findEntry(const void *found, const void *first, const void *last, const char *const *key, const void *match)
{
	searchEntries(found, first, last, key, match, 0);
	return found;
}
