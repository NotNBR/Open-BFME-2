// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// BFME2 STLport tree: AsciiString key and opaque 0xDF4-byte mapped object.
// hint 0x436E3B -> insert 0x4367AF -> _M_insert 0x43671B -> node 0x436234.
// The node allocates 0xE08 bytes and constructs its 0xDF8-byte value at node+16.
// _Construct 0x43616A calls pair copy 0x435DAA: AsciiString copy 0x365F0,
// then the mapped object copy constructor 0x22D106 on the second pair field.
// Comparison reaches the established AsciiString operator< at 0x5598C.
// Semantic donor: BFME1 RvaTreeInsertUniqueHint.cpp and STLport pair/tree.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Distinct 0xDF4-byte mapped object. The original application type is unknown.
// Pair copying passes destination+4 and source+4 to its copy constructor.
// Preserve its out-of-line copy and destruction; do not assume trivial ownership.
struct TreeHintOpaque0043671B {
    unsigned char m_body[0xDF4];
    TreeHintOpaque0043671B(const TreeHintOpaque0043671B &);
    ~TreeHintOpaque0043671B();
};

typedef _STL::pair<const AsciiString, TreeHintOpaque0043671B> TreeHintPair0043671B;
typedef _STL::_Rb_tree<AsciiString, TreeHintPair0043671B, _STL::_Select1st<TreeHintPair0043671B>, _STL::less<AsciiString>, _STL::allocator<TreeHintPair0043671B> > TreeHint0043671B;
template TreeHint0043671B::iterator TreeHint0043671B::insert_unique(TreeHint0043671B::iterator, const TreeHintPair0043671B &);
