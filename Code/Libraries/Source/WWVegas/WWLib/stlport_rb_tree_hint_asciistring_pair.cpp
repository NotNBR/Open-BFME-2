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
template StringPairTree::iterator StringPairTree::insert_unique(StringPairTree::iterator, const StringPair &);
