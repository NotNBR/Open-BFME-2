// BFME 1.03 GameLogic::processCommandList at RVA 0x00383050.

class GameMessage
{
private:
	void *m_argumentList;

public:
	GameMessage *m_next;
};

class CommandList
{
public:
	virtual void commandListSlot00(void);
	virtual void commandListSlot04(void);
	virtual void commandListSlot08(void);
	virtual void commandListSlot0C(void);
	virtual void commandListSlot10(void);
	virtual void commandListSlot14(void);
	virtual void commandListSlot18(void);
	virtual void commandListSlot1C(void);
	virtual void commandListSlot20(void);
	virtual void reset(void);

private:
	int m_messageCount;
	int m_padCount;

public:
	GameMessage *m_firstMessage;
};

class GameLogic
{
public:
	void processCommandList(void);
	void logicMessageDispatcher(GameMessage *message, void *userData);
};

extern CommandList *TheCommandList;

void GameLogic::processCommandList(void)
{
	for (GameMessage *message = TheCommandList->m_firstMessage;
		 message; message = message->m_next)
	{
		logicMessageDispatcher(message, 0);
	}

	TheCommandList->reset();
}
