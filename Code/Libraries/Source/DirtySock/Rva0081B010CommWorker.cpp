// cl: /Od /GZ /GS /MD /DNDEBUG

struct Rva0081B010Comm
{
	char m_head[ 0x7c ];
	void *m_handle;
	char m_gap80[ 0x10 ];
	void *m_event0;
	char m_gap94[ 0x10 ];
	void *m_event1;
	char m_gapA8[ 0x10 ];
	void *m_event2;
	char m_gapBC[ 0x10 ];
	int m_state;
};

struct Rva0081B010Dcb
{
	unsigned int m_length;
	unsigned int m_baudRate;
	unsigned int m_flags;
	unsigned short m_reserved;
	unsigned short m_xonLimit;
	unsigned short m_xoffLimit;
	unsigned char m_byteSize;
	unsigned char m_parity;
	unsigned char m_stopBits;
	char m_xonChar;
	char m_xoffChar;
	char m_errorChar;
	char m_eofChar;
	char m_evtChar;
	unsigned short m_reserved1;
};

struct Rva0081B010Timeouts
{
	unsigned int m_readInterval;
	unsigned int m_readMultiplier;
	unsigned int m_readConstant;
	unsigned int m_writeMultiplier;
	unsigned int m_writeConstant;
};

struct Rva0081B010Locals
{
	unsigned int m_configSize;
	char m_gap08[ 4 ];
	char *m_parse;
	struct Rva0081B010Dcb *m_dcb;
	char m_gap14[ 4 ];
	char m_config[ 0x1000 ];
	char m_gap1018[ 8 ];
	struct Rva0081B010Timeouts m_timeouts;
};

/* Retail calls the serial API through import thunks this repo names
 * Rva01358* (see the pin log); the import verifier maps each slot to its
 * real kernel32 entry, so the declarations below use the real names.
 * Rva01358CCC=CloseHandle Rva01358CE8=CreateFileA Rva01358D54=GetCommConfig
 * Rva01358D58=GetCommState Rva01358F28=SetupComm Rva01358ED8=SetCommConfig
 * Rva01358EDC=SetCommMask Rva01358EE0=SetCommState Rva01358EE4=SetCommTimeouts
 * Rva01358EB0=PurgeComm Rva01358F0C=SetEvent. */
extern "C" {
__declspec(dllimport) int __stdcall CloseHandle( void *handle );
__declspec(dllimport) void *__stdcall CreateFileA( const char *name,
	unsigned int desiredAccess, unsigned int shareMode, void *security,
	unsigned int creation, unsigned int flags, void *templateHandle );
__declspec(dllimport) int __stdcall GetCommConfig( void *handle, void *config,
	unsigned int *size );
__declspec(dllimport) int __stdcall GetCommState( void *handle,
	struct Rva0081B010Dcb *dcb );
__declspec(dllimport) int __stdcall SetupComm( void *handle,
	unsigned int inQueue, unsigned int outQueue );
__declspec(dllimport) int __stdcall SetCommConfig( void *handle, void *config,
	unsigned int size );
__declspec(dllimport) int __stdcall SetCommMask( void *handle,
	unsigned int mask );
__declspec(dllimport) int __stdcall SetCommState( void *handle,
	struct Rva0081B010Dcb *dcb );
__declspec(dllimport) int __stdcall SetCommTimeouts( void *handle,
	struct Rva0081B010Timeouts *timeouts );
__declspec(dllimport) int __stdcall PurgeComm( void *handle,
	unsigned int flags );
__declspec(dllimport) int __stdcall SetEvent( void *eventHandle );

char *__cdecl strncpy( char *destination, const char *source,
	unsigned int count );
char *__cdecl strchr( const char *string, int character );
int __cdecl strncmp( const char *left, const char *right,
	unsigned int count );
}

struct Rva0081BD40Comm;
extern "C" void __cdecl Rva0081B700( struct Rva0081BD40Comm *comm );

extern "C" int Rva0081B010( struct Rva0081B010Comm *comm, char *argument )
{
	int baud;
	char temp[ 0x20 ];
	struct Rva0081B010Locals locals;

	baud = 0;
	locals.m_timeouts.m_readInterval = 0xffffffff;
	locals.m_timeouts.m_readMultiplier = 0;
	locals.m_timeouts.m_readConstant = 0;
	locals.m_timeouts.m_writeMultiplier = 0;
	locals.m_timeouts.m_writeConstant = 0;
	locals.m_dcb = (struct Rva0081B010Dcb *)( locals.m_config + 8 );

	if ( argument == 0 && comm->m_state == 4 )
	{
		comm->m_state = 5;
		SetCommMask( comm->m_handle, 2 );
		PurgeComm( comm->m_handle, 0x0f );
		CloseHandle( comm->m_handle );
		comm->m_handle = (void *)-1;
		return 0;
	}

	if ( comm->m_state != 1 && comm->m_state != 5 )
		return -8;

	if ( comm->m_state == 1 )
		Rva0081B700( reinterpret_cast< struct Rva0081BD40Comm * >( comm ) );

	strncpy( temp, argument, 0x20 );
	if ( strchr( temp, ':' ) != 0 )
	{
		*( strchr( temp, ':' ) ) = 0;
		argument = strchr( argument, ':' ) + 1;
	}
	else
	{
		/* Retail's stale default serial pointer: 0x00E0ABA4 points outside
		 * the image (BFME1 has 0x0130B18C in the same slot), so this path
		 * cannot be dereferencing a live global in either game. Spelled
		 * as retail wrote it to preserve the bytes. */
		argument = (char *)0x00E0ABA4;
	}

	if ( strncmp( temp, "TAPI", 4 ) == 0 )
	{
		locals.m_parse = temp + 4;
		baud = 0;
		for ( ; *locals.m_parse >= '0' && *locals.m_parse <= '9';
			locals.m_parse++ )
		{
			baud = baud * 10 + ( *locals.m_parse & 0x0f );
		}
		comm->m_handle = (void *)baud;
	}
	else
	{
		comm->m_handle = CreateFileA( temp, 0xc0000000, 0, 0,
			3, 0x40000080, 0 );
		if ( comm->m_handle == (void *)-1 )
			return -4;
	}

	SetupComm( comm->m_handle, 0x2000, 0x1000 );
	SetCommTimeouts( comm->m_handle, &locals.m_timeouts );
	SetCommMask( comm->m_handle, 2 );

	if ( baud != 0 )
	{
		locals.m_configSize = 0x1000;
		GetCommConfig( comm->m_handle, locals.m_config, &locals.m_configSize );
		locals.m_dcb->m_evtChar = 0x0a;
		locals.m_dcb->m_flags = locals.m_dcb->m_flags | 1;
		locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xfffff7ff;
		locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xfffffeff;
		locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xfffffdff;
		locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xffffbfff;
		SetCommConfig( comm->m_handle, locals.m_config, locals.m_configSize );
		goto finish;
	}

	locals.m_dcb->m_length = 0x1c;
	GetCommState( comm->m_handle, locals.m_dcb );
	locals.m_dcb->m_evtChar = 0x0a;
	locals.m_dcb->m_flags = locals.m_dcb->m_flags | 1;
	locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xfffff7ff;
	locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xfffffeff;
	locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xfffffdff;
	locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xffffbfff;
	locals.m_dcb->m_byteSize = 8;
	locals.m_dcb->m_flags = locals.m_dcb->m_flags | 2;
	locals.m_dcb->m_stopBits = 0;
	locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xffffffbf;
	locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xfffffff7;
	locals.m_dcb->m_flags = ( locals.m_dcb->m_flags & 0xffffffcf ) | 0x10;

	while ( argument != 0 && *argument != 0 )
	{
		if ( *argument == ',' )
			argument++;

		if ( strncmp( argument, "+RTS", 4 ) == 0 )
			locals.m_dcb->m_flags = ( locals.m_dcb->m_flags & 0xffffcfff ) | 0x2000;
		if ( strncmp( argument, "-RTS", 4 ) == 0 )
			locals.m_dcb->m_flags = ( locals.m_dcb->m_flags & 0xffffcfff ) | 0x1000;
		if ( strncmp( argument, "+CTS", 4 ) == 0 )
			locals.m_dcb->m_flags = locals.m_dcb->m_flags | 4;
		if ( strncmp( argument, "-CTS", 4 ) == 0 )
			locals.m_dcb->m_flags = locals.m_dcb->m_flags & 0xfffffffb;

		if ( *argument >= '0' && *argument <= '9' )
		{
			locals.m_dcb->m_baudRate = 0;
			while ( *argument >= '0' && *argument <= '9' )
			{
				locals.m_dcb->m_baudRate = locals.m_dcb->m_baudRate * 10
					+ ( *argument & 0x0f );
				argument++;
			}
		}

		while ( *argument != ',' && *argument != 0 )
			argument++;
	}

	SetCommState( comm->m_handle, locals.m_dcb );

finish:
	PurgeComm( comm->m_handle, 0x0c );
	SetEvent( comm->m_event0 );
	SetEvent( comm->m_event1 );
	SetEvent( comm->m_event2 );
	comm->m_state = ( comm->m_state != 5 ) + 4;
	return 0;
}
