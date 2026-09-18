// ?remove@Gen009F5040@@QAEXPAUGen009F5040Node@@@Z
//
// BFME1 donor Gen009F5040Handle.cpp shape: unlink the node from the
// secondary list, then walk the counter pyramid (mask/count halving per
// level). BFME2 repair: m_mask sits at +0x11C here, not BFME1's +0xEC
// (near-miss drift at +0x37: mov esi,[ecx+0xEC] vs [ecx+0x11C]), so the pad
// runs 0xFC, not 0xCC. B1 0x009F4E40 134B -> B2 0x00627570 134B,
// immediate-only drift. Leaf (no callees, no pins). The handle() sibling is
// not carried here (its B2 twin is unidentified).
struct Gen009F5040Item;

struct Gen009F5040Node
{
	char m_pad00[4];
	Gen009F5040Item *m_item;
	char m_pad08[8];
	Gen009F5040Node **m_secondaryPreviousLink;
	Gen009F5040Node *m_secondaryNext;
	Gen009F5040Node **m_previousLink;
	Gen009F5040Node *m_next;
	volatile int m_index;
	int m_result24;
	int m_result28;
	int m_result2c;
};

struct Gen009F5040Counter
{
	int m_value;
	int m_pad;
};

struct Gen009F5040Bucket
{
	Gen009F5040Counter *m_counter;
	int m_pad04;
	int m_pad08;
};

class Gen009F5040
{
public:
	__declspec(noinline) void remove(Gen009F5040Node *node);

	Gen009F5040Bucket m_buckets[2];
	Gen009F5040Counter *m_rangeBegin;
	Gen009F5040Counter *m_rangeEnd;
	char m_pad20[0xfc];
	unsigned int m_mask;
	Gen009F5040Node *m_node;
};

// ?remove@Gen009F5040@@QAEXPAUGen009F5040Node@@@Z
void Gen009F5040::remove(Gen009F5040Node *node)
{
	if (node->m_secondaryNext != 0)
		node->m_secondaryNext->m_secondaryPreviousLink = node->m_secondaryPreviousLink;
	*node->m_secondaryPreviousLink = node->m_secondaryNext;

	node->m_secondaryPreviousLink = 0;
	Gen009F5040Counter *counter = m_buckets[node->m_index + 2].m_counter;

	Gen009F5040Counter *rangeEnd = m_rangeEnd;
	Gen009F5040Counter *rangeBegin = m_rangeBegin;
	unsigned int mask = m_mask >> 1;
	unsigned int count = (unsigned int)(rangeEnd - rangeBegin) >> 2;
	while (count != 0) {
		if ((node->m_result24 & mask) != 0)
			return;
		--counter->m_value;
		int step = (node->m_result2c & mask) != 0 ? 2 : 0;
		step += ((node->m_result28 & mask) != 0);
		counter += step * count + 1;
		count >>= 2;
		mask >>= 1;
	}
}
