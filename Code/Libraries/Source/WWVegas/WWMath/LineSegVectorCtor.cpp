// cl: /G7 /arch:SSE2 /O1 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/shims/sweep

#include "vector3.h"

class LineSegClass
{
public:
	Vector3 P0;
	Vector3 P1;
	Vector3 DP;
	Vector3 Dir;
	float Length;

	LineSegClass(const Vector3 &p0, const Vector3 &p1);

protected:
	void recalculate(void);
};

LineSegClass::LineSegClass(const Vector3 &p0, const Vector3 &p1) : P0(p0), P1(p1)
{
	recalculate();
}
