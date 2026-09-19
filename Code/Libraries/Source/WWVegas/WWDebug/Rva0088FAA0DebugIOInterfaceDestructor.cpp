// cl: /DNDEBUG /MD /EHa
//
// ??_GDebugIOInterface@@MAEPAXI@Z, retail 0x0003F340 (31 bytes).
//
// Base-class scalar deleting destructor of the DebugIOOds hierarchy
// (derived bodies live in Rva0088FAA0DebugIOOdsDestructor.cpp). The trivial
// inline dtor folds to a vtable store plus operator delete, and the body is
// frameless: this TU builds without /Oy-, unlike the derived /Oy- TU. The
// Rva0088FAA0Interface name in the BFME1 donor is the port's guess-label;
// retail owns the base as DebugIOInterface (upstream debug_io.h).

class DebugIOInterface
{
protected:
    virtual ~DebugIOInterface(void) {}

public:
    DebugIOInterface(void);
    virtual int Read(char *, int) = 0;
    virtual void Write(int, const char *, const char *) = 0;
    virtual void EmergencyFlush(void) = 0;
    virtual void Execute(void) = 0;
    virtual void Delete(void) = 0;
};

// ??0DebugIOInterface@@QAE@XZ absent-from-retail
DebugIOInterface::DebugIOInterface(void)
{
}
