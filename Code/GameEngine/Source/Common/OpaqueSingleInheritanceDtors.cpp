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

class Rva0023AE08
{
public:
	virtual ~Rva0023AE08();

private:
	char m_pad04[8];
};

class MiBase1_4C743
{
public:
	virtual void f1();
};

class Rva004C743 : public Rva0023AE08, public MiBase1_4C743
{
public:
	virtual ~Rva004C743();
};

Rva004C743::~Rva004C743()
{
}

class Rva0028418A
{
public:
	virtual ~Rva0028418A();
};

class MiBase1_62AF7
{
public:
	virtual void f1();

private:
	char m_pad04[8];
};

class MiBase2_62AF7
{
public:
	virtual void f2();
};

class MiBase3_62AF7
{
public:
	virtual void f3();
};

class Rva0062AF7 : public Rva0028418A, public MiBase1_62AF7, public MiBase2_62AF7, public MiBase3_62AF7
{
public:
	virtual ~Rva0062AF7();
};

Rva0062AF7::~Rva0062AF7()
{
}

class Rva00605CA7
{
public:
	virtual ~Rva00605CA7();
};

class Rva00605C6A : public Rva00605CA7
{
public:
	virtual ~Rva00605C6A();
};

Rva00605C6A::~Rva00605C6A()
{
}

class Rva003B00D6
{
public:
	virtual ~Rva003B00D6();
};

class Rva003B0152 : public Rva003B00D6
{
public:
	virtual ~Rva003B0152();
};

Rva003B0152::~Rva003B0152()
{
}

class Rva003B0344
{
public:
	virtual ~Rva003B0344();
};

class Rva003B0401 : public Rva003B0344
{
public:
	virtual ~Rva003B0401();
};

Rva003B0401::~Rva003B0401()
{
}

class Rva003FCE38
{
public:
	virtual ~Rva003FCE38();
};

class Rva005C4B1B : public Rva003FCE38
{
public:
	virtual ~Rva005C4B1B();
};

Rva005C4B1B::~Rva005C4B1B()
{
}

class Rva001E3624
{
public:
	virtual ~Rva001E3624();
};

class Rva003FA776 : public Rva001E3624
{
public:
	virtual ~Rva003FA776();
};

Rva003FA776::~Rva003FA776()
{
}
