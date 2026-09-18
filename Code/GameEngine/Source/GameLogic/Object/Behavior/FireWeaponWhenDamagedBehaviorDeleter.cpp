// cl: /O1 /G7 /DNDEBUG /DWIN32 /D_WINDOWS /MD
//
// ??_GFireWeaponWhenDamagedBehavior@@UAEPAXI@Z, retail 0x004A4D54 (28 bytes).
// Scalar deleting destructor: calls the dtor at 0x004A4C19 (rowed opaque as
// ??1Rva004A4C19 in Rva0024A797Grandchildren.cpp; same 4-vptr MI shape) then
// conditional global operator delete (matched 0x002FD60).
// Identity proof: adjacent to the reloc-named ctor at 0x004A4CC7 (ModuleFactory
// call-site names ??0FireWeaponWhenDamagedBehavior@@QAE@PAVThing@@PBVModuleData@@Z),
// which installs the same four vtables (0xC52868/0xC49188/0xC5285C/0xC52858);
// the dtor reinstalls that set and tail-jmps base 0x0024A797.
// The dtor is declared-not-defined so this TU calls it out-of-line (callee
// visibility); it resolves via the real-name pin alongside the opaque row.

class Thing;
class ModuleData;

class FireWeaponWhenDamagedBehavior
{
public:
	virtual ~FireWeaponWhenDamagedBehavior();
	FireWeaponWhenDamagedBehavior();
};

// ??0FireWeaponWhenDamagedBehavior@@QAE@XZ present-unmatched
FireWeaponWhenDamagedBehavior::FireWeaponWhenDamagedBehavior()
{
}

void FireWeaponWhenDamagedBehaviorDeleter(FireWeaponWhenDamagedBehavior *doomed)
{
	delete doomed;
}
