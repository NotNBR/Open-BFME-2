// cl: /O2 /arch:SSE2 /DNDEBUG /MD /GX-
//
// ?read_texcoords@MeshModelClass@@IAE_NAAVChunkLoadClass@@PAVMeshLoadContextClass@@@Z,
// retail 0x001896D0 (167 bytes).
// BFME1 meshmdlio.cpp read_texcoords port (their 170B Open-BFME5 clean C++ row
// d_0096e330, object-symbol IAE_N bool). BFME2 adaptations (all retail-measured
// from the 0x1896D0 body):
// - VertexCount at this+0x28 (loop bound, signed compare).
// - DefMatDesc at this+0x8C (Install_UV_Array this).
// - MeshLoadContext CurPass/CurTexStage at +0x8C/+0x90.
// - TempUVArray (SimpleVecClass<Vector2>) at +0x23C: retail inlines
//   Get_Temporary_UV_Array as a virtual Uninitialised_Grow call (slot 2, +8)
//   on the member plus a direct read of its Vector word at +0x240.
// - Install_UV_Array resolves to the new pin at 0x15B960 (BFME1 mangling,
//   3 mesh-reader callers); Cur_Chunk_Length/Read resolve to matched rows.
// Dedicated TU: marker-less meshmdlio.cpp cannot take rows (PostProcess precedent).

#ifndef NULL
#define NULL 0
#endif

class Vector2
{
public:
	float X;
	float Y;
	void __forceinline Set(float x, float y) { X = x; Y = y; }
};

struct W3dTexCoordStruct
{
	float U;
	float V;
};

template <class T> class SimpleVecClass
{
public:
	virtual ~SimpleVecClass();
	virtual bool Resize(int newsize);
	virtual bool Uninitialised_Grow(int newsize);
	T & operator[](int index) { return Vector[index]; }

protected:
	T *Vector;
	int VectorMax;
};

class ChunkLoadClass
{
public:
	unsigned long Cur_Chunk_Length();
	unsigned long Read(void *dst, unsigned long size);
};

class MeshMatDescClass
{
public:
	void Install_UV_Array(int pass, int stage, Vector2 *uvs, int count);
};

class MeshLoadContextClass
{
public:
	Vector2 *__forceinline Get_Temporary_UV_Array(int elementcount)
	{
		TempUVArray.Uninitialised_Grow(elementcount);
		return &TempUVArray[0];
	}

private:
	virtual ~MeshLoadContextClass();
	char m_pad0[0x8C - 4];
public:
	int CurPass;
	int CurTexStage;
private:
	char m_pad1[0x23C - 0x94];
public:
	SimpleVecClass<Vector2> TempUVArray;
};

class MeshModelClass
{
protected:
	virtual ~MeshModelClass();
	bool read_texcoords(ChunkLoadClass &cload, MeshLoadContextClass *context);

private:
	char m_pad0[0x28 - 4];
	int VertexCount;
	char m_pad1[0x8C - 0x2C];
	MeshMatDescClass *DefMatDesc;
};

// ?read_texcoords@MeshModelClass@@IAE_NAAVChunkLoadClass@@PAVMeshLoadContextClass@@@Z
bool MeshModelClass::read_texcoords(ChunkLoadClass &cload, MeshLoadContextClass *context)
{
	W3dTexCoordStruct texcoord;
	Vector2 *uvarray = 0;
	int elementcount = cload.Cur_Chunk_Length() / sizeof(W3dTexCoordStruct);

	context->TempUVArray.Uninitialised_Grow(elementcount);
	uvarray = &context->TempUVArray[0];

	if (uvarray != NULL) {
		for (int i = 0; i < VertexCount; i++) {
			if (cload.Read(&texcoord, sizeof(W3dTexCoordStruct)) != sizeof(W3dTexCoordStruct)) {
				return false;
			}
			uvarray[i].Set(texcoord.U, 1.0f - texcoord.V);
		}

		DefMatDesc->Install_UV_Array(context->CurPass, context->CurTexStage, uvarray, elementcount);
	}

	return true;
}
