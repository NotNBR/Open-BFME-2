// Make-and-return body Gen_0035B680::bfmeCreate.
//
// BFME1 donor Bfme5MakeAndReturn.cpp verbatim shape: a single new expression
// (allocate, test the block, construct it with this, hand it back, with the
// failed allocation returning zero through its own epilogue). BFME2 repair:
// the created class is 0x38 wide here (push 0x38), not BFME1's 0x40, so the
// field run is 0xE ints, not 0x10. B1 0x0035B680 93B -> B2 0x001701E0 93B,
// immediate-only drift at +0x18 (push 0x40 vs 0x38).


class Gen_0035B680;

class BfmeCreated_0035B680
{
public:
	BfmeCreated_0035B680(Gen_0035B680 *owner);

private:
	int m_bfmeFields[0xE];
};

class Gen_0035B680
{
public:
	BfmeCreated_0035B680 *bfmeCreate(void);
};

// ?bfmeCreate@Gen_0035B680@@QAEPAVBfmeCreated_0035B680@@XZ
BfmeCreated_0035B680 *Gen_0035B680::bfmeCreate(void)
{
	return new BfmeCreated_0035B680(this);
}
