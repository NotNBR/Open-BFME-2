// cl: /O1 /MD
//
// ??_GRva0024A797@@UAEPAXI@Z at retail 0x002533E0 (28B): emitted scalar
// deleting destructor for the pinned opaque MI middle Rva0024A797 (25B
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

class Rva0024A797_B2
{
public:
	virtual void f2();

private:
	char m_pad08[12];
};

class Rva0024A797 : public Rva0049B47C, public MiBase1, public Rva0024A797_B2
{
public:
	virtual ~Rva0024A797()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0024A797_Anchor(Rva0024A797 *p)
{
	p->Rva0024A797::~Rva0024A797();
}
