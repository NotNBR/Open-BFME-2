// Trimmed from Open-BFME-1
// (Code/GameEngine/Source/Common/R2GuardedGlobalCalls.cpp): only the placed
// ?run@Rva007E8AC0 body is defined here. The donor's other members (guarded
// tail dispatches Rva0007C530/Rva002EEA30/Rva002EEA50/Rva007B7600, the guarded
// this-dispatch Rva002D9AC0::run, field writes Rva00588E40::run and
// Rva0073A860/Rva0073B540/Rva00739D20 plus Rva00739C10::release) stay out of
// this TU so the unmatched-definition gate passes; the ICF-folded
// Rva007B7600 twin is deliberately unclaimed (over-claim, see the sweep).

class Rva007E8AC0
{
public:
	char m_leadingA[0x10];
	char *m_at10;
	char m_leadingB[4];
	int m_at18;
	char m_leadingC[8];
	int m_at24;
	char m_leadingD[4];
	int m_at2C;
	void run();
};

void Rva007E8AC0::run()
{
	*m_at10 = 0;
	m_at18 = 0;
	m_at24 = 0;
	m_at2C = 4;
}
