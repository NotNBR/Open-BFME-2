// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /GX
//
// BFME2 DockUpdate crippled-flag setter v2, transferred from the exact BFME1
// reconstruction (Code/GameEngine/Source/GameLogic/Object/Update/DockUpdate/DockUpdate.cpp).
// Retail BFME2 keeps the flag at the same offset (+0x65): crippling means
// approach requests are accepted but enter clearance is never granted.

class Object
{
public:
	int m_pad74[0x74 / 4];	// vptr at +0x0, id at +0x74
	int m_id;	// +0x74
};

class DockUpdate
{
public:
	virtual void setDockCrippled(bool setting);
	virtual bool isClearToEnter(const Object *docker) const;

private:
	unsigned char m_pre[0x5C];	// implicit vptr at +0x0, covers +0x04..+0x5F
	int m_activeDocker;	// +0x60
	unsigned char m_pad64;	// +0x64
	bool m_dockCrippled;	// +0x65
};

// ?setDockCrippled@DockUpdate@@UAEX_N@Z
void DockUpdate::setDockCrippled(bool setting)
{
	m_dockCrippled = setting;
}

// ?isClearToEnter@DockUpdate@@UBE_NPBVObject@@@Z
bool DockUpdate::isClearToEnter(const Object *docker) const
{
	return docker->m_id == m_activeDocker;
}
