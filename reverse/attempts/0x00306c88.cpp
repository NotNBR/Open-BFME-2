// ?closeDataChunk@DataChunkOutput@@QAEXXZ
// partial score=0.99 date=2026-09-14
// cl: /O1
//
// DataChunkOutput::closeDataChunk, retail 0x00306C88 (119 bytes).
// Pops the top chunk: records the position, seeks back to the header,
// writes the size, seeks forward, pops the stack and frees the chunk via
// the inline MemoryPoolObject::deleteInstance (explicit virtual dtor call
// with the no-free flag, then the global scalar operator delete).

extern "C" __declspec(dllimport) long __cdecl ftell(void *stream);
extern "C" __declspec(dllimport) int __cdecl fseek(void *stream, long offset, int origin);
extern "C" __declspec(dllimport) unsigned int __cdecl fwrite(
	const void *ptr, unsigned int size, unsigned int count, void *file);

void __cdecl operator delete(void *ptr);

enum { SEEK_SET_ = 0 };

class MemoryPoolObject
{
public:
	virtual ~MemoryPoolObject() {}
};

class OutputChunk : public MemoryPoolObject
{
public:
	OutputChunk *next;	// +0x04
	int id;		// +0x08
	int filepos;	// +0x0C
};

class DataChunkOutput
{
public:
	void closeDataChunk(void);

private:
	char pad_0000[4];
	void *file;	// +0x04
	char pad_0008[0x10];
	OutputChunk *chunkStack;	// +0x18
};

void DataChunkOutput::closeDataChunk(void)
{
	if (chunkStack == 0)
	{
		return;
	}

	int here = ftell(file);

	fseek(file, chunkStack->filepos, SEEK_SET_);

	int size = here - chunkStack->filepos - sizeof(int);

	fwrite(&size, sizeof(int), 1, file);

	fseek(file, here, SEEK_SET_);

	OutputChunk *c = chunkStack;
	chunkStack = chunkStack->next;
	if (c != 0)
		c->~OutputChunk(), ::operator delete(c);
}
