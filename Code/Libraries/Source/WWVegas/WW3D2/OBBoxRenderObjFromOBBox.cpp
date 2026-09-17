// cl: /arch:SSE2 /Ireference/shims/bfme2renderobj /DNDEBUG /MD /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// ??0OBBoxRenderObjClass@@QAE@ABVOBBoxClass@@@Z @ 0x00176000 (178B).
// Dedicated TU: boxrobj.cpp cannot take another row (bulk import left defs
// without rows or markers, failing find_declared_unmatched on any staging).
// Same headers and /arch:SSE2 (retail inlines the vector/matrix ops as SSE),
// so layout and codegen match the home TU. Verbatim BFME1 body.
#include "rendobj.h"
#include "boxrobj.h"

// ??0OBBoxRenderObjClass@@QAE@ABVOBBoxClass@@@Z
// Defined here (verbatim BFME1) so the ctor inlines it: retail's ctor body
// carries its two calls inline (direct RenderObj::Set_Transform + virtual
// update_cached_box) ahead of the explicit update_cached_box.
void OBBoxRenderObjClass::Set_Transform(const Matrix3D & m)
{
	RenderObjClass::Set_Transform(m);
	update_cached_box();
}

OBBoxRenderObjClass::OBBoxRenderObjClass(const OBBoxClass & box)
{
	ObjSpaceCenter.Set(Vector3(0, 0, 0));
	ObjSpaceExtent.Set(box.Extent);
	Set_Transform(Matrix3D(box.Basis, box.Center));
	update_cached_box(); // cached box should == box!
}
