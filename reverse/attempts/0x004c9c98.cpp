// ??0MarkerTypeUpdateModuleData@@QAE@XZ
// partial score=0.5 date=2026-09-21
// cl: /O1 /DNDEBUG /MD
//
// ??0MarkerTypeUpdateModuleData@@QAE@XZ, retail 0x004C9C98, 12 bytes.
//
// The module-data half of MarkerType: the ModuleData base carries the vtable
// immediate 0x00C5EDF8 (inline base ctor, so no vtable is emitted and no dtor
// row is owed) plus the tag key at +0x04 retail never stores, and the derived
// word at +0x08 is zeroed in the body. Base-init-before-body is load-bearing:
// it forces the vtable store ahead of the AND-zero, which straight-line
// source schedules the other way. Class identity is the rowed
// MarkerTypeUpdateModuleData::buildFieldParse proc (table 0x00C5ED98 whose
// first field is MarkerType) pushed by the rowed 0x252B11 factory, whose sole
// call to this address is the pin this row supersedes. Frameless leaf; the
// factory's 0x0C news size fits vptr plus tag plus the +0x08 word.

class ModuleData
{
public:
	ModuleData() : m_vtable( reinterpret_cast<const void *>(0x00C5EDF8) ) {}

protected:
	const void *m_vtable;			// +0x00
	unsigned int m_moduleTagNameKey;	// +0x04
};

class MarkerTypeUpdateModuleData : public ModuleData
{
public:
	MarkerTypeUpdateModuleData();

private:
	unsigned int m_08;			// +0x08
};

// ??0MarkerTypeUpdateModuleData@@QAE@XZ
MarkerTypeUpdateModuleData::MarkerTypeUpdateModuleData()
{
	m_08 = 0;
}
