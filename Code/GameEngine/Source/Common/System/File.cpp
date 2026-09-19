// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// Trimmed from Open-BFME-1
// (Code/GameEngine/Source/Common/System/File.cpp): only the placed
// ?lock@File and ?close@File bodies are defined here. Slots stay
// declared-only (destructor for the slot-0 delete-this dispatch, rest for
// layout) and the donor's other members stay out, so the unmatched-definition
// gate passes. Layout follows the donor: AsciiString is pointer-sized (+0x04),
// access +0x08, single-byte open/deleteOnClose flags, mutex handle +0x10;
// lock is vtable slot 15, unlock slot 16, close slot 2. /O1: retail keeps its
// zero in ebx (cmp/mov bl + push ebx); default flags use immediates and drop
// a callee-saved save. The two imports are read straight out of retail:
// KERNEL32 CreateMutexA + WaitForSingleObject.

typedef void *FileHandle;

extern "C" __declspec(dllimport) FileHandle __stdcall CreateMutexA(void *attrs, int owned, const char *name);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(FileHandle handle, unsigned long timeout);

static const unsigned long FILE_INFINITE = 0xFFFFFFFF;

template <typename T>
class StringBase
{
public:
	void set(const T *str);
private:
	void *m_data;
};

class File
{
public:
	virtual ~File();
	virtual void slot01();
	virtual void close();
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

protected:
	void setName(const char *name)
	{
		m_nameStr.set(name);
	}

private:
	StringBase<char> m_nameStr;
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

// ?close@File@@UAEXXZ
// BFME1 File::close shape (their setName ends with deleteInstance; ours clears
// m_deleteOnClose first and then deletes through vtable slot 0 with a separate
// operator delete -- a plain delete this, not MemoryPoolObject's
// getObjectMemoryPool/dtor/freeBlock sequence). Retail calls the one-arg
// StringBase::set, so setName is the one-arg form here, not the two-arg +
// strlen spelling BFME1 uses.
void File::close()
{
	if (m_isOpen) {
		setName("<no file>");
		m_isOpen = 0;
		if (m_deleteOnClose) {
			m_deleteOnClose = 0;
			::delete this;
		}
	}
}
