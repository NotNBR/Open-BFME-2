// BFME1 byte-identical donor: reference/open-bfme-1/Code/GameEngine/Source/Common/Bfme5ThirtySix.cpp
// Trimmed to the bodies that reproduce game.dat bytes. The file's counted-handle
// and bounded-read members (BfmeHandleCX/bfmeGet, Gen_009CBC90/bfmeAt) are BFME1-only
// shapes with no matching body here, and bfmeBlurRowsSse is a bare-assembly
// kernel in the donor that the conversion gate refuses as a lift; all three
// stay out so every defined function has a ledger row.

// The copy is the compiler's own memcpy, not hand-written assembly: only the
// intrinsic puts the register saves between the argument loads.
extern "C" void * __cdecl memcpy(void *destination, const void *source, unsigned int bytes);

#pragma intrinsic(memcpy)

// ?bfmeCopy@@YAXPBXIPAX@Z
void __cdecl bfmeCopy(const void *source, unsigned int bytes, void *destination)
{
	memcpy(destination, source, bytes);
}
