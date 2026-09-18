// cl: /Od /Ob0 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc

// Only the first of the donor's two identical twins is defined here: both
// fold to the single BFME2 body at 0x00024AE0, so one function owns the row
// (one body per address; the name is this sweep's pick among its twins).
void rva0082C000Add(int *value, int delta)
{
	*value += delta;
}
