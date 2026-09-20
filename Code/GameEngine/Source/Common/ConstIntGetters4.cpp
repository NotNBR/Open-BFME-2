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

// ?Rva003A5A42Get@@YAHXZ @ 0x003a5a42 (6B): returns 0x00C1B5F0.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003A5A42Get(void)
{
	return 0x00C1B5F0;
}

// ?Rva003ABAADGet@@YAHXZ @ 0x003abaad (6B): returns 0x00C1C360.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABAADGet(void)
{
	return 0x00C1C360;
}

// ?Rva003ABAEDGet@@YAHXZ @ 0x003abaed (6B): returns 0x00C1C3B4.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABAEDGet(void)
{
	return 0x00C1C3B4;
}

// ?Rva003ABB1DGet@@YAHXZ @ 0x003abb1d (6B): returns 0x00C1C3F4.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABB1DGet(void)
{
	return 0x00C1C3F4;
}

// ?Rva003ABB4DGet@@YAHXZ @ 0x003abb4d (6B): returns 0x00C1C430.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABB4DGet(void)
{
	return 0x00C1C430;
}

// ?Rva003ABB7DGet@@YAHXZ @ 0x003abb7d (6B): returns 0x00C1C470.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABB7DGet(void)
{
	return 0x00C1C470;
}

// ?Rva003ABBBDGet@@YAHXZ @ 0x003abbbd (6B): returns 0x00C1C4B4.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABBBDGet(void)
{
	return 0x00C1C4B4;
}

// ?Rva003ABBF5Get@@YAHXZ @ 0x003abbf5 (6B): returns 0x00C1C4F4.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABBF5Get(void)
{
	return 0x00C1C4F4;
}

// ?Rva003ABC9FGet@@YAHXZ @ 0x003abc9f (6B): returns 0x00C1C51C.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABC9FGet(void)
{
	return 0x00C1C51C;
}

// ?Rva003ABDB2Get@@YAHXZ @ 0x003abdb2 (6B): returns 0x00C1C5EC.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABDB2Get(void)
{
	return 0x00C1C5EC;
}

// ?Rva003ABE2AGet@@YAHXZ @ 0x003abe2a (6B): returns 0x00C1C630.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABE2AGet(void)
{
	return 0x00C1C630;
}

// ?Rva003ABEBEGet@@YAHXZ @ 0x003abebe (6B): returns 0x00C1C6B4.
// Follows a ret-8 (prev C2-08-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ABEBEGet(void)
{
	return 0x00C1C6B4;
}

// ?Rva003AC930Get@@YAHXZ @ 0x003ac930 (6B): returns 0x00C1C91C.
// Follows a ret-4 (prev C2-04-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003AC930Get(void)
{
	return 0x00C1C91C;
}

// ?Rva003ACA16Get@@YAHXZ @ 0x003aca16 (6B): returns 0x00C1C9CC.
// Follows a ret-4 (prev C2-04-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ACA16Get(void)
{
	return 0x00C1C9CC;
}

// ?Rva003ACA7DGet@@YAHXZ @ 0x003aca7d (6B): returns 0x00C1CA14.
// Follows a ret-4 (prev C2-04-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ACA7DGet(void)
{
	return 0x00C1CA14;
}

// ?Rva003ACAFAGet@@YAHXZ @ 0x003acafa (6B): returns 0x00C1CA6C.
// Follows a ret-4 (prev C2-04-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ACAFAGet(void)
{
	return 0x00C1CA6C;
}

// ?Rva003ACB61Get@@YAHXZ @ 0x003acb61 (6B): returns 0x00C1CAB4.
// Follows a ret-4 (prev C2-04-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ACB61Get(void)
{
	return 0x00C1CAB4;
}

// ?Rva003ACFC1Get@@YAHXZ @ 0x003acfc1 (6B): returns 0x00C1CE30.
// Follows a ret-4 (prev C2-04-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ACFC1Get(void)
{
	return 0x00C1CE30;
}

// ?Rva003ADCE5Get@@YAHXZ @ 0x003adce5 (6B): returns 0x00C1D144.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ADCE5Get(void)
{
	return 0x00C1D144;
}

// ?Rva003ADDC7Get@@YAHXZ @ 0x003addc7 (6B): returns 0x00C1D1B4.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ADDC7Get(void)
{
	return 0x00C1D1B4;
}

// ?Rva003ADEB9Get@@YAHXZ @ 0x003adeb9 (6B): returns 0x00C1D204.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ADEB9Get(void)
{
	return 0x00C1D204;
}

// ?Rva003ADFACGet@@YAHXZ @ 0x003adfac (6B): returns 0x00C1D274.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ADFACGet(void)
{
	return 0x00C1D274;
}

// ?Rva003AE136Get@@YAHXZ @ 0x003ae136 (6B): returns 0x00C1D300.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003AE136Get(void)
{
	return 0x00C1D300;
}

// ?Rva003AE26AGet@@YAHXZ @ 0x003ae26a (6B): returns 0x00C1D368.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003AE26AGet(void)
{
	return 0x00C1D368;
}

// ?Rva003AE336Get@@YAHXZ @ 0x003ae336 (6B): returns 0x00C1D3C0.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003AE336Get(void)
{
	return 0x00C1D3C0;
}

// ?Rva003B00D0Get@@YAHXZ @ 0x003b00d0 (6B): returns 0x00C1D930.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003B00D0Get(void)
{
	return 0x00C1D930;
}

// ?Rva003B014CGet@@YAHXZ @ 0x003b014c (6B): returns 0x00C1D990.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003B014CGet(void)
{
	return 0x00C1D990;
}

// ?Rva00367E8CGet@@YAHXZ @ 0x00367e8c (6B): returns 0x00C1768C.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00367E8CGet(void)
{
	return 0x00C1768C;
}

// ?Rva00367EDBGet@@YAHXZ @ 0x00367edb (6B): returns 0x00C176EC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00367EDBGet(void)
{
	return 0x00C176EC;
}

// ?Rva00367F13Get@@YAHXZ @ 0x00367f13 (6B): returns 0x00C1774C.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00367F13Get(void)
{
	return 0x00C1774C;
}

// ?Rva003680E3Get@@YAHXZ @ 0x003680e3 (6B): returns 0x00C17804.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003680E3Get(void)
{
	return 0x00C17804;
}

// ?Rva00368A0DGet@@YAHXZ @ 0x00368a0d (6B): returns 0x00C179BC.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00368A0DGet(void)
{
	return 0x00C179BC;
}

// ?Rva003730F6Get@@YAHXZ @ 0x003730f6 (6B): returns 0x00BF5A74.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003730F6Get(void)
{
	return 0x00BF5A74;
}

// ?Rva0038374DGet@@YAHXZ @ 0x0038374d (6B): returns 0x00C194A0.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0038374DGet(void)
{
	return 0x00C194A0;
}

// ?Rva003A2875Get@@YAHXZ @ 0x003a2875 (6B): returns 0x00C1AE80.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003A2875Get(void)
{
	return 0x00C1AE80;
}

// ?Rva003A33A1Get@@YAHXZ @ 0x003a33a1 (6B): returns 0x00C1AEA4.
// Follows a ret-28 (prev C2-1C-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003A33A1Get(void)
{
	return 0x00C1AEA4;
}

// ?Rva003A3709Get@@YAHXZ @ 0x003a3709 (6B): returns 0x00BEE898.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003A3709Get(void)
{
	return 0x00BEE898;
}

// ?Rva003ECCD0Get@@YAHXZ @ 0x003eccd0 (6B): returns 0x00BF4E94.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003ECCD0Get(void)
{
	return 0x00BF4E94;
}

// ?Rva003EFD37Get@@YAHXZ @ 0x003efd37 (6B): returns 0x00C36BA8.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003EFD37Get(void)
{
	return 0x00C36BA8;
}

// ?Rva003F24D0Get@@YAHXZ @ 0x003f24d0 (6B): returns 0x00C36E58.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003F24D0Get(void)
{
	return 0x00C36E58;
}

// ?Rva003FAB8DGet@@YAHXZ @ 0x003fab8d (6B): returns 0x00C379F4.
// Follows a ret-4 (prev C2-04-00), carried by 2 .rdata vtable slots,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003FAB8DGet(void)
{
	return 0x00C379F4;
}

// ?Rva003FD783Get@@YAHXZ @ 0x003fd783 (6B): returns 0x00C37D88.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva003FD783Get(void)
{
	return 0x00C37D88;
}

// ?Rva0040C586Get@@YAHXZ @ 0x0040c586 (6B): returns 0x00C39460.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0040C586Get(void)
{
	return 0x00C39460;
}

// ?Rva0041431FGet@@YAHXZ @ 0x0041431f (6B): returns 0x00C3A068.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0041431FGet(void)
{
	return 0x00C3A068;
}

// ?Rva00436846Get@@YAHXZ @ 0x00436846 (6B): returns 0x006D20D3.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00436846Get(void)
{
	return 0x006D20D3;
}

// ?Rva0044643DGet@@YAHXZ @ 0x0044643d (6B): returns 0x006D1F77.
// Follows a ret-4 (prev C2-04-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0044643DGet(void)
{
	return 0x006D1F77;
}

// ?Rva004543A3Get@@YAHXZ @ 0x004543a3 (6B): returns 0x00BF5CF4.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva004543A3Get(void)
{
	return 0x00BF5CF4;
}

// ?Rva4583A9Get@@YAHXZ @ 0x4583a9 (6B): returns 0x00bf5c90.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva4583A9Get(void)
{
	return 0x00bf5c90;
}

// ?Rva458759Get@@YAHXZ @ 0x458759 (6B): returns 0x00bf5c7c.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva458759Get(void)
{
	return 0x00bf5c7c;
}

// ?Rva458FFCGet@@YAHXZ @ 0x458ffc (6B): returns 0x00bf5c5c.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva458FFCGet(void)
{
	return 0x00bf5c5c;
}

// ?Rva4599DFGet@@YAHXZ @ 0x4599df (6B): returns 0x00bf5bf4.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva4599DFGet(void)
{
	return 0x00bf5bf4;
}

// ?Rva45CEEEGet@@YAHXZ @ 0x45ceee (6B): returns 0x00c41ea8.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva45CEEEGet(void)
{
	return 0x00c41ea8;
}

// ?Rva45E9F4Get@@YAHXZ @ 0x45e9f4 (6B): returns 0x00bf5b4c.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva45E9F4Get(void)
{
	return 0x00bf5b4c;
}

// ?Rva0045EFB6Get@@YAHXZ @ 0x0045efb6 (6B): returns 0x00bf5a4c.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva0045EFB6Get(void)
{
	return 0x00bf5a4c;
}

// ?Rva00460827Get@@YAHXZ @ 0x00460827 (6B): returns 0x00bf5ac4.
// Follows a ret-8 (prev C2-08-00), carried by 1 .rdata vtable slot,
// no direct callers, no branch sources. Opaque address-derived name.
int Rva00460827Get(void)
{
	return 0x00bf5ac4;
}
