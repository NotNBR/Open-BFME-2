// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// BFME2 STLport tree: AsciiString key and opaque reference-counted pointer.
// hint 0x218022 -> insert 0x217D4C -> _M_insert 0x217CB8 -> node 0x217A6C.
// The node allocates 24 bytes and constructs its 8-byte value at node+16.
// _Construct 0x21789E calls pair copy 0x358B43: AsciiString copy 0x365F0,
// followed by copying a pointer and incrementing its non-null pointee at +4.
// Comparison reaches the established AsciiString operator< at 0x5598C.
// Semantic donor: BFME1 RvaTreeInsertUniqueHint.cpp and STLport pair/tree.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Only the copied pointer and pointee reference-count prefix are established.
// The original application type and release behavior remain unidentified.
struct TreeHintRef00217D4C {
    struct Target { unsigned int unknownHeader; int references; };
    Target *m_ptr;
    TreeHintRef00217D4C(const TreeHintRef00217D4C &other) : m_ptr(other.m_ptr) {
        if (m_ptr) ++m_ptr->references;
    }
    ~TreeHintRef00217D4C();
};

typedef _STL::pair<const AsciiString, TreeHintRef00217D4C> TreeHintPair00217D4C;
typedef _STL::_Rb_tree<AsciiString, TreeHintPair00217D4C, _STL::_Select1st<TreeHintPair00217D4C>, _STL::less<AsciiString>, _STL::allocator<TreeHintPair00217D4C> > TreeHint00217D4C;
template TreeHint00217D4C::iterator TreeHint00217D4C::insert_unique(TreeHint00217D4C::iterator, const TreeHintPair00217D4C &);
