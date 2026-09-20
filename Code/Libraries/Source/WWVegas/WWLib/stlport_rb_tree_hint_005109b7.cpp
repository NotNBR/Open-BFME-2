// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// BFME2 STLport tree: AsciiString key and opaque reference-counted pointer.
// hint 0x5109b7 -> insert 0x51030C -> _M_insert 0x510278 -> node 0x50F81F.
// The node allocates 24 bytes and constructs its 8-byte value at node+16.
// _Construct 0x50F263 calls pair copy 0x358B43: AsciiString copy 0x365F0,
// followed by copying a pointer and incrementing its non-null pointee at +4.
// Comparison reaches the established AsciiString operator< at 0x5598C.
// Semantic donor: BFME1 RvaTreeInsertUniqueHint.cpp and STLport pair/tree.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Only the copied pointer and pointee reference-count prefix are established.
// The original application type and release behavior remain unidentified.
struct TreeHintRef0051030C {
    struct Target { unsigned int unknownHeader; int references; };
    Target *m_ptr;
    TreeHintRef0051030C(const TreeHintRef0051030C &other) : m_ptr(other.m_ptr) {
        if (m_ptr) ++m_ptr->references;
    }
    ~TreeHintRef0051030C();
};

typedef _STL::pair<const AsciiString, TreeHintRef0051030C> TreeHintPair0051030C;
typedef _STL::_Rb_tree<AsciiString, TreeHintPair0051030C, _STL::_Select1st<TreeHintPair0051030C>, _STL::less<AsciiString>, _STL::allocator<TreeHintPair0051030C> > TreeHint0051030C;
template TreeHint0051030C::iterator TreeHint0051030C::insert_unique(TreeHint0051030C::iterator, const TreeHintPair0051030C &);
