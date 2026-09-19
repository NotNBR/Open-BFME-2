// Trimmed from Open-BFME-1
// (Code/GameEngine/Source/Common/R2SmallMemberOps.cpp): only the placed
// Rva009A8C30 helper is defined here. The donor's other 41 members stay out,
// so the unmatched-definition gate passes.

class Rva009A8C30Owner
{
public:
	char m_leading[0x1C0];
	int m_at1C0;
	int m_at1C4;
};

void Rva009A8C30(Rva009A8C30Owner *owner)
{
	owner->m_at1C0 = 8;
	owner->m_at1C4 = 8;
}
