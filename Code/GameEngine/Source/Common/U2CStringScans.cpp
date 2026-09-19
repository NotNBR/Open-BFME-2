// Two relocation-free scans over a NUL-terminated buffer.
//
// 0x00850790 is a string hash with a rolling five-bit rotation; it is a free
// function taking one argument, not a member (declared-only here).
//
// Identity is not recovered; both names are derived from an address.

class Rva0084E030Buffer
{
public:
	void squash();

	char m_chars[1];
};

void Rva0084E030Buffer::squash()
{
	char *p = m_chars;
	while (*p)
	{
		if (*p >= '0' && *p <= '9')
		{
			*p = (char)(*p - '0');
			++p;
		}
		else if (*p == ';')
		{
			char *q = p;
			while (*q)
			{
				*q = q[1];
				++q;
			}
		}
		else
		{
			++p;
		}
	}
}

unsigned int Rva00850790Hash(const char *s);
