// cl: /Ireference/shims/bfmerendobj /G7 /arch:SSE /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep
// ?Build_Matrix3@@YA?AVMatrix3@@ABVQuaternion@@@Z candidate (Matrix3 twin of the
// landed Matrix4 body). Dedicated /arch:SSE split TU: quat.cpp builds at SSE2,
// the FPU tail only matches at SSE. Source verbatim from the BFME1 ancestor
// (Code/Libraries/Source/WWVegas/WWMath/quat.cpp, Build_Matrix3); Matrix3x3 is a
// typedef to Matrix3 there, so both spellings are the same symbol.
#include "quat.h"
#include "matrix3d.h"
#include "matrix4.h"
#include "wwmath.h"

Matrix3 Build_Matrix3(const Quaternion & q)
{
	Matrix3 m;

	m[0][0] = (float)(1.0 - 2.0 * (q[1] * q[1] + q[2] * q[2]));
	m[0][1] = (float)(2.0 * (q[0] * q[1] - q[2] * q[3]));
	m[0][2] = (float)(2.0 * (q[2] * q[0] + q[1] * q[3]));

	m[1][0] = (float)(2.0 * (q[0] * q[1] + q[2] * q[3]));
	m[1][1] = (float)(1.0 - 2.0f * (q[2] * q[2] + q[0] * q[0]));
	m[1][2] = (float)(2.0 * (q[1] * q[2] - q[0] * q[3]));

	m[2][0] = (float)(2.0 * (q[2] * q[0] - q[1] * q[3]));
	m[2][1] = (float)(2.0 * (q[1] * q[2] + q[0] * q[3]));
	m[2][2] =(float)(1.0 - 2.0 * (q[1] * q[1] + q[0] * q[0]));

	return m;
}
