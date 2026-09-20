// cl: /Od /Gy
// Open-BFME5 conversions.
// ?bfmeOneSUA@BfmeThingSUA@@QAEXD@Z, retail 0x00028BF0 (27B) and
// ?bfmeTwoSUA@BfmeThingSUA@@QAEXD@Z, retail 0x0002A090 (27B). Ported from
// Open-BFME-1 Code/GameEngine/Source/Common/BfmeConv1301.cpp (BFME1 0x0082F700
// and 0x00830390). Trimmed to the two placed forwarders; Three/Four are
// declared-only here. Callee notes: bfmeFwdOneSUA resolves via the new ledger
// pin at 0x000274D0 (single family name; Ghidra 107B body). The Two-body's
// target is the rowed bfmeAssignV16 at 0x00029490 (same B1 body 0x0082FB10),
// spelled with its rowed BfmeStrV16 name; zero bytes differ either way.

class BfmeThingSUA
{
public:
	void bfmeOneSUA(char a);
	void bfmeTwoSUA(char a);
	void bfmeThreeSUA(char a, int b);
	void bfmeFourSUA(int a, int b);
	void bfmeFwdOneSUA(char a, int b);
	void bfmeFwdThreeSUA(char a, int b);
};

class BfmeStrV16
{
public:
	BfmeStrV16 *bfmeAssignV16(unsigned int id, char tag);
};

// ?bfmeOneSUA@BfmeThingSUA@@QAEXD@Z
void BfmeThingSUA::bfmeOneSUA(char a)
{
	bfmeFwdOneSUA(a, 0);
}

// ?bfmeTwoSUA@BfmeThingSUA@@QAEXD@Z
void BfmeThingSUA::bfmeTwoSUA(char a)
{
	((BfmeStrV16 *)this)->bfmeAssignV16(1, a);
}

// ?bfmeThreeSUA@BfmeThingSUA@@QAEXDH@Z
void BfmeThingSUA::bfmeThreeSUA(char a, int b)
{
	bfmeFwdThreeSUA(a, b);
}
