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
// Retail uses its static byte allocator and has no node cleanup catch block.
namespace _STL {
template <> class allocator<char> {
public:
    static char *allocate(unsigned int bytes, const void *hint);
};
}
// ?_M_create_node@?$_Rb_tree@VAsciiString@@U?$pair@$$CBVAsciiString@@UTreeHintOpaque0043671B@@@_STL@@U?$_Select1st@U?$pair@$$CBVAsciiString@@UTreeHintOpaque0043671B@@@_STL@@@3@U?$less@VAsciiString@@@3@V?$allocator@U?$pair@$$CBVAsciiString@@UTreeHintOpaque0043671B@@@_STL@@@3@@_STL@@IAEPAU?$_Rb_tree_node@U?$pair@$$CBVAsciiString@@UTreeHintOpaque0043671B@@@_STL@@@2@ABU?$pair@$$CBVAsciiString@@UTreeHintOpaque0043671B@@@2@@Z
template <>
TreeHint0043671B::_Link_type TreeHint0043671B::_M_create_node(const TreeHintPair0043671B &value)
{
    _Link_type node = (_Link_type)_STL::allocator<char>::allocate(sizeof(_STL::_Rb_tree_node<TreeHintPair0043671B>), 0);
    _STL::_Construct(&node->_M_value_field, value);
    return node;
}
template TreeHint0043671B::iterator TreeHint0043671B::insert_unique(TreeHint0043671B::iterator, const TreeHintPair0043671B &);
