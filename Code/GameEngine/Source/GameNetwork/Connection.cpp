// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// Trimmed from Open-BFME-1
// (Code/GameEngine/Source/GameNetwork/Connection.cpp): only the placed
// Connection::setQuitting body is defined here. The constructor,
// isQueueEmpty and doRetryMetrics stay declared-only and the donor's other
// members stay out, so the unmatched-definition gate passes. Layout is the
// donor's: connection id +0x00, opened-time +0x04, stamped by winmm
// timeGetTime.

typedef int Int;
typedef unsigned int UnsignedInt;
typedef int Bool;

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);

class Connection
{
public:
	Connection();
	Bool isQueueEmpty();
	void setQuitting(UnsignedInt quitFrame);

protected:
	void doRetryMetrics();

private:
	Int m_id;
	UnsignedInt m_openedTime;
};

void Connection::setQuitting(UnsignedInt quitFrame)
{
	m_id = quitFrame;
	m_openedTime = timeGetTime();
}
