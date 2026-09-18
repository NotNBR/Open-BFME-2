// ?detach@Rva006CD530@@QAEXXZ, retail 0x006CD530, 35 bytes.
//
// Per-node teardown for the Nugget-chain blocks: releases the head
// reference through Rva006CFDF0DecRef and, when the count reaches zero,
// destroys the head through Rva006D1210Destroy. Both callees are ledger
// rows resolving by name; this definition lives apart from the drain TU
// that declares detach (same-TU definitions capture the call locally).
// No // cl: line (defaults match the EH-free body).
int Rva006CFDF0DecRef(int *refCount);
void Rva006D1210Destroy(void *block);

class Rva006CD530
{
public:
	void detach();

private:
	void *m_head;
};

// ?detach@Rva006CD530@@QAEXXZ
void Rva006CD530::detach()
{
	void *head = m_head;
	if (head == 0)
		return;
	if (Rva006CFDF0DecRef((int *)head) != 0)
		return;
	Rva006D1210Destroy(m_head);
}
