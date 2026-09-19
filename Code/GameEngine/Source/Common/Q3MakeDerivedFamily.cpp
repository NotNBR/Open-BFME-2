// Trimmed port of reference/open-bfme-1/Code/GameEngine/Source/Common/
// Q3MakeDerivedFamily.cpp: only the Rva007E9B40 helper is carried; the seven
// sibling helpers stay with the donor until rows land. See the donor for the
// full multiple-inheritance analysis.

void *Gen007F0130( unsigned int size );

class Q3MakeBaseA
{
public:
	virtual void primary();
	static void *operator new( unsigned int size ) { return Gen007F0130( size ); }
};

class Q3MakeBaseB
{
public:
	virtual void secondary();
	void *m_payload;
	Q3MakeBaseB( void *payload ) { m_payload = payload; }
};

class Rva007E9B40Object : public Q3MakeBaseA, public Q3MakeBaseB
{
public:
	Rva007E9B40Object( void *payload ) : Q3MakeBaseB( payload ) {}
	virtual void primary();
	virtual void secondary();
};

Rva007E9B40Object *Rva007E9B40( void *payload )
{
	return new Rva007E9B40Object( payload );
}
