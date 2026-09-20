// cl: /O1 /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /D_BFME_RETAIL_TREE_INSERT_LAYOUT
// stlport
// BFME2 STLport tree with an AsciiString key and a four-byte opaque mapped value.
// The application's original mapped-type name is not established.
// Identity chain: hinted insert 0x002181DD -> ordinary insert 0x00217E77
// and _M_insert 0x00217DE3 -> _M_create_node 0x00217A8E.
// The node allocator requests 24 bytes: 16 bytes tree links + 8 bytes value.
// _Construct at 0x002178CB calls the independently matched 27-byte pair copy
// at 0x00466EA7: AsciiString copy at offset 0, one raw dword at offset 4.
// The comparisons reach the independently matched AsciiString operator<,
// RVA 0x0005598C, and both iterator-step helpers are already independently matched.
// Semantic reference: reference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib/
// RvaTreeInsertUniqueHint.cpp. Here /O1 leaves the comparator out of line.
#include <map>
class AsciiString { public: AsciiString(const AsciiString &); ~AsciiString(); private: void *m_data; };
bool operator<(const AsciiString &, const AsciiString &);
struct TreeHintPayload00217DE3 { char m_body[4]; };
typedef _STL::pair<const AsciiString, TreeHintPayload00217DE3> TreeHintPair00217DE3;
typedef _STL::_Rb_tree<AsciiString, TreeHintPair00217DE3, _STL::_Select1st<TreeHintPair00217DE3>, _STL::less<AsciiString>, _STL::allocator<TreeHintPair00217DE3> > TreeHint00217DE3;
template TreeHint00217DE3::iterator TreeHint00217DE3::insert_unique(TreeHint00217DE3::iterator, const TreeHintPair00217DE3 &);

