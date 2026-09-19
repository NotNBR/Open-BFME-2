// Guarded indirect call.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/BfmeConv929.cpp); trimmed to the single T1
// body the sweep places.

// Open-BFME5 conversions.

class BfmeThing929B
{
public:
	void bfmeGo929B(void *a, void *b);
	char m_bfmePad[8];
	void (*m_bfmeFn)(void *a, void *b);
};

void BfmeThing929B::bfmeGo929B(void *a, void *b)
{
	void (*fn)(void *, void *) = m_bfmeFn;
	if (!fn)
		return;
	if (!a)
		return;
	fn(a, b);
}
