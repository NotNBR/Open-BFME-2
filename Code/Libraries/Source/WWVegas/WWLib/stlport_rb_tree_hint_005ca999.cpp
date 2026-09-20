// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// BFME2 STLport tree: AsciiString key and opaque four-byte mapped object.
// hint 0x5CA999 -> insert 0x5CA881 -> _M_insert 0x5CA7ED -> node 0x5CA291.
// The node allocates 24 bytes and constructs its 8-byte value at node+16.
// _Construct 0x5CA173 calls pair copy 0x5C9F87: AsciiString copy 0x365F0,
// then the mapped object copy constructor 0x54D800 on the second pair field.
// Comparison reaches the established AsciiString operator< at 0x5598C.
// Semantic donor: BFME1 RvaTreeInsertUniqueHint.cpp and STLport pair/tree.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Distinct four-byte mapped object. The original application type is unknown.
// Pair copying passes destination+4 and source+4 to its copy constructor.
// Preserve its out-of-line copy and destruction; do not assume trivial ownership.
struct TreeHintOpaque005CA7ED {
    void *m_body;
    TreeHintOpaque005CA7ED(const TreeHintOpaque005CA7ED &);
    ~TreeHintOpaque005CA7ED();
};

typedef _STL::pair<const AsciiString, TreeHintOpaque005CA7ED> TreeHintPair005CA7ED;
typedef _STL::_Rb_tree<AsciiString, TreeHintPair005CA7ED, _STL::_Select1st<TreeHintPair005CA7ED>, _STL::less<AsciiString>, _STL::allocator<TreeHintPair005CA7ED> > TreeHint005CA7ED;
template TreeHint005CA7ED::iterator TreeHint005CA7ED::insert_unique(TreeHint005CA7ED::iterator, const TreeHintPair005CA7ED &);
