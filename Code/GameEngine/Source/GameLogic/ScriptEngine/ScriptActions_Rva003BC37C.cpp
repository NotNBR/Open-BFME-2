// cl: /O1 /DNDEBUG /MD /EHsc /arch:SSE
//
// ScriptActions float setter over the GameLogic singleton, retail 0x003BC37C
// (19 bytes, ret 4): movss the argument into [TheGameLogic+0xD40]. Boundary
// by ret-scan; no E8 caller image-wide (likely vtable-reached or dead), so
// the true identity stays open and the row carries an address token
// (opaque-holder precedent). The /arch:SSE flag reproduces the movss pair
// (RadiusDecal_setOpacity precedent).

struct GameLogicMirror
{
	unsigned char pad[0xD40];
	float float0D40;
};

extern GameLogicMirror *TheGameLogic;

struct Rva003BC37CHolder
{
	void set(float value);
};

// ?set@Rva003BC37CHolder@@QAEXM@Z
void Rva003BC37CHolder::set(float value)
{
	TheGameLogic->float0D40 = value;
}
