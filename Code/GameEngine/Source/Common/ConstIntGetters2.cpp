// Cold-slice B8-imm32 const-int returners (twin-free TU).
//
// Same shape as ConstIntGetters.cpp (mov eax,<IMM32> / ret, 6B) but kept in
// a separate TU so this lane does not contend with the hot ConstIntGetters
// appends on origin/master. Rows are opaque address-derived names: each
// body is a CC-island or ret-prev leaf carried by .rdata vtable slots with
// no direct callers and no branch sources, so no class identity is
// witnessed. No // cl: line (defaults match the frameless 6-byte shape).

// ?Rva00742550Get@@YAHXZ @ 0x00742550 (6B): returns 0x1C (28). CC-island
// (16xCC before, 20xCC after), carried by 2 .rdata slots (0x7D3D4C and
// 0x8F1694, same vtable family suffix 4D43D0/4D43D0/46CE6B/87A69C),
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00742550Get(void)
{
	return 0x1C;
}
