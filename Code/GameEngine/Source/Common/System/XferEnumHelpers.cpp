// cl: /O1

// Labelled-enum transfer helpers: each one moves a 4-byte enum through the
// text-mode Xfer's slot-37 XferEnum virtual with its field-name label (the
// label strings live in .rdata next to neighbouring enum labels). The bodies
// are free cdecl functions taking (Xfer*, value*) with no other dependencies,
// so both helpers share this TU. The Xfer declaration below is Xfer.cpp's
// model verbatim so the XferEnum call lands on the shipped slot.

enum SlotState
{
	SLOT_OPEN = 0,
	SLOT_CLOSED = 1,
	SLOT_EASY_AI = 2,
	SLOT_MED_AI = 3,
	SLOT_BRUTAL_AI = 4,
	SLOT_AI_5 = 5,
	SLOT_PLAYER = 6
};

struct Coord3DBase
{
	float x;
	float y;
	float z;
};

struct ICoord3D
{
	int x;
	int y;
	int z;
};

class Coord2D
{
public:
	float x;
	float y;
};

struct ICoord2D
{
	int x;
	int y;
};

struct Region3D
{
	Coord3DBase lo;
	Coord3DBase hi;
};

struct IRegion3D
{
	ICoord3D lo;
	ICoord3D hi;
};

struct Region2D
{
	Coord2D lo;
	Coord2D hi;
};

struct IRegion2D
{
	ICoord2D lo;
	ICoord2D hi;
};

struct RealRange
{
	float lo;
	float hi;
};

struct RGBColor
{
	float red;
	float green;
	float blue;
};

struct RGBAColorReal
{
	float red;
	float green;
	float blue;
	float alpha;
};

struct RGBAColorInt
{
	unsigned int red;
	unsigned int green;
	unsigned int blue;
	unsigned int alpha;
};

class Xfer;

class Snapshot
{
public:
	virtual ~Snapshot();
	virtual void crc(Xfer *xfer) = 0;
	virtual void loadPostProcess() = 0;
	virtual void xfer(Xfer *xfer) = 0;
};

class AsciiString;
class UnicodeString;
class PooledString;
struct XferUnknown11;

class Xfer
{
public:
	class Version;

	Xfer();
	virtual ~Xfer();

	void Version1();

	virtual bool IsStoring() const;
	virtual bool IsLoading() const;
	virtual bool IsCRC() const;
	virtual bool IsLightCRC() const;

	virtual void v5() = 0;
	virtual void v6() = 0;
	virtual void v7() = 0;

	virtual void SkipBadBlock(Snapshot &snapshot, unsigned int size);
	virtual Xfer &XferRawBytes(void *data, unsigned int size);
	virtual Xfer &operator==(bool &value);
	virtual Xfer &operator==(char &value);
	virtual Xfer &operator==(unsigned char &value);
	virtual Xfer &operator==(short &value);
	virtual Xfer &operator==(unsigned short &value);
	virtual Xfer &operator==(int &value);
	virtual Xfer &operator==(unsigned int &value);
	virtual Xfer &operator==(__int64 &value);
	virtual Xfer &operator==(float &value);
	virtual Xfer &operator==(AsciiString &value);
	virtual Xfer &operator==(UnicodeString &value);
	virtual Xfer &operator==(PooledString &value);
	virtual Xfer &operator==(Coord3DBase &value);
	virtual Xfer &operator==(ICoord3D &value);
	virtual Xfer &operator==(Region3D &value);
	virtual Xfer &operator==(IRegion3D &value);
	virtual Xfer &operator==(Coord2D &value);
	virtual Xfer &operator==(ICoord2D &value);
	virtual Xfer &operator==(Region2D &value);
	virtual Xfer &operator==(IRegion2D &value);
	virtual Xfer &operator==(RealRange &value);
	virtual Xfer &operator==(RGBColor &value);
	virtual Xfer &operator==(RGBAColorReal &value);
	virtual Xfer &operator==(RGBAColorInt &value);
	virtual Xfer &operator==(Snapshot &value);
	virtual Xfer &operator==(XferUnknown11 &value) = 0;
	virtual Xfer &operator==(Version &value);

	virtual Xfer &XferEnum(const char *name, void *data, unsigned int size);

protected:
	virtual void XferData(unsigned int type, void *data, unsigned int size) = 0;
};

// ?XferSlotState@@YAXPAVXfer@@PAW4SlotState@@@Z
// Retail 0x003FF0B4 (24B): sole caller is GameSlot::xfer at 0x003FF649,
// passing &m_state with the "SlotState" label for the text-dump Xfer.
void XferSlotState(Xfer *xfer, SlotState *state)
{
	xfer->XferEnum("SlotState", state, 4);
}

// ?XferLivingWorldPlayerID@@YAXPAVXfer@@PAH@Z
// Retail 0x002034C4 (24B): shared helper used by 19 callers (team, player
// and slot xfer methods), moving a 4-byte Living World player ID through
// XferEnum with the "LivingWorldPlayerID" label.
void XferLivingWorldPlayerID(Xfer *xfer, int *playerID)
{
	xfer->XferEnum("LivingWorldPlayerID", playerID, 4);
}
