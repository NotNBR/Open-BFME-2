// cl: /O1
//
// _bfme_updateTimedOps, retail 0x003FE74B (71 bytes).
//
// Direct port of the Battle for Middle-earth timed-operation pump
// (reference/open-bfme-1/Code/GameEngine/Source/Common/TimedOperations.cpp
// updateTimedOperations): sample the head node, retire it through the
// explicit deleting-destructor call plus a separate operator delete when it
// reports bit 1, narrow the flags down to bit 2 once the list drains, and
// return bits 0 and 2. The update call on the head node is a direct
// non-virtual thiscall; only the destruction goes through the vtable.

class TimedOp
{
public:
	virtual ~TimedOp(void);
	unsigned int update(void);

	TimedOp *m_next;
};

extern TimedOp *g_timedOperationHead;

unsigned int _bfme_updateTimedOps(void)
{
	unsigned int flags = 0;

	if (g_timedOperationHead != 0)
	{
		flags = g_timedOperationHead->update();

		if ((flags & 2) != 0)
		{
			TimedOp *head = g_timedOperationHead;
			g_timedOperationHead = head->m_next;
			::delete head;

			if (g_timedOperationHead == 0)
				flags &= 4;
		}
	}

	return flags & 5;
}
