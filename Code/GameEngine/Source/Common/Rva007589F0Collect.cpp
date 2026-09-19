// Bucket-array drain used by the CGD family: splice every node out of all
// 0x2B7B buckets onto the head list. Retail @0x007589F0 (56B), called from
// ?bfmeGlobalCGD with this = the +0xAE10 bucket region (collect head lands
// exactly on the family's +0xADEC head slot).

struct Rva007589F0Node
{
	unsigned char m_pad00[0x30];
	Rva007589F0Node *m_next; // +0x30
};

class Rva007589F0
{
public:
	void collectAll();
	Rva007589F0Node *m_buckets[0x2B7B]; // +0x00
	Rva007589F0Node *m_head; // +0xADEC
};

void Rva007589F0::collectAll()
{
	for (unsigned i = 0; i < 0x2B7B; i++)
	{
		Rva007589F0Node *node = m_buckets[i];
		if (node != 0)
		{
			do
			{
				Rva007589F0Node *next = node->m_next;
				node->m_next = m_head;
				m_head = node;
				node = next;
			} while (node != 0);
		}
		m_buckets[i] = 0;
	}
}
