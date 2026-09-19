// Two bodies whose call goes through a DWORD SLOT (FF 15 + DIR32 into .idata).
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/S1IndirectSlotCalls.cpp); trimmed to the two
// T1 bodies the sweep places. Slots are spelled as function-pointer globals
// named after their RVA.

typedef void ( *BfmeVoidSlot )();
typedef int ( *BfmeIntSlot )();

extern BfmeVoidSlot Data00F595C4;
extern BfmeIntSlot Data00F59544;

// Constructor: call a different slot, then set one byte at offset 0.
class Rva00694BC0
{
public:
	Rva00694BC0();
	bool m_flag;
};

Rva00694BC0::Rva00694BC0()
{
	Data00F595C4();
	m_flag = true;
}

// Void: store the slot's dword result into a member far out in the object.
class Rva006629A0
{
public:
	void refresh();
	char m_lead[ 0x34C ];
	int m_value;
};

void Rva006629A0::refresh()
{
	m_value = Data00F59544();
}
