// cl: /O1 /DNDEBUG /DWIN32 /MD /EHsc /D_STLP_USE_STATIC_LIB
// stlport

// Evidence: retail 0x0028C7E3 (54 bytes) is byte-identical to the landed
// BitFlags getSingleBitFromName pair (0x000B42CA, 0x002AA2F9) except for the
// name-table DIR32: it reads 0x00DBC2C8, whose first entries are VETERAN,
// ELITE, HERO (104 names total). Same _strcmpi thunk at 0x00BBA518, same
// index-or-minus-one loop. ZH BitFlags.h declares the shared static shape.

#include <bitset>
#include <string.h>

typedef int Int;
typedef bool Bool;

extern const char *VeterancyNames104[104]; ///< retail [0x00DBC2C8]

template <size_t NUMBITS>
class BitFlags
{
public:
	static Int getSingleBitFromName( const char *token );

private:
	_STL::bitset<NUMBITS> m_bits;
};

template <size_t NUMBITS>
Int BitFlags<NUMBITS>::getSingleBitFromName( const char *token )
{
	Int i = 0;
	for ( const char *const *name = VeterancyNames104; *name; ++name, ++i )
	{
		if ( _strcmpi( *name, token ) == 0 )
			return i;
	}
	return -1;
}

// ?getSingleBitFromName@?$BitFlags@$0GI@@@SAHPBD@Z
template Int BitFlags<104>::getSingleBitFromName( const char *token );
