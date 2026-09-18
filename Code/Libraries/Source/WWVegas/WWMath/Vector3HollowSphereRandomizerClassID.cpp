// cl: /O2 /DNDEBUG /MD /EHsc
//
// ?Class_ID@Vector3HollowSphereRandomizer@@UBEIXZ,
// retail 0x0013C5F0 (6 bytes, mov eax,2; ret).
// BFME1 v3_rnd.h verbatim: return CLASSID_HOLLOWSPHERE (2).
// Dedicated TU with the proven 8-byte model (vptr + Radius at +4).
// Vtable proof: HollowSphere vtable 0xCEFD1C carries 0x13C5F0 in the
// Class_ID slot; Solid twin at 0x756B00 returns 1 but folds with four
// STLport codecvt virtuals there, so only Hollow gets a row.

class Vector3Randomizer
{
public:
	virtual unsigned int Class_ID(void) const = 0;
};

class Vector3HollowSphereRandomizer : public Vector3Randomizer
{
public:
	virtual unsigned int Class_ID(void) const;
};

// ?Class_ID@Vector3HollowSphereRandomizer@@UBEIXZ
unsigned int Vector3HollowSphereRandomizer::Class_ID(void) const
{
	return 2;
}
