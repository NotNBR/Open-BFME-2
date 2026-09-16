// cl: /arch:SSE2 /Ireference/shims/bfme2renderobj /DNDEBUG /MD /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// ??0BoxRenderObjClass@@QAE@ABUW3dBoxStruct@@@Z @ 0x00175A40 (266B).
// Dedicated TU: boxrobj.cpp cannot take another row (bulk import left defs
// without rows or markers, failing find_declared_unmatched on any staging).
// Same headers and /arch:SSE2 (retail inlines the conversions as SSE math),
// so layout and codegen match the home TU. The name copy goes through the
// member Set_Name so the inlined strcpy keeps retail's coloring.
#include "rendobj.h"
#include "boxrobj.h"
#include <string.h>

// ??0BoxRenderObjClass@@QAE@ABUW3dBoxStruct@@@Z
// The name copy goes through the member Set_Name (as in boxrobj.cpp) so the
// inlined strcpy keeps retail's register coloring; forceinline single-use
// emits no out-of-line copy.
__forceinline void BoxRenderObjClass::Set_Name(const char *name)
{
	strcpy(Name, name);
}

BoxRenderObjClass::BoxRenderObjClass(const W3dBoxStruct & def)
{
	// BFME2 retail inlines the color/vector conversions as SSE math and
	// plain stores (no Convert_Color/Convert_Vector calls): the color bytes
	// scale by the 1/255 reciprocal from .rdata and Opacity loads 0.25f from
	// .rdata instead of a mov-immediate.
	static const float Inv255 = 1.0f / 255.0f;
	static const float DefaultOpacity = 0.25f;

	Set_Name(def.Name);
	Color.X = (float)def.Color.R * Inv255;
	Color.Y = (float)def.Color.G * Inv255;
	Color.Z = (float)def.Color.B * Inv255;
	ObjSpaceCenter.X = def.Center.X;
	ObjSpaceCenter.Y = def.Center.Y;
	ObjSpaceCenter.Z = def.Center.Z;
	ObjSpaceExtent.X = def.Extent.X;
	ObjSpaceExtent.Y = def.Extent.Y;
	ObjSpaceExtent.Z = def.Extent.Z;
	int col_bits = (def.Attributes & W3D_BOX_ATTRIBUTE_COLLISION_TYPE_MASK) >> W3D_BOX_ATTRIBUTE_COLLISION_TYPE_SHIFT;
	Set_Collision_Type(col_bits<<1);
	Opacity = DefaultOpacity;
}
