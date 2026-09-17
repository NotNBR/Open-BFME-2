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

class Rva0089971_B2
{
public:
	virtual void f2();
};

class Rva0089971 : public Rva0049B47C, public MiBase1, public Rva0089971_B2
{
public:
	virtual ~Rva0089971()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0089971_Anchor(Rva0089971 *p)
{
	p->Rva0089971::~Rva0089971();
}

class Rva0089851_B2
{
public:
	virtual void f2();
};

class Rva0089851 : public Rva0049B47C, public MiBase1, public Rva0089851_B2
{
public:
	virtual ~Rva0089851()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0089851_Anchor(Rva0089851 *p)
{
	p->Rva0089851::~Rva0089851();
}

class Rva008B77D_B2
{
public:
	virtual void f2();
};

class Rva008B77D : public Rva0049B47C, public MiBase1, public Rva008B77D_B2
{
public:
	virtual ~Rva008B77D()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva008B77D_Anchor(Rva008B77D *p)
{
	p->Rva008B77D::~Rva008B77D();
}

class Rva009045E_B2
{
public:
	virtual void f2();
};

class Rva009045E : public Rva0049B47C, public MiBase1, public Rva009045E_B2
{
public:
	virtual ~Rva009045E()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva009045E_Anchor(Rva009045E *p)
{
	p->Rva009045E::~Rva009045E();
}

class Rva0090771_B2
{
public:
	virtual void f2();
};

class Rva0090771 : public Rva0049B47C, public MiBase1, public Rva0090771_B2
{
public:
	virtual ~Rva0090771()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0090771_Anchor(Rva0090771 *p)
{
	p->Rva0090771::~Rva0090771();
}

class Rva0090840_B2
{
public:
	virtual void f2();
};

class Rva0090840 : public Rva0049B47C, public MiBase1, public Rva0090840_B2
{
public:
	virtual ~Rva0090840()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0090840_Anchor(Rva0090840 *p)
{
	p->Rva0090840::~Rva0090840();
}

class Rva009203A_B2
{
public:
	virtual void f2();
};

class Rva009203A : public Rva0049B47C, public MiBase1, public Rva009203A_B2
{
public:
	virtual ~Rva009203A()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva009203A_Anchor(Rva009203A *p)
{
	p->Rva009203A::~Rva009203A();
}

class Rva0094F38_B2
{
public:
	virtual void f2();
};

class Rva0094F38 : public Rva0049B47C, public MiBase1, public Rva0094F38_B2
{
public:
	virtual ~Rva0094F38()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0094F38_Anchor(Rva0094F38 *p)
{
	p->Rva0094F38::~Rva0094F38();
}

class Rva0095360_B2
{
public:
	virtual void f2();
};

class Rva0095360 : public Rva0049B47C, public MiBase1, public Rva0095360_B2
{
public:
	virtual ~Rva0095360()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0095360_Anchor(Rva0095360 *p)
{
	p->Rva0095360::~Rva0095360();
}

class Rva0098477_B2
{
public:
	virtual void f2();
};

class Rva0098477 : public Rva0049B47C, public MiBase1, public Rva0098477_B2
{
public:
	virtual ~Rva0098477()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0098477_Anchor(Rva0098477 *p)
{
	p->Rva0098477::~Rva0098477();
}

class Rva00986E7_B2
{
public:
	virtual void f2();
};

class Rva00986E7 : public Rva0049B47C, public MiBase1, public Rva00986E7_B2
{
public:
	virtual ~Rva00986E7()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00986E7_Anchor(Rva00986E7 *p)
{
	p->Rva00986E7::~Rva00986E7();
}

class Rva0098B8B_B2
{
public:
	virtual void f2();
};

class Rva0098B8B : public Rva0049B47C, public MiBase1, public Rva0098B8B_B2
{
public:
	virtual ~Rva0098B8B()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0098B8B_Anchor(Rva0098B8B *p)
{
	p->Rva0098B8B::~Rva0098B8B();
}

class Rva0098D9E_B2
{
public:
	virtual void f2();
};

class Rva0098D9E : public Rva0049B47C, public MiBase1, public Rva0098D9E_B2
{
public:
	virtual ~Rva0098D9E()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0098D9E_Anchor(Rva0098D9E *p)
{
	p->Rva0098D9E::~Rva0098D9E();
}

class Rva0099927_B2
{
public:
	virtual void f2();
};

class Rva0099927 : public Rva0049B47C, public MiBase1, public Rva0099927_B2
{
public:
	virtual ~Rva0099927()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0099927_Anchor(Rva0099927 *p)
{
	p->Rva0099927::~Rva0099927();
}

class Rva009D6FA_B2
{
public:
	virtual void f2();
};

class Rva009D6FA : public Rva0049B47C, public MiBase1, public Rva009D6FA_B2
{
public:
	virtual ~Rva009D6FA()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva009D6FA_Anchor(Rva009D6FA *p)
{
	p->Rva009D6FA::~Rva009D6FA();
}

class Rva00A6454_B2
{
public:
	virtual void f2();
};

class Rva00A6454 : public Rva0049B47C, public MiBase1, public Rva00A6454_B2
{
public:
	virtual ~Rva00A6454()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00A6454_Anchor(Rva00A6454 *p)
{
	p->Rva00A6454::~Rva00A6454();
}

class Rva00514E6B_B2
{
public:
	virtual void f2();
};

class Rva00514E6B : public Rva0049B47C, public MiBase1, public Rva00514E6B_B2
{
public:
	virtual ~Rva00514E6B()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00514E6B_Anchor(Rva00514E6B *p)
{
	p->Rva00514E6B::~Rva00514E6B();
}

class Rva00A8E0A_B2
{
public:
	virtual void f2();
};

class Rva00A8E0A : public Rva0049B47C, public MiBase1, public Rva00A8E0A_B2
{
public:
	virtual ~Rva00A8E0A()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00A8E0A_Anchor(Rva00A8E0A *p)
{
	p->Rva00A8E0A::~Rva00A8E0A();
}

class Rva0011018B_B2
{
public:
	virtual void f2();
};

class Rva0011018B : public Rva0049B47C, public MiBase1, public Rva0011018B_B2
{
public:
	virtual ~Rva0011018B()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0011018B_Anchor(Rva0011018B *p)
{
	p->Rva0011018B::~Rva0011018B();
}

class Rva00A9CC7_B2
{
public:
	virtual void f2();
};

class Rva00A9CC7 : public Rva0049B47C, public MiBase1, public Rva00A9CC7_B2
{
public:
	virtual ~Rva00A9CC7()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00A9CC7_Anchor(Rva00A9CC7 *p)
{
	p->Rva00A9CC7::~Rva00A9CC7();
}

class Rva00111B25_B2
{
public:
	virtual void f2();
};

class Rva00111B25 : public Rva0049B47C, public MiBase1, public Rva00111B25_B2
{
public:
	virtual ~Rva00111B25()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00111B25_Anchor(Rva00111B25 *p)
{
	p->Rva00111B25::~Rva00111B25();
}

class Rva00419E3_B2
{
public:
	virtual void f2();
};

class Rva00419E3 : public Rva0049B47C, public MiBase1, public Rva00419E3_B2
{
public:
	virtual ~Rva00419E3()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00419E3_Anchor(Rva00419E3 *p)
{
	p->Rva00419E3::~Rva00419E3();
}

class Rva004C743_B2
{
public:
	virtual void f2();
};

class Rva004C743 : public Rva0049B47C, public MiBase1, public Rva004C743_B2
{
public:
	virtual ~Rva004C743()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva004C743_Anchor(Rva004C743 *p)
{
	p->Rva004C743::~Rva004C743();
}

class Rva004CA13_B2
{
public:
	virtual void f2();
};

class Rva004CA13 : public Rva0049B47C, public MiBase1, public Rva004CA13_B2
{
public:
	virtual ~Rva004CA13()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva004CA13_Anchor(Rva004CA13 *p)
{
	p->Rva004CA13::~Rva004CA13();
}

class Rva00628FD_B2
{
public:
	virtual void f2();
};

class Rva00628FD : public Rva0049B47C, public MiBase1, public Rva00628FD_B2
{
public:
	virtual ~Rva00628FD()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00628FD_Anchor(Rva00628FD *p)
{
	p->Rva00628FD::~Rva00628FD();
}

class Rva0062AF7_B2
{
public:
	virtual void f2();
};

class Rva0062AF7 : public Rva0049B47C, public MiBase1, public Rva0062AF7_B2
{
public:
	virtual ~Rva0062AF7()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0062AF7_Anchor(Rva0062AF7 *p)
{
	p->Rva0062AF7::~Rva0062AF7();
}

class Rva008FCA3_B2
{
public:
	virtual void f2();
};

class Rva008FCA3 : public Rva0049B47C, public MiBase1, public Rva008FCA3_B2
{
public:
	virtual ~Rva008FCA3()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva008FCA3_Anchor(Rva008FCA3 *p)
{
	p->Rva008FCA3::~Rva008FCA3();
}

class Rva0090034_B2
{
public:
	virtual void f2();
};

class Rva0090034 : public Rva0049B47C, public MiBase1, public Rva0090034_B2
{
public:
	virtual ~Rva0090034()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0090034_Anchor(Rva0090034 *p)
{
	p->Rva0090034::~Rva0090034();
}

class Rva0090088_B2
{
public:
	virtual void f2();
};

class Rva0090088 : public Rva0049B47C, public MiBase1, public Rva0090088_B2
{
public:
	virtual ~Rva0090088()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0090088_Anchor(Rva0090088 *p)
{
	p->Rva0090088::~Rva0090088();
}

class Rva009111B_B2
{
public:
	virtual void f2();
};

class Rva009111B : public Rva0049B47C, public MiBase1, public Rva009111B_B2
{
public:
	virtual ~Rva009111B()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva009111B_Anchor(Rva009111B *p)
{
	p->Rva009111B::~Rva009111B();
}

class Rva00B0028_B2
{
public:
	virtual void f2();
};

class Rva00B0028 : public Rva0049B47C, public MiBase1, public Rva00B0028_B2
{
public:
	virtual ~Rva00B0028()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00B0028_Anchor(Rva00B0028 *p)
{
	p->Rva00B0028::~Rva00B0028();
}

class Rva00B6DD2_B2
{
public:
	virtual void f2();
};

class Rva00B6DD2 : public Rva0049B47C, public MiBase1, public Rva00B6DD2_B2
{
public:
	virtual ~Rva00B6DD2()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00B6DD2_Anchor(Rva00B6DD2 *p)
{
	p->Rva00B6DD2::~Rva00B6DD2();
}

class Rva00B6971_B2
{
public:
	virtual void f2();
};

class Rva00B6971 : public Rva0049B47C, public MiBase1, public Rva00B6971_B2
{
public:
	virtual ~Rva00B6971()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00B6971_Anchor(Rva00B6971 *p)
{
	p->Rva00B6971::~Rva00B6971();
}

class Rva00BE201_B2
{
public:
	virtual void f2();
};

class Rva00BE201 : public Rva0049B47C, public MiBase1, public Rva00BE201_B2
{
public:
	virtual ~Rva00BE201()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00BE201_Anchor(Rva00BE201 *p)
{
	p->Rva00BE201::~Rva00BE201();
}

class Rva00C6D44_B2
{
public:
	virtual void f2();
};

class Rva00C6D44 : public Rva0049B47C, public MiBase1, public Rva00C6D44_B2
{
public:
	virtual ~Rva00C6D44()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00C6D44_Anchor(Rva00C6D44 *p)
{
	p->Rva00C6D44::~Rva00C6D44();
}

class Rva00A86CE_B2
{
public:
	virtual void f2();
};

class Rva00A86CE : public Rva0049B47C, public MiBase1, public Rva00A86CE_B2
{
public:
	virtual ~Rva00A86CE()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00A86CE_Anchor(Rva00A86CE *p)
{
	p->Rva00A86CE::~Rva00A86CE();
}

class Rva00A897D_B2
{
public:
	virtual void f2();
};

class Rva00A897D : public Rva0049B47C, public MiBase1, public Rva00A897D_B2
{
public:
	virtual ~Rva00A897D()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva00A897D_Anchor(Rva00A897D *p)
{
	p->Rva00A897D::~Rva00A897D();
}

class Rva0084CEF_B2
{
public:
	virtual void f2();
};

class Rva0084CEF : public Rva0049B47C, public MiBase1, public Rva0084CEF_B2
{
public:
	virtual ~Rva0084CEF()
	{
	}
};

// Anchor: forces out-of-line emission of the in-class destructor COMDAT,
// including the scalar deleting destructor.
void Rva0084CEF_Anchor(Rva0084CEF *p)
{
	p->Rva0084CEF::~Rva0084CEF();
}
