// Open-BFME5 conversions - BfmeHostER float-bucket index.
//
// Near-miss donor from Open-BFME-1 BfmeConv2039.cpp
// (?bfmeIndexER@BfmeHostER@@QAEIM@Z @0x009F46E0, 100B), carried verbatim
// including its fld/fistp pair: plain C++ lowers the float-to-int step to
// an out-of-line _ftol call, while retail holds the inline x87 shape, so
// the asm is load-bearing here (same finding as the BfmeHostES twin at
// 0x00627020). Sole BFME2 repair: the head array grew by 0x30, so
// m_bfmeInvER sits at +0x118 and m_bfmeCountER at +0x11C (not BFME1's
// +0xE8/+0xEC). The floor call reaches the msvcr71 floor import through its
// IAT slot; no new pins.

extern "C" __declspec(dllimport) double floor(double x);

class BfmeHostER
{
public:
	unsigned int bfmeIndexER(float v);

	float m_bfmeBaseER;
	unsigned char m_bfmeHeadER[0x114];
	float m_bfmeInvER;            // +0x118
	unsigned int m_bfmeCountER;   // +0x11C
};

unsigned int BfmeHostER::bfmeIndexER(float v)
{
	float t = (float)floor((v - m_bfmeBaseER) * m_bfmeInvER * (float)m_bfmeCountER);
	int i;

	__asm fld t
	__asm fistp i

	if (i < 0)
		return 0;

	if ((unsigned int)i >= m_bfmeCountER)
		i = m_bfmeCountER - 1;

	return i;
}
