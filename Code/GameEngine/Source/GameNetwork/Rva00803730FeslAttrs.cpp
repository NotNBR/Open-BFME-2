// cl: /GX- /GS
//
// ?go@Rva00803730Host@@QAEXPAVRva00803730Getter@@@Z, retail 0x0066F770,
// 97 bytes. Dedicated TU holding only go (the donor file also defines
// Rva00803730Sink::apply, which lives at 0x00675B60 and lands separately).
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/GameNetwork/Rva00803730FeslAttrs.cpp):
// verbatim go body. The two pushed-literal drifts in the sweep packet are
// string-literal DIR32s ("TID" 0xCE3930, "ALLOWED" 0xCE38E4), auto-patched.

class Rva00803730Getter
{
public:
	void *getPtr( void *key, void *fallback );
	bool getBool( const char *key, char flag );
};

class Rva00803730Sink
{
public:
	void apply( void *tid, bool allowed, void *pid, void *reason );
};

class Rva00803730Host
{
public:
	void go( Rva00803730Getter *r );

	char m_pad[0x18];
	Rva00803730Sink *m_sink;
};

void Rva00803730Host::go( Rva00803730Getter *r )
{
	void *tid = r->getPtr( (void *)"TID", 0 );
	bool allowed = r->getBool( "ALLOWED", 0 );
	void *pid = r->getPtr( (void *)"PID", 0 );
	void *reason = r->getPtr( (void *)"REASON", 0 );
	m_sink->apply( tid, allowed, pid, reason );
}
