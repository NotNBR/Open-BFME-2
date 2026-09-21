// ?checkedInteger@BfmeAptValue006DCD20@@QAEPAV1@XZ
// partial score=0.88 date=2026-09-21
// cl: /O1 /MD
// PC AptValue.inl checked casts. Names are descriptive local shims; exact
// derived target type names are not asserted from another game's PDB.
extern void (__cdecl *g_bfmeAptAssertAtE17734)(const char *, const char *, int);
extern int g_bfmeAptBreakOnAssertAtDDC01C;
void __debugbreak();
#pragma intrinsic(__debugbreak)
class BfmeAptValue006DCD20 {
public:
    int isLookup() const;
    int isInteger() const;
    int isRegister() const;
    int isFloat() const;
    int isString() const;
    BfmeAptValue006DCD20 *checkedLookup();
    BfmeAptValue006DCD20 *checkedInteger();
    BfmeAptValue006DCD20 *checkedRegister();
    BfmeAptValue006DCD20 *checkedFloat();
    BfmeAptValue006DCD20 *checkedString();
};
BfmeAptValue006DCD20 *BfmeAptValue006DCD20::checkedLookup()
{
    if (!static_cast<unsigned char>(isLookup())) {
        g_bfmeAptAssertAtE17734("isLookup()","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",632);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    return this;
}
BfmeAptValue006DCD20 *BfmeAptValue006DCD20::checkedInteger()
{
    if (!static_cast<unsigned char>(isInteger())) {
        g_bfmeAptAssertAtE17734("isInteger()","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",657);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    return this;
}
BfmeAptValue006DCD20 *BfmeAptValue006DCD20::checkedRegister()
{
    if (!static_cast<unsigned char>(isRegister())) {
        g_bfmeAptAssertAtE17734("isRegister()","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",682);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    return this;
}
BfmeAptValue006DCD20 *BfmeAptValue006DCD20::checkedFloat()
{
    if (!static_cast<unsigned char>(isFloat())) {
        g_bfmeAptAssertAtE17734("isFloat()","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",707);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    return this;
}
BfmeAptValue006DCD20 *BfmeAptValue006DCD20::checkedString()
{
    if (!static_cast<unsigned char>(isString())) {
        g_bfmeAptAssertAtE17734("isString()","c:\\projects\\bfme2patch103\\bfme2\\code\\libraries\\source\\apt\\AptValue/AptValue.inl",732);
        if (g_bfmeAptBreakOnAssertAtDDC01C) __debugbreak();
    }
    return this;
}
