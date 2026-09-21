// cl: /G7 /arch:SSE /MD /EHsc /DNDEBUG /DWIN32 /D_WINDOWS
//
// Opaque 0xA8-byte array-deleted class for retail 0x0073B700.
//
// Identity OPEN. The Zero Hour ??_EPivotClass pairing is REFUTED: retail
// HTree.Pivot elements are proven 0x58 bytes (green Scale 0x160C00 and copy
// ctor 0x1662A0 rows stride Pivot[] by 0x58), while this body pushes 0xA8.
// The ??_E shape is generic across WW3D classes (shared heap helper and
// delete callees), so the 63/64 match against htree.cpp's emission proves the
// TU context and flags, not the name. The body sits in Partition/Shroud
// territory (neighbors 0x73B520-0x73B660 STL, 0x73B750 likely its ??_G).
// Retail-measured facts only: sizeof 0xA8, array cookie at [esi-4],
// per-element dtor via ??_M, scalar ??3@0x2FD60, vector ??_V@0x2FD80.

// Retail's array branch frees through the vector delete operator; MSVC only
// routes the call through ??_V when a vector-delete is declared in the TU
// (probe-proven: without this declaration cl emits ??3 in both branches).
// The declaration emits no code.
void operator delete[](void *p);

class Rva0073B700
{
public:
	~Rva0073B700();
private:
	// Retail-measured size only. Contents unknown.
	char m_pad[0xA8];
};

// ??1Rva0073B700@@QAE@XZ present-unmatched
Rva0073B700::~Rva0073B700()
{
}

// ?Rva0073B700DeleteArray@@YAXPAVRva0073B700@@@Z absent-from-retail
void Rva0073B700DeleteArray(Rva0073B700 *array)
{
	delete[] array;
}
