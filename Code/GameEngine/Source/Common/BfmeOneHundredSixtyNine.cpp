// cl: /Od /GR- /EHsc-
// Whether a number falls inside a range, kept at the low end of the two and
// short of the high one. Built without the optimiser, as retail has it.
//
// Single-pick claim: BFME1 folds bfmeInsideAM (b1 0x0082BF00) and
// bfmeWithinAM (b1 0x0082BF80) to identical bytes, and game.dat carries one
// body at 0x00024A20. Only the InsideAM spelling is defined here so the TU
// holds one claimed body (one body per address; a second same-range row
// would be an over-claim). The WithinAM twin is documented, not rowed.

class BfmeRangeAM
{
public:
	unsigned char bfmeInsideAM(unsigned int value) const;
	unsigned char bfmeWithinAM(unsigned int value) const;

private:
	unsigned int m_bfmeLow;			// 0x0
	unsigned int m_bfmeHigh;		// 0x4
};

unsigned char BfmeRangeAM::bfmeInsideAM(unsigned int value) const
{
	unsigned int at = value;

	return (unsigned char)((at >= m_bfmeLow && at < m_bfmeHigh) ? 1 : 0);
}
