// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// BFME2 STLport tree: AsciiString key and opaque four-byte mapped object.
// hint 0x2A5895 -> insert 0x2A48DE -> _M_insert 0x2A484A -> node 0x2A42B6.
// The node allocates 24 bytes and constructs its 8-byte value at node+16.
// _Construct 0x2A1EC8 calls pair copy 0x2A1538: AsciiString copy 0x365F0,
// then the mapped object copy constructor 0x2A1383 on the second pair field.
// Comparison reaches the established AsciiString operator< at 0x5598C.
// Semantic donor: BFME1 RvaTreeInsertUniqueHint.cpp and STLport pair/tree.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Distinct four-byte mapped object. The original application type is unknown.
// Pair copying passes destination+4 and source+4 to its copy constructor.
// Preserve its out-of-line copy and destruction; do not assume trivial ownership.
struct TreeHintOpaque002A484A {
    void *m_body;
    TreeHintOpaque002A484A(const TreeHintOpaque002A484A &);
    ~TreeHintOpaque002A484A();
};

typedef _STL::pair<const AsciiString, TreeHintOpaque002A484A> TreeHintPair002A484A;
typedef _STL::_Rb_tree<AsciiString, TreeHintPair002A484A, _STL::_Select1st<TreeHintPair002A484A>, _STL::less<AsciiString>, _STL::allocator<TreeHintPair002A484A> > TreeHint002A484A;
template TreeHint002A484A::iterator TreeHint002A484A::insert_unique(TreeHint002A484A::iterator, const TreeHintPair002A484A &);
