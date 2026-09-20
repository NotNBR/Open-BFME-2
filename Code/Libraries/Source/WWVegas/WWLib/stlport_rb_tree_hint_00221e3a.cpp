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
// Retail uses its static byte allocator and has no node cleanup catch block.
namespace _STL {
template <> class allocator<char> {
public:
    static char *allocate(unsigned int bytes, const void *hint);
};
}
// ?_M_create_node@?$_Rb_tree@VAsciiString@@U?$pair@$$CBVAsciiString@@UTreeHintRef00221D6B@@@_STL@@U?$_Select1st@U?$pair@$$CBVAsciiString@@UTreeHintRef00221D6B@@@_STL@@@3@U?$less@VAsciiString@@@3@V?$allocator@U?$pair@$$CBVAsciiString@@UTreeHintRef00221D6B@@@_STL@@@3@@_STL@@IAEPAU?$_Rb_tree_node@U?$pair@$$CBVAsciiString@@UTreeHintRef00221D6B@@@_STL@@@2@ABU?$pair@$$CBVAsciiString@@UTreeHintRef00221D6B@@@2@@Z
template <>
TreeHint00221D6B::_Link_type TreeHint00221D6B::_M_create_node(const TreeHintPair00221D6B &value)
{
    _Link_type node = (_Link_type)_STL::allocator<char>::allocate(sizeof(_STL::_Rb_tree_node<TreeHintPair00221D6B>), 0);
    _STL::_Construct(&node->_M_value_field, value);
    return node;
}
template TreeHint00221D6B::iterator TreeHint00221D6B::insert_unique(TreeHint00221D6B::iterator, const TreeHintPair00221D6B &);

// The map wrapper directly calls this tree's verified hinted insertion.
typedef _STL::map<AsciiString,TreeHintRef00221D6B,_STL::less<AsciiString>,_STL::allocator<TreeHintPair00221D6B> > MapInsert00221e3a;
template MapInsert00221e3a::iterator MapInsert00221e3a::insert(MapInsert00221e3a::iterator, const TreeHintPair00221D6B &);
