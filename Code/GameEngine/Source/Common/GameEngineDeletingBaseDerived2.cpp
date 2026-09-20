// cl: /MD
//
// Opaque GameEngineDeletingBase-derived destructor whose scalar deleting
// destructor retail compiled WITHOUT size optimization (add esp,4 cleanup
// instead of the /O1 pop ecx the sibling TU emits). Split from
// GameEngineDeletingBaseDerived.cpp, which compiles /O1 and cannot
// reproduce this body. The base is only declared here and defined once in
// GameEngineDeletingBaseDtor.cpp, so the tail call resolves to the ledger
// address 0x001B4E74. Owner identity is unproven (opaque Rva name).

class GameEngineDeletingBase
{
public:
	virtual ~GameEngineDeletingBase();
};

class Rva006892F0 : public GameEngineDeletingBase
{
public:
	virtual ~Rva006892F0();
};

Rva006892F0::~Rva006892F0()
{
}
