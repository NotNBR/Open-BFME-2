// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// BFME2 STLport tree: AsciiString key and opaque twelve-byte mapped value.
// hint 0x301883 -> insert 0x301384 -> _M_insert 0x3012F0 -> node 0x3012CE.
// The node allocates 32 bytes and constructs its 16-byte value at node+16.
// _Construct 0x3008E5 calls pair copy 0x52BEC9: AsciiString copy 0x365F0,
// followed by raw four-byte copies at pair offsets +4, +8 and +12.
// Comparison reaches the established AsciiString operator< at 0x5598C.
// Semantic donor: BFME1 RvaTreeInsertUniqueHint.cpp and STLport pair/tree.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Retail pair copy preserves three four-byte fields without ownership calls.
// Their application meaning and original mapped-type name are unknown.
struct TreeHintPayload003012F0 {
    unsigned int a, b, c;
    TreeHintPayload003012F0(const TreeHintPayload003012F0 &other)
        : a(other.a), b(other.b), c(other.c) {}
};

typedef _STL::pair<const AsciiString, TreeHintPayload003012F0> TreeHintPair003012F0;
typedef _STL::_Rb_tree<AsciiString, TreeHintPair003012F0, _STL::_Select1st<TreeHintPair003012F0>, _STL::less<AsciiString>, _STL::allocator<TreeHintPair003012F0> > TreeHint003012F0;
template TreeHint003012F0::iterator TreeHint003012F0::insert_unique(TreeHint003012F0::iterator, const TreeHintPair003012F0 &);
