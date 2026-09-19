// S1 call-then-member-store family: save `this`, make one no-argument call,
// then write one constant into a member. Trimmed BFME1 byte-identical TU:
// only the placed body below is defined, the rest of the donor file is
// omitted. The callee is spelled as a no-argument void free function named
// after its (BFME1) address -- the spelling that claims no owner, because
// the bytes cannot decide between a member, a base call and a free function.

void b_00025e1e();

class Rva002E2680
{
public:
	Rva002E2680();
	char m_lead[ 4 ];
	bool m_value;
};

Rva002E2680::Rva002E2680()
{
	b_00025e1e();
	m_value = false;
}
