// cl: /G7 /arch:SSE /DNDEBUG /MD /EHsc
//
// ?Clone@Vector3SolidSphereRandomizer@@UBEPAVVector3Randomizer@@XZ,
// retail unclaimed (companion to the landed SolidBox/SolidCylinder Clones).
// BFME1 v3_rnd.h verbatim: plain ::new over the protected copy ctor
// (BFME2 uses plain global ::new, not the W3DMPO pool glue -- boxrobj
// Clone precedent). Dedicated TU with the proven 8-byte model
// (vptr + Radius at +4).

class Vector3Randomizer
{
public:
	virtual ~Vector3Randomizer(void) { }
	virtual Vector3Randomizer *Clone(void) const = 0;
};

class Vector3SolidSphereRandomizer : public Vector3Randomizer
{
public:
	Vector3SolidSphereRandomizer(const Vector3SolidSphereRandomizer &src) : Radius(src.Radius) { }
	virtual Vector3Randomizer *Clone(void) const;

private:
	float Radius; // +4
};

// ?Clone@Vector3SolidSphereRandomizer@@UBEPAVVector3Randomizer@@XZ
Vector3Randomizer *Vector3SolidSphereRandomizer::Clone(void) const
{
	return ::new Vector3SolidSphereRandomizer(*this);
}
