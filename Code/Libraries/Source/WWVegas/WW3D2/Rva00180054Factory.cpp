// cl: /O1 /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS
//
// ?Rva00180054_MakeOwner@@YA?AVRva00180023@@PBD@Z @ 0x00180054 (94 bytes).
// Registry-owner factory (mixed named-return plus temporary-return recipe,
// as the landed 0x0017FC1E/0x0014CF01 factories). Owner copy ctor pinned at
// 0x00180023.

class HierarchyPrototype
{
public:
	void Release_Ref();
};

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

class Rva00180023
{
public:
	Rva00180023() : m_prototype(0) {}
	Rva00180023(const HierarchyPrototypeRef &source);
	~Rva00180023()
	{
		if (m_prototype != 0)
			m_prototype->Release_Ref();
	}

	HierarchyPrototype *m_prototype; // +0x00
};

extern HierarchyPrototypeRef __cdecl Rva0061F230_GetPrototype(const char *name);

// ?Rva00180054_MakeOwner@@YA?AVRva00180023@@PBD@Z
Rva00180023 Rva00180054_MakeOwner(const char *name)
{
	if (name == 0)
	{
		Rva00180023 empty;
		return empty;
	}
	return Rva00180023(Rva0061F230_GetPrototype(name));
}
