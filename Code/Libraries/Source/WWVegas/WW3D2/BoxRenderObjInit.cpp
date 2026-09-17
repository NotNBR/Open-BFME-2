// cl: /arch:SSE2 /Ireference/shims/bfme2renderobj /DNDEBUG /MD /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/shims/sweep /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWLib /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WW3D2 /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWMath /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWSaveLoad /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/Wwutil /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDownload /Ireference/open-bfme-1/Code/Libraries/Source/WWVegas/WWDebug /Ireference/open-bfme-1/Code/Libraries/Source/Compression /Ireference/shims/sweep
// ?Init@BoxRenderObjClass@@SAXXZ @ 0x00174E20 (205B).
// Dedicated TU: boxrobj.cpp cannot take another row. Same headers as the
// landed ctor TUs. BFME1 uses NEW_REF (pool); BFME2 retail uses plain global
// operator new (pinned @0x2FDA0), so plain ::new here (proven Clone pattern).
// File-statics share the home TU's retail addresses by name (clean_list
// precedent). All 8 callees already matched; no pins needed.
#include "rendobj.h"
#include "boxrobj.h"
#include "vertmaterial.h"

static VertexMaterialClass * _BoxMaterial = NULL;
static ShaderClass _BoxShader;

// ?Init@BoxRenderObjClass@@SAXXZ
void BoxRenderObjClass::Init(void)
{
	_BoxMaterial = ::new VertexMaterialClass();
	_BoxMaterial->Set_Ambient(0, 0, 0);
	_BoxMaterial->Set_Diffuse(0, 0, 0);
	_BoxMaterial->Set_Specular(0, 0, 0);
	_BoxMaterial->Set_Emissive(1, 1, 1);
	_BoxMaterial->Set_Opacity(1.0f);
	_BoxMaterial->Set_Shininess(0.0f);

	_BoxShader = ShaderClass::_PresetAlphaSolidShader;

	IsInitted = true;
}
