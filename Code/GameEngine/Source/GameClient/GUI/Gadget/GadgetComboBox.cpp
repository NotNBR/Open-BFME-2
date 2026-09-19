// cl: /O1 /DNDEBUG /MD

// GadgetComboBox small setters, retail 0x003226E7/0x00322703.
// Ported from Open-BFME-1 Code/GameEngine/Source/GameClient/GUI/Gadget/GadgetComboBox.cpp
// (BFME1 0x004B3980/0x004B39B0). ComboBoxData/EntryData keep their ZH order
// here; winGetUserData resolves through the ledger (no new pins).

typedef int Int;
typedef bool Bool;
typedef short Short;

class GameWindow;
class ListboxData;
class DisplayString;

struct EntryData
{
	DisplayString *text;
	DisplayString *sText;
	DisplayString *constructText;
	Bool secretText;
	Bool numericalOnly;
	Bool alphaNumericalOnly;
	Bool aSCIIOnly;
	Short maxTextLen;
	Bool receivedUnichar;
	Bool drawTextFromStart;
	GameWindow *constructList;
	unsigned short charPos;
	unsigned short conCharPos;
};

struct ComboBoxData
{
	Bool isEditable;
	Int maxDisplay;
	Int maxChars;
	Bool asciiOnly;
	Bool lettersAndNumbersOnly;
	ListboxData *listboxData;
	EntryData *entryData;
	Bool dontHide;
	Int entryCount;
	GameWindow *dropDownButton;
	GameWindow *editBox;
	GameWindow *listBox;
};

class GameWindow
{
public:
	void *winGetUserData(void);
};

#ifndef NULL
#define NULL 0
#endif

// ?GadgetComboBoxSetMaxChars@@YAXPAVGameWindow@@H@Z, retail 0x003226E7 (28B).
void GadgetComboBoxSetMaxChars(GameWindow *comboBox, Int maxChars)
{
	if (comboBox == NULL)
		return;

	ComboBoxData *comboData = (ComboBoxData *)comboBox->winGetUserData();
	comboData->maxChars = maxChars;
	comboData->entryData->maxTextLen = maxChars;
}

// ?GadgetComboBoxSetMaxDisplay@@YAXPAVGameWindow@@H@Z, retail 0x00322703 (17B).
void GadgetComboBoxSetMaxDisplay(GameWindow *comboBox, Int maxDisplay)
{
	ComboBoxData *comboData = (ComboBoxData *)comboBox->winGetUserData();
	comboData->maxDisplay = maxDisplay;
}

// ?GadgetComboBoxGetLength@@YAHPAVGameWindow@@@Z, retail 0x003229B1 (20B).
// Entry count lives at +0x20 (BFME ComboBoxData places the child windows at
// +0x24/+0x28/+0x2C); load by offset so the body matches retail.
Int GadgetComboBoxGetLength(GameWindow *comboBox)
{
	ComboBoxData *comboData = (ComboBoxData *)comboBox->winGetUserData();
	if (comboData)
		return *(Int *)((char *)comboData + 0x20);

	return 0;
}
