// cl: /O1 /DNDEBUG /MD

// ?GadgetButtonGetData@@YAPAXPAVGameWindow@@@Z, retail 0x00327D56 (24B).
// Ported from Open-BFME-1 Code/GameEngine/Source/GameClient/GUI/Gadget/GadgetPushButton.cpp
// (BFME1 0x004BBEE0). PushButtonData keeps its ZH field order up to userData;
// winGetUserData resolves through the ledger (no new pins). Trimmed to the
// placed getter; the 11 siblings are declared-only here.

typedef int Int;
typedef bool Bool;
typedef unsigned char UnsignedByte;
typedef unsigned int Color;

struct PushButtonData
{
	UnsignedByte drawClock;
	Int percentClock;
	Color colorClock;
	Bool drawBorder;
	Color colorBorder;
	void *userData;
};

class WinInstanceData
{
public:
	unsigned char m_pad[8];
	unsigned int m_state;
};

class GameWindow
{
public:
	void *winGetUserData();
	WinInstanceData *winGetInstanceData();
};

#ifndef NULL
#define NULL 0
#endif

// ?GadgetButtonGetData@@YAPAXPAVGameWindow@@@Z
void *GadgetButtonGetData(GameWindow *button)
{
	if (button == NULL)
		return NULL;

	PushButtonData *buttonData = (PushButtonData *)button->winGetUserData();
	if (buttonData == NULL)
		return NULL;

	return buttonData->userData;
}

// ?GadgetCheckLikeButtonIsChecked@@YA_NPAVGameWindow@@@Z, retail 0x00327C9B (30B).
// Selected state is bit 2 of WinInstanceData::m_state (+0x08).
Bool GadgetCheckLikeButtonIsChecked(GameWindow *button)
{
	if (button == NULL)
		return 0;

	WinInstanceData *instData = button->winGetInstanceData();
	if (instData == NULL)
		return 0;

	return (instData->m_state >> 2) & 1;
}
