// Open-BFME5 conversions - BfmeHostES float-bucket index.
//
// Near-miss donor from Open-BFME-1 BfmeConv2040.cpp
// (?bfmeIndexES@BfmeHostES@@QAEIM@Z @0x009F4750, 101B), carried verbatim
// including its fld/fistp pair: plain C++ lowers the float-to-int step to
// an out-of-line _ftol call, while retail holds the inline x87 shape, so
// the asm is load-bearing here. Sole BFME2 repair: the head array grew by
// 0x30, so m_bfmeInvES sits at +0x118 and m_bfmeCountES at +0x11C (not
// BFME1's +0xE8/+0xEC) -- the same +0x30 shift the BfmeHostEQR lane proved
// at 0x00627810. The floor call reaches the BfmeFloorER import through its
// IAT slot; no new pins.

extern "C" __declspec(dllimport) double floor(double x);

class BfmeHostES
{
public:
	unsigned int bfmeIndexES(float v);

	unsigned char m_bfmeLeadES[4];
	float m_bfmeBaseES;
	unsigned char m_bfmeHeadES[0x110];
	float m_bfmeInvES;            // +0x118
	unsigned int m_bfmeCountES;   // +0x11C
};

unsigned int BfmeHostES::bfmeIndexES(float v)
{
	float t = (float)floor((v - m_bfmeBaseES) * m_bfmeInvES * (float)m_bfmeCountES);
	int i;

	__asm fld t
	__asm fistp i

	if (i < 0)
		return 0;

	if ((unsigned int)i >= m_bfmeCountES)
		i = m_bfmeCountES - 1;

	return i;
}
