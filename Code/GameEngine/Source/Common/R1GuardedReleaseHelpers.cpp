class Gen0089C880
{
public:
	void handle();
};

class BfmeThingVGP
{
public:
	int bfmeGoVGP();
};

class Rva008A2C60
{
public:
	void go();
	char m_lead[ 0x10 ];
	Gen0089C880 *m_target;
	bool m_done;
};
void Rva008A2C60::go()
{
	if( m_target )
		m_target->handle();
	m_done = true;
}

class Rva00958C40
{
public:
	void go();
	BfmeThingVGP *m_target;
};
// ?go@Rva00958C40@@QAEXXZ, retail 0x00176FF0 (22B).
// Call-and-clear-together shape (the jz covers the call and the store).
// The callee is the _bstr_t Data release the WebBrowser lane donor-attests
// as ?bfmeGoVGP@BfmeThingVGP@@QAEHXZ (ledger pin at 0x00176E90); BFME1's
// opaque Gen00958BF0::handle names the same release, so no new pin is added.
void Rva00958C40::go()
{
	if( m_target )
	{
		m_target->bfmeGoVGP();
		m_target = 0;
	}
}
