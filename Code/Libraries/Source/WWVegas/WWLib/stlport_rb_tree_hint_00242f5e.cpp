// stlport
// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// BFME1 RvaTreeInsertUniqueHint.cpp and STLport tree/pair semantic donor.
// Comparator0x240CE0 orders signed dword then AsciiString at key+4.
// Keycopy0xCF475 calls AsciiString copy0x365F0; paircopy0x23E90D adds mapped dword+8.
// Node0x240DF1 allocates28bytes. Original application names/destruction unknown.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
struct TreeKey00242F5E { int m_id; AsciiString m_name; };
inline bool operator<(const TreeKey00242F5E &a, const TreeKey00242F5E &b) { return a.m_id < b.m_id || (!(b.m_id < a.m_id) && a.m_name < b.m_name); }
struct TreeOpaqueMapped242F5E { unsigned int m_bits; ~TreeOpaqueMapped242F5E(); };
typedef _STL::pair<const TreeKey00242F5E, TreeOpaqueMapped242F5E> IntAsciiPair;
typedef _STL::_Rb_tree<TreeKey00242F5E, IntAsciiPair, _STL::_Select1st<IntAsciiPair>, _STL::less<TreeKey00242F5E>, _STL::allocator<IntAsciiPair> > Tree242F5E;
template Tree242F5E::iterator Tree242F5E::insert_unique(Tree242F5E::iterator, const IntAsciiPair &);

