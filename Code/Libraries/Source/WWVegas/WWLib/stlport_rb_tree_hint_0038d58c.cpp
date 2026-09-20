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

