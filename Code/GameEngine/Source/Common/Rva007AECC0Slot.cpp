// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// Trimmed from Open-BFME-1
// (Code/GameEngine/Source/Common/Rva007AECC0Slot.cpp): only the placed
// Rva007AECC0Slot::set body is defined here. get/getPair stay declared-only
// and the donor's other members stay out, so the unmatched-definition gate
// passes. The slot holds an array of item pointers at +0x58; each item
// carries its value at +0x68.

struct Rva007AECC0Item
{
	char m_pad[0x68];
	int m_value;
};

class Rva007AECC0Slot
{
public:
	void set(unsigned int index, int value);
	int get(unsigned int index);
	void getPair(unsigned int index, int *first, int *second);

	char m_pad[0x58];
	Rva007AECC0Item *m_items[1];
};

void Rva007AECC0Slot::set(unsigned int index, int value)
{
	Rva007AECC0Item *item = m_items[index];
	if (item)
		item->m_value = value;
}
