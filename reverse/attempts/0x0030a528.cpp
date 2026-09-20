// ?convertBonePosToWorldPos@Thing@@QBEXPBUCoord3D@@PBVMatrix3D@@PAU2@PAV3@@Z
// partial score=0.6 date=2026-09-20
// cl: /arch:SSE /Oy- /DNDEBUG /MD /EHsc /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// stlport
/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// FILE: Thing_convertBonePosToWorldPos.cpp ///////////////////////////////////
// Byte-exact BFME 2 recovery of Thing::convertBonePosToWorldPos, ported from
// the Open-BFME-1 conversion. Retail inlines Matrix3D::mul and
// Matrix3D::Transform_Vector as SSE math (/arch:SSE), so this body lives in
// its own TU: Thing.cpp builds without /arch:SSE for its matched bodies.
//-----------------------------------------------------------------------------
#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

#include "Common/Thing.h"

//-------------------------------------------------------------------------------------------------
void Thing::convertBonePosToWorldPos(const Coord3D* bonePos, const Matrix3D* boneTransform, Coord3D* worldPos, Matrix3D* worldTransform) const
{
	if (worldTransform)
	{
		worldTransform->mul(m_transform, *boneTransform);
	}
	if (worldPos)
	{
		Vector3 vector;
		vector.X = bonePos->x;
		vector.Y = bonePos->y;
		vector.Z = bonePos->z;
		m_transform.Transform_Vector(m_transform, vector, &vector);
		// Structure copy: retail moves the result out with three movsd.
		*reinterpret_cast<Vector3 *>(worldPos) = vector;
	}
}
