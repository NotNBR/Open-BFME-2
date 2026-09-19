// cl: /O1 /DNDEBUG /MD

// GameWindow small setters, retail 0x00313B87/0x00313CF2/0x00314147.
// Ported from Open-BFME-1 Code/GameEngine/Source/GameClient/GUI/GameWindow.cpp
// (BFME1 0x00478250/0x00478440/0x00478E70). BFME moves the window fields:
// status at +0x08, size at +0x0C/+0x10, region at +0x14..0x20, input callback
// at +0x1E0. The manager's winSendSystemMsg sits at vtable +0xE8 (slot 58),
// like GadgetListBoxReset's +0xE8 call.

typedef int Int;
typedef unsigned int UnsignedInt;
typedef UnsignedInt WindowMsgData;

enum WindowMsgHandledType
{
	MSG_IGNORED,
	MSG_HANDLED
};

enum
{
	WIN_ERR_OK = 0,
	GGM_RESIZED = 16388
};

class GameWindow;

typedef WindowMsgHandledType (*GameWinInputFunc)(GameWindow *, UnsignedInt, WindowMsgData, WindowMsgData);

class GameWindowManager
{
public:
#define V(n) virtual void pad##n() = 0;
	V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
	V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
	V(16) V(17) V(18) V(19) V(20) V(21) V(22) V(23)
	V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31)
	V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
	V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47)
	V(48) V(49) V(50) V(51) V(52) V(53) V(54) V(55)
	V(56) V(57)
#undef V
	virtual WindowMsgHandledType winSendSystemMsg(GameWindow *window, UnsignedInt msg, WindowMsgData mData1, WindowMsgData mData2) = 0;
};

extern GameWindowManager *TheWindowManager;

class GameWindow
{
public:
	Int winSetSize(Int width, Int height);
	UnsignedInt winClearStatus(UnsignedInt status);
	Int winSetInputFunc(GameWinInputFunc input);

private:
	unsigned char m_pad0[0x08];
	UnsignedInt m_status;
	Int m_sizeX;
	Int m_sizeY;
	Int m_regionLoX;
	Int m_regionLoY;
	Int m_regionHiX;
	Int m_regionHiY;
	unsigned char m_pad1[0x1E0 - 0x24];
	GameWinInputFunc m_inputFunc;
};

// ?winSetSize@GameWindow@@QAEHHH@Z, retail 0x00313B87 (63B).
Int GameWindow::winSetSize(Int width, Int height)
{
	m_sizeX = width;
	m_sizeY = height;
	m_regionHiX = m_regionLoX + width;
	m_regionHiY = m_regionLoY + height;

	TheWindowManager->winSendSystemMsg(this, GGM_RESIZED, (WindowMsgData)width, (WindowMsgData)height);

	return WIN_ERR_OK;
}

// ?winClearStatus@GameWindow@@QAEII@Z, retail 0x00313CF2 (17B).
UnsignedInt GameWindow::winClearStatus(UnsignedInt status)
{
	UnsignedInt oldStatus;

	oldStatus = m_status;
	m_status &= ~status;

	return oldStatus;
}

// ?winSetInputFunc@GameWindow@@QAEHP6A?AW4WindowMsgHandledType@@PAV1@III@Z@Z, retail 0x00314147 (19B).
Int GameWindow::winSetInputFunc(GameWinInputFunc input)
{
	if (input)
		m_inputFunc = input;

	return WIN_ERR_OK;
}
