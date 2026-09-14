// ?getPristineBonePositions@Drawable@@QBEHPBDHPAUCoord3D@@PAVMatrix3D@@HH@Z
// partial score=0.15 date=2026-09-14
// cl: /O1 /DNDEBUG /MD /EHsc
//
// Drawable::getPristineBonePositions (seven-argument form), retail 0x0027274D,
// 123 bytes. Module list at +0x14C, condition state at +0x258, draw-module
// vtable slot 0xA4 for the object-draw interface, seven-argument form at
// slot 0xC. Positions advance by sizeof(Coord3D), transforms by
// sizeof(Matrix3D). Structure follows the BFME1 recovery of the same query.

typedef int Int;

struct Coord3D
{
	float x;
	float y;
	float z;
};

class Matrix3D
{
	float m[12];
};

// Slot 3 is the seven-argument form. Declared after a placeholder so the
// vtable slot lands at 0xC, matching retail's `call dword ptr [edx+0xC]`.
class BfmeObjectDrawForPristine
{
public:
	virtual void slot00() = 0;
	virtual void slot04() = 0;
	virtual void slot08() = 0;
	virtual Int getPristineBonePositions(const void *conditionState,
		const char *boneNamePrefix, Int startIndex,
		Coord3D *positions, Matrix3D *transforms, Int maxBones,
		Int extra) const = 0;
};

class BfmeDrawModuleForPristine
{
public:
	virtual void slot00() = 0;
	// ... slot 0xA4/4 = 41 holds the object-draw interface getter.
	virtual void s04() = 0; virtual void s08() = 0; virtual void s0C() = 0;
	virtual void s10() = 0; virtual void s14() = 0; virtual void s18() = 0;
	virtual void s1C() = 0; virtual void s20() = 0; virtual void s24() = 0;
	virtual void s28() = 0; virtual void s2C() = 0; virtual void s30() = 0;
	virtual void s34() = 0; virtual void s38() = 0; virtual void s3C() = 0;
	virtual void s40() = 0; virtual void s44() = 0; virtual void s48() = 0;
	virtual void s4C() = 0; virtual void s50() = 0; virtual void s54() = 0;
	virtual void s58() = 0; virtual void s5C() = 0; virtual void s60() = 0;
	virtual void s64() = 0; virtual void s68() = 0; virtual void s6C() = 0;
	virtual void s70() = 0; virtual void s74() = 0; virtual void s78() = 0;
	virtual void s7C() = 0; virtual void s80() = 0; virtual void s84() = 0;
	virtual void s88() = 0; virtual void s8C() = 0; virtual void s90() = 0;
	virtual void s94() = 0; virtual void s98() = 0; virtual void s9C() = 0;
	virtual void sA0() = 0;
	virtual BfmeObjectDrawForPristine *getObjectDrawInterface() = 0;
};

class Drawable
{
public:
	Int getPristineBonePositions(const char *boneNamePrefix, Int startIndex,
		Coord3D *positions, Matrix3D *transforms, Int maxBones,
		Int extra) const;
};

Int Drawable::getPristineBonePositions(const char *boneNamePrefix,
	Int startIndex, Coord3D *positions, Matrix3D *transforms, Int maxBones,
	Int extra) const
{
	Int count = 0;
	BfmeDrawModuleForPristine **dm =
		*reinterpret_cast<BfmeDrawModuleForPristine ***>(
			(unsigned char *)this + 0x14C);
	while (*dm)
	{
		if (maxBones <= 0)
			break;
		BfmeObjectDrawForPristine *di = (*dm)->getObjectDrawInterface();
		if (di)
		{
			Int subcount = di->getPristineBonePositions(
				(unsigned char *)this + 0x258, boneNamePrefix, startIndex,
				positions, transforms, maxBones, extra);
			if (subcount > 0)
			{
				count += subcount;
				if (positions)
					positions += subcount;
				if (transforms)
					transforms += subcount;
				maxBones -= subcount;
			}
		}
		++dm;
	}
	return count;
}
