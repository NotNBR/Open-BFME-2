// cl: /G7 /DNDEBUG /DWIN32 /D_WINDOWS /MD
//
// Array-holder scalar-deleting destructors for the DX8MeshRendererClass dtor
// family (see DX8MeshRendererClassDtor.cpp for the full layout archaeology).
// The holder is a two-level chain (vptr installs 0xBD34FC/0xBD34F0) whose
// dtors free an array member with delete[] plus nulls; retail rechecks the
// array after each null instead of folding (same idiom twice).

// The holder dtors emit no EH funclets (frameless): declare the global
// deletes nothrow (BFME1 DX8MeshRendererDestructorNothrow.cpp pattern).

void __cdecl operator delete(void *) throw();
void __cdecl operator delete[](void *) throw();

class Rva00143FB0
{
public:
	virtual ~Rva00143FB0();

protected:
	char *m_array;
	int m_x;
};

// ??1Rva00143FB0@@UAE@XZ absent-from-retail
Rva00143FB0::~Rva00143FB0()
{
	if (m_array != 0) {
		delete[] m_array;
		m_array = 0;
	}
	m_x = 0;
}

class Rva00143F60 : public Rva00143FB0
{
public:
	virtual ~Rva00143F60();
};

// ??1Rva00143F60@@UAE@XZ present-unmatched
Rva00143F60::~Rva00143F60()
{
	if (m_array != 0) {
		delete[] m_array;
		m_array = 0;
	}
}
