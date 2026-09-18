// Open-BFME: inline-buffer pointer predicate reconstructed from retail RVA 0x00892500.

class Rva00892500Object
{
public:
    char m_padding[8];
    int *m_end;
    int m_inline;

    bool usesInlineBuffer();
};

bool Rva00892500Object::usesInlineBuffer()
{
    int *end = m_end;
    int *inlineValue = &m_inline;
    return end == inlineValue;
}

// Only the first of the donor's two identical twins is defined here: both
// fold to the single BFME2 body at 0x006CD4E0, so one function owns the row
// (one body per address; the name is this sweep's pick among its twins).
