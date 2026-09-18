// cl: /DNDEBUG /MD /EHs-c- /Oy-
// Open-BFME: DebugExceptionhandler::LogRegisters, converted from the
// verified GeneralsMD debug exception implementation.

// windows.h is not available to this TU: minimal Win32 x86 ABI view.
// Field offsets are the fixed WinNT CONTEXT layout (verified by byte-match).
struct _CONTEXT
{
	unsigned long m_pad00[35]; // 0x00..0x8B: flags, debug regs, float save
	unsigned long SegGs;      // 0x8C
	unsigned long SegFs;      // 0x90
	unsigned long SegEs;      // 0x94
	unsigned long SegDs;      // 0x98
	unsigned long Edi;        // 0x9C
	unsigned long Esi;        // 0xA0
	unsigned long Ebx;        // 0xA4
	unsigned long Edx;        // 0xA8
	unsigned long Ecx;        // 0xAC
	unsigned long Eax;        // 0xB0
	unsigned long Ebp;        // 0xB4
	unsigned long Eip;        // 0xB8
	unsigned long SegCs;      // 0xBC
	unsigned long EFlags;     // 0xC0
	unsigned long Esp;        // 0xC4
	unsigned long SegSs;      // 0xC8
};

struct _EXCEPTION_POINTERS
{
	void *ExceptionRecord;
	struct _CONTEXT *ContextRecord;
};


// This TU uses the BFME Debug interface as a local ABI view.  The retail
// exception logger dispatches the unsigned-long writer at +0x28, the string
// writer at +0x38, and SetPrefixAndRadix at +0x50.  The fields used by the
// inline manipulators are at +0x9f44/+0x9f48 in the BFME object.
class Debug
{
public:
    class Hex {};
    class Dec {};
    class Bin {};

    class Width
    {
        friend class Debug;
        int m_width;

    public:
        explicit Width(int width): m_width(width) {}
    };

    class FillChar
    {
        friend class Debug;
        char m_fill;

    public:
        explicit FillChar(char fill=' '): m_fill(fill) {}
    };

    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    // MSVC places this overload group in reverse declaration order.  These
    // are the retail slots +0x28 through +0x38; the three middle overloads
    // are part of the existing Debug interface and are not called here.
    virtual Debug &operator<<(const char *);
    virtual Debug &operator<<(int);
    virtual Debug &operator<<(unsigned);
    virtual Debug &operator<<(long);
    virtual Debug &operator<<(unsigned long);
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void SetPrefixAndRadix(const char *, int);

    Debug &operator<<(const Hex &)
    {
        SetPrefixAndRadix("0x", 16);
        return *this;
    }

    Debug &operator<<(const Dec &)
    {
        SetPrefixAndRadix("", 10);
        return *this;
    }

    Debug &operator<<(const Bin &)
    {
        SetPrefixAndRadix("%", 2);
        return *this;
    }

    Debug &operator<<(const Width &width)
    {
        m_width = width.m_width;
        return *this;
    }

    Debug &operator<<(const FillChar &fill)
    {
        m_fillChar = fill.m_fill;
        return *this;
    }

private:
    // BFME2 tail layout: width at +0x9F50, fill at +0x9F54 (donor's BFME1
    // view has them at +0x9F44/+0x9F48; everything else already matches).
    unsigned char m_pad[0x9f4c];
    int m_width;
    char m_fillChar;
};

class DebugExceptionhandler
{
    static void LogRegisters(Debug &, struct _EXCEPTION_POINTERS *);
};

// ?LogRegisters@DebugExceptionhandler@@CAXAAVDebug@@PAU_EXCEPTION_POINTERS@@@Z
void DebugExceptionhandler::LogRegisters(Debug &dbg, struct _EXCEPTION_POINTERS *exptr)
{
    struct _CONTEXT &ctx = *exptr->ContextRecord;

    dbg << Debug::FillChar('0')
        << Debug::Hex()
        << "EAX:" << Debug::Width(8) << ctx.Eax
        << " EBX:" << Debug::Width(8) << ctx.Ebx
        << " ECX:" << Debug::Width(8) << ctx.Ecx
        << "\n"
        << "EDX:" << Debug::Width(8) << ctx.Edx
        << " ESI:" << Debug::Width(8) << ctx.Esi
        << " EDI:" << Debug::Width(8) << ctx.Edi
        << "\n"
        << "EIP:" << Debug::Width(8) << ctx.Eip
        << " ESP:" << Debug::Width(8) << ctx.Esp
        << " EBP:" << Debug::Width(8) << ctx.Ebp
        << "\n"
        << "Flags:" << Debug::Bin() << Debug::Width(32) << ctx.EFlags
        << Debug::Hex() << "\n"
        << "CS:" << Debug::Width(4) << ctx.SegCs
        << " DS:" << Debug::Width(4) << ctx.SegDs
        << " SS:" << Debug::Width(4) << ctx.SegSs
        << "\nES:" << Debug::Width(4) << ctx.SegEs
        << " FS:" << Debug::Width(4) << ctx.SegFs
        << " GS:" << Debug::Width(4) << ctx.SegGs
        << "\n" << Debug::FillChar() << Debug::Dec();
}
