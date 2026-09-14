// ??0TexBufferClass@@QAE@HPBD@Z
// partial score=0.99 date=2026-09-14
// cl: /G7 /DNDEBUG /MD /O2 /Ob2
// readable body of ??0TexBufferClass@@QAE@HPBD@Z (retail 0x0015D080, 62B).
// Ported from reference/open-bfme-1/.../TexBufferClassCtorThunk.cpp:
// ShareBufferClassBase(count, name, 0) then memset the pointer array.

#include <string.h>

class ShareBufferClassBase
{
public:
	ShareBufferClassBase(int count, const char *name, int flags);
	virtual ~ShareBufferClassBase();

protected:
	int field04;
	int field08;
	void *Array;
	int Count;
};

class TexBufferClass : public ShareBufferClassBase
{
public:
	TexBufferClass(int count, const char *name);
};

// ??0TexBufferClass@@QAE@HPBD@Z
TexBufferClass::TexBufferClass(int count, const char *name)
	: ShareBufferClassBase(count, name, 0)
{
	int bytes = Count;
	bytes += bytes;
	bytes += bytes;
	memset(Array, 0, bytes);
}
