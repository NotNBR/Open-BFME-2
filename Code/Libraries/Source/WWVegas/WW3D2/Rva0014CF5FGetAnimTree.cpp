// cl: /O1 /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS
//
// ?Rva0014CF5F_GetAnimTree@@YAPAVHTreeClass@@PBD@Z @ 0x0014CF5F (189 bytes).
// Free animation-asset lookup: builds the "a*"+name key lowercased, fetches
// the counted prototype from the asset registry, and returns its +0x14
// object with an added reference (the owner is released). Same shape as the
// landed Get_HTree (0x0017FC7C) with three deltas: the "a*" prefix, a
// distinct owner type (copy ctor 0x0014CED0), and the counted return (dword
// increment at +4 of the returned object after a null check, then the
// object is re-read for the return).

extern "C" char *strcpy(char *destination, const char *source);
#pragma function(strcpy)
extern "C" __declspec(dllimport) char *__cdecl _strlwr(char *string);

class HTreeClass
{
public:
	char m_pad00[4]; // +0x00, untouched by this body
	int m_refCount; // +0x04, incremented when the tree is returned
};

class HierarchyPrototype
{
public:
	virtual void slot00();
	virtual void slot01();
	virtual void slot02();
	virtual void slot03();
	virtual void slot04();
	virtual void slot05();
	virtual void slot06();
	virtual void slot07();
	virtual void slot08();
	virtual void slot09();
	virtual int slot10();
	virtual void slot11();
	void Release_Ref();

	char m_pad[0x10]; // +0x04
	HTreeClass *m_tree; // +0x14
};

// Counted registry reference returned by value from the asset registry.
// The non-trivial destructor forces the hidden-return slot; retail reuses
// the dead argument slot for it.
class HierarchyPrototypeRef
{
public:
	~HierarchyPrototypeRef()
	{
		if (m_object != 0)
			m_object->Release_Ref();
	}

private:
	HierarchyPrototype *m_object;
};

// Four-byte owner: holds the prototype pointer and releases it.
class HAnimPrototypeOwner
{
public:
	HAnimPrototypeOwner(const HierarchyPrototypeRef &source);
	~HAnimPrototypeOwner()
	{
		if (m_prototype != 0)
			m_prototype->Release_Ref();
	}

	HierarchyPrototype *m_prototype; // +0x00
};

// Asset-registry prototype lookup (retail 0x0061F230). Evidence: frameless
// SEH body returning a counted reference through the hidden slot (null name
// writes a null reference), reading the registry singleton; shared with the
// landed Get_HTree.
extern HierarchyPrototypeRef __cdecl Rva0061F230_GetPrototype(const char *name);

// ?Rva0014CF5F_GetAnimTree@@YAPAVHTreeClass@@PBD@Z
HTreeClass *Rva0014CF5F_GetAnimTree(const char *name)
{
	if (name == 0)
		return 0;

	char lookup[512];
	strcpy(lookup, "a*");
	strcpy(lookup + 2, name);
	_strlwr(lookup);

	HAnimPrototypeOwner owner(Rva0061F230_GetPrototype(lookup));
	if (owner.m_prototype == 0)
		return 0;

	HierarchyPrototype *object = owner.m_prototype;
	if ((unsigned char)object->slot10() == 0)
		object->slot11();
	HTreeClass *tree = object->m_tree;
	if (tree != 0)
		++tree->m_refCount;
	return object->m_tree;
}
