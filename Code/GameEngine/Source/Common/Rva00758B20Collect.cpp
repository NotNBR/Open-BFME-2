// Bucket-array drain used by the CGD family: splice every node out of all
// 0x493 buckets onto the head list. Retail @0x00758B20 (56B), called from
// ?bfmeGlobalCGD with this = the +0xAE10 bucket region (collect head lands
// exactly on the family's +0xC05C freelist slot).

struct Rva00758B20Node
{
	unsigned char m_pad00[0x30];
	Rva00758B20Node *m_next; // +0x30
};

class Rva00758B20
{
public:
	void collectAll();
	Rva00758B20Node *m_buckets[0x493]; // +0x00
	Rva00758B20Node *m_head; // +0x124C
};

void Rva00758B20::collectAll()
{
	for (unsigned i = 0; i < 0x493; i++)
	{
		Rva00758B20Node *node = m_buckets[i];
		if (node != 0)
		{
			do
			{
				Rva00758B20Node *next = node->m_next;
				node->m_next = m_head;
				m_head = node;
				node = next;
			} while (node != 0);
		}
		m_buckets[i] = 0;
	}
}
