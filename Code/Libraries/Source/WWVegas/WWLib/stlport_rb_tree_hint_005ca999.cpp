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
// Retail uses its static byte allocator and has no node cleanup catch block.
namespace _STL {
template <> class allocator<char> {
public:
    static char *allocate(unsigned int bytes, const void *hint);
};
}
// ?_M_create_node@?$_Rb_tree@VAsciiString@@U?$pair@$$CBVAsciiString@@UTreeHintOpaque005CA7ED@@@_STL@@U?$_Select1st@U?$pair@$$CBVAsciiString@@UTreeHintOpaque005CA7ED@@@_STL@@@3@U?$less@VAsciiString@@@3@V?$allocator@U?$pair@$$CBVAsciiString@@UTreeHintOpaque005CA7ED@@@_STL@@@3@@_STL@@IAEPAU?$_Rb_tree_node@U?$pair@$$CBVAsciiString@@UTreeHintOpaque005CA7ED@@@_STL@@@2@ABU?$pair@$$CBVAsciiString@@UTreeHintOpaque005CA7ED@@@2@@Z
template <>
TreeHint005CA7ED::_Link_type TreeHint005CA7ED::_M_create_node(const TreeHintPair005CA7ED &value)
{
    _Link_type node = (_Link_type)_STL::allocator<char>::allocate(sizeof(_STL::_Rb_tree_node<TreeHintPair005CA7ED>), 0);
    _STL::_Construct(&node->_M_value_field, value);
    return node;
}
template TreeHint005CA7ED::iterator TreeHint005CA7ED::insert_unique(TreeHint005CA7ED::iterator, const TreeHintPair005CA7ED &);

// The map wrapper directly calls this tree's verified hinted insertion.
typedef _STL::map<AsciiString,TreeHintOpaque005CA7ED,_STL::less<AsciiString >,_STL::allocator<TreeHintPair005CA7ED> > MapInsert005ca999;
template MapInsert005ca999::iterator MapInsert005ca999::insert(MapInsert005ca999::iterator, const TreeHintPair005CA7ED &);
