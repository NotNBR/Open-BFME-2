// ?init@FrameData@@QAEXXZ
// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /EHsc
//
// FrameData::init, retail 0x005DA4F9, 100 bytes. BFME1 FrameData.cpp shape
// (reference/open-bfme-1, where this is 135B matched): allocate the command
// list on first use, then reset it and clear the counters. BFME2 adaptations,
// all retail-measured: no m_commandList->init() call (BFME1 has one; retail
// calls reset() on the fresh list instead, then reset() again on the member,
// so both reset calls in this body target 0x0058B283); the two -2 stores share
// one push/pop materialization under /O1; member layout is the shim-proven
// +0/+4/+8/+0xC/+0x10 (m_frameCommandCount/m_commandCount/m_commandList/
// m_lastFailedCC/m_lastFailedFrameCC, no m_frame). /O1 selects the outlined
// __EH_prolog head (mov eax,scope + call 0x00629188) rather than SEH funclets.

void *operator new(unsigned int size);

class NetCommandList
{
	// Proven 0x10 layout from the matched NetCommandList::reset TU: the new
	// size retail pushes (0x10) is this class, not a 1-byte shell.
	void *m_unreconstructed_00;
	void *m_head;
	int m_count;
	int m_unreconstructed_0C;

public:
	NetCommandList(void);
	void reset(void);
};

class FrameData
{
public:
	void init(void);

private:
	int m_frameCommandCount;
	int m_commandCount;
	NetCommandList *m_commandList;
	int m_lastFailedCC;
	int m_lastFailedFrameCC;
};

// ?init@FrameData@@QAEXXZ
void FrameData::init(void)
{
	if (m_commandList == 0)
	{
		m_commandList = new NetCommandList;
		m_commandList->reset();
	}
	m_commandList->reset();

	m_frameCommandCount = -1;
	m_commandCount = 0;
	m_lastFailedCC = -2;
	m_lastFailedFrameCC = -2;
}
