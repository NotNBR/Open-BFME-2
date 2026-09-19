// cl: /O1 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// Trimmed from Open-BFME-1
// (Code/GameEngine/Source/Common/System/File.cpp): only the placed
// ?lock@File, ?close@File, ?open@File and ??1File bodies are defined here.
// Slots stay declared-only (destructor for the slot-0 delete-this dispatch,
// rest for layout) and the donor's other members stay out, so the
// unmatched-definition gate passes. Layout follows the donor: AsciiString is
// pointer-sized (+0x04), access +0x08, single-byte open/deleteOnClose flags,
// mutex handle +0x10; close is slot 2, open slot 1, lock slot 15, unlock
// slot 16. The member is a TU-local AsciiString whose inline set() reaches
// StringBase::set and whose forceinline dtor reaches the folded clear, so the
// open/close set calls and the destructor teardown stay direct. /O1: retail
// keeps its zero in ebx (cmp/mov bl + push ebx); default flags use immediates
// and drop a callee-saved save. Imports read straight out of retail: KERNEL32
// CreateMutexA + WaitForSingleObject + CloseHandle.

typedef void *FileHandle;

extern "C" __declspec(dllimport) FileHandle __stdcall CreateMutexA(void *attrs, int owned, const char *name);
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(FileHandle handle, unsigned long timeout);
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void *handle);

static const unsigned long FILE_INFINITE = 0xFFFFFFFF;

template <typename T>
class StringBase
{
public:
	void set(const T *str);
private:
	void *m_data;
};

class AsciiString
{
public:
	void set(const char *str) { m_base.set(str); }
	void clear();
	__forceinline ~AsciiString() { clear(); }
private:
	StringBase<char> m_base;
};

class File
{
public:
	virtual ~File();
	virtual bool open(const char *filename, int access);
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
	AsciiString m_nameStr;
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

// ?open@File@@UAE_NPBDH@Z
// BFME1 File::open logic (their setName is the two-arg + strlen form; ours is
// the one-arg form like close, so no length push). Access-flag numbering is
// unchanged from Zero Hour (READ 1, WRITE 2, APPEND 4, TRUNCATE 0x10,
// TEXT 0x20, BINARY 0x40, STREAMING 0x100).
bool File::open(const char *filename, int access)
{
	if (m_isOpen) {
		return false;
	}
	setName(filename);
	if ((access & (0x100 | 0x02)) == (0x100 | 0x02)) {
		return false;
	}
	if ((access & (0x20 | 0x40)) == (0x20 | 0x40)) {
		return false;
	}
	if ((access & (0x01 | 0x02)) == 0) {
		access |= 0x01;
	}
	if (!(access & (0x01 | 0x04))) {
		access |= 0x10;
	}
	if ((access & (0x20 | 0x40)) == 0) {
		access |= 0x40;
	}
	m_access = access;
	m_isOpen = 1;
	return true;
}

// ??1File@@UAE@XZ
// BFME1 File::~File verbatim: clears delete-on-close (so a self-deleting File
// does not re-enter delete while being destroyed), closes, then releases the
// mutex. The trailing AsciiString teardown (0x36410 via the forceinline member
// dtor) is implicit.
File::~File()
{
	m_deleteOnClose = 0;
	close();
	if (m_mutex) {
		CloseHandle(m_mutex);
	}
}
