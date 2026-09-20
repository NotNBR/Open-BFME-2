// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// BFME2 STLport tree: AsciiString key and opaque 28-byte mapped value.
// hint 0x5b3a2a -> insert 0x5b381a -> _M_insert 0x5B3786 -> node 0x5B3609.
// The node allocates 48 bytes and constructs its 32-byte value at node+16.
// _Construct 0x5B303D calls pair copy 0x5B2A37: AsciiString copy 0x365F0,
// followed by a raw 28-byte copy of the mapped value at pair offset +4.
// Comparison reaches the established AsciiString operator< at 0x5598C.
// Semantic donor: BFME1 RvaTreeInsertUniqueHint.cpp and STLport pair/tree.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Retail pair copying transfers this 28-byte mapped value without further calls.
// Its original application type and any ownership/destruction behavior are unknown.
struct TreeHintPayload005B3786 {
    unsigned int words[7];
    ~TreeHintPayload005B3786();
};

typedef _STL::pair<const AsciiString, TreeHintPayload005B3786> TreeHintPair005B3786;
typedef _STL::_Rb_tree<AsciiString, TreeHintPair005B3786, _STL::_Select1st<TreeHintPair005B3786>, _STL::less<AsciiString>, _STL::allocator<TreeHintPair005B3786> > TreeHint005B3786;
template TreeHint005B3786::iterator TreeHint005B3786::insert_unique(TreeHint005B3786::iterator, const TreeHintPair005B3786 &);
