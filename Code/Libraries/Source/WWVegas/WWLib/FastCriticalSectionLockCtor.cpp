// cl: /DNDEBUG /MD /EHsc
// ??0LockClass@FastCriticalSectionClass@@QAE@AAV1@@Z at 0x006C5F40 (20B).
//
// Out-of-line FastCriticalSectionClass::LockClass guard constructor: stores
// the critical section address and acquires it through the string-domain
// spin at 0x006C5EF0 (pinned under the void spelling of the spin symbol).
// In MSVC back-references the AAV1 parameter names the second class in the
// mangling, FastCriticalSectionClass itself, so this reference-taking
// spelling is the constructor the retail bytes (which store the incoming
// reference without a load) assemble to. Lives apart from the wwstring.h
// inline model (whose forceinline constructor cannot be redefined) in this
// standalone unit.

class FastCriticalSectionClass
{
	unsigned Flag;

public:
	class LockClass
	{
		FastCriticalSectionClass &cs;
		static void __fastcall spin(void *lock);

	public:
		LockClass(FastCriticalSectionClass &critical_section);
	};
};

FastCriticalSectionClass::LockClass::LockClass(FastCriticalSectionClass &critical_section) : cs(critical_section)
{
	spin(&cs.Flag);
}

// Force MSVC to emit the constructor as a standalone body. The game never
// calls it through this helper (wwstring.obj keeps it as non-/Gy object
// code with no live caller).
// ?forceFastCriticalLockConstruct@@YAPAVLockClass@FastCriticalSectionClass@@PAXAAV2@@Z absent-from-retail
inline void *operator new(unsigned int, void *storage)
{
	return storage;
}

__declspec(noinline) FastCriticalSectionClass::LockClass *forceFastCriticalLockConstruct(
	void *storage, FastCriticalSectionClass &section)
{
	return new (storage) FastCriticalSectionClass::LockClass(section);
}
