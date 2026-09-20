// stlport
// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// BFME1 RvaTreeInsertUniqueHint.cpp and STLport pair/tree are the semantic donor.
// BFME2 comparator0x206BCF orders two AsciiStrings lexicographically.
// Key copy0x20492B calls AsciiString copy0x365F0 twice.
// Node0x32B62F allocates28bytes; paircopy0x32ACB4 copies mapped dword+8.
// The original mapped type and its destruction remain unknown.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
typedef _STL::pair<AsciiString,AsciiString> TreeKey00206BCF;
bool operator<(const TreeKey00206BCF &a,const TreeKey00206BCF &b) { return (a.first < b.first) || (!(b.first < a.first) && (a.second < b.second)); }
struct TreeOpaqueMapped0032CB55 { unsigned int m_bits; ~TreeOpaqueMapped0032CB55(); };
typedef _STL::pair<const TreeKey00206BCF,TreeOpaqueMapped0032CB55> TreePair0032CB55;
typedef _STL::_Rb_tree<TreeKey00206BCF,TreePair0032CB55,_STL::_Select1st<TreePair0032CB55>,_STL::less<TreeKey00206BCF>,_STL::allocator<TreePair0032CB55> > Tree0032CB55;
template Tree0032CB55::iterator Tree0032CB55::insert_unique(Tree0032CB55::iterator,const TreePair0032CB55 &);


