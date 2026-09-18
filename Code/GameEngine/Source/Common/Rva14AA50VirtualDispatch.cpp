// BFME1 donor: reference/open-bfme-1/Code/GameEngine/Source/Common/Rva14AA50VirtualDispatch.cpp
// Opaque address-derived name (true identity unknown; b1 folds 8 twins).
// Slot-9 virtual dispatch forwarder, 20B.
struct Rva006C1650Interface
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void dispatch(int first, int second);
};

void Rva006C1650(Rva006C1650Interface *object, int first, int second)
{
    object->dispatch(first, second);
}
