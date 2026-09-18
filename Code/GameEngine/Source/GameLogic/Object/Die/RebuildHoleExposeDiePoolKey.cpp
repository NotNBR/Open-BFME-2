// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva000486792@RebuildHoleExposeDie@@SA?AW4NameKeyType@@XZ @0x486792
// (69B): cached pool-name key for RebuildHoleExposeDie. The class
// identity comes from the pool-name string the body pushes
// ("RebuildHoleExposeDie"); the body guards a function-local static
// key fetched once through TheNameKeyGenerator. It is NOT getClassMemoryPool:
// retail stores nameToKey's return (a key, not a pool pointer) and returns it,
// and the address carries no getClassMemoryPool row anywhere. /EHsc for the
// static-guard EH prologue; globals are TU-local externs (DIR32 slots patch
// from retail, no pins; nameToKey resolves via its matched row).

enum NameKeyType
{
	NK_UNKNOWN = 0
};

class NameKeyGenerator
{
public:
	NameKeyType nameToKey(const char *name);
};

extern NameKeyGenerator *TheNameKeyGenerator;

class RebuildHoleExposeDie
{
public:
	static NameKeyType rva000486792();
};

// ?rva000486792@RebuildHoleExposeDie@@SA?AW4NameKeyType@@XZ
NameKeyType RebuildHoleExposeDie::rva000486792()
{
	static NameKeyType TheRebuildHoleExposeDiePoolKey =
		TheNameKeyGenerator->nameToKey("RebuildHoleExposeDie");
	return TheRebuildHoleExposeDiePoolKey;
}

