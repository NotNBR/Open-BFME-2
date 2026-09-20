// Cold-slice B8-imm32 const-int returners (twin-free TU).
//
// Same shape as ConstIntGetters2.cpp/ConstIntGetters3.cpp (mov eax,<IMM32> /
// ret, 6B) but kept in a separate TU so this lane does not contend with the
// hot ConstIntGetters appends on origin/master. Rows are opaque
// address-derived names: each body follows a ret-imm (C2-04-00 / C2-08-00)
// and is carried by .rdata vtable slots with no direct callers and no branch
// sources, so no class identity is witnessed. No // cl: line (defaults match
// the frameless 6-byte shape).

// ?Rva0033F4ABGet@@YAHXZ @ 0x0033f4ab (6B): returns 0x00C1123C.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F4ABGet(void)
{
	return 0x00C1123C;
}

// ?Rva0033F4D9Get@@YAHXZ @ 0x000033f4d9 (6B): returns 0x00C1129C.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F4D9Get(void)
{
	return 0x00C1129C;
}

// ?Rva0033F53AGet@@YAHXZ @ 0x000033f53a (6B): returns 0x00C1135C.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F53AGet(void)
{
	return 0x00C1135C;
}

// ?Rva0033F565Get@@YAHXZ @ 0x000033f565 (6B): returns 0x00C113AC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F565Get(void)
{
	return 0x00C113AC;
}

// ?Rva0033F590Get@@YAHXZ @ 0x0033f590 (6B): returns 0x00C113FC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F590Get(void)
{
	return 0x00C113FC;
}

// ?Rva0033F5B3Get@@YAHXZ @ 0x0033f5b3 (6B): returns 0x00C11454.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F5B3Get(void)
{
	return 0x00C11454;
}

// ?Rva0033F5DDGet@@YAHXZ @ 0x0033f5dd (6B): returns 0x00C114AC.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F5DDGet(void)
{
	return 0x00C114AC;
}

// ?Rva0033F5FFGet@@YAHXZ @ 0x0033f5ff (6B): returns 0x00C11504.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F5FFGet(void)
{
	return 0x00C11504;
}

// ?Rva0033F621Get@@YAHXZ @ 0x0033f621 (6B): returns 0x00C11564.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F621Get(void)
{
	return 0x00C11564;
}

// ?Rva0033F648Get@@YAHXZ @ 0x0033f648 (6B): returns 0x00C115CC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F648Get(void)
{
	return 0x00C115CC;
}

// ?Rva0033F676Get@@YAHXZ @ 0x0033f676 (6B): returns 0x00C1162C.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F676Get(void)
{
	return 0x00C1162C;
}

// ?Rva0033F698Get@@YAHXZ @ 0x0033f698 (6B): returns 0x00C1167C.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F698Get(void)
{
	return 0x00C1167C;
}

// ?Rva0033F6BAGet@@YAHXZ @ 0x0033f6ba (6B): returns 0x00C116DC.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F6BAGet(void)
{
	return 0x00C116DC;
}

// ?Rva0033F6FBGet@@YAHXZ @ 0x0033f6fb (6B): returns 0x00C11784.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F6FBGet(void)
{
	return 0x00C11784;
}

// ?Rva0033F71EGet@@YAHXZ @ 0x0033f71e (6B): returns 0x00C117DC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F71EGet(void)
{
	return 0x00C117DC;
}

// ?Rva0033F745Get@@YAHXZ @ 0x0033f745 (6B): returns 0x00C11834.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F745Get(void)
{
	return 0x00C11834;
}

// ?Rva0033F76CGet@@YAHXZ @ 0x0033f76c (6B): returns 0x00C11894.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F76CGet(void)
{
	return 0x00C11894;
}

// ?Rva0033F797Get@@YAHXZ @ 0x0033f797 (6B): returns 0x00C118F4.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F797Get(void)
{
	return 0x00C118F4;
}

// ?Rva0033F7C2Get@@YAHXZ @ 0x0033f7c2 (6B): returns 0x00C11944.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F7C2Get(void)
{
	return 0x00C11944;
}

// ?Rva0033F7E5Get@@YAHXZ @ 0x0033f7e5 (6B): returns 0x00C119A0.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F7E5Get(void)
{
	return 0x00C119A0;
}

// ?Rva0033F808Get@@YAHXZ @ 0x0033f808 (6B): returns 0x00C119F4.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F808Get(void)
{
	return 0x00C119F4;
}

// ?Rva0033F837Get@@YAHXZ @ 0x0033f837 (6B): returns 0x00C11A4C.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033F837Get(void)
{
	return 0x00C11A4C;
}

// ?Rva0033FC3CGet@@YAHXZ @ 0x0033fc3c (6B): returns 0x00C11DF4.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033FC3CGet(void)
{
	return 0x00C11DF4;
}

// ?Rva0033FE9DGet@@YAHXZ @ 0x0033fe9d (6B): returns 0x00C11E4C.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0033FE9DGet(void)
{
	return 0x00C11E4C;
}

// ?Rva003400F3Get@@YAHXZ @ 0x003400f3 (6B): returns 0x00C11F48.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003400F3Get(void)
{
	return 0x00C11F48;
}

// ?Rva003403ADGet@@YAHXZ @ 0x003403ad (6B): returns 0x00C12090.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003403ADGet(void)
{
	return 0x00C12090;
}

// ?Rva00367839Get@@YAHXZ @ 0x00367839 (6B): returns 0x00C1758C.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00367839Get(void)
{
	return 0x00C1758C;
}

// ?Rva00346CF5Get@@YAHXZ @ 0x00346cf5 (6B): returns 0x00C136E8.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00346CF5Get(void)
{
	return 0x00C136E8;
}

// ?Rva00362E16Get@@YAHXZ @ 0x00362e16 (6B): returns 0x00C17098.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00362E16Get(void)
{
	return 0x00C17098;
}

// ?Rva00362F5EGet@@YAHXZ @ 0x00362f5e (6B): returns 0x00BCB950.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00362F5EGet(void)
{
	return 0x00BCB950;
}

// ?Rva00136825Get@@YAHXZ @ 0x00136825 (6B): returns 0x6D6F6472.
// Follows a ret-28 (prev C2-1C-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00136825Get(void)
{
	return 0x6D6F6472;
}

// ?Rva0015162CGet@@YAHXZ @ 0x0015162c (6B): returns 0x46585348.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0015162CGet(void)
{
	return 0x46585348;
}

// ?Rva0017FB8EGet@@YAHXZ @ 0x0017fb8e (6B): returns 0x48494552.
// Follows a ret-12 (prev C2-0C-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0017FB8EGet(void)
{
	return 0x48494552;
}

// ?Rva0017FFC4Get@@YAHXZ @ 0x0017ffc4 (6B): returns 0x484C4F44.
// Follows a ret-12 (prev C2-0C-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0017FFC4Get(void)
{
	return 0x484C4F44;
}

// ?Rva001826B0Get@@YAHXZ @ 0x001826b0 (6B): returns 0x0000000A.
// Follows a ret-16 (prev C2-10-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva001826B0Get(void)
{
	return 0x0000000A;
}

// ?Rva0028C933Get@@YAHXZ @ 0x0028c933 (6B): returns 0x00BFBD24.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0028C933Get(void)
{
	return 0x00BFBD24;
}

// ?Rva00299C6EGet@@YAHXZ @ 0x00299c6e (6B): returns 0x00BE07C4.
// Follows a ret-20 (prev C2-14-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00299C6EGet(void)
{
	return 0x00BE07C4;
}

// ?Rva002B117CGet@@YAHXZ @ 0x002b117c (6B): returns 0x00BFDF5C.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva002B117CGet(void)
{
	return 0x00BFDF5C;
}

// ?Rva002C74FBGet@@YAHXZ @ 0x002c74fb (6B): returns 0x00C008AC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva002C74FBGet(void)
{
	return 0x00C008AC;
}

// ?Rva002CC2F6Get@@YAHXZ @ 0x002cc2f6 (6B): returns 0x00BE1058.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva002CC2F6Get(void)
{
	return 0x00BE1058;
}

// ?Rva002D6E02Get@@YAHXZ @ 0x002d6e02 (6B): returns 0x00C03368.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva002D6E02Get(void)
{
	return 0x00C03368;
}

// ?Rva002E07C6Get@@YAHXZ @ 0x002e07c6 (6B): returns 0x00C04920.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva002E07C6Get(void)
{
	return 0x00C04920;
}

// ?Rva0008FC9DGet@@YAHXZ @ 0x0008fc9d (6B): returns 0x0049DCEE.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0008FC9DGet(void)
{
	return 0x0049DCEE;
}

// ?Rva0008FFBEGet@@YAHXZ @ 0x0008ffbe (6B): returns 0x0048FF84.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0008FFBEGet(void)
{
	return 0x0048FF84;
}

// ?Rva001052F9Get@@YAHXZ @ 0x001052f9 (6B): returns 0x00504FD5.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva001052F9Get(void)
{
	return 0x00504FD5;
}

// ?Rva003A59ADGet@@YAHXZ @ 0x003a59ad (6B): returns 0x00C1B5B8.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003A59ADGet(void)
{
	return 0x00C1B5B8;
}
