// A three-dimensional distance-squared (trimmed from a four-body donor; the
// other three are declared-only here).

class Gen_000D3690
{
public:
	int bfmeLookup(unsigned int index) const;
};

class BfmeVec3EJ
{
public:
	float m_bfmeX;						// +0x00
	float m_bfmeY;						// +0x04
	float m_bfmeZ;						// +0x08
};

class Gen_000E5A50
{
public:
	float bfmeDistanceSquared(const BfmeVec3EJ *point) const;

private:
	int m_bfmeHead[14];					// +0x00
	float m_bfmeX;						// +0x38
	float m_bfmeY;						// +0x3C
	float m_bfmeZ;						// +0x40
};

// ?bfmeDistanceSquared@Gen_000E5A50@@QBEMPBVBfmeVec3EJ@@@Z
float Gen_000E5A50::bfmeDistanceSquared(const BfmeVec3EJ *point) const
{
	float dx = m_bfmeX - point->m_bfmeX;
	float dy = m_bfmeY - point->m_bfmeY;
	float dz = m_bfmeZ - point->m_bfmeZ;

	return dx * dx + dy * dy + dz * dz;
}

class Gen_000E5A90
{
public:
	float bfmeDistanceSquared(const Gen_000E5A90 *other) const;
};

bool __cdecl bfmeEqualFloats(const float *first, const float *last, const float *other);
