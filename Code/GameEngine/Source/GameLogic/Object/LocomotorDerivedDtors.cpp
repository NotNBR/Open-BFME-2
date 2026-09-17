// cl: /O1 /MD
//
// Opaque multiple-inheritance destructor tail-calling the matched
// Locomotor::~Locomotor at 0x003067D2 (defined in
// GameLogic/Object/Locomotor.cpp; only declared here so the tail-call
// resolves to the ledger address instead of a same-TU definition). The
// class below derives (in order) from the real base and its own empty
// polymorphic base, giving vptrs at +0x00/+0x04 (0xBC5A5C/0xBC5A24, DIR32
// auto-patches); the empty base has an implicit trivial destructor, so the
// derived destructor stores both vptrs and tail-calls the base destructor.
// The base declares a protected virtual dtor to mangle MAE like the row.
// Owner identity is unproven (opaque Rva name). One ledger row per
// destructor, landed one commit at a time.

class Locomotor
{
protected:
	virtual ~Locomotor();
};

class Rva000647D4_B
{
public:
	virtual void f();
};

class Rva000647D4 : public Locomotor, public Rva000647D4_B
{
public:
	virtual ~Rva000647D4();
};

Rva000647D4::~Rva000647D4()
{
}
