// ?Rva000BEED0@@YAPAVR1DwordPair@@PAV1@HH@Z, retail 0x00219701 (18B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/R1SmallFieldInitialisers.cpp
// (BFME1 0x000BEED0). The donor bytes are the only free placement: the other
// two candidates sit inside the matched STLport __copy_sign bodies (86B at
// 0x0000FA80 and 89B at 0x00010640), so elimination leaves this address. The
// helper fills an R1DwordPair from two ints and hands the pair back.

class R1DwordPair
{
public:
	int m_first;
	int m_second;
};

R1DwordPair *Rva000BEED0(R1DwordPair *pair, int first, int second)
{
	pair->m_first = first;
	pair->m_second = second;
	return pair;
}
