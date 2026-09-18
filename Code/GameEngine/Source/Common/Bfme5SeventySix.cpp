// cl: /GX

// ?bfmeResetGrid@BfmeTaintManager@@QAEXXZ
//
// BFME1 donor Bfme5SeventySix.cpp shape: reset the owned grid, then
// re-establish it over an empty region. BFME2 repair: the grid pointer sits
// at +0x10 here, not BFME1's +0x0C (near-miss drift at +0x08: mov ecx,
// [esi+0x0C] vs [esi+0x10]). B1 0x00881070 82B -> B2 0x006C0A50 82B,
// immediate-only drift. The grid reset itself is the empty fold at
// 0x0069E440 (pin); SetRegion resolves via pin at 0x006C1500.

typedef float Real;

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include/Lib/BaseType.h
struct Coord3D
{
	Real x;
	Real y;
	Real z;

	void zero()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
};

// upstream layout: reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include/Lib/BaseType.h
struct Region3D
{
	__forceinline Region3D() {}

	__forceinline Region3D(const Region3D &other)
	{
		lo.x = other.lo.x;
		lo.y = other.lo.y;
		lo.z = other.lo.z;
		hi.x = other.hi.x;
		hi.y = other.hi.y;
		hi.z = other.hi.z;
	}

	__forceinline ~Region3D() {}

	Real width() const { return hi.x - lo.x; }
	Real height() const { return hi.y - lo.y; }

	Coord3D lo;
	Coord3D hi;
};

class Gen_008812D0
{
public:
	void bfmeReset();
	void bfmeSetRegion(const Region3D *region, Real cellSize);
	void bfmeConfigure(Region3D region, Real cellSize);

private:
	Region3D m_bfmeRegion;					// +0x00
	Real m_bfmeCellSize;					// +0x18
};

class BfmeTaintManager
{
public:
	void bfmeResetGrid();

private:
	unsigned char m_bfmeHead[0x10];				// +0x00
	Gen_008812D0 *m_bfmeGrid;				// +0x10
};

// ?bfmeResetGrid@BfmeTaintManager@@QAEXXZ
void BfmeTaintManager::bfmeResetGrid()
{
	m_bfmeGrid->bfmeReset();

	Region3D region;
	region.lo.zero();
	region.hi.zero();
	m_bfmeGrid->bfmeSetRegion(&region, 0.0f);
}

// ?bfmeSetRegion@Gen_008812D0@@QAEXPBURegion3D@@M@Z
void Gen_008812D0::bfmeSetRegion(const Region3D *region, Real cellSize)
{
	if (cellSize <= 0.0f)
		cellSize = m_bfmeCellSize;

	if (!(region->width() < 0.0f)
		&& !(region->height() < 0.0f))
	{
		bfmeConfigure(*region, cellSize);
	}
}
