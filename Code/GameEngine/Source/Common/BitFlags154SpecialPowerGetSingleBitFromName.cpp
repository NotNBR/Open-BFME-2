// cl: /O1 /DNDEBUG /DWIN32 /MD /EHsc /D_STLP_USE_STATIC_LIB
// stlport

// Evidence: retail 0x0028C84F (54 bytes) is byte-identical to the landed
// BitFlags getSingleBitFromName pair except for the name-table DIR32: it
// reads 0x00DC0B40, whose first entries are SPECIAL_INVALID,
// SPECIAL_DAISY_CUTTER, SPECIAL_PARADROP_AMERICA (154 names total).
// Same _strcmpi thunk at 0x00BBA518.

#include <bitset>
#include <string.h>

typedef int Int;
typedef bool Bool;

extern const char *SpecialPowerNames[154]; ///< retail [0x00DC0B40]

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
	for ( const char *const *name = SpecialPowerNames; *name; ++name, ++i )
	{
		if ( _strcmpi( *name, token ) == 0 )
			return i;
	}
	return -1;
}

// ?getSingleBitFromName@?$BitFlags@$0JK@@@SAHPBD@Z
template Int BitFlags<154>::getSingleBitFromName( const char *token );
