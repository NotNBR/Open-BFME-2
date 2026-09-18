// cl: /O1 /DNDEBUG /MD /EHsc
// ?rva000486155@CrushDie@@SA?AW4NameKeyType@@XZ @0x486155
// (69B): cached pool-name key for CrushDie. The class
// identity comes from the pool-name string the body pushes
// ("CrushDie"); the body guards a function-local static
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

class CrushDie
{
public:
	static NameKeyType rva000486155();
};

// ?rva000486155@CrushDie@@SA?AW4NameKeyType@@XZ
NameKeyType CrushDie::rva000486155()
{
	static NameKeyType TheCrushDiePoolKey =
		TheNameKeyGenerator->nameToKey("CrushDie");
	return TheCrushDiePoolKey;
}
