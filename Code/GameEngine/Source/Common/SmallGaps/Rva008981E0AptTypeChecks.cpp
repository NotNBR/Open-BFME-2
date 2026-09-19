// ?aptHasAll@Rva008981E0Value@@QAEHXZ, retail 0x006E6CD0 (17B).
// Ported from Open-BFME-1 Code/GameEngine/Source/Common/SmallGaps/Rva008981E0AptTypeChecks.cpp
// (BFME1 0x00898240). Trimmed to the placed count-comparison body;
// the three type predicates are declared-only here.
struct Rva008981E0Value
{
	int m_count;
	union
	{
		unsigned int m_flags;
		struct
		{
			unsigned int m_type : 6;
			unsigned int m_bits : 9;
			unsigned int m_pooled : 1;
		};
	};
	int aptIsType9();
	int aptIsType27();
	int aptIsType28();
	int aptHasAll();
};

// ?aptHasAll@Rva008981E0Value@@QAEHXZ
int Rva008981E0Value::aptHasAll()
{
	return (int)m_flags >= m_count;
}
