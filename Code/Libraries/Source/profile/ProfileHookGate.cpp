// cl: /MD
//
// Profile hook gate at retail 0x0006C8380 (21B).
// Decoded from retail bytes: calls the optional global hook at
// [0x00E0C768] with (1, 0) when non-null (indirect call with no
// caller cleanup, so the hook is __stdcall), then returns 1.
// Human-readable names; opaque identity (no callers, no literals).

typedef int (__stdcall *Rva006C8380Hook)(int first, int second);

#define TheProfileHook (*(Rva006C8380Hook *)0x00E0C768)

int rva006C8380()
{
	if (TheProfileHook != 0)
		TheProfileHook(1, 0);
	return 1;
}
