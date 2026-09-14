// cl: /DNDEBUG /MD /GX- /O2 /Ob2
//
// Add_Prototype thin wrapper (BFME1 Add_Prototype.cpp pattern).
// Null-check the global resource enumerator at VA 0x00E09C0C,
// then thiscall into Add_Prototype_Impl at 0x00621710.

class BfmeResourceEnumerator
{
public:
	void Add_Prototype_Impl(void *prototype);
};

extern BfmeResourceEnumerator *TheResourceEnumerator;

// ?Add_Prototype@@YAXPAX@Z
void Add_Prototype(void *prototype)
{
	if (TheResourceEnumerator)
		TheResourceEnumerator->Add_Prototype_Impl(prototype);
}
