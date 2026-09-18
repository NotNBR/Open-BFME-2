// cl: /Od /Ob0 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc

// Retail calls 0x000245A0, which the ledger already matches as
// ?bfmeFindQH@@YAPAHPAHH@Z (BfmeFindQH.cpp, pinned in symbols.csv);
// the sweep-guess name rva0082BBC0Find names no such body.
int *bfmeFindQH(int *node, int value);

int *rva0082C740Find(int *node, int value)
{
	return bfmeFindQH(node, value);
}
