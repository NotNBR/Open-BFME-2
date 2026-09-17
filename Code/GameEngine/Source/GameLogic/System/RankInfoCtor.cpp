// cl: /O1 /DNDEBUG /MD /EHsc
// stlport
//
// ??0RankInfo@@QAE@XZ,
// retail 0x0020010B, 76 bytes. Dedicated TU.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/GameLogic/System/RankInfoConstructorThunk.cpp,
// RankInfo::RankInfo): BFME2 layout measured from retail (vector at +0x38,
// seven -1 words at +0x18..+0x30, zeros at +0x10/+0x14/+0x34, -1 at +0x0C).

#include <vector>

typedef int Int;

class Overridable
{
public:
	Overridable() : m_nextOverride(0), m_isAllocatedOverride(0), m_extra0C(-1) {}
	virtual void overridableAnchor();

private:
	Overridable *m_nextOverride; // +0x04
	unsigned char m_isAllocatedOverride; // +0x08
	Int m_extra0C; // +0x0C, -1 (BFME2-new third Overridable word)
};

class UnicodeString
{
public:
	UnicodeString() : m_data(0) {}
private:
	void *m_data; // +0x10
};

class RankInfo : public Overridable
{
public:
	RankInfo();

private:
	UnicodeString m_rankName; // +0x10, null
	Int m_skillPointsNeeded; // +0x14, 0
	Int m_bfme18; // +0x18, -1
	Int m_bfme1C; // +0x1C, -1
	Int m_bfme20; // +0x20, -1
	Int m_bfme24; // +0x24, -1
	Int m_bfme28; // +0x28, -1
	Int m_bfme2C; // +0x2C, -1
	Int m_bfme30; // +0x30, -1
	Int m_sciencePurchasePointsGranted; // +0x34, 0
	_STL::vector<Int> m_sciencesGranted; // +0x38
};

// ??0RankInfo@@QAE@XZ
RankInfo::RankInfo()
{
	m_skillPointsNeeded = 0;
	m_bfme18 = -1;
	m_bfme1C = -1;
	m_bfme20 = -1;
	m_bfme24 = -1;
	m_bfme28 = -1;
	m_bfme2C = -1;
	m_bfme30 = -1;
	m_sciencePurchasePointsGranted = 0;
}
