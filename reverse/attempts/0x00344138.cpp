// ?getAdjustsDestination@AIInternalMoveToState@@IBE_NXZ
// partial score=0.8272251308900523 date=2026-09-21
// cl: /O1 /MD /EHsc
// BFME1 AIStates.cpp and banked 0x001724b0.cpp semantic/control-flow donors.
// PC 344138 diagnostics independently name the routine. PC offsets, not Xbox:
// machine18 -> owner14 -> AI258; own adjusts48; permission vtable slot1AC.
#define TEN(P) virtual void v##P##0(); virtual void v##P##1(); virtual void v##P##2(); virtual void v##P##3(); virtual void v##P##4(); virtual void v##P##5(); virtual void v##P##6(); virtual void v##P##7(); virtual void v##P##8(); virtual void v##P##9();
class AIUpdateInterface {
public:
    TEN(0) TEN(1) TEN(2) TEN(3) TEN(4) TEN(5) TEN(6) TEN(7) TEN(8) TEN(9)
    virtual void v100(); virtual void v101(); virtual void v102(); virtual void v103();
    virtual void v104(); virtual void v105(); virtual void v106();
    virtual bool isAllowedToAdjustDestination() const;
};
#undef TEN
enum ObjectStatusTypes { OBJECT_STATUS_PARACHUTING = 7 };
struct Object {
    char unknown[0x258];
    AIUpdateInterface *ai;
    bool testStatus(ObjectStatusTypes) const;
};
struct StateMachine { char unknown[0x14]; Object *owner; };
class State {
protected:
    virtual void stateSlot();
    char unknown[0x14];
    StateMachine *machine;
};
class AIInternalMoveToState : public State {
protected:
    bool getAdjustsDestination() const;
private:
    char unknown[0x48-0x1c];
    bool adjustsDestinations;
};
extern unsigned char gCritterDesyncLoggingEnabled;
struct _iobuf;
extern _iobuf *gCritterDesyncLogFile;
extern "C" int __cdecl fprintf(_iobuf *, const char *, ...);
bool AIInternalMoveToState::getAdjustsDestination() const
{
    AIInternalMoveToState *self = (AIInternalMoveToState *)this;
    if (gCritterDesyncLoggingEnabled && gCritterDesyncLogFile)
        fprintf(gCritterDesyncLogFile,"CritterDesync: getAdjustsDestination() entered.");
    Object *obj = self->machine->owner;
    if (obj->testStatus(OBJECT_STATUS_PARACHUTING)) {
        if (gCritterDesyncLoggingEnabled && gCritterDesyncLogFile)
            fprintf(gCritterDesyncLogFile,"CritterDesync: getAdjustsDestination1 - parachuting returning FALSE.");
        return false;
    }
    AIUpdateInterface *ai = obj->ai;
    if (ai && !ai->isAllowedToAdjustDestination()) {
        if (gCritterDesyncLoggingEnabled && gCritterDesyncLogFile)
            fprintf(gCritterDesyncLogFile,"CritterDesync: getAdjustsDestination1 - isAllowedToAdjustDestination FALSE, returning FALSE.");
        return false;
    }
    if (gCritterDesyncLoggingEnabled && gCritterDesyncLogFile) {
        const char *label = self->adjustsDestinations ? "TRUE" : "FALSE";
        fprintf(gCritterDesyncLogFile,"CritterDesync: getAdjustsDestination1 - m_adjustsDestinations = %s",label);
    }
    return self->adjustsDestinations;
}
