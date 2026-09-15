// ?bfmeNextResource@@YA?AUBfmeResetAnyRef@@XZ
// partial score=0.4 date=2026-09-15
// ?bfmeNextResource@@YA?AUBfmeResetAnyRef@@XZ
// partial score=0.4 date=2026-09-15
// ?bfmeNextResource@@YA?AUBfmeResetAnyRef@@XZ
// partial score=0.4 date=2026-09-14
// cl: /O2 /DNDEBUG /MD /EHsc
//
// ?bfmeNextResource@@YA?AUBfmeResetAnyRef@@XZ, retail 0x0061F310, 175 bytes.
// Produces the next owning registry reference. When the global enumerator at
// VA 0x00E09C0C is live, advance it into a branch-local holder and return a
// copy (the copy AddRefs through the WORD reference count at +4, the same
// WORD released by TextureBaseClass::Release_Ref at 0x0061ED10); otherwise
// return a null holder. Each branch destroys only its own holder, hence the
// two conditional Release_Ref calls and the SEH frame. Dedicated TU so the
// definition carries default optimization flags.

struct BfmeResetResource
{
	unsigned char unexamined[4];
	unsigned short refCount;
	void Release_Ref();
};

struct BfmeResetAnyRef
{
	BfmeResetResource *pointer;
	BfmeResetAnyRef() : pointer(0) {}
	BfmeResetAnyRef(const BfmeResetAnyRef &other) : pointer(other.pointer)
	{
		if (pointer != 0)
			pointer->refCount++;
	}
	~BfmeResetAnyRef()
	{
		if (pointer != 0)
			pointer->Release_Ref();
	}
};

struct BfmeResourceEnumerator
{
	BfmeResetAnyRef *Advance(BfmeResetAnyRef *scratch);
};

extern BfmeResourceEnumerator *TheResourceEnumerator;

BfmeResetAnyRef bfmeNextResource()
{
	if (TheResourceEnumerator != 0)
	{
		BfmeResetAnyRef selected;
		return *TheResourceEnumerator->Advance(&selected);
	}
	else
	{
		BfmeResetAnyRef empty;
		return empty;
	}
}
