// cl: /Ireference/shims/bfmerendobj /arch:SSE /G7 /DNDEBUG /MD /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// stlport
#define Matrix4x4 Matrix4
// BFME1 byte-identical donor: reference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2/light.cpp
// Split from light.cpp (whose nested-ZH scene.h puts Scene::Register at +0x3C);
// direct BFME1 scene.h keeps Register at retail +0x38 (Get_Scene_ID non-virtual).
#include "light.h"
#include "ww3d.h"
#include "rinfo.h"
#include "scene.h"

/***********************************************************************************************
 * LightClass::Notify_Added -- lights add themselves to the VP list when added                 *
 *=============================================================================================*/
void LightClass::Notify_Added(SceneClass * scene)
{
	RenderObjClass::Notify_Added(scene);
	scene->Register(this,SceneClass::LIGHT);
}

/***********************************************************************************************
 * LightClass::Notify_Removed -- lights remove themselves from the VP list when removed        *
 *=============================================================================================*/
void LightClass::Notify_Removed(SceneClass * scene)
{
	scene->Unregister(this,SceneClass::LIGHT);
	RenderObjClass::Notify_Removed(scene);
}
