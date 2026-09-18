// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva0004864C9@DestroyDie@@SA?AW4NameKeyType@@XZ @0x4864C9
// (69B): cached pool-name key for DestroyDie. The class
// identity comes from the pool-name string the body pushes
// ("DestroyDie"); the body guards a function-local static
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

class DestroyDie
{
public:
	static NameKeyType rva0004864C9();
};

// ?rva0004864C9@DestroyDie@@SA?AW4NameKeyType@@XZ
NameKeyType DestroyDie::rva0004864C9()
{
	static NameKeyType TheDestroyDiePoolKey =
		TheNameKeyGenerator->nameToKey("DestroyDie");
	return TheDestroyDiePoolKey;
}
