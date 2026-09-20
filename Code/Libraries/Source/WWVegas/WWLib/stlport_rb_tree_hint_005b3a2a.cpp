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
// Retail uses its static byte allocator and has no node cleanup catch block.
namespace _STL {
template <> class allocator<char> {
public:
    static char *allocate(unsigned int bytes, const void *hint);
};
}
// ?_M_create_node@?$_Rb_tree@VAsciiString@@U?$pair@$$CBVAsciiString@@UTreeHintPayload005B3786@@@_STL@@U?$_Select1st@U?$pair@$$CBVAsciiString@@UTreeHintPayload005B3786@@@_STL@@@3@U?$less@VAsciiString@@@3@V?$allocator@U?$pair@$$CBVAsciiString@@UTreeHintPayload005B3786@@@_STL@@@3@@_STL@@IAEPAU?$_Rb_tree_node@U?$pair@$$CBVAsciiString@@UTreeHintPayload005B3786@@@_STL@@@2@ABU?$pair@$$CBVAsciiString@@UTreeHintPayload005B3786@@@2@@Z
template <>
TreeHint005B3786::_Link_type TreeHint005B3786::_M_create_node(const TreeHintPair005B3786 &value)
{
    _Link_type node = (_Link_type)_STL::allocator<char>::allocate(sizeof(_STL::_Rb_tree_node<TreeHintPair005B3786>), 0);
    _STL::_Construct(&node->_M_value_field, value);
    return node;
}
template TreeHint005B3786::iterator TreeHint005B3786::insert_unique(TreeHint005B3786::iterator, const TreeHintPair005B3786 &);
