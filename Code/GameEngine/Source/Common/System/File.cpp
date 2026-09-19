// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// Trimmed from Open-BFME-1
// (Code/GameEngine/Source/Common/System/File.cpp): only the placed
// ?lock@File body is defined here. Slots 0-14 and 16 stay declared-only and
// the donor's other 44 members stay out, so the unmatched-definition gate
// passes. Layout follows the donor: AsciiString is pointer-sized (+0x04),
// access +0x08, single-byte open/deleteOnClose flags, mutex handle +0x10;
// lock is vtable slot 15, unlock slot 16. The two imports are read straight
// out of retail: KERNEL32 CreateMutexA + WaitForSingleObject.

typedef void *FileHandle;

extern "C" __declspec(dllimport) FileHandle __stdcall CreateMutexA(void *attrs, int owned, const char *name);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(FileHandle handle, unsigned long timeout);

static const unsigned long FILE_INFINITE = 0xFFFFFFFF;

class File
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
	virtual void slot10();
	virtual void slot11();
	virtual void slot12();
	virtual void slot13();
	virtual void slot14();
	virtual void lock();
	virtual void unlock();

private:
	void *m_nameStr;
	int m_access;
	unsigned char m_isOpen;
	unsigned char m_deleteOnClose;
	unsigned char m_pad0E[2];
	FileHandle m_mutex;
};

void File::lock()
{
	if (m_mutex == 0)
		m_mutex = CreateMutexA(0, 1, 0);
	else
		WaitForSingleObject(m_mutex, FILE_INFINITE);
}
