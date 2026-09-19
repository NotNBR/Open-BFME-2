// cl: /DNDEBUG /MD /EHa /Oy-
//
// ??0Rva0088FAA0DebugIOOds@@QAE@XZ, retail 0x0003F380 (70 bytes),
// ??1Rva0088FAA0DebugIOOds@@UAE@XZ, retail 0x0003F460 (55 bytes), plus the
// ??_GRva0088FAA0DebugIOOds@@UAEPAXI@Z scalar deleting destructor at
// 0x0003F430 (33 bytes).
//
// Ported from Open-BFME-1
// Code/Libraries/Source/WWVegas/WWDebug/Rva0088FAA0DebugIOOdsDestructor.cpp:
// same memberless two-vtable DebugIO hierarchy (DebugIOOds::Create already
// landed from DebugIOOds_Create.cpp, so the Rva0088FAA0Create factory is left
// out here). The dtor is the ambiguous twin of ??1DebugCmdInterfaceDebug at
// 0x00039980 (map-resolved here, differs only in the vtable constant); the
// ctor is the 70B two-store EH shape of ??0DebugCmdInterfaceDebug.

class Rva0088FAA0DebugIOInterface
{
protected:
    virtual ~Rva0088FAA0DebugIOInterface(void) {}

public:
    Rva0088FAA0DebugIOInterface(void) {}
    virtual int Read(char *, int) = 0;
    virtual void Write(int, const char *, const char *) = 0;
    virtual void EmergencyFlush(void) = 0;
    virtual void Execute(void) = 0;
    virtual void Delete(void) = 0;
};

class Rva0088FAA0DebugIOOds : public Rva0088FAA0DebugIOInterface
{
public:
    explicit Rva0088FAA0DebugIOOds(void);
    virtual int Read(char *, int) { return 0; }
    virtual void Write(int, const char *, const char *) {}
    virtual void EmergencyFlush(void) {}
    virtual void Execute(void) {}
    virtual void Delete(void);
};

// ??0Rva0088FAA0DebugIOOds@@QAE@XZ
Rva0088FAA0DebugIOOds::Rva0088FAA0DebugIOOds(void)
{
}

// ?Delete@Rva0088FAA0DebugIOOds@@UAEXXZ absent-from-retail
void Rva0088FAA0DebugIOOds::Delete(void)
{
    this->~Rva0088FAA0DebugIOOds();
}
