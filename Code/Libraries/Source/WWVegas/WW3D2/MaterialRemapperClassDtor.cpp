// cl: /G7 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// ??1MaterialRemapperClass@@QAE@XZ
// retail 0x0016F170, 169 bytes. Dedicated TU.
//
// BFME2 rewrote only the texture side of the BFME1 MaterialRemapperClass as
// owning references (the vertex-material side stays raw, like BFME1):
// - TextureRemapStruct holds RefCountPtr<TextureClass> handles, so
//   `delete[] TextureRemaps` runs the vector destructor iterator (ehvec at
//   0x629110 over 8-byte elements with the struct dtor at 0x16EBA0), while
//   `delete[] VertexMaterialRemaps` stays a plain array delete.
// - The dtor releases the cached LastDestTex/LastSrcTex through the
//   out-of-line TextureBaseClass::Release_Ref (matched at 0x61ED10); the
//   Src/Dest MaterialInfo releases stay inline (dword add-form decrement
//   plus slot-0 Delete_This under /G7).
// TU-local replicas mangle identically to the real instantiations, so the
// texture element destructor and the Release_Ref calls resolve with no pins.

typedef unsigned int size_t;
void __cdecl operator delete[](void *ptr);

#define NULL 0

class TextureBaseClass
{
public:
	void Release_Ref();
};

class TextureClass : public TextureBaseClass
{
};

class VertexMaterialClass
{
};

class MaterialInfoClass
{
public:
	void Release_Ref(void)
	{
		NumRefs--;
		if (NumRefs == 0) {
			Delete_This();
		}
	}
	virtual void Delete_This();

private:
	int NumRefs;
};

template<class T>
class RefCountPtr
{
public:
	RefCountPtr() : Referent(0) {}
	~RefCountPtr()
	{
		if (Referent) {
			Referent->Release_Ref();
		}
	}

private:
	T *Referent;
};

// ??1TextureRemapStruct@MaterialRemapperClass@@QAE@XZ present-unmatched
class MaterialRemapperClass
{
public:
	~MaterialRemapperClass(void);

private:
	struct VmatRemapStruct
	{
		VertexMaterialClass *Src;
		VertexMaterialClass *Dest;
	};

	struct TextureRemapStruct
	{
		RefCountPtr<TextureClass> Src;
		RefCountPtr<TextureClass> Dest;
	};

	MaterialInfoClass *SrcMatInfo;
	MaterialInfoClass *DestMatInfo;

	int TextureCount;
	TextureRemapStruct *TextureRemaps;
	int VertexMaterialCount;
	VmatRemapStruct *VertexMaterialRemaps;

	VertexMaterialClass *LastSrcVmat;
	VertexMaterialClass *LastDestVmat;
	RefCountPtr<TextureClass> LastSrcTex;
	RefCountPtr<TextureClass> LastDestTex;
};

MaterialRemapperClass::~MaterialRemapperClass(void)
{
	SrcMatInfo->Release_Ref();
	DestMatInfo->Release_Ref();

	if (TextureRemaps) {
		delete[] TextureRemaps;
	}
	if (VertexMaterialRemaps) {
		delete[] VertexMaterialRemaps;
	}
}
