// cl: /Ob2 /G7 /arch:SSE /DNDEBUG /MD /EHsc
// readable body of ??1RoadType@@QAE@XZ: Code/GameEngineDevice/Source/W3DDevice/GameClient/W3DRoadBuffer.cpp
// BFME2 RoadType is a 0x24 nine-pointer rewrite of the three-pointer ZH
// RoadType (see the shim W3DRoadBuffer.h): the vector deleting dtor at
// 0x18E830 strides 0x24 and every member is released here. Each member is
// freed through the same 24B dtor body at 0x1960C0 that ~NodeCompressedMotionStruct
// uses for its Vis member (delete Vis at +0x18 with the same esi-tail shape,
// matched row ?Free@MotionChannelClass@@AAEXXZ plus pin
// ??1TimeCodedBitChannelClass@@QAE@XZ): the members' true type is unproven,
// so this TU redeclares the proven-sharer locally (TU-local replicas mangle
// identically) and drops its polymorphic W3DMPO base, which retail never
// dispatches through here (all nine releases are direct calls).

class TimeCodedBitChannelClass
{
public:
	~TimeCodedBitChannelClass();
};

class RoadType
{
public:
	~RoadType();

private:
	TimeCodedBitChannelClass *m_slot00;
	TimeCodedBitChannelClass *m_slot01;
	TimeCodedBitChannelClass *m_slot02;
	TimeCodedBitChannelClass *m_slot03;
	TimeCodedBitChannelClass *m_slot04;
	TimeCodedBitChannelClass *m_slot05;
	TimeCodedBitChannelClass *m_slot06;
	TimeCodedBitChannelClass *m_slot07;
	TimeCodedBitChannelClass *m_slot08;
};

RoadType::~RoadType()
{
	if (m_slot00)
		delete m_slot00;
	if (m_slot01)
		delete m_slot01;
	if (m_slot02)
		delete m_slot02;
	if (m_slot03)
		delete m_slot03;
	if (m_slot04)
		delete m_slot04;
	if (m_slot05)
		delete m_slot05;
	if (m_slot06)
		delete m_slot06;
	if (m_slot08)
		delete m_slot08;
	if (m_slot07)
		delete m_slot07;
}
