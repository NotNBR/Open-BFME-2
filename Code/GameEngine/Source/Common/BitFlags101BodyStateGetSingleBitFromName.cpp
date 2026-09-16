// cl: /O1 /DNDEBUG /DWIN32 /MD /EHsc /D_STLP_USE_STATIC_LIB
// stlport

// Evidence: retail 0x0028C819 (54 bytes) is byte-identical to the landed
// BitFlags getSingleBitFromName pair except for the name-table DIR32: it
// reads 0x00DA5F30, whose first entries are DESTROYED, CAN_ATTACK,
// UNDER_CONSTRUCTION (101 names total). Same _strcmpi thunk at 0x00BBA518.

#include <bitset>
#include <string.h>

typedef int Int;
typedef bool Bool;

extern const char *BodyStateNames[101]; ///< retail [0x00DA5F30]

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
	for ( const char *const *name = BodyStateNames; *name; ++name, ++i )
	{
		if ( _strcmpi( *name, token ) == 0 )
			return i;
	}
	return -1;
}

// ?getSingleBitFromName@?$BitFlags@$0GF@@@SAHPBD@Z
template Int BitFlags<101>::getSingleBitFromName( const char *token );
