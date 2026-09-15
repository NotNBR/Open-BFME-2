// ?bfmeOneCGD@BfmeThingCGD@@QAEXXZ
// partial score=0.7 date=2026-09-15
// cl: /DNDEBUG /MD /EHsc /O2 /Ob2
// ?bfmeOneCGD@BfmeThingCGD@@QAEXXZ
//
// BfmeThingCGD::bfmeOneCGD at 0x00758D10 (193 bytes): sweep the 0x493
// bucket array, and splice every node whose two sub-objects agree it is
// ready from its home chain onto the collection list.  Pure pointer
// surgery, no calls, so the member names below are only offset carriers;
// only the +0xAE10/+0xC05C/+0xC060/+0xC064 slots and the node +0/+4/+0x10
// /+0x2C/+0x30 shape matter.

struct BfmeCGDSub
{
	unsigned char m_pad00[0x04];
	void *m_ptr04;
	unsigned char m_pad08[0x10 - 0x08];
	int m_flag10;
};

struct BfmeCGDNode
{
	BfmeCGDSub *m_subA;		// +0x00
	BfmeCGDSub *m_subB;		// +0x04
	unsigned char m_pad08[0x10 - 0x08];
	int m_flag10;			// +0x10
	unsigned char m_pad14[0x2C - 0x14];
	void *m_prevLink;		// +0x2C: address of the link field holding this node
	BfmeCGDNode *m_next;		// +0x30
};

class BfmeThingCGD
{
public:
	void bfmeOneCGD(void);

private:
	unsigned char m_pad00[0xAE10];
	BfmeCGDNode *m_buckets[0x493];	// +0xAE10
	BfmeCGDNode *m_collect;		// +0xC05C
	int m_index;			// +0xC060
	BfmeCGDNode *m_cursor;		// +0xC064
};

// ?bfmeOneCGD@BfmeThingCGD@@QAEXXZ
void BfmeThingCGD::bfmeOneCGD(void)
{
	m_index = 0;
	m_cursor = m_buckets[0];
	for (;;) {
		if (m_cursor == 0) {
			m_index = m_index + 1;
			if (m_index == 0x493) {
				return;
			}
			m_cursor = m_buckets[m_index];
			if (m_cursor == 0) {
				continue;
			}
		}
		BfmeCGDNode *cur = m_cursor;
		m_cursor = cur->m_next;
		if (cur == 0) {
			return;
		}
		if (cur->m_subA->m_flag10 != 0) {
			goto check_second;
		}
		if (cur->m_subB->m_flag10 == 0) {
			continue;
		}
check_second:
		if (cur->m_subA->m_ptr04 == 0) {
			goto splice_node;
		}
		if (cur->m_subB->m_ptr04 == 0) {
			goto splice_node;
		}
		cur->m_flag10 = 0;
		continue;
splice_node:
		if (m_cursor != cur) {
			goto skip_advance;
		}
		m_cursor = cur->m_next;
skip_advance:
		if (cur->m_next != 0) {
			cur->m_next->m_prevLink = cur->m_prevLink;
		}
		{
			void **prevLink = (void **)cur->m_prevLink;
			*prevLink = cur->m_next;
		}
		cur->m_prevLink = 0;
		cur->m_next = m_collect;
		m_collect = cur;
	}
}
