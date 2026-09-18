// cl: /O1 /MD
//
// ??_GRva002E4272@@UAEPAXI@Z, retail 0x002E42D2, 28 bytes. Dedicated TU.
//
// The complete destructor lives in Rva003B1F65Derived.cpp (row at
// 0x002E4272, 11B tail-jmp to the pinned opaque SEH base); this TU only
// declares it so the deleting-destructor call resolves through the row,
// following the MeshGeometry-copy precedent. Emitted by the delete
// anchor below, following the CollectionClass ??_G precedent.

class Rva002E4272
{
public:
	__declspec(noinline) virtual ~Rva002E4272();

private:
	// Keeps the local destructor non-trivial so the deleting
	// destructor below calls it out of line instead of folding it.
	int m_dummy;
};

// Local definition solely so the delete anchor below emits the ??_G
// scalar-deleting destructor referencing it; the retail body is rowed
// from Rva003B1F65Derived.cpp and duplicate emissions across TUs pass
// the gates. The bytes of this copy are unclaimed.
Rva002E4272::~Rva002E4272()
{
	m_dummy = 0;
}

// Anchor: emits the ??_G scalar-deleting-destructor COMDAT.
void deleteRva002E4272(Rva002E4272 *p)
{
	delete p;
}
