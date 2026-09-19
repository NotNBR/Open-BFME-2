// BfmeThingDSU::bfmeGoDSU -- BFME1 near-miss donor repair.
// Retail 0x0047042E (25B) differs from the BFME1 body (b1 0x00240660) in a
// single literal: the table sits at +0x17c in BFME2, not +0x120.
//
// BFME2 structure differs from the BFME1 donor
// (reference/open-bfme-1/Code/GameEngine/Source/Common/BfmeConv776.cpp):
// the retail call decodes to 0x0028932C, which the ledger already rows as
// stlport map<int,int>::operator[] (its body calls insert, per the pin at
// reverse/symbols.csv:992), so the BfmeSubDSU wrapper is gone here and the
// table is an stlport map. The TU-local declarations below name that same
// operator (definition and rows owned by the WWLib stlport TU) without
// pulling in <map>, which would let MSVC inline the call away.

namespace _STL
{

template <typename Arg>
struct less
{
	bool operator()(const Arg &left, const Arg &right) const;
};

template <typename First, typename Second>
struct pair
{
	First first;
	Second second;
};

template <typename Value>
class allocator
{
};

template <typename Key, typename Value, typename Compare, typename Alloc>
class map
{
public:
	int &operator[](const int &key);

private:
	void *m_header;
	unsigned int m_nodeCount;
};

}

struct BfmeThingDSU
{
	void bfmeGoDSU(void *what, void *v);
	unsigned char m_bfmeHead[0x17c];
	_STL::map<int, int, _STL::less<int>, _STL::allocator<_STL::pair<const int, int> > > m_bfmeTable;
};

void BfmeThingDSU::bfmeGoDSU(void *what, void *v)
{
	m_bfmeTable[*(int *)&what] = (int)v;
}
