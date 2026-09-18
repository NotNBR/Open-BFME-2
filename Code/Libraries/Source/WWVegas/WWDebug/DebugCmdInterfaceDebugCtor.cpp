// cl: /DNDEBUG /MD /EHa /Oy-
//
// ??0DebugCmdInterfaceDebug@@QAE@XZ, retail 0x00038670 (70 bytes).
// Ported from Open-BFME-1 WWDebug/DebugCmdInterfaceDebugConstructorThunk.cpp
// verbatim: empty DebugCmdInterfaceDebug ctor. Same two-vtable EH shape as
// DebugIOOds / DebugIONet: inlines the DebugCmdInterface vtable store, then
// stores the derived vtable, with the EH state around the derived store
// because the base has a virtual destructor. Dedicated TU so the other
// WWDebug TUs keep their matched bodies.

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug/debug_cmd.h
class DebugCmdInterface
{
protected:
	virtual ~DebugCmdInterface() {}

public:
	DebugCmdInterface() {}
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug/internal.h
class DebugCmdInterfaceDebug : public DebugCmdInterface
{
public:
	explicit DebugCmdInterfaceDebug(void);
};

// ??0DebugCmdInterfaceDebug@@QAE@XZ
DebugCmdInterfaceDebug::DebugCmdInterfaceDebug(void)
{
}

// Anchor: emits the implicit ??1 scalar-dtor COMDAT plus the ??_G
// scalar-deleting-destructor COMDAT. The dtor MUST stay implicit (no
// declaration): an explicitly-defined empty dtor emits the derived vtable
// reinstall at entry (61B), while retail's implicit dtor keeps only the
// EH state plus the base reinstall (55B). Probe-proven in build/.
void deleteCmdInterfaceDebug(DebugCmdInterfaceDebug *p)
{
	delete p;
}
