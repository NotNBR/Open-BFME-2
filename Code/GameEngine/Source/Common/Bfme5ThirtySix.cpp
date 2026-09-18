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

// ?bfmeCopyMmx@@YAXPAXHH@Z
// "offset" is an assembler keyword, so the stride cannot carry that name.
void __cdecl bfmeCopyMmx(void *source, int stride, int bytes)
{
	__asm
	{
		mov esi, source
		mov ecx, stride
		mov edx, bytes
	bfmeNext:
		movq mm0, [esi]
		movq [esi+ecx], mm0
		add esi, 8
		sub edx, 8
		jg bfmeNext
	}
}

namespace
{
	__declspec(align(8)) const unsigned short g_bfmeRoundMmx[4] = { 1, 1, 1, 1 };
}

// ?bfmeAverageMmx@@YAXPAXHH@Z
// Blends the row two strides below "source" into the row one stride below it,
// eight bytes at a time. "offset" is an assembler keyword, so the stride
// cannot carry that name.
void __cdecl bfmeAverageMmx(void *source, int stride, int bytes)
{
	__asm
	{
		mov esi, source
		mov ecx, stride
		pxor mm7, mm7
		mov edx, bytes
	bfmeNext:
		movq mm0, [esi]
		movq mm1, [esi+ecx*2]
		movq mm2, mm0
		movq mm3, mm1
		punpcklbw mm0, mm7
		movq mm6, g_bfmeRoundMmx
		punpcklbw mm1, mm7
		paddw mm0, mm1
		punpckhbw mm2, mm7
		paddw mm0, mm6
		punpckhbw mm3, mm7
		paddw mm2, mm3
		psraw mm0, 1
		paddw mm2, mm6
		psraw mm2, 1
		packuswb mm0, mm2
		movq [esi+ecx], mm0
		add esi, 8
		sub edx, 8
		jg bfmeNext
	}
}
