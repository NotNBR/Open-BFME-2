// Trimmed port of reference/open-bfme-1/Code/GameEngine/Source/Common/
// Q3MakeDerivedFamily.cpp: the Rva007E9B40, Rva007F2E60 and Rva007F3410
// helpers are carried; the five sibling helpers stay with the donor until
// rows land. See the donor for the full multiple-inheritance analysis.

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

class Rva007F2E60Object : public Q3MakeBaseA, public Q3MakeBaseB
{
public:
	Rva007F2E60Object( void *payload ) : Q3MakeBaseB( payload ) {}
	virtual void primary();
	virtual void secondary();
};

Rva007F2E60Object *Rva007F2E60( void *payload )
{
	return new Rva007F2E60Object( payload );
}

class Rva007F3410Object : public Q3MakeBaseA, public Q3MakeBaseB
{
public:
	Rva007F3410Object( void *payload ) : Q3MakeBaseB( payload ) {}
	virtual void primary();
	virtual void secondary();
};

Rva007F3410Object *Rva007F3410( void *payload )
{
	return new Rva007F3410Object( payload );
}
