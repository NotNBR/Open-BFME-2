struct CodecState
{
	unsigned char m_unmodelled00[ 0x13c ];
	void *m_buffer;
	unsigned char m_unmodelled140[ 0x158 ];
	void *m_callback;
};

void releaseCodecMembers( CodecState *state );
void releaseCodecBuffer( void **buffer );
void releaseCodecCallback( void **callback );
// BFME2 names the free helper bfmeTwoBZB (pinned at 0x1B6410 via Rva009A6EC0Release);
// the BFME1 donor's local extern freeCodecMemory resolves to the same body.
void bfmeTwoBZB( void *what );

// ?releaseCodecState@@YAXPAPAUCodecState@@@Z
void releaseCodecState( CodecState **state )
{
	if( *state )
	{
		releaseCodecMembers( *state );
		releaseCodecBuffer( &(*state)->m_buffer );
		releaseCodecCallback( &(*state)->m_callback );
	}
	bfmeTwoBZB( *state );
	*state = 0;
}
