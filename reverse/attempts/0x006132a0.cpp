// ?Return_File@RawFileFactoryClass@@QAEXPAVFileClass@@@Z
// partial score=0.85 date=2026-09-14
// cl: /O2 /DNDEBUG /MD
//
// RawFileFactoryClass::Return_File, retail 0x006132A0 (36 bytes).
// Releases the file through vtable slot 0, then frees the handle with
// scalar operator delete (matched at 0x0002FD60); null frees null.

class FileClass
{
public:
	virtual void *Release(int flags);
};

class RawFileFactoryClass
{
public:
	void Return_File(FileClass *file);
};

void __cdecl operator delete(void *block);

void RawFileFactoryClass::Return_File(FileClass *file)
{
	if (file != 0)
		::operator delete(file->Release(0));
	else
		::operator delete(0);
}
