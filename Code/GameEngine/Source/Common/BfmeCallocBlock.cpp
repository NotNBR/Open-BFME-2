// Two allocations that hand back cleared memory — calloc half.
//
// Retail 0x001B6460 is BFME1's ?bfmeCallocBlock@@YAPAXII@Z verbatim:
// count times size, allocate through bfmeAllocBlock, and clear only when
// the block came back. The memset intrinsic compiles to the retail
// rep-stosd/rep-stosb tail under the base /O2 flags.
//
// The donor TU (reference/open-bfme-1/Code/GameEngine/Source/Common/
// Bfme5AllocAndZero.cpp) also defines bfmeMakeBlock, which game.dat does
// not place, so only the calloc body moves here under its own TU name.

extern "C" void *__cdecl memset(void *block, int value, unsigned int bytes);

#pragma intrinsic(memset)

void *__cdecl bfmeAllocBlock(unsigned int bytes);

// ?bfmeCallocBlock@@YAPAXII@Z
void *__cdecl bfmeCallocBlock(unsigned int count, unsigned int size)
{
	unsigned int bytes = count * size;

	void *block = bfmeAllocBlock(bytes);

	if (block)
		memset(block, 0, bytes);

	return block;
}
