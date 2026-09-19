// Eight tiny bodies that free something the object owns (trimmed to the placed
// Rva008B3990 body; the other seven are declared-only here).

#define R2_RELEASE( NAME, OFF )                                           \
	class NAME##Owned                                                     \
	{                                                                     \
	public:                                                               \
		virtual ~NAME##Owned();                                             \
	};                                                                    \
	class NAME                                                            \
	{                                                                     \
	public:                                                               \
		char m_leading[ OFF ];                                              \
		NAME##Owned *m_owned;                                               \
		void release();                                                     \
	};                                                                    \
	void NAME::release()                                                  \
	{                                                                     \
		delete m_owned;                                                     \
		m_owned = 0;                                                        \
	}

R2_RELEASE( Rva008B3990, 0x20 )

class Rva004C11B0
{
public:
	void release();
};

class Rva00670150
{
public:
	void release();
};

class Rva00971120
{
public:
	void release();
};

class Rva00971B70
{
public:
	void release();
};

class Rva007837C0Owner;
void Rva007837C0(Rva007837C0Owner *owner);

class Rva006915E0
{
public:
	void release();
};

class Rva00691600
{
public:
	void release();
};
