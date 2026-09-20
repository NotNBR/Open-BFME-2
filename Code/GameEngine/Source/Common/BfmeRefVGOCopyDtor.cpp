// cl: /O1
// BfmeRefVGO copy constructor, retail 0x000A9806 (28B). The BFME1 donor
// (BfmeConv1355.cpp) only carries bfmeAssignVGO; the copy is the same
// single-pointer acquire through the shared VGO refcount helpers: copy the
// pointer, then increment when non-null. Callee resolves through the
// existing bfmeIncVGO pin at 0x006CFDE0.

unsigned __cdecl bfmeIncVGO(unsigned *p);

class BfmeRefVGO
{
public:
    BfmeRefVGO(const BfmeRefVGO &other);

private:
    unsigned *m_bfmeP;
};

// ??0BfmeRefVGO@@QAE@ABV0@@Z
BfmeRefVGO::BfmeRefVGO(const BfmeRefVGO &other)
{
    m_bfmeP = other.m_bfmeP;
    if (m_bfmeP)
        bfmeIncVGO(m_bfmeP);
}
