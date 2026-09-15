// ??0VertexMaterialClass@@QAE@XZ
// partial score=0.9 date=2026-09-15
// cl: /DNDEBUG /MD /EHa /arch:SSE

// VertexMaterialClass default constructor, retail 0x0013D420, 296 bytes.
// Dedicated TU: Init_Thunk keeps its declaration-only view so Init's codegen
// is undisturbed (callee-visibility rule), and this body needs /arch:SSE for
// the scalar movss material stores.
//
// Adapts the Zero Hour vertmaterial.cpp ctor to the BFME2 retail divergences:
//   - sizeof is 0x6C with the D3D material pointer at this+0x8 and plain
//     ::operator new(0x44), not the W3DMPO pooled macro (Init_Thunk notes).
//   - Name rides the upstream StringClass(int, bool) inline (preset shared
//     empty, Get_String(0, false) at 0x610B00, terminator refresh), which is
//     exactly the retail store sequence.
//   - Mapper[i] = NULL with UVSource[i] = i identity.
//   - Material floats land Ambient(1,1,1), Diffuse(1,1,1), Opacity(1) in that
//     order with a CRCDirty refresh ahead of the opacity store.

#include <string.h>

class StringClass
{
public:
	// Mirrors the upstream wwstring.h inline used by member init: preset the
	// shared empty buffer, fetch through Get_String, refresh the terminator.
	StringClass(int initial_len = 0, bool hint_temporary = false) :
		m_Buffer(m_EmptyString)
	{
		Get_String(initial_len, hint_temporary);
		m_Buffer[0] = m_NullChar;
	}

	~StringClass() { Free_String(); }

private:
	void Get_String(int length, bool is_temp);
	void Free_String();

	char *m_Buffer;
	static char *m_EmptyString;
	static char m_NullChar;
};

struct BfmeDynMaterial
{
	float diffuseR;
	float diffuseG;
	float diffuseB;
	float diffuseA;
	float ambientR;
	float ambientG;
	float ambientB;
	unsigned char fill[0x44 - 0x1C];
};

class RefCountClass
{
public:
	RefCountClass() : NumRefs(1) {}

private:
	int NumRefs;
};

class VertexMaterialClass : public RefCountClass
{
public:
	enum
	{
		MAX_STAGES = 8
	};

	VertexMaterialClass();
	virtual ~VertexMaterialClass();

private:
	BfmeDynMaterial *MaterialDyn;
	int Flags;
	int AmbientColorSource;
	int EmissiveColorSource;
	int DiffuseColorSource;
	StringClass Name;
	void *Mapper[MAX_STAGES];
	int UVSource[MAX_STAGES];
	int UniqueID;
	int CRCValue;
	unsigned char CRCDirty;
	unsigned char UseLighting;
};

// ?Get_String@StringClass@@AAEXH_N@Z
// ??2@YAPAXI@Z

VertexMaterialClass::VertexMaterialClass() :
	MaterialDyn(0),
	Flags(0),
	AmbientColorSource(0),
	EmissiveColorSource(0),
	DiffuseColorSource(0),
	UniqueID(0),
	CRCDirty(true),
	UseLighting(false)
{
	int stage;

	for (stage = 0; stage < MAX_STAGES; stage++)
	{
		Mapper[stage] = 0;
		UVSource[stage] = stage;
	}

	MaterialDyn = new BfmeDynMaterial;
	memset(MaterialDyn, 0, sizeof(BfmeDynMaterial));

	MaterialDyn->ambientR = 1.0f;
	MaterialDyn->ambientG = 1.0f;
	MaterialDyn->ambientB = 1.0f;
	MaterialDyn->diffuseR = 1.0f;
	MaterialDyn->diffuseG = 1.0f;
	MaterialDyn->diffuseB = 1.0f;
	CRCDirty = true;
	MaterialDyn->diffuseA = 1.0f;
}
