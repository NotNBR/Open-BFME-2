// B8-imm32 const-int returners: six-byte free functions with one shape:
//
//     mov eax,<IMM32> / ret
//
// Each stands on a CC-island (int3 before and after) with no Ghidra entry
// (dead emissions) and is carried in several .rdata vtable slots, so the
// address is a genuine shared virtual implementation whose class identity
// is not witnessed anywhere. Rows are named for their own address with the
// proven return value, following Rva0073B660False.cpp and the Disp family
// (address-derived names, identity unrecoverable from 6 bytes).
// No // cl: line (defaults match the frameless 6-byte shape).

// ?Rva001820A0Get@@YAHXZ @ 0x001820A0 (6B): returns 8. CC-island
// (4xCC before, 8xCC after), 4 vtable refs in the 0x7D49xx-0x7D55xx mapper
// family, no direct callers, no branch sources.
int Rva001820A0Get(void)
{
	return 8;
}
