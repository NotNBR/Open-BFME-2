// cl: /O2 /DNDEBUG /MD

// BfmeMsg::~BfmeMsg at 0x00655780 (7B). The FESL message base (vtable
// 0xCE0BC4) proven by the landed BfmeMsgVJH ctor row. The 7B direct vptr
// reinstall (no eax homing) is a trivial destructor, not a constructor:
// MSVC 7.1 ctors copy this to EAX (they return it), dtors do not. The 16B
// sibling stays matched under the PrototypeClass ICF alias (it is the
// ctor: vptr plus m_state zero). The 121 image-wide direct callers are
// explicit base destructions at FESL message-creation sites.

class BfmeMsg
{
public:
    virtual ~BfmeMsg();

    // NOTE: the full base has an int m_state at +4 (proven by the landed
    // VJH row and the 16B sibling zeroing [eax+4]), omitted here because
    // this body never touches it.
};

BfmeMsg::~BfmeMsg()
{
}

// ??_GBfmeMsg@@UAEPAXI@Z, retail 0x00655880 (29B), is emitted by the
// delete below. The trivial dtor inlines to nothing, leaving the vptr
// reinstall plus conditional operator delete (no dtor call, like retail).

// Anchor: emits the ??_G scalar-deleting-destructor COMDAT.
void deleteBfmeMsg(BfmeMsg *p)
{
    delete p;
}
