// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc
// stlport
// ?Random_Float@WWMath@@SAMMM@Z retail 0x0006598A (20B).
// Ported from Open-BFME-1 Code/GameEngineDevice/Source/W3DDevice/GameClient/camerashakesystem.cpp
// (BFME1 0x0040B410). The reference defines this two-argument overload inline in
// wwmath.h as Random_Float() * (max - min) + min; written out of line here so the
// TU emits the standalone body. The no-arg call resolves through the rowed
// ?Random_Float@WWMath@@SAMXZ body. Only the placed body is defined here.

class WWMath
{
public:
	static float Random_Float();
	static float Random_Float(float min, float max);
};

float WWMath::Random_Float(float min, float max)
{
	return Random_Float() * (max - min) + min;
}
