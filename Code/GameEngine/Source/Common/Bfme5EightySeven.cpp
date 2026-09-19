// A search over a list of pointers.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/Bfme5EightySeven.cpp); trimmed to the single
// T1 body the sweep places.

class BfmeThingHA
{
public:
	int m_bfmeGap[2];							// +0x00
	int m_bfmeA;								// +0x08
	int m_bfmeB;								// +0x0c
};

class Gen_00808E90
{
public:
	BfmeThingHA *bfmeFind(const BfmeThingHA *key) const;
private:
	int m_bfmeGap;								// +0x00
	int m_bfmeCount;							// +0x04
	BfmeThingHA **m_bfmeList;					// +0x08
};

BfmeThingHA *Gen_00808E90::bfmeFind(const BfmeThingHA *key) const
{
	for (int index = 0; index < m_bfmeCount; ++index)
	{
		BfmeThingHA *thing = m_bfmeList[index];
		if (thing != 0 && thing->m_bfmeA == key->m_bfmeA && thing->m_bfmeB == key->m_bfmeB)
			return thing;
	}
	return 0;
}
