// cl: /O1 /DNDEBUG /MD
//
// ?reset@Radar@@UAEXXZ, retail 0x002D7DB9, 28 bytes. Dedicated TU: the two
// callees live in other TUs (deleteListResources is a pinned row,
// clearAllEvents is pinned), so the body lives here alone.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/Common/System/Radar.cpp):
// delete the list resources, clear all events, then stop forcing the radar
// on. BFME1 spells the flag store as [esi+0x9]; retail writes [esi+0xD].
//
// Retail passes this-4 to both callees (lea edi,[esi-4]): reset is a method
// of the second MI base (the ctor near 0x002D7CF0 installs two vptrs,
// 0xC0363C at +0 and 0xC03604 at +4; the thunk at 0x002D7D4F adjusts this
// by -4 the same way), while deleteListResources/clearAllEvents live on
// the primary base. The sole caller (0x0004E30B, an SEH init body touching
// [esi+0x146C]) passes its own this through unadjusted, as a fellow
// second-base method would.
//
// The UAE spelling is BFME1's own: reset is public virtual there.

class Radar
{
public:
	virtual void reset();
protected:
	void deleteListResources();
	void clearAllEvents();
private:
	char m_pad[0x9];
	bool m_radarForceOn;  // +0xD past the vptr
};

void Radar::reset()
{
	Radar *core = (Radar *)((char *)this - 4);
	core->deleteListResources();
	core->clearAllEvents();

	m_radarForceOn = false;
}
