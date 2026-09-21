// cl: /O1 /DNDEBUG /MD
//
// ?buildFieldParse@W3DTreeDrawModuleData@@SAXAAVMultiIniFieldParse@@@Z,
// retail 0x000CED03 (17 bytes: a single MultiIniFieldParse::add of the class
// table at 0x00BCCFE8 with offset 0). The table runs ModelName, TextureName,
// MoveOutwardTime, MoveInwardTime, MoveOutwardDistanceFactor, DarkeningFactor,
// ToppleFX, BounceFX, StumpName, KillWhenFinishedToppling, DoTopple,
// InitialVelocityPercent, InitialAccelPercent, BounceVelocityPercent,
// MinimumToppleSpeed, SinkDistance, SinkTime, MorphTree, MorphTime, MorphFX,
// TaintedTree, FadeRate, FadeTarget, FadeDistance (25 entries plus terminator,
// class size 0x64). The two-phase ModuleData factory at retail 0x00064C0B
// pushes this proc's address before calling INI::initFromINIMultiProc, which
// names the class; the BFME1 W3DTreeDraw donor
// (reference/open-bfme-1/.../Draw/W3DTreeDraw.cpp:90) registers the same
// ModelName/TextureName/MoveOutwardTime/MoveInwardTime spine plus the topple
// block, with BFME2 extending it by Morph/Fade/Tainted entries.

class MultiIniFieldParse;

struct FieldParse;

class MultiIniFieldParse
{
public:
	void add(const FieldParse *parse, unsigned int extraOffset);
};

class W3DTreeDrawModuleData
{
public:
	static void buildFieldParse(MultiIniFieldParse &parse);
};

void W3DTreeDrawModuleData::buildFieldParse(MultiIniFieldParse &parse)
{
	parse.add(reinterpret_cast<const FieldParse *>(0x00BCCFE8), 0);
}
