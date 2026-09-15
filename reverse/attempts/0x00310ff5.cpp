// ?propagateMessages@MessageStream@@QAEXXZ
// partial score=0.7 date=2026-09-15
// cl: /O1 /G6 /DNDEBUG /MD
// ?propagateMessages@MessageStream@@QAEXXZ
//
// MessageStream::propagateMessages at 0x00310FF5 (101 bytes).  Each
// translator sees every queued message; a translator that consumes one
// (returns 1) has it torn down through the slot-0 virtual and freed.
// Leftovers are handed to the command list, then both heads are cleared.
//
// Layout follows Common/MessageStream.h: TranslatorData links at +0 with
// the translator at +0xC; GameMessage links at +0x4; the stream keeps the
// message head at +0xC and the translator head at +0x14.  Only two
// out-of-line callees: CommandList::appendMessageList (existing pin) and
// scalar operator delete (matched WWLib unit).  The slot-0 teardown and
// the translator interface are trivial stubs purely to shape the vtable
// slots retail calls; both are unclaimed and never compared, and the
// twins here omit vtables/polymorphism the body never constrains.

void __cdecl operator delete(void *block);

class GameMessage;
class CommandList;

class GameMessageTranslator
{
public:
	virtual int translateGameMessage(GameMessage const *msg);
};

class TranslatorData
{
public:
	TranslatorData *m_Next;			// +0x00
	unsigned char m_pad04[8];
	GameMessageTranslator *m_translator;	// +0x0C
};

class GameMessage
{
public:
	virtual void *Destroy(int flags);

	GameMessage *m_Next;			// +0x04
};

class CommandList
{
public:
	void appendMessageList(GameMessage *list);
};

class MessageStream
{
public:
	void propagateMessages(void);

private:
	unsigned char m_pad00[0x0C];
	GameMessage *m_firstMessage;	// +0x0C
	int m_unknown10;			// +0x10
	TranslatorData *m_firstTranslator;	// +0x14
};

extern CommandList *TheCommandList;

// ?propagateMessages@MessageStream@@QAEXXZ
void MessageStream::propagateMessages(void)
{
	TranslatorData *translator = m_firstTranslator;
	GameMessage *msg, *next;
	while (translator != 0) {
		msg = m_firstMessage;
		while (msg != 0) {
			next = msg->m_Next;
			if (translator->m_translator != 0) {
				if (translator->m_translator->translateGameMessage(msg) == 1) {
					operator delete(msg->Destroy(0));
				}
			}
			msg = next;
		}
		translator = translator->m_Next;
	}

	TheCommandList->appendMessageList(m_firstMessage);
	m_firstMessage = 0;
	m_unknown10 = 0;
}
