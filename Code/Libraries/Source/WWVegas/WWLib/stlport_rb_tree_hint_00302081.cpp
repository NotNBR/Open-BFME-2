// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// BFME2 STLport tree: AsciiString key and opaque 1-byte mapped value.
// hint 0x302081 -> insert 0x207a04 -> _M_insert 0x207343 -> node 0x206C76.
// The node allocates 24 bytes and constructs its 8-byte value at node+16.
// _Construct 0x2058E3 calls pair copy 0x5117F6: AsciiString copy 0x365F0,
// followed by a raw 1-byte copy of the mapped value at pair offset +4.
// Comparison reaches the established AsciiString operator< at 0x5598C.
// Semantic donor: BFME1 RvaTreeInsertUniqueHint.cpp and STLport pair/tree.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Retail pair copying transfers this 1-byte mapped value without further calls.
// Its original application type and any ownership/destruction behavior are unknown.
struct TreeHintPayload00207343 {
    unsigned char value;
    ~TreeHintPayload00207343();
};

typedef _STL::pair<const AsciiString, TreeHintPayload00207343> TreeHintPair00207343;
typedef _STL::_Rb_tree<AsciiString, TreeHintPair00207343, _STL::_Select1st<TreeHintPair00207343>, _STL::less<AsciiString>, _STL::allocator<TreeHintPair00207343> > TreeHint00207343;
template TreeHint00207343::iterator TreeHint00207343::insert_unique(TreeHint00207343::iterator, const TreeHintPair00207343 &);
