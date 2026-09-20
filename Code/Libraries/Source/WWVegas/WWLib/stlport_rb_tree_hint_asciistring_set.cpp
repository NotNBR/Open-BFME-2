// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// Semantic donor: reference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib/RvaTreeInsertUniqueHint.cpp.
// BFME2 uses the established external AsciiString comparator.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
// Retail _M_create_node 0x0002C552 allocates 20 bytes: 16-byte links + AsciiString.
// _Construct 0x0002C485 invokes the independently established AsciiString copy at 0x000365F0.
// There is no mapped value; this is a tree with _Identity<AsciiString>.
typedef _STL::_Rb_tree<AsciiString, AsciiString, _STL::_Identity<AsciiString>, _STL::less<AsciiString>, _STL::allocator<AsciiString> > StringSetTree;
template StringSetTree::iterator StringSetTree::insert_unique(StringSetTree::iterator, const AsciiString &);
