// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ireference/shims/networkutil /Ireference/shims/sweep /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/debug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/reference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main
// stlport
#define Matrix4x4 Matrix4  // BFME renamed it
// stlport

#include "PreRTS.h"	// This must go first in EVERY cpp file int the GameEngine

// present-unmatched: BFME-only helper, no Zero Hour counterpart.
//
// Retail: 0x00682CF0, 20 bytes. mov eax,[esp+4]; add eax,0Ah; imul eax,eax,3E8h;
// mov word ptr [012BA084h],ax; ret.
//
// 012BA084h is the exact address of NetworkUtil.cpp's GenerateNextCommandID()
// static UnsignedShort commandID (that function loads/increments the very same
// address -- three total .text xrefs to 012BA084h in the whole exe: this
// store, GenerateNextCommandID's load, and its increment). Zero Hour just
// initializes that static to a fixed 100/64000; BFME instead reseeds it here
// with a value derived from the player count. The sole caller is
// BFMEConnectionManager::attachPlayersFromGameInfo (0x00666610), which calls
// this immediately after fetching GameInfo's player count, before attaching
// any per-player slots -- i.e. once, at match-attach time.
// BFME2's copy of that static lives at 00DD2DB4h: the very next body in
// game.dat (0x5811A8: mov eax,[DD2DB4] / inc word ptr [DD2DB4] / ret) is
// GenerateNextCommandID loading and incrementing this same address, and the
// seeding store here is its only other xref.
void SeedNextCommandIDFromPlayerCount(Int numPlayers)
{
	*reinterpret_cast<unsigned short *>(0x00DD2DB4) =
			static_cast<unsigned short>((numPlayers + 10) * 1000);
}
