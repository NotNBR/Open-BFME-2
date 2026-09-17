// cl: /O1 /DNDEBUG /MD /EHsc
//
// ?getFirstObject@GameLogic@@QAEPAVObject@@XZ,
// retail 0x0023CAD2, 7 bytes. Dedicated TU.
//
// Battle for Middle-earth reference
// (reference/open-bfme-1/Code/GameEngine/Source/GameLogic/System/GameLogic.cpp,
// GameLogic::getFirstObject): returns the head of the world object list.
// The retail object-list head sits at +0xAC; everything else is padding.
// Called from TerrainLogic::setActiveBoundary at 0x28074D to seed the
// notify-of-new-boundary walk (next link at Object+0x8C).

class Object;

class GameLogic
{
public:
	Object *getFirstObject();

private:
	unsigned char m_pad[0xAC];
	Object *m_firstObject; // +0xAC
};

// ?getFirstObject@GameLogic@@QAEPAVObject@@XZ
Object *GameLogic::getFirstObject()
{
	return m_firstObject;
}
