// cl: /O1 /MD
//
// Opaque single-inheritance destructors tail-calling Rva006D6470::~
// Rva006D6470 at 0x006D6470 (pinned opaque SEH base dtor; identity
// unproven). Each class below stores its own vtable and tail-calls the base
// destructor; the base itself is only declared here (defined nowhere -- it
// resolves via the pin), because a same-TU definition would capture the call
// locally instead of at the ledger address. Owner identities are unproven
// (opaque Rva names). One ledger row per destructor, landed one commit at
// a time.

class Rva006D6470
{
public:
	virtual ~Rva006D6470();
};

class Rva006D65A0 : public Rva006D6470
{
public:
	virtual ~Rva006D65A0();
};

Rva006D65A0::~Rva006D65A0()
{
}

class Rva006E8F30 : public Rva006D6470
{
public:
	virtual ~Rva006E8F30();
};

Rva006E8F30::~Rva006E8F30()
{
}

class Rva006F25D0 : public Rva006D6470
{
public:
	virtual ~Rva006F25D0();
};

Rva006F25D0::~Rva006F25D0()
{
}

class Rva006F3990 : public Rva006D6470
{
public:
	virtual ~Rva006F3990();
};

Rva006F3990::~Rva006F3990()
{
}

class Rva006FC120 : public Rva006D6470
{
public:
	virtual ~Rva006FC120();
};

Rva006FC120::~Rva006FC120()
{
}

class Rva006FC1C0 : public Rva006D6470
{
public:
	virtual ~Rva006FC1C0();
};

Rva006FC1C0::~Rva006FC1C0()
{
}
