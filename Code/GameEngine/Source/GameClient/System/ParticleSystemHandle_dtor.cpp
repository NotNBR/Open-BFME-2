// cl: /O1 /DNDEBUG /MD /EHsc
// ??1BfmeParticleSystemHandle@@QAE@XZ, retail 0x0004CBC0, 55 bytes.
// Intrusive-list unlink spelt from Open-BFME-1
// (Code/GameEngine/Source/GameClient/System/ParticleSystemHandleListClear.cpp,
// whose 111B list-clear row documents the idiom): destroying the handle unlinks
// it from the ParticleSystem handle chain. BFME2 deltas (retail-measured): no
// outer m_system guard, and the chain head lives at ParticleSystem
// +0x9C/+0xA0 (first/last). Pin pre-existed; row joins it here.

class ParticleSystem;

struct BfmeParticleSystemHandle
{
	~BfmeParticleSystemHandle();
	ParticleSystem *m_system;
	BfmeParticleSystemHandle *m_previous;
	BfmeParticleSystemHandle *m_next;
};

class ParticleSystem
{
public:
	unsigned char m_pad[0x9C];
	BfmeParticleSystemHandle *m_firstHandle;	// +0x9C
	BfmeParticleSystemHandle *m_lastHandle;		// +0xA0
};

BfmeParticleSystemHandle::~BfmeParticleSystemHandle()
{
	if (m_previous)
		m_previous->m_next = m_next;
	else
		m_system->m_firstHandle = m_next;
	if (m_next)
		m_next->m_previous = m_previous;
	else
		m_system->m_lastHandle = m_previous;
	m_previous = 0;
	m_next = 0;
}
