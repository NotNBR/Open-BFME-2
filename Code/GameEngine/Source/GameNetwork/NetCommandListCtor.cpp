// ??0NetCommandList@@QAE@XZ
// cl: /DNDEBUG /MD /EHsc /O1
//
// NetCommandList constructor, retail 0x0058B06A, 19 bytes: installs vtable
// RVA 0x00870A08 (DIR32 auto-patch; slot 0 is the now-matched ??_G row, so no
// dtor definition is needed here), zeroes the three list words, returns this.
//
// Dedicated TU (callee-visibility: defining it in the init TU would inline it
// into the matched FrameData::init; defining it in the Deleter TU would see
// the defined dtor there instead of the row). The virtual dtor is declared
// only; the vtable resolves across TUs via the Deleter TU's emission.
class NetCommandList
{
public:
	NetCommandList();
protected:
	virtual ~NetCommandList();
private:
	void *m_first;
	void *m_last;
	void *m_lastMessageInserted;
};
// ??0NetCommandList@@QAE@XZ
NetCommandList::NetCommandList()
{
	m_first = 0;
	m_last = 0;
	m_lastMessageInserted = 0;
}
