// cl: /DNDEBUG /MD /EHa /Oy-
//
// ??0DebugIOOds@@QAE@XZ, retail 0x0003F380 (70 bytes), plus the
// ??_GDebugIOOds@@UAEPAXI@Z scalar deleting destructor at 0x0003F430
// (33 bytes). ??1DebugIOOds@@UAE@XZ at 0x0003F460 is rowed from
// DebugIOOdsCtor.cpp (same class, twin TU).
//
// Ported from Open-BFME-1
// Code/Libraries/Source/WWVegas/WWDebug/Rva0088FAA0DebugIOOdsDestructor.cpp:
// same memberless two-vtable DebugIO hierarchy (DebugIOOds::Create already
// landed from DebugIOOds_Create.cpp, so the factory is left out here). The
// Rva0088FAA0 names in the donor are the port's guess-labels for this class;
// retail owns it as DebugIOOds (Create/Write rows + upstream debug_io_ods.h).
// Same implicit-dtor shape as ??1DebugCmdInterfaceDebug at 0x00039980
// (the ambiguous twin that differs only in the vtable constant); the ctor
// is the 70B two-store EH shape of ??0DebugCmdInterfaceDebug.

class DebugIOInterface
{
protected:
    virtual ~DebugIOInterface(void) {}

public:
    DebugIOInterface(void) {}
    virtual int Read(char *, int) = 0;
    virtual void Write(int, const char *, const char *) = 0;
    virtual void EmergencyFlush(void) = 0;
    virtual void Execute(void) = 0;
    virtual void Delete(void) = 0;
};

class DebugIOOds : public DebugIOInterface
{
public:
    explicit DebugIOOds(void);
    virtual int Read(char *, int) { return 0; }
    virtual void Write(int, const char *, const char *) {}
    virtual void EmergencyFlush(void) {}
    virtual void Execute(void) {}
    virtual void Delete(void);
};

// ??0DebugIOOds@@QAE@XZ
DebugIOOds::DebugIOOds(void)
{
}

// ?Delete@DebugIOOds@@UAEXXZ absent-from-retail
void DebugIOOds::Delete(void)
{
    this->~DebugIOOds();
}
