// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// Semantic donor: reference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib/RvaTreeInsertUniqueHint.cpp.
// BFME2 uses the established external AsciiString comparator.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Retail _M_create_node 0x00202B4A allocates 24 bytes: 16-byte links + two AsciiStrings.
// _Construct 0x0002C71B invokes pair copy 0x0002C574, which calls the independently
// established AsciiString copy 0x000365F0 at offsets 0 and 4, with exception cleanup.
typedef _STL::pair<const AsciiString, AsciiString> StringPair;
typedef _STL::_Rb_tree<AsciiString, StringPair, _STL::_Select1st<StringPair>, _STL::less<AsciiString>, _STL::allocator<StringPair> > StringPairTree;
// BFME replaces STLport allocation with a static byte allocator (RVA 0x307F0).
namespace _STL {
template <> class allocator<char> {
public:
    static char *allocate(unsigned int bytes, const void *hint);
};
}

// Retail 0x00202B4A allocates the node, then constructs its value.
// Unlike stock STLport, this retail body has no allocation-cleanup catch path.
// ?_M_create_node@?$_Rb_tree@VAsciiString@@U?$pair@$$CBVAsciiString@@V1@@_STL@@U?$_Select1st@U?$pair@$$CBVAsciiString@@V1@@_STL@@@3@U?$less@VAsciiString@@@3@V?$allocator@U?$pair@$$CBVAsciiString@@V1@@_STL@@@3@@_STL@@IAEPAU?$_Rb_tree_node@U?$pair@$$CBVAsciiString@@V1@@_STL@@@2@ABU?$pair@$$CBVAsciiString@@V1@@2@@Z
template <>
StringPairTree::_Link_type StringPairTree::_M_create_node(const StringPair &value)
{
    _Link_type node = (_Link_type)_STL::allocator<char>::allocate(sizeof(_STL::_Rb_tree_node<StringPair>), 0);
    _STL::_Construct(&node->_M_value_field, value);
    return node;
}

template StringPairTree::iterator StringPairTree::insert_unique(StringPairTree::iterator, const StringPair &);

// The map wrapper directly calls this tree's verified hinted insertion.
typedef _STL::map<AsciiString,AsciiString,_STL::less<AsciiString>,_STL::allocator<StringPair> > MapPairExtra;
template MapPairExtra::iterator MapPairExtra::insert(MapPairExtra::iterator, const StringPair &);
