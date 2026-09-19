// cl: /DNDEBUG /MD /GX-

// LZHLCompress, retail 0x0068ECA0 (25B).
// Ported from Open-BFME-1 Code/Libraries/Source/Compression/LZHCompress/CompLibSource/LZHLApi.cpp
// (BFME1 0x00823130). Only the placed compress probe is defined here; the
// donor's create/destroy/maxbuf helpers stay out, so the unmatched-definition
// gate passes. Retail shuffles the four cdecl slots into thiscall shape
// (this = handle, push dst/src/size) and tail-returns the member answer
// through the single pinned call site.

typedef unsigned char BYTE;

class LZHLCompressor
{
public:
	unsigned int compress(BYTE *dst, const BYTE *src, unsigned int size);
};

// ?LZHLCompress@@YAIPAX00I@Z, retail 0x0068ECA0 (25B).
unsigned int LZHLCompress(void *handle, void *destination, void *source, unsigned int sourceSize)
{
	return static_cast<LZHLCompressor *>(handle)->compress(
		static_cast<BYTE *>(destination), static_cast<const BYTE *>(source), sourceSize);
}
