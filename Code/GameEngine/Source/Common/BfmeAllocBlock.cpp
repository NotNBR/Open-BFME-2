// Retail 0x001B63C0 is BFME1's ?bfmeAllocBlock@@YAPAXI@Z pattern:
// through the global allocator when present, otherwise through the game's
// byte allocator at 0x000307F0.
//
// BFME1 donor is reference/open-bfme-1/Code/GameEngine/Source/Common/
// Bfme5AllocBlock.cpp (62B at b1 0x009A5920). The global is a DIR32 slot
// (masked, no pin needed); the fallback resolves through the existing
// ?vectorSmallAllocate@_STL@@YAPAXII@Z pin at 0x000307F0, called as
// (bytes, 0) to reproduce retail's two pushes.

class BfmeAllocGlobal
{
public:
	virtual void *allocate(unsigned int bytes, void *metadata);
};

extern BfmeAllocGlobal *g_bfmeAllocGlobal;

namespace _STL
{
void *vectorSmallAllocate(unsigned int bytes, unsigned int alignment);
}

// ?bfmeAllocBlock@@YAPAXI@Z
void *__cdecl bfmeAllocBlock(unsigned int bytes)
{
	BfmeAllocGlobal *global = g_bfmeAllocGlobal;
	if (global)
	{
		unsigned int metadata[3] = { 0, 0, 0 };
		return global->allocate(bytes, metadata);
	}
	return _STL::vectorSmallAllocate(bytes, 0);
}
