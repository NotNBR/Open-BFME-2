// cl: /G7 /arch:SSE /DNDEBUG /MD /EHsc
//
// ?Clone@Vector3HollowSphereRandomizer@@UBEPAVVector3Randomizer@@XZ,
// retail unclaimed (twin of the landed SolidSphere Clone at 0x7235F0).
// BFME1 v3_rnd.h verbatim: plain ::new over the protected copy ctor.
// Dedicated TU with the proven 8-byte model (vptr + Radius at +4).
// Vtable 0xCEFD1C proves HollowSphere via Get_Vector 0x723380 slot;
// Scale slot is the folded 0x723320 shared with SolidSphere.

class Vector3Randomizer
{
public:
	virtual ~Vector3Randomizer(void) { }
	virtual Vector3Randomizer *Clone(void) const = 0;
};

class Vector3HollowSphereRandomizer : public Vector3Randomizer
{
public:
	Vector3HollowSphereRandomizer(const Vector3HollowSphereRandomizer &src) : Radius(src.Radius) { }
	virtual Vector3Randomizer *Clone(void) const;

private:
	float Radius; // +4
};

// ?Clone@Vector3HollowSphereRandomizer@@UBEPAVVector3Randomizer@@XZ
Vector3Randomizer *Vector3HollowSphereRandomizer::Clone(void) const
{
	return ::new Vector3HollowSphereRandomizer(*this);
}
