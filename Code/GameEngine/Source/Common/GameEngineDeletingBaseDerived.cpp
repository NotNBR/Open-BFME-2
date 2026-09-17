// cl: /O1 /MD
//
// Opaque derived destructors that tail-call GameEngineDeletingBase::~
// GameEngineDeletingBase at 0x001B4E74 (vtable store, tail jump, no member
// of their own). Each class below is a distinct retail vtable whose owner
// identity is unproven. One ledger row per destructor, landed one commit at
// a time; the base declaration is shared and defined once in
// GameEngineDeletingBaseDtor.cpp (its row resolves the tail calls).

class GameEngineDeletingBase
{
public:
	virtual ~GameEngineDeletingBase();
};

class Rva00221027 : public GameEngineDeletingBase
{
public:
	virtual ~Rva00221027();
};

Rva00221027::~Rva00221027()
{
}

class Rva00225ACA : public GameEngineDeletingBase
{
public:
	virtual ~Rva00225ACA();
};

Rva00225ACA::~Rva00225ACA()
{
}

class Rva00232D7B : public GameEngineDeletingBase
{
public:
	virtual ~Rva00232D7B();
};

Rva00232D7B::~Rva00232D7B()
{
}
