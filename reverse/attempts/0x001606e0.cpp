// ?Simple_Evaluate_Pivot@HTreeClass@@QBE_NHABVMatrix3D@@PAV2@@Z
// partial score=0.6 date=2026-09-15
// cl: /G7 /arch:SSE /DNDEBUG /MD /EHsc
// ?Simple_Evaluate_Pivot@HTreeClass@@QBE_NHABVMatrix3D@@PAV2@@Z
//
// HTreeClass::Simple_Evaluate_Pivot at 0x001606E0 (1144 bytes): walk from
// the pivot up to the root accumulating rotation and translation, build
// the matrix, then post-multiply by the object transform.
//
// Layout (proven by the HTreeClassCopyConstructor / HTreeClassInitDefault
// units): 0x58-byte pivots, rotation-plus-translation blocks at +0x14 and
// +0x30, Index at +0x4C.  Only Matrix3D::Multiply is called (matched
// WWMath unit); all of the quaternion math is inline.

class Vector3
{
public:
	float X, Y, Z;
};

class Quaternion
{
public:
	float X, Y, Z, W;
};

class Matrix3D
{
public:
	void Make_Identity(void)
	{
		Row[0][0] = 1.0f; Row[0][1] = 0.0f; Row[0][2] = 0.0f; Row[0][3] = 0.0f;
		Row[1][0] = 0.0f; Row[1][1] = 1.0f; Row[1][2] = 0.0f; Row[1][3] = 0.0f;
		Row[2][0] = 0.0f; Row[2][1] = 0.0f; Row[2][2] = 1.0f; Row[2][3] = 0.0f;
	}

	static void Multiply(Matrix3D const &a, Matrix3D const &b, Matrix3D *result);

	float Row[3][4];
};

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

class HTreeClass
{
public:
	bool Simple_Evaluate_Pivot(int pivot_index, Matrix3D const &obj_tm, Matrix3D *end_tm) const;

private:
	char Name[16];
	int NumPivots;					// +0x10
	PivotClass *Pivot;				// +0x14
	float ScaleFactor;				// +0x18
	unsigned char Reserved[24];
};

// ?Simple_Evaluate_Pivot@HTreeClass@@QBE_NHABVMatrix3D@@PAV2@@Z
bool HTreeClass::Simple_Evaluate_Pivot(int pivot_index, Matrix3D const &obj_tm, Matrix3D *end_tm) const
{
	if (end_tm == 0) {
		return false;
	}

	end_tm->Make_Identity();

	if (pivot_index < 0 || pivot_index >= NumPivots) {
		return false;
	}

	float qx = 0.0f, qy = 0.0f, qz = 0.0f, qw = 1.0f;
	float tx = 0.0f, ty = 0.0f, tz = 0.0f;

	for (PivotClass *pivot = &Pivot[pivot_index]; pivot != 0 && pivot->Parent != 0; pivot = pivot->Parent) {
		float x = pivot->Base.Rotation.W * tx + (pivot->Base.Rotation.Y * tz - ty * pivot->Base.Rotation.Z);
		float y = pivot->Base.Rotation.W * ty - (pivot->Base.Rotation.X * tz - tx * pivot->Base.Rotation.Z);
		float z = pivot->Base.Rotation.W * tz + (pivot->Base.Rotation.X * ty - tx * pivot->Base.Rotation.Y);
		float w = -(pivot->Base.Rotation.X * tx + pivot->Base.Rotation.Y * ty + pivot->Base.Rotation.Z * tz);
		float rtx = w * (-pivot->Base.Rotation.X) + pivot->Base.Rotation.W * x +
			(y * (-pivot->Base.Rotation.Z) - (-pivot->Base.Rotation.Y) * z);
		float rty = w * (-pivot->Base.Rotation.Y) + pivot->Base.Rotation.W * y -
			(x * (-pivot->Base.Rotation.Z) - (-pivot->Base.Rotation.X) * z);
		float rtz = w * (-pivot->Base.Rotation.Z) + pivot->Base.Rotation.W * z +
			(x * (-pivot->Base.Rotation.Y) - (-pivot->Base.Rotation.X) * y);
		tx = rtx + pivot->Base.Translation.X;
		ty = rty + pivot->Base.Translation.Y;
		tz = rtz + pivot->Base.Translation.Z;
		float nx = pivot->Base.Rotation.W * qx + qw * pivot->Base.Rotation.X +
			(pivot->Base.Rotation.Y * qz - qy * pivot->Base.Rotation.Z);
		float ny = pivot->Base.Rotation.W * qy + qw * pivot->Base.Rotation.Y -
			(pivot->Base.Rotation.X * qz - qx * pivot->Base.Rotation.Z);
		float nz = pivot->Base.Rotation.W * qz + qw * pivot->Base.Rotation.Z +
			(pivot->Base.Rotation.X * qy - qx * pivot->Base.Rotation.Y);
		float nw = pivot->Base.Rotation.W * qw -
			(pivot->Base.Rotation.X * qx + pivot->Base.Rotation.Y * qy + pivot->Base.Rotation.Z * qz);
		qx = nx;
		qy = ny;
		qz = nz;
		qw = nw;
	}

	float xx = qx * qx * 2.0f;
	float yy = qy * qy * 2.0f;
	float zz = qz * qz * 2.0f;
	float xy = qx * qy * 2.0f;
	float xz = qx * qz * 2.0f;
	float xw = qx * qw * 2.0f;
	float yz = qy * qz * 2.0f;
	float yw = qy * qw * 2.0f;
	float zw = qz * qw * 2.0f;

	end_tm->Row[0][0] = 1.0f - yy - zz;
	end_tm->Row[0][1] = xy - zw;
	end_tm->Row[0][2] = xz + yw;
	end_tm->Row[1][0] = xy + zw;
	end_tm->Row[1][1] = 1.0f - zz - xx;
	end_tm->Row[1][2] = yz - xw;
	end_tm->Row[2][0] = xz - yw;
	end_tm->Row[2][1] = yz + xw;
	end_tm->Row[2][2] = 1.0f - yy - xx;
	end_tm->Row[0][3] = tx;
	end_tm->Row[1][3] = ty;
	end_tm->Row[2][3] = tz;

	Matrix3D::Multiply(obj_tm, *end_tm, end_tm);
	return true;
}
