// cl: /DNDEBUG /MD /EHsc

// BFME2's base destructor call goes to the rowed 14-byte body at 0x001B4E74
// (??1GameEngineDeletingBase@@UAE@XZ, folded with ??1Snapshot/??1Subsystem-
// Interface pins), so the base is declared under that established name: zero
// new pins for the base call. The member's identity is unrecovered (opaque
// address-derived name on the BFME2 target).
// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include/Common/Snapshot.h
class GameEngineDeletingBase
{
public:
	virtual void anchor();
	virtual ~GameEngineDeletingBase();
};

class Gen_dtor_00625040
{
public:
	~Gen_dtor_00625040();
};

class W3DRenderObjectSnapshot : public GameEngineDeletingBase
{
public:
	virtual ~W3DRenderObjectSnapshot();

private:
	void *m_debugName;
	// BFME2 reads the member at +0x0C (BFME1: +0x08): one unidentified dword
	// sits between the debug name and the render object.
	void *m_bfme08;
	Gen_dtor_00625040 *m_renderObject;
};

W3DRenderObjectSnapshot::~W3DRenderObjectSnapshot()
{
	delete m_renderObject;
}
