// cl: /arch:SSE2 /Ireference/shims/bfme2renderobj /DNDEBUG /MD /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// ??0AABoxRenderObjClass@@QAE@ABVAABoxClass@@@Z @ 0x00175CD0 (262B).
// Dedicated TU: boxrobj.cpp cannot take another row. BFME1 twin is 147B via
// set_aabox_ctor_position helper; BFME2 retail (262B) inlines Set_Position +
// update, so both are defined in-TU (proven OBBox/AABox-def pattern).
#include "rendobj.h"
#include "boxrobj.h"

void AABoxRenderObjClass::Set_Position(const Vector3 & v)
{
	RenderObjClass::Set_Position(v);
	update_cached_box();
}

void AABoxRenderObjClass::update_cached_box(void)
{
	CachedBox.Center = Transform.Get_Translation() + ObjSpaceCenter;
	CachedBox.Extent = ObjSpaceExtent;
}

// ??0AABoxRenderObjClass@@QAE@ABVAABoxClass@@@Z
AABoxRenderObjClass::AABoxRenderObjClass(const AABoxClass & box)
{
	ObjSpaceCenter.Set(0, 0, 0);
	ObjSpaceExtent.Set(box.Extent);
	Set_Position(box.Center);
	update_cached_box();
}
