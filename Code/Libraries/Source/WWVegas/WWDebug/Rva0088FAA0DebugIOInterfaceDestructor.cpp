// cl: /DNDEBUG /MD /EHa
//
// ??_GRva0088FAA0DebugIOInterface@@MAEPAXI@Z, retail 0x0003F340 (31 bytes).
//
// Base-class scalar deleting destructor of the Rva0088FAA0DebugIO hierarchy
// (derived bodies live in Rva0088FAA0DebugIOOdsDestructor.cpp). The trivial
// inline dtor folds to a vtable store plus operator delete, and the body is
// frameless: this TU builds without /Oy-, unlike the derived /Oy- TU.

class Rva0088FAA0DebugIOInterface
{
protected:
    virtual ~Rva0088FAA0DebugIOInterface(void) {}

public:
    Rva0088FAA0DebugIOInterface(void);
    virtual int Read(char *, int) = 0;
    virtual void Write(int, const char *, const char *) = 0;
    virtual void EmergencyFlush(void) = 0;
    virtual void Execute(void) = 0;
    virtual void Delete(void) = 0;
};

// ??0Rva0088FAA0DebugIOInterface@@QAE@XZ absent-from-retail
Rva0088FAA0DebugIOInterface::Rva0088FAA0DebugIOInterface(void)
{
}
