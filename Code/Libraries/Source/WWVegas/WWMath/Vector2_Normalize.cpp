// cl: /O1 /Oy- /arch:SSE2 /EHsc /DNDEBUG /MD
//
// ?Normalize@Vector2@@QAEXXZ, retail 0x0007E60B, 72 bytes.
// Dedicated TU: the only in-tree emission (ParticleUplinkCannonUpdate.cpp,
// /Oy-implied) comes out frameless, but retail keeps an ebp frame for the
// len2 spill (movss [ebp-0x4] + fld round-trip into the Inv_Sqrt call), so
// this body lives in its own /Oy- unit. BFME1 vector2.h shape verbatim;
// Inv_Sqrt resolves to the matched ?Inv_Sqrt@WWMath@@SIMM@Z row.

class WWMath { public: static float __fastcall Inv_Sqrt(float); };

class Vector2
{
public:
	float X;
	float Y;
	float Length2() const { return X * X + Y * Y; }
	void Normalize();
};

// ?Normalize@Vector2@@QAEXXZ
void Vector2::Normalize()
{
	float len2 = Length2();
	if (len2 != 0.0f) {
		float oolen = WWMath::Inv_Sqrt(len2);
		X *= oolen;
		Y *= oolen;
	}
}
