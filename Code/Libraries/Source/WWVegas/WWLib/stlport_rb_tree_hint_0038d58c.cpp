// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
#include <map>
#include <string>



// BFME1 RvaTreeInsertUniqueHint.cpp and STLport tree/pair semantic donor.
// Comparator0x388F39 passes narrow-string begin/end pointers to compare0x24FC0.
// Paircopy0x389DD6 calls known basic_string<char> copy0x9170, then copies dword+12.
// Node0x38AAA8 allocates32bytes: links16 + narrow string12 + mapped4.
// Original mapped application name and destruction remain unknown.
struct TreePayload0038D58C {
    unsigned int value;
    ~TreePayload0038D58C();
};
typedef _STL::pair<const _STL::basic_string<char>, TreePayload0038D58C> TreePair0038D58C;
typedef _STL::_Rb_tree<_STL::basic_string<char>, TreePair0038D58C, _STL::_Select1st<TreePair0038D58C>, _STL::less<_STL::basic_string<char> >, _STL::allocator<TreePair0038D58C> > Tree0038D58C;
template Tree0038D58C::iterator Tree0038D58C::insert_unique(Tree0038D58C::iterator, const TreePair0038D58C &);

namespace _STL { template <> class allocator<char> { public: static char *allocate(unsigned int bytes, const void *hint); static void deallocate(char *p, unsigned int bytes); }; }
// ?_M_create_node@?$_Rb_tree@V?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@U?$pair@$$CBV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@UTreePayload0038D58C@@@2@U?$_Select1st@U?$pair@$$CBV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@UTreePayload0038D58C@@@_STL@@@2@U?$less@V?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@UTreePayload0038D58C@@@_STL@@@2@@_STL@@IAEPAU?$_Rb_tree_node@U?$pair@$$CBV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@UTreePayload0038D58C@@@_STL@@@2@ABU?$pair@$$CBV?$basic_string@DV?$char_traits@D@_STL@@V?$allocator@D@2@@_STL@@UTreePayload0038D58C@@@2@@Z
template <> Tree0038D58C::_Link_type Tree0038D58C::_M_create_node(const TreePair0038D58C &value)
{
    _Link_type node = (_Link_type)_STL::allocator<char>::allocate(sizeof(_STL::_Rb_tree_node<TreePair0038D58C>), 0);
    _STL::_Construct(&node->_M_value_field, value);
    return node;
}

// The map wrapper directly calls this tree's verified hinted insertion.
typedef _STL::map<_STL::basic_string<char>,TreePayload0038D58C,_STL::less<_STL::basic_string<char> >,_STL::allocator<TreePair0038D58C> > MapInsert0038d58c;
template MapInsert0038d58c::iterator MapInsert0038d58c::insert(MapInsert0038d58c::iterator, const TreePair0038D58C &);
