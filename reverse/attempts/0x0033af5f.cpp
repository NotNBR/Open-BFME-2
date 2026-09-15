// ??$_M_find@V?$BitFlags@$0BB@@@@?$_Rb_tree@$$CBV?$BitFlags@$0BB@@@U?$pair@$$CBV?$BitFlags@$0BB@@@PBVWeaponTemplateSet@@@_STL@@U?$_Select1st@U?$pair@$$CBV?$BitFlags@$0BB@@@PBVWeaponTemplateSet@@@_STL@@@3@UMapHelper@?$SparseMatchFinder@VWeaponTemplateSet@@V?$BitFlags@$0BB@@@@@V?$allocator@U?$pair@$$CBV?$BitFlags@$0BB@@@PBVWeaponTemplateSet@@@_STL@@@3@@_STL@@ABEPAU?$_Rb_tree_node@U?$pair@$$CBV?$BitFlags@$0BB@@@PBVWeaponTemplateSet@@@_STL@@@1@ABV?$BitFlags@$0BB@@@@Z
// partial score=0.5 date=2026-09-15
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /D_STLP_USE_STATIC_LIB
// stlport

// STLport red-black tree find over map<const BitFlags<0xBB>,
// const WeaponTemplateSet *, MapHelper>, retail 0x0033AF5F (92 bytes) with
// its MapHelper comparator at 0x0033AD5C (73 bytes).
//
// Follows RvaTreeFindGenP12pod00927790: explicit instantiation over locally
// modelled key/compare types. The comparator keeps the Zero Hour
// SparseMatchFinder MapHelper shape (bit-by-bit early-out ordering); retail
// compares only the first 21 bits (cmp esi,0x15), matching the damage-flag
// key space, rather than the full 187.

#define _BFME_RETAIL_TREE_INSERT_LAYOUT
#include <map>

class WeaponTemplateSet;

template <size_t NUMBITS>
class BitFlags
{
public:
	int size() const { return NUMBITS; }

	bool test(int idx) const
	{
		unsigned word = m_words[(unsigned)idx >> 5];
		return (word & (1u << (idx & 31))) != 0;
	}

private:
	unsigned m_words[(NUMBITS + 31) / 32];
};

template <class Matchable, class BitSet>
class SparseMatchFinder
{
public:
	struct MapHelper
	{
		bool operator()(const BitSet &a, const BitSet &b) const
		{
			int i;
			if (a.size() < b.size()) {
				return true;
			}
			// Retail bound, not size(): the damage-flag keys order over the
			// first 21 bits.
			for (i = 0; i < 21; ++i) {
				bool aVal = a.test(i);
				bool bVal = b.test(i);
				if (aVal && bVal) continue;
				if (!aVal && !bVal) continue;
				if (!aVal) return true;
				return false;
			}
			return false;
		}
	};
};

typedef BitFlags<0xBB> Rva0033AF5FKey;
typedef _STL::pair<const Rva0033AF5FKey, const WeaponTemplateSet *> Rva0033AF5FValue;
typedef SparseMatchFinder<WeaponTemplateSet, Rva0033AF5FKey>::MapHelper Rva0033AF5FCompare;
typedef _STL::_Rb_tree<Rva0033AF5FKey, Rva0033AF5FValue,
	_STL::_Select1st<Rva0033AF5FValue>, Rva0033AF5FCompare,
	_STL::allocator<Rva0033AF5FValue> > Rva0033AF5FTree;

// retail 0x0033AD5C
template bool Rva0033AF5FCompare::operator()(
	const Rva0033AF5FKey &, const Rva0033AF5FKey &) const;

// retail 0x0033AF5F
template _STL::_Rb_tree_node<Rva0033AF5FValue> *
Rva0033AF5FTree::_M_find<Rva0033AF5FKey>(const Rva0033AF5FKey &) const;
