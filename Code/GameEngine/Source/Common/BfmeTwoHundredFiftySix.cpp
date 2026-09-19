// cl: /Od
// Port of Open-BFME-1 Code/GameEngine/Source/Common/BfmeTwoHundredFiftySix.cpp
// (near-miss donor: ?bfmeSetOU@BfmeThingOU@@QAEPAV1@E@Z @0x00830C30, 30B).
// Only the served setter is carried here.
//
// WHAT THE BODY IS. An unoptimised frame setter: it spills `this`, pushes
// the byte argument and delegates to the private worker, returning `this`.
// Retail routes the worker call at 0x0000C330, the rowed 84-byte stlport
// narrow-string push_back body (ghidra concurs on the extent): the worker is
// that append operation on the string at +0, folded onto a single address in
// BFME2. BFME1 pins the same worker name at 0x0003BC23, so the name is kept
// and the pin transposed to the BFME2 fold address; the call itself is the
// byte-match proof.

class BfmeThingOU
{
public:
	BfmeThingOU *bfmeSetOU(unsigned char one);

	void bfmeDoOU(unsigned char one);
};

BfmeThingOU *BfmeThingOU::bfmeSetOU(unsigned char one)
{
	unsigned char spare[0x14];

	bfmeDoOU(one);

	return this;
}
