// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// BFME2 STLport tree: AsciiString key and opaque reference-counted pointer.
// hint 0x221e3a -> insert 0x221D6B -> _M_insert 0x221CD7 -> node 0x221BF3.
// The node allocates 24 bytes and constructs its 8-byte value at node+16.
// _Construct 0x221AE0 calls pair copy 0x358B43: AsciiString copy 0x365F0,
// followed by copying a pointer and incrementing its non-null pointee at +4.
// Comparison reaches the established AsciiString operator< at 0x5598C.
// Semantic donor: BFME1 RvaTreeInsertUniqueHint.cpp and STLport pair/tree.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Only the copied pointer and pointee reference-count prefix are established.
// The original application type and release behavior remain unidentified.
struct TreeHintRef00221D6B {
    struct Target { unsigned int unknownHeader; int references; };
    Target *m_ptr;
    TreeHintRef00221D6B(const TreeHintRef00221D6B &other) : m_ptr(other.m_ptr) {
        if (m_ptr) ++m_ptr->references;
    }
    ~TreeHintRef00221D6B();
};

typedef _STL::pair<const AsciiString, TreeHintRef00221D6B> TreeHintPair00221D6B;
typedef _STL::_Rb_tree<AsciiString, TreeHintPair00221D6B, _STL::_Select1st<TreeHintPair00221D6B>, _STL::less<AsciiString>, _STL::allocator<TreeHintPair00221D6B> > TreeHint00221D6B;
template TreeHint00221D6B::iterator TreeHint00221D6B::insert_unique(TreeHint00221D6B::iterator, const TreeHintPair00221D6B &);
