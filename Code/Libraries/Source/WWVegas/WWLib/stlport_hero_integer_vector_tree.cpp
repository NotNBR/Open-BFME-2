// cl: /O1 /D_STLP_NO_EXCEPTIONS /EHsc /MD /D_STLP_USE_STATIC_LIB /D_STLP_USE_MALLOC /D_CRTIMP= /Ireference/shims/bfmealloc
// stlport
// STLport4.5.3 copy family for CreateAHeroData member0x74.
// Retail insertion at0x21D203 uses signed key comparisons. Node0x21D159
// allocates32 bytes; value copy0x795C1 copies the int key then the established
// vector<unsigned int> copy0x2CFAB9. These calls anchor the complete family.
#include <map>
#include <vector>
typedef _STL::vector<unsigned int> HeroVector;
typedef _STL::pair<const int, HeroVector> HeroValue;
typedef _STL::_Rb_tree<int, HeroValue, _STL::_Select1st<HeroValue>, _STL::less<int>, _STL::allocator<HeroValue> > HeroTree;
template HeroTree::_Rb_tree(const HeroTree &);
