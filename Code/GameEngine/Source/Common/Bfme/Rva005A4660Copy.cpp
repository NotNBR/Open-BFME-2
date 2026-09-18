// cl: /DNDEBUG /MD /EHsc

class Rva005A4660
{
public:
	void copy(unsigned *first, unsigned *second) const;

private:
	unsigned char m_unmodelled_000[0x4f0c]; // retail-measured: words at +0x4F0C/+0x4F10, not donor +0x4D10/+0x4D14
	unsigned m_word0;
	unsigned m_word1;
};

void Rva005A4660::copy(unsigned *first, unsigned *second) const
{
	*first = m_word0;
	*second = m_word1;
}
