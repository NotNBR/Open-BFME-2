// A straight-line field initialiser.
//
// BFME1 byte-identical donor (reference/open-bfme-1
// Code/GameEngine/Source/Common/S3FieldInitialisers.cpp); trimmed to the
// single T1 body the sweep places.

class Rva008D2B10
{
public:
	Rva008D2B10();
	float m_00, m_04, m_08, m_0c, m_10, m_14, m_18, m_1c;
	float m_20, m_24, m_28, m_2c, m_30, m_34;
	char  m_gap[ 0x3b8 - 0x38 ];
	float m_3b8, m_3bc;
};

Rva008D2B10::Rva008D2B10()
{
	m_00 = 1.0f; m_04 = 1.0f; m_08 = 1.0f; m_0c = 1.0f;
	m_10 = 0.0f; m_14 = 0.0f; m_18 = 0.0f; m_1c = 0.0f;
	m_20 = 1.0f; m_24 = 0.0f; m_28 = 0.0f; m_2c = 1.0f;
	m_30 = 0.0f; m_34 = 0.0f;
	m_3b8 = 0.0f; m_3bc = 0.0f;
}
