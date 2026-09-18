// cl: /DNDEBUG /DWIN32 /MD /EHsc /Ireference/shims/drawable /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad
// stlport
//
// Drawable field accessors, byte-matched against the reconstructed BFME
// Drawable layout (reference/shims/drawable/GameClient/Drawable.h). These
// are the retail bodies the incremental-link thunks jump to.
//
// They live here rather than in GameClient/Drawable.cpp because that TU
// resolves GameClient/Drawable.h to the ZH-layout reference header (m_id at
// the ZH-compiled offset 0x08c); the private /Ireference/shims/drawable
// above makes only this TU see the true BFME offsets, so converting these
// leaves does not disturb Drawable.cpp's existing matches.
#include "PreRTS.h"
#include "GameClient/Drawable.h"

// Retail body at 0x0077F6B0 (17B): mov eax,[ecx+0x138]; test eax,eax;
// je +4; add eax,0x3c; ret / xor eax,eax; ret. Matches ZH's own
// `m_locoInfo ? &m_locoInfo->m_wheelInfo : NULL` -- DrawableLocoInfo's
// internal layout (vptr + 14 Reals = 0x3c before m_wheelInfo) is unchanged
// from ZH, only the outer Drawable::m_locoInfo pointer moved.
// BFME2's copy of this body (0x00318B83) reads [ecx+0x88] instead: BFME2's
// Drawable keeps the holder pointer 0xB0 earlier. The shared shim above is
// BFME1's layout (featured rows depend on +0x138), so this TU spells the
// BFME2 offset explicitly rather than moving the shim. The +0x3c inner
// offset is unchanged, so DrawableLocoInfo's own layout carried over.
// ?getWheelInfo@Drawable@@QBEPBUTWheelInfo@@XZ
const TWheelInfo *Drawable::getWheelInfo( void ) const
{
	const void *locoInfo = *reinterpret_cast<const void * const *>(
		reinterpret_cast<const unsigned char *>(this) + 0x88);
	return locoInfo ? reinterpret_cast<const TWheelInfo *>(
		reinterpret_cast<const unsigned char *>(locoInfo) + 0x3c) : NULL;
}
