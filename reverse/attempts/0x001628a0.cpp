// ?Base_Update@HTreeClass@@QAEXABVMatrix3D@@@Z
// partial score=0.5 date=2026-09-15
// cl: /G7 /arch:SSE /DNDEBUG /MD /EHsc
// ?Base_Update@HTreeClass@@QAEXABVMatrix3D@@@Z
//
// HTreeClass::Base_Update at 0x001628A0 (769 bytes: Ghidra's 761-byte row
// is truncated mid-epilogue; the real end is the three-byte RET4 at
// 0x00162B9E).
//
// Layout (proven by the HTreeClassCopyConstructor / HTreeClassInitDefault
// units): PivotClass is 0x58 bytes -- Name[16], Parent at +0x10, two
// rotation-plus-translation blocks at +0x14/+0x30, Index at +0x4C,
// IsVisible at +0x50, PivotFade at +0x54.  The +0x1C member is a
// begin/end/capacity triple over 0x24-byte captured-bone records whose
// first word is the pivot index (the 0x001622B0 helper searches it).
//
// Math: the loop is parent-quaternion times pivot-base-quaternion plus a
// rotated-and-offset translation, all inline.  The bodies below are the
// engine's own formulas (BFME1 WWMath), force-inlined so no calls remain,
// exactly as retail's call-free loop requires.

class Vector3
{
public:
	__forceinline Vector3() {}
	__forceinline Vector3(float x, float y, float z) : X(x), Y(y), Z(z) {}
	__forceinline Vector3 &operator+=(Vector3 const &v)
	{
		X += v.X; Y += v.Y; Z += v.Z;
		return *this;
	}

	float X, Y, Z;
};

class Quaternion
{
public:
	__forceinline Quaternion() {}
	__forceinline explicit Quaternion(float a, float b, float c, float d) :
		X(a), Y(b), Z(c), W(d) {}

	float X, Y, Z, W;

	__forceinline void Rotate_Vector(Vector3 const &v, Vector3 *result) const
	{
		float x = W * v.X + (Y * v.Z - v.Y * Z);
		float y = W * v.Y - (X * v.Z - v.X * Z);
		float z = W * v.Z + (X * v.Y - v.X * Y);
		float w = -(X * v.X + Y * v.Y + Z * v.Z);

		result->X = w * (-X) + W * x + (y * (-Z) - (-Y) * z);
		result->Y = w * (-Y) + W * y - (x * (-Z) - (-X) * z);
		result->Z = w * (-Z) + W * z + (x * (-Y) - (-X) * y);
	}
};

__forceinline Quaternion operator*(Quaternion const &a, Quaternion const &b)
{
	return Quaternion(
		a.W * b.X + b.W * a.X + (a.Y * b.Z - b.Y * a.Z),
		a.W * b.Y + b.W * a.Y - (a.X * b.Z - b.X * a.Z),
		a.W * b.Z + b.W * a.Z + (a.X * b.Y - b.X * a.Y),
		a.W * b.W - (a.X * b.X + a.Y * b.Y + a.Z * b.Z));
}

class Matrix3D
{
public:
	__forceinline void Get_Translation(Vector3 *set) const
	{
		set->X = Row[0][3];
		set->Y = Row[1][3];
		set->Z = Row[2][3];
	}

	float Row[3][4];
};

Quaternion Build_Quaternion(Matrix3D const &matrix);

struct PivotTransformBlock
{
	Quaternion Rotation;
	Vector3 Translation;
};

struct PivotClass
{
	char Name[16];
	PivotClass *Parent;				// +0x10
	PivotTransformBlock Base;		// +0x14
	PivotTransformBlock Transform;	// +0x30
	int Index;						// +0x4C
	bool IsVisible;					// +0x50
	float PivotFade;				// +0x54
};

struct CapturedBone
{
	int Index;
	unsigned char More[0x24 - 4];
};

class HTreeClass
{
public:
	void Base_Update(Matrix3D const &root);
	void Apply_Captured_Bone(int index);

private:
	char Name[16];
	int NumPivots;					// +0x10
	PivotClass *Pivot;				// +0x14
	float ScaleFactor;				// +0x18
	CapturedBone *CaptureBegin;		// +0x1C
	CapturedBone *CaptureEnd;		// +0x20
	CapturedBone *CaptureCap;		// +0x24
	unsigned int Unknown28;
	unsigned int Unknown2C;
	unsigned int Unknown30;
};

// ?Base_Update@HTreeClass@@QAEXABVMatrix3D@@@Z
void HTreeClass::Base_Update(Matrix3D const &root)
{
	int captured_index;

	Pivot[0].Transform.Rotation = Build_Quaternion(root);
	root.Get_Translation(&Pivot[0].Transform.Translation);
	Pivot[0].IsVisible = true;
	Pivot[0].PivotFade = 1.0f;

	if (CaptureBegin == CaptureEnd) {
		captured_index = -1;
	}
	else {
		captured_index = CaptureBegin->Index;
	}

	for (int piv_idx = 1; piv_idx < NumPivots; piv_idx++) {
		PivotClass *pivot = &Pivot[piv_idx];
		PivotClass *parent = pivot->Parent;
		parent->Transform.Rotation.Rotate_Vector(pivot->Base.Translation, &pivot->Transform.Translation);
		pivot->Transform.Translation += parent->Transform.Translation;
		pivot->Transform.Rotation = parent->Transform.Rotation * pivot->Base.Rotation;
		pivot->IsVisible = true;
		pivot->PivotFade = 1.0f;
		if (piv_idx == captured_index) {
			Apply_Captured_Bone(captured_index);
		}
	}
}
