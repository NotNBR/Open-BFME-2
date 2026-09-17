// cl: /O1 /GX /MD /DNDEBUG /DWIN32 /D_WINDOWS
//
// ??0BfmeMapPictureTexture@@QAE@PBD@Z,
// retail 0x002DB93E, 85 bytes. Dedicated TU.
//
// The map-picture image keeps its texture behind a retaining holder: the
// constructor allocates a filename-built texture and adopts it. The retail
// body follows that shape directly, including the failing-new skip around
// the texture build (0x2DB882 pin) and the retaining adopt (0xEF87B pin).

typedef int Int;

#define NULL 0

typedef unsigned int size_t;
void *__cdecl operator new(size_t bytes);

class TextureClass
{
public:
	TextureClass(const char *filename);

private:
	char m_pad[0x3C];
};

template <typename T>
class RefCountPtr
{
public:
	RefCountPtr() : m_ptr(0) {}
	RefCountPtr &operator=(T *ptr);
	~RefCountPtr();

private:
	T *m_ptr;
};

class BfmeMapPictureTexture
{
public:
	BfmeMapPictureTexture(const char *filename);

private:
	RefCountPtr<TextureClass> m_texture;
};

// ??0BfmeMapPictureTexture@@QAE@PBD@Z
BfmeMapPictureTexture::BfmeMapPictureTexture(const char *filename)
{
	m_texture = new TextureClass(filename);
}
