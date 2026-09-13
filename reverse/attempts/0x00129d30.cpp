// ?Get_Texture_Name@BFME2ParticleTextureHandle@@QBE?AVStringClass@@XZ
// partial score=0.75 date=2026-09-13
// cl: /O2 /Oy /DNDEBUG /MD /EHsc
//
// BFME2ParticleTextureHandle::Get_Texture_Name, retail 0x00129D30, 176 bytes.
// Dedicated TU so no other unit can see these bodies (cf. the Get_Texture TU).
// Null-guarded slot-0 virtual name, staged through a local StringClass with
// the temp-pool Get_String fast path, assigned over the local, then copied to
// the by-value return slot. Minimal local StringClass view: only the default
// initializer is inline (a single m_EmptyString store); every other member
// resolves to its already-landed address.
#include <string.h>

class BFME2ParticleTextureHandle;

class StringClass
{
	friend class BFME2ParticleTextureHandle;
public:
	StringClass(void) { m_Buffer = m_EmptyString; }
	StringClass(const StringClass &string, bool hint_temporary = false);
	~StringClass(void) { Free_String(); }
	const StringClass &operator=(const char *string);

	static char *m_EmptyString;

private:
	void Get_String(int length, bool is_temp);
	void Free_String(void);

	char *m_Buffer;
};

char *StringClass::m_EmptyString;

class TextureClass
{
public:
	virtual const char *Get_Name(void) const = 0;
};

class BFME2ParticleTextureHandle
{
	TextureClass *Ptr;

public:
	StringClass Get_Texture_Name(void) const;
};

StringClass BFME2ParticleTextureHandle::Get_Texture_Name(void) const
{
	const char *name;

	if (Ptr != NULL)
	{
		name = Ptr->Get_Name();
	}
	else
	{
		name = NULL;
	}

	StringClass tmp;
	int len = 0;

	if (name != NULL && (len = (int)strlen(name)) > 0)
	{
		tmp.Get_String(len + 1, false);
	}

	tmp = name;
	return tmp;
}
