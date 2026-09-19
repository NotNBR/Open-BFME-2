class Gen0089C880
{
public:
	void handle();
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
