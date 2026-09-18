// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva000486C95@KeepObjectDie@@SA?AW4NameKeyType@@XZ @0x486c95
// (69B): cached pool-name key for KeepObjectDie. The class
// identity comes from the pool-name string the body pushes
// ("KeepObjectDie"); the body guards a function-local static
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

class KeepObjectDie
{
public:
	static NameKeyType rva000486C95();
};

// ?rva000486C95@KeepObjectDie@@SA?AW4NameKeyType@@XZ
NameKeyType KeepObjectDie::rva000486C95()
{
	static NameKeyType TheKeepObjectDiePoolKey =
		TheNameKeyGenerator->nameToKey("KeepObjectDie");
	return TheKeepObjectDiePoolKey;
}

