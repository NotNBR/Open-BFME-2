// cl: /O1 /MD
//
// Opaque destructors that free a heap member at +0x04 (null-checked), the
// same shape seven times with distinct vtables. The free target at
// 0x00030830 resolves via the matched _free row. Owner identities are
// unproven (opaque Rva names). One ledger row per destructor, landed one
// commit at a time.

extern "C" void free(void *ptr);

class Rva0025BFE3
{
public:
	virtual ~Rva0025BFE3();

private:
	void *m_ptr04;
};

Rva0025BFE3::~Rva0025BFE3()
{
	if (m_ptr04)
		free(m_ptr04);
}
