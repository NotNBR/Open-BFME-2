// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling SEH bases pinned
// elsewhere. Each class below stores its own vtable and tail-calls its base
// destructor; every base is only declared here (defined nowhere -- it
// resolves via its pin), because a same-TU definition would capture the call
// locally instead of at the ledger address. Vtable values are DIR32
// auto-patches. Owner identities are unproven (opaque Rva names). One ledger
// row per destructor, landed one commit at a time.

class Rva0098477
{
public:
	virtual ~Rva0098477();
};

class Rva00984EF : public Rva0098477
{
public:
	virtual ~Rva00984EF();
};

Rva00984EF::~Rva00984EF()
{
}

class Rva0040EDB
{
public:
	virtual ~Rva0040EDB();
};

class Rva00514E6B : public Rva0040EDB
{
public:
	virtual ~Rva00514E6B();
};

Rva00514E6B::~Rva00514E6B()
{
}

class Rva002D0588
{
public:
	virtual ~Rva002D0588();
};

class Rva004CA13 : public Rva002D0588
{
public:
	virtual ~Rva004CA13();
};

Rva004CA13::~Rva004CA13()
{
}

class Rva00224A90
{
public:
	virtual ~Rva00224A90();
};

class Rva00628FD : public Rva00224A90
{
public:
	virtual ~Rva00628FD();
};

Rva00628FD::~Rva00628FD()
{
}

class Rva002C5398
{
public:
	virtual ~Rva002C5398();
};

class Rva008FCA3 : public Rva002C5398
{
public:
	virtual ~Rva008FCA3();
};

Rva008FCA3::~Rva008FCA3()
{
}
