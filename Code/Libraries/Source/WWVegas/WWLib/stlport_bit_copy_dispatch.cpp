// cl: /O1 /Ob2 /EHs /MD /D_CRTIMP= /D_STLP_USE_STATIC_LIB
// stlport
// STLport 4.5.3 bit-vector copy dispatch. Retail copy at 3893CD passes
// its false-type tag by reference to __copy_aux at 38925D, which calls
// the independently recovered random-access bit-copy loop at 388F9B.
// Use the original headers: the bfmealloc shim changes the tag ABI.
#include <vector>
typedef _STL::vector<bool>::const_iterator BitInput;
typedef _STL::vector<bool>::iterator BitOutput;
template BitOutput _STL::__copy_aux<BitInput,BitOutput>(BitInput,BitInput,BitOutput,const _STL::__false_type&);
