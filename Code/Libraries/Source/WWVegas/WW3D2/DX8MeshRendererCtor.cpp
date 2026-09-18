// cl: /Ireference/shims/bfmestages /arch:SSE /G7 /DNDEBUG /DWIN32 /D_WINDOWS /MD /EHsc /Ireference/shims/sweep /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Include /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngine/Source /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Include /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/Compression /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWLib /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/GameEngineDevice/Include /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWMath /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWDebug /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/CnC_Generals_Zero_Hour/GeneralsMD/Code/Main /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep
// stlport

// ??0DX8MeshRendererClass@@QAE@XZ at retail 0x00145AA0 (101B). Dedicated TU:
// the Code/ dx8renderer.cpp TU builds against the ZH header (file-static
// delete lists, no such members), so the member-constructing BFME1 ctor
// cannot live there (same reason Clear_Pending_Delete_Lists and Shutdown
// live in DX8MeshRendererClearPendingDeleteLists.cpp).
//
// Ported verbatim from Open-BFME-1 (Code/Libraries/Source/WWVegas/WW3D2/
// dx8renderer.cpp). BFME1's header declares the same member order retail
// shows (enable_lighting +0, camera +4, rigid vector +8 with vptr/Vec/Max/
// Count, skin list +0x18, delete lists +0x1C/+0x34); visible_decal_meshes
// stays uninitialized in both games. No pins: every member ctor is header-
// inline (SimpleDynVecClass, GenericMultiListClass head self-link).
#define Matrix4x4 Matrix4  // BFME renamed it
#include "dx8renderer.h"

// ??0DX8MeshRendererClass@@QAE@XZ
DX8MeshRendererClass::DX8MeshRendererClass()
	:
	camera(NULL),
	enable_lighting(true),
	texture_category_container_list_skin(NULL)
{
}
