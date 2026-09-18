// cl: /O2 /MD /EHsc
//
// ?Clone@GridClassicEnvironmentMapperClass@@UBEPAVTextureMapperClass@@XZ @ 0x0013D330 (85B).
// Dedicated TU: vertmaterial.cpp cannot take another row. Layout mirrors the
// landed GridTextureMapperClass copy-ctor TU (base is 0x34, the derived class
// adds no members, so the implicit copy ctor calls the matched base copy
// @0x00184420 then installs the derived vtable). BFME2 retail uses plain
// global operator new (pinned @0x2FDA0), so ::new here.

class RefCountClass
{
public:
	virtual ~RefCountClass();
	int NumRefs;
};

class TextureMapperClass : public RefCountClass
{
public:
	TextureMapperClass(const TextureMapperClass &src);
	virtual ~TextureMapperClass();
	unsigned Stage;
};

class GridTextureMapperClass : public TextureMapperClass
{
public:
	GridTextureMapperClass(const GridTextureMapperClass &src);
	virtual ~GridTextureMapperClass();
	virtual void Reset();

	int Unk;
	int Sign;
	unsigned MSPerFrame;
	float OOGridWidth;
	unsigned GridWidthLog2;
	unsigned LastFrame;
	unsigned Offset;
	unsigned Remainder;
	unsigned CurrentFrame;
	unsigned LastUsedSyncTime;
};

class GridClassicEnvironmentMapperClass : public GridTextureMapperClass
{
public:
	virtual TextureMapperClass *Clone() const;
};

// ?Clone@GridClassicEnvironmentMapperClass@@UBEPAVTextureMapperClass@@XZ
TextureMapperClass *GridClassicEnvironmentMapperClass::Clone() const
{
	return ::new GridClassicEnvironmentMapperClass(*this);
}
