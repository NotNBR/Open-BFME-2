// cl: /O1 /MD
//
// ??_GRva004B8CDE@@UAEPAXI@Z at retail 0x004B8D32 (28B): emitted scalar
// deleting destructor for the pinned opaque MI middle Rva004B8CDE (25B
// order-B body tail-jumping the 0x49B47C fold). The dtor call resolves via
// the existing pin; the middle itself stays unclaimed (order-B wall, see the
// 0x484EF4 partial bank). Operator delete resolves via the pinned ??3.

class Rva0049B47C
{
public:
	virtual ~Rva0049B47C();

private:
	char m_pad04[8];
};

class MiBase1
{
public:
	virtual void f1();
};

class Rva004B8CDE_B2
{
public:
	virtual void f2();
};

class Rva004B8CDE : public Rva0049B47C, public MiBase1, public Rva004B8CDE_B2
{
public:
	virtual ~Rva004B8CDE()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva004B8CDE_Anchor(Rva004B8CDE *p)
{
	p->Rva004B8CDE::~Rva004B8CDE();
}
