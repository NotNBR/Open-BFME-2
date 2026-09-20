// cl: /O2 /DNDEBUG /MD
// BFME2 Apt value constructor at RVA 0x006DCD20 (40 bytes).
// Semantic reference: BFME1 Rva00899560AptValueCtor.cpp; BFME2 stores
// the AptVFT type in the high seven flag bits via the out-of-line initializer.
// Its assertions name AptValue/AptValue.inl and require 0 < type < 47.
// The exact original class name and meaning of the unused second argument
// are unknown. This body is not the DrawableModule constructor.
class BfmeAptValue006DCD20
{
    virtual void vtableSlot0();
    unsigned int m_flags;
    void setTypeAt006DBBC0(int type);
public:
    BfmeAptValue006DCD20(int type, unsigned int unused);
};
BfmeAptValue006DCD20::BfmeAptValue006DCD20(int type, unsigned int)
{
    setTypeAt006DBBC0(type);
    m_flags = (m_flags & 0xFE000011u) | 0x10u;
}
