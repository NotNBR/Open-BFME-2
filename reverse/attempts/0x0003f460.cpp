// ??1Rva0088FAA0DebugIOOds@@UAE@XZ
// partial score=0.45 date=2026-09-19
// ??1Rva0088FAA0DebugIOOds@@UAE@XZ
// partial score=0.45 date=2026-09-19
// cl: /DNDEBUG /MD /EHa /Oy-
// Scratch-best explicit-dtor shape for retail @0x3F460 (55B, SEH, Ghidra-55
// exact, prev CC). Compiles 61B: SEH frame and vptr store match, but MSVC
// emits the vptr store TWICE (entry + post-state) where retail stores ONCE
// (post-state only). Implicit dtor refuted (symbol not emitted), /EHsc
// refuted (7B store-only, no SEH), non-virtual base refuted (same double
// store). The single-store+SEH combo needs a non-source lever or a
// different dtor spelling (PipeDestructorThunk precedent is non-empty).

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
    explicit Rva0088FAA0DebugIOOds(void) {}
    virtual ~Rva0088FAA0DebugIOOds(void);
    virtual int Read(char *, int) { return 0; }
    virtual void Write(int, const char *, const char *) {}
    virtual void EmergencyFlush(void) {}
    virtual void Execute(void) {}
    virtual void Delete(void) { this->~Rva0088FAA0DebugIOOds(); }
};

Rva0088FAA0DebugIOOds::~Rva0088FAA0DebugIOOds(void)
{
}
