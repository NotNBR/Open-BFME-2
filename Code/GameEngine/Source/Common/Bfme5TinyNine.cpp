// ?bfmeLoadTable@@YAXPAE@Z, retail 0x001B7050 (24B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/Bfme5TinyNine.cpp.
// Table copy into an object: the intrinsic memcpy becomes the retail rep
// movsd and the table address is a masked DIR32. The byte-twin BFME1 ctor
// ??0Rva00354B60 is refuted by ABI (retail reads its pointer from the stack;
// a thiscall ctor would take this in ecx), so the cdecl loader owns the name.

extern "C" void *__cdecl memcpy(void *destination, const void *source, unsigned int bytes);

#pragma intrinsic(memcpy)

extern int g_bfmeTableBZ[64];

// ?bfmeLoadTable@@YAXPAE@Z
void __cdecl bfmeLoadTable(unsigned char *out)
{
	memcpy(out + 0x3C, g_bfmeTableBZ, sizeof(g_bfmeTableBZ));
}
