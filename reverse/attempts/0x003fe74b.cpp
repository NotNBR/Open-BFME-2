// ?_bfme_updateTimedOps@@YAIXZ
// partial score=0.9 date=2026-09-15
// cl: /O1 /DNDEBUG /MD
// ?_bfme_updateTimedOps@@YAIXZ
//
// GameLogic timed-operation pump at 0x003FE74B (71 bytes).  It runs the
// head of the global TimedOp queue; when the head reports finished
// (flags bit 1) it is unlinked, torn down through the slot-0 virtual and
// freed with scalar operator delete, and when the queue drains the
// input-locked bit is cleared.  The caller (GameEngineClientSubsystems)
// uses bit 0 as inputLocked and bit 2 for the mouse-visibility guard,
// matching the flags & 5 return.
//
// Only two callees: TimedOp::update (pinned at 0x003FE6E8, out of line
// elsewhere) and scalar operator delete (matched WWLib unit).  The
// slot-0 teardown is unrecovered, so this unit carries a trivial stub
// purely to shape the vtable slot retail calls; the stub itself is
// unclaimed and never compared.

void __cdecl operator delete(void *block);

class TimedOp
{
public:
	virtual void *Destroy(int flags);
	unsigned int update(void);

	TimedOp *m_Next;	// +0x04
};

extern TimedOp *g_timedOpHead;

// ?_bfme_updateTimedOps@@YAIXZ
unsigned int _bfme_updateTimedOps(void)
{
	unsigned int flags = 0;
	if (g_timedOpHead != 0) {
		flags = g_timedOpHead->update();
		if ((flags & 2) != 0) {
			TimedOp *head = g_timedOpHead;
			g_timedOpHead = head->m_Next;
			operator delete(head->Destroy(0));
		}
	}
	if (g_timedOpHead == 0) {
		flags &= 4;
	}
	return flags & 5;
}
