// cl: /O1 /MD
//
// Emitted scalar deleting destructors (28B flag-test shape) for unclaimed
// destructors found by sweeping the image for the
// push-esi/mov-esi,ecx/call/test-[esp+8],1 pattern. Each dtor is pinned
// opaquely (evidence: the ??_G call site plus the body bytes at the pinned
// address); the dtor bodies themselves stay unclaimed. The emitting classes
// below use a three-vptr MI model so the in-class destructor is too big to
// inline and the ??_G calls out through the pin (a single-vptr dtor would
// inline into the ??_G instead). Operator delete resolves via the pinned ??3.
// Owner identities are unproven (opaque Rva names). One ledger row per
// destructor, landed one commit at a time.

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

class Rva0065D52_B2
{
public:
	virtual void f2();
};

class Rva0065D52 : public Rva0049B47C, public MiBase1, public Rva0065D52_B2
{
public:
	virtual ~Rva0065D52()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0065D52_Anchor(Rva0065D52 *p)
{
	p->Rva0065D52::~Rva0065D52();
}

class Rva0049FCB_B2
{
public:
	virtual void f2();
};

class Rva0049FCB : public Rva0049B47C, public MiBase1, public Rva0049FCB_B2
{
public:
	virtual ~Rva0049FCB()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0049FCB_Anchor(Rva0049FCB *p)
{
	p->Rva0049FCB::~Rva0049FCB();
}

class Rva009023C_B2
{
public:
	virtual void f2();
};

class Rva009023C : public Rva0049B47C, public MiBase1, public Rva009023C_B2
{
public:
	virtual ~Rva009023C()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva009023C_Anchor(Rva009023C *p)
{
	p->Rva009023C::~Rva009023C();
}

class Rva004EFE9_B2
{
public:
	virtual void f2();
};

class Rva004EFE9 : public Rva0049B47C, public MiBase1, public Rva004EFE9_B2
{
public:
	virtual ~Rva004EFE9()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva004EFE9_Anchor(Rva004EFE9 *p)
{
	p->Rva004EFE9::~Rva004EFE9();
}

class Rva0050B2A_B2
{
public:
	virtual void f2();
};

class Rva0050B2A : public Rva0049B47C, public MiBase1, public Rva0050B2A_B2
{
public:
	virtual ~Rva0050B2A()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0050B2A_Anchor(Rva0050B2A *p)
{
	p->Rva0050B2A::~Rva0050B2A();
}

class Rva006DD51_B2
{
public:
	virtual void f2();
};

class Rva006DD51 : public Rva0049B47C, public MiBase1, public Rva006DD51_B2
{
public:
	virtual ~Rva006DD51()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva006DD51_Anchor(Rva006DD51 *p)
{
	p->Rva006DD51::~Rva006DD51();
}

class Rva0072892_B2
{
public:
	virtual void f2();
};

class Rva0072892 : public Rva0049B47C, public MiBase1, public Rva0072892_B2
{
public:
	virtual ~Rva0072892()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0072892_Anchor(Rva0072892 *p)
{
	p->Rva0072892::~Rva0072892();
}

class Rva005333F_B2
{
public:
	virtual void f2();
};

class Rva005333F : public Rva0049B47C, public MiBase1, public Rva005333F_B2
{
public:
	virtual ~Rva005333F()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva005333F_Anchor(Rva005333F *p)
{
	p->Rva005333F::~Rva005333F();
}

class Rva00638C4_B2
{
public:
	virtual void f2();
};

class Rva00638C4 : public Rva0049B47C, public MiBase1, public Rva00638C4_B2
{
public:
	virtual ~Rva00638C4()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00638C4_Anchor(Rva00638C4 *p)
{
	p->Rva00638C4::~Rva00638C4();
}

class Rva006422F_B2
{
public:
	virtual void f2();
};

class Rva006422F : public Rva0049B47C, public MiBase1, public Rva006422F_B2
{
public:
	virtual ~Rva006422F()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva006422F_Anchor(Rva006422F *p)
{
	p->Rva006422F::~Rva006422F();
}

class Rva0065288_B2
{
public:
	virtual void f2();
};

class Rva0065288 : public Rva0049B47C, public MiBase1, public Rva0065288_B2
{
public:
	virtual ~Rva0065288()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0065288_Anchor(Rva0065288 *p)
{
	p->Rva0065288::~Rva0065288();
}

class Rva0065CA4_B2
{
public:
	virtual void f2();
};

class Rva0065CA4 : public Rva0049B47C, public MiBase1, public Rva0065CA4_B2
{
public:
	virtual ~Rva0065CA4()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0065CA4_Anchor(Rva0065CA4 *p)
{
	p->Rva0065CA4::~Rva0065CA4();
}

class Rva000D3996_B2
{
public:
	virtual void f2();
};

class Rva000D3996 : public Rva0049B47C, public MiBase1, public Rva000D3996_B2
{
public:
	virtual ~Rva000D3996()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva000D3996_Anchor(Rva000D3996 *p)
{
	p->Rva000D3996::~Rva000D3996();
}

class Rva006D0D7_B2
{
public:
	virtual void f2();
};

class Rva006D0D7 : public Rva0049B47C, public MiBase1, public Rva006D0D7_B2
{
public:
	virtual ~Rva006D0D7()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva006D0D7_Anchor(Rva006D0D7 *p)
{
	p->Rva006D0D7::~Rva006D0D7();
}

class Rva007280A_B2
{
public:
	virtual void f2();
};

class Rva007280A : public Rva0049B47C, public MiBase1, public Rva007280A_B2
{
public:
	virtual ~Rva007280A()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva007280A_Anchor(Rva007280A *p)
{
	p->Rva007280A::~Rva007280A();
}

class Rva00751EF_B2
{
public:
	virtual void f2();
};

class Rva00751EF : public Rva0049B47C, public MiBase1, public Rva00751EF_B2
{
public:
	virtual ~Rva00751EF()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00751EF_Anchor(Rva00751EF *p)
{
	p->Rva00751EF::~Rva00751EF();
}

class Rva0078393_B2
{
public:
	virtual void f2();
};

class Rva0078393 : public Rva0049B47C, public MiBase1, public Rva0078393_B2
{
public:
	virtual ~Rva0078393()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0078393_Anchor(Rva0078393 *p)
{
	p->Rva0078393::~Rva0078393();
}

class Rva007BB16_B2
{
public:
	virtual void f2();
};

class Rva007BB16 : public Rva0049B47C, public MiBase1, public Rva007BB16_B2
{
public:
	virtual ~Rva007BB16()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva007BB16_Anchor(Rva007BB16 *p)
{
	p->Rva007BB16::~Rva007BB16();
}

class Rva007C454_B2
{
public:
	virtual void f2();
};

class Rva007C454 : public Rva0049B47C, public MiBase1, public Rva007C454_B2
{
public:
	virtual ~Rva007C454()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva007C454_Anchor(Rva007C454 *p)
{
	p->Rva007C454::~Rva007C454();
}

class Rva007E1AE_B2
{
public:
	virtual void f2();
};

class Rva007E1AE : public Rva0049B47C, public MiBase1, public Rva007E1AE_B2
{
public:
	virtual ~Rva007E1AE()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva007E1AE_Anchor(Rva007E1AE *p)
{
	p->Rva007E1AE::~Rva007E1AE();
}

class Rva007EC44_B2
{
public:
	virtual void f2();
};

class Rva007EC44 : public Rva0049B47C, public MiBase1, public Rva007EC44_B2
{
public:
	virtual ~Rva007EC44()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva007EC44_Anchor(Rva007EC44 *p)
{
	p->Rva007EC44::~Rva007EC44();
}

class Rva0084096_B2
{
public:
	virtual void f2();
};

class Rva0084096 : public Rva0049B47C, public MiBase1, public Rva0084096_B2
{
public:
	virtual ~Rva0084096()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0084096_Anchor(Rva0084096 *p)
{
	p->Rva0084096::~Rva0084096();
}
