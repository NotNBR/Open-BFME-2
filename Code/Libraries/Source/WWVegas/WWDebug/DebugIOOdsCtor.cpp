// cl: /DNDEBUG /MD /EHa /Oy-
//
// ??0DebugIOOds@@QAE@XZ, retail 0x0003F380 (70 bytes).
// ??1DebugIOOds@@UAE@XZ, retail 0x0003F460 (55 bytes).
// ??_GDebugIOOds@@UAEPAXI@Z, retail 0x0003F430 (33 bytes).
// Ported from Open-BFME-1 WWDebug/Rva0088FAA0DebugIOOdsDestructor.cpp
// verbatim shape: empty DebugIOOds ctor/dtor. Same two-vtable EH shape as
// DebugCmdInterfaceDebug: inlines the DebugIOInterface vtable store, then
// stores the derived vtable, with the EH state around the derived store
// because the base has a virtual destructor. Dedicated TU so the other
// WWDebug TUs keep their matched bodies.

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug/debug_io.h
class DebugIOInterface
{
protected:
	virtual ~DebugIOInterface() {}

public:
	DebugIOInterface() {}
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug/debug_io_ods.h
class DebugIOOds : public DebugIOInterface
{
public:
	explicit DebugIOOds(void);
};

// ??0DebugIOOds@@QAE@XZ
DebugIOOds::DebugIOOds(void)
{
}

// Anchor: emits the implicit ??1 scalar-dtor COMDAT plus the ??_G
// scalar-deleting-destructor COMDAT. The dtor MUST stay implicit (no
// declaration): an explicitly-defined empty dtor emits the derived vtable
// reinstall at entry (61B), while retail's implicit dtor keeps only the
// EH state plus the base reinstall (55B). Probe-proven in build/.
void deleteDebugIOOds(DebugIOOds *p)
{
	delete p;
}
