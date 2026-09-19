// Open-BFME5 conversions.
//
// Retail 0x003E53B1 (23B). Go939D: compare the 939D glob's byte against the
// caller's char, boolized. Transferred from the BFME1 reconstruction
// (BFME1 0x00324340, same BfmeConv939.cpp TU family). Only bfmeGo939D is
// claimed here; the TU's siblings need their own identity passes.

class BfmeGlob939D
{
public:
	char bfmeCall939D();
};

extern BfmeGlob939D *g_bfme939GlobD;

int __stdcall bfmeGo939D(char v)
{
	char r = g_bfme939GlobD->bfmeCall939D();
	return (char)(r - v) == 0;
}
