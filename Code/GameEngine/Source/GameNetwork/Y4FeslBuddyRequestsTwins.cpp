#include <string.h>

// EA FESL client SDK ("jabba") -- buddy/presence transaction request builders,
// second part: the four ICF-folded twins omitted from Y4FeslBuddyRequests.cpp.
// Source: reference/open-bfme-1/Code/GameEngine/Source/GameNetwork/Y4FeslBuddyRequests.cpp
// (verbatim bodies; b2 addresses are distinct so each address is claimed once,
// the name being this sweep's pick among its BFME1-folded twins).
// b1 0x007FAE40 145B -> b2 0x00667350 ('AUTH' with LKEY)
// b1 0x007FAEE0 162B -> b2 0x006673F0 ('AUTH' with USER/PASS)
// b1 0x007FAFB0 194B -> b2 0x006674C0 ('USCH' user search)
// b1 0x007FB620 176B -> b2 0x00667B30 ('RDEM')
// String-literal drift is DIR32 auto-patch; callees pre-pinned.

typedef __int64 FeslInt64;

// Class name is the claimed pin (ctor 0x007E8810).  Layout is the same object
// V2FeslTxnRequests.cpp already recovered from reset()/add* stores.
class Rva007E8810Message
{
public:
	void reset( void );                                              // 0x007E8AC0
	void addString( const char *key, const char *value );            // 0x007E8A10
	void addInt( const char *key, int value );                       // 0x007E88D0
	void addInt64( const char *key, FeslInt64 value );               // 0x007E8E90
	void addBool( const char *key, bool value );                     // 0x007E8980
	void setError( int code );                                       // 0x007E88C0

	char m_pad00[ 0x10 ];
	char *m_output;                                                  // +0x10
	int m_bufferSize;                                                // +0x14
	int m_writeCursor;                                               // +0x18
	unsigned int m_category;                                         // +0x1C
	char m_pad20[ 4 ];
	int m_errorCode;                                                 // +0x24
	char m_pad28[ 4 ];
	int m_depth;                                                     // +0x2C
};

typedef Rva007E8810Message FeslTxnMessage;

// ---- 'AUTH' ---------------------------------------------------------------

void __stdcall Rva007FAE40( FeslTxnMessage *msg, const char *lkey,
	const char *prod, const char *vers, const char *pres, const char *rsrc )
{
	msg->reset();
	msg->m_category = 'AUTH';
	msg->m_depth = 3;
	msg->addString( "LKEY", lkey );
	msg->addString( "PROD", prod );
	msg->addString( "VERS", vers );
	msg->addString( "PRES", pres );
	if( rsrc && *rsrc )
		msg->addString( "RSRC", rsrc );
	else
		msg->addString( "RSRC", "CSO" );
}

void __stdcall Rva007FAEE0( FeslTxnMessage *msg, const char *user,
	const char *pass, const char *prod, const char *vers, const char *pres,
	const char *rsrc )
{
	msg->reset();
	msg->m_category = 'AUTH';
	msg->m_depth = 3;
	msg->addString( "USER", user );
	msg->addString( "PASS", pass );
	msg->addString( "PROD", prod );
	msg->addString( "VERS", vers );
	msg->addString( "PRES", pres );
	if( rsrc && *rsrc )
		msg->addString( "RSRC", rsrc );
	else
		msg->addString( "RSRC", "CSO" );
}

// ---- 'USCH' ---------------------------------------------------------------

void __stdcall Rva007FAFB0( FeslTxnMessage *msg, const char *user,
	const char *domain, const char *rsrc, bool dist, int maxResults )
{
	msg->reset();
	msg->m_category = 'USCH';
	msg->m_depth = 3;
	msg->addString( "USER", user );
	if( domain && strlen( domain ) != 0 )
		msg->addString( "DOMN", domain );
	if( rsrc && strlen( rsrc ) != 0 )
		msg->addString( "RSRC", rsrc );
	if( dist )
		msg->addString( "DIST", "T" );
	else
		msg->addString( "DIST", "F" );
	msg->addInt( "MAXR", maxResults );
}

// ---- 'RDEM' -----------------------------------------------------------------

void __stdcall Rva007FB620( FeslTxnMessage *msg, const char *user,
	const char *group, const char *lsrc, bool pres )
{
	msg->reset();
	msg->m_category = 'RDEM';
	msg->m_depth = 3;
	msg->addString( "USER", user );
	if( group && strlen( group ) != 0 )
		msg->addString( "GROUP", group );
	if( lsrc && strlen( lsrc ) != 0 )
		msg->addString( "LSRC", lsrc );
	msg->addString( "PRES", pres ? "Y" : "N" );
}
