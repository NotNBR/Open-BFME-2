// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD
//
// ?setTimeOfDay@W3DGameClient@@UAEXW4TimeOfDay@@@Z @ 0x0004C884 (56B).
// Dedicated TU: BFME1 donor shape verbatim, adapted to BFME2 retail (measured):
// water/shadow/display globals at 0x00DE2000/0x00DE5DFC/0x00DFE9D8 (DIR32,
// address-derived placeholder names per the R2Data precedent) and the display
// call at virtual slot 0xB4 (45 pads, AddFrameEntry idiom). The Bool twins
// (EnableLoginControls/enableControls) are refuted by the dword push.

enum TimeOfDay
{
	TIME_OF_DAY_MORNING = 0,
	TIME_OF_DAY_AFTERNOON = 1,
	TIME_OF_DAY_EVENING = 2,
	TIME_OF_DAY_NIGHT = 3
};

extern void *W3DGCData00DE2000;
extern void *W3DGCData00DE5DFC;
extern void *W3DGCData00DFE9D8;

class W3DGameClientWaterShim
{
public:
	void setTimeOfDay(TimeOfDay tod);
};

class W3DGameClientShadowShim
{
public:
	void setTimeOfDay(TimeOfDay tod);
};

class W3DGameClientDisplayShim
{
public:
	virtual void slot00() = 0;
	virtual void slot01() = 0;
	virtual void slot02() = 0;
	virtual void slot03() = 0;
	virtual void slot04() = 0;
	virtual void slot05() = 0;
	virtual void slot06() = 0;
	virtual void slot07() = 0;
	virtual void slot08() = 0;
	virtual void slot09() = 0;
	virtual void slot10() = 0;
	virtual void slot11() = 0;
	virtual void slot12() = 0;
	virtual void slot13() = 0;
	virtual void slot14() = 0;
	virtual void slot15() = 0;
	virtual void slot16() = 0;
	virtual void slot17() = 0;
	virtual void slot18() = 0;
	virtual void slot19() = 0;
	virtual void slot20() = 0;
	virtual void slot21() = 0;
	virtual void slot22() = 0;
	virtual void slot23() = 0;
	virtual void slot24() = 0;
	virtual void slot25() = 0;
	virtual void slot26() = 0;
	virtual void slot27() = 0;
	virtual void slot28() = 0;
	virtual void slot29() = 0;
	virtual void slot30() = 0;
	virtual void slot31() = 0;
	virtual void slot32() = 0;
	virtual void slot33() = 0;
	virtual void slot34() = 0;
	virtual void slot35() = 0;
	virtual void slot36() = 0;
	virtual void slot37() = 0;
	virtual void slot38() = 0;
	virtual void slot39() = 0;
	virtual void slot40() = 0;
	virtual void slot41() = 0;
	virtual void slot42() = 0;
	virtual void slot43() = 0;
	virtual void slot44() = 0;
	virtual void setTimeOfDay(TimeOfDay tod) = 0;
};

class W3DGameClient
{
public:
	virtual void setTimeOfDay(TimeOfDay tod);
};

// ?setTimeOfDay@W3DGameClient@@UAEXW4TimeOfDay@@@Z
void W3DGameClient::setTimeOfDay(TimeOfDay tod)
{
	void *water = W3DGCData00DE2000;
	if (water)
		((W3DGameClientWaterShim *)water)->setTimeOfDay(tod);
	void *shadow = W3DGCData00DE5DFC;
	if (shadow)
		((W3DGameClientShadowShim *)shadow)->setTimeOfDay(tod);
	void *display = W3DGCData00DFE9D8;
	((W3DGameClientDisplayShim *)display)->setTimeOfDay(tod);
}
