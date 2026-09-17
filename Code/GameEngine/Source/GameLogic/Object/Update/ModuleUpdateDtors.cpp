// cl: /O1 /MD
//
// Opaque module destructors tail-calling Rva0044EF5E::~Rva0044EF5E at
// 0x00451F45 (pinned opaque intermediate base dtor; the derived module
// dtors re-store the vtable plus the +0x0C/+0x10/+0x20 consts, then
// tail-jump it). The base is modeled with its full 0x88 layout but its
// destructor is only declared here (defined nowhere -- it resolves via the
// pin), because a same-TU definition would capture the call locally instead
// of at the ledger address. Vtable values and consts are DIR32 auto-patches.
// Derived identities come from factory stub order (OCLUpdate,
// SpawnPointProductionExitUpdate, SupplyCenterDockUpdate); the base identity
// is unproven (opaque Rva name). One ledger row per destructor, landed one
// commit at a time. Each class also emits its scalar deleting destructor
// (vtable slot 0), claimed as its own row once the primary lands.

class Thing;
class ModuleData;

static int s_dummy0C;
static int s_dummy10;
static int s_dummy20;

// Opaque 0x88-byte UpdateModule-derived intermediate; dtor resolves to the
// opaque pin at 0x00451F45. Protected slots mirror the retail stores.
class Rva0044EF5E
{
public:
	Rva0044EF5E(Thing *thing, const ModuleData *moduleData);
	virtual ~Rva0044EF5E();

protected:
	unsigned char m_pad0[8];
	const void *m_p0C;
	const void *m_p10;
	unsigned char m_pad1[0x20 - 0x14];
	const void *m_p20;
	unsigned char m_pad2[0x88 - 0x24];
};

class OCLUpdate : public Rva0044EF5E
{
public:
	virtual ~OCLUpdate();
};

OCLUpdate::~OCLUpdate()
{
	m_p0C = &s_dummy0C;
	m_p10 = &s_dummy10;
	m_p20 = &s_dummy20;
}

class SpawnPointProductionExitUpdate : public Rva0044EF5E
{
public:
	virtual ~SpawnPointProductionExitUpdate();
};

SpawnPointProductionExitUpdate::~SpawnPointProductionExitUpdate()
{
	m_p0C = &s_dummy0C;
	m_p10 = &s_dummy10;
	m_p20 = &s_dummy20;
}

class SupplyCenterDockUpdate : public Rva0044EF5E
{
public:
	virtual ~SupplyCenterDockUpdate();
};

SupplyCenterDockUpdate::~SupplyCenterDockUpdate()
{
	m_p0C = &s_dummy0C;
	m_p10 = &s_dummy10;
	m_p20 = &s_dummy20;
}

class Rva00490D76 : public Rva0044EF5E
{
public:
	virtual ~Rva00490D76();
};

Rva00490D76::~Rva00490D76()
{
	m_p0C = &s_dummy0C;
	m_p10 = &s_dummy10;
	m_p20 = &s_dummy20;
}

class Rva004921B0 : public Rva0044EF5E
{
public:
	virtual ~Rva004921B0();
};

Rva004921B0::~Rva004921B0()
{
	m_p0C = &s_dummy0C;
	m_p10 = &s_dummy10;
	m_p20 = &s_dummy20;
}

static int s_dummyDFD4;
static int s_dummyEB30;
static int s_dummyE184;
static int s_dummyEB0C;

class Rva00492439 : public Rva0044EF5E
{
public:
	virtual ~Rva00492439();
};

Rva00492439::~Rva00492439()
{
	m_p0C = &s_dummy0C;
	m_p10 = &s_dummy10;
	m_p20 = &s_dummyDFD4;
}

class Rva00492C90 : public Rva0044EF5E
{
public:
	virtual ~Rva00492C90();
};

Rva00492C90::~Rva00492C90()
{
	m_p0C = &s_dummy0C;
	m_p10 = &s_dummyEB30;
	m_p20 = &s_dummyE184;
}

class Rva00494E01 : public Rva0044EF5E
{
public:
	virtual ~Rva00494E01();
};

Rva00494E01::~Rva00494E01()
{
	m_p0C = &s_dummy0C;
	m_p10 = &s_dummyEB30;
	m_p20 = &s_dummyEB0C;
}

class Rva00494F1B : public Rva0044EF5E
{
public:
	virtual ~Rva00494F1B();
};

Rva00494F1B::~Rva00494F1B()
{
	m_p0C = &s_dummy0C;
	m_p10 = &s_dummy10;
	m_p20 = &s_dummy20;
}
