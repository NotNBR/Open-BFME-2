// cl: /DNDEBUG /DWIN32 /D_WINDOWS /MD /O1 /GX
//
// BFME2 Object module accessors, transferred from the exact BFME1
// reconstruction (Code/GameEngine/Source/GameLogic/Object/Object.cpp).
// Retail BFME2 keeps this run of module-cache fields at the same offsets:
// behaviors at +0x18C, body at +0x194, stealth at +0x198, ai at +0x19C,
// radar data at +0x1A8.

class BehaviorModule;
class BodyModuleInterface;
class StealthUpdate;
class AIUpdateInterface;
class RadarObject;

typedef bool Bool;
typedef unsigned int UnsignedInt;

// Bit indices only; the values live in the callers' headers. Opaque here so
// this TU claims no numbering it has not measured.
enum ObjectStatusTypes;
enum KindOfType;

class Object
{
public:
	BehaviorModule **getBehaviorModules() const;
	BodyModuleInterface *getBodyModule() const;
	StealthUpdate *getStealth() const;
	AIUpdateInterface *getAI();
	RadarObject *friend_getRadarData();
	void *rva00313EA8() const;
	Bool testStatus( ObjectStatusTypes bit ) const;
	Bool isKindOf( KindOfType kind ) const;

private:
	unsigned char m_pre[0x94];		// +0x00..0x94
	unsigned int m_statusBits[3];		// +0x94, ObjectStatus bits (86-bit per BFME1)
	unsigned char m_0A0[0x6C];		// +0xA0..0x10C
	unsigned int m_kindOfBits[14];		// +0x10C, KindOf bits (max observed bit 442)
	unsigned char m_144[0x48];		// +0x144..0x18C
	BehaviorModule **m_behaviors;	// +0x18C
	void *m_contain;			// +0x190
	BodyModuleInterface *m_body;	// +0x194
	StealthUpdate *m_stealth;	// +0x198
	AIUpdateInterface *m_ai;	// +0x19C
	void *m_1A0;			// +0x1A0
	void *m_1A4;			// +0x1A4
	RadarObject *m_radarData;	// +0x1A8
};

// ?getBehaviorModules@Object@@QBEPAPAVBehaviorModule@@XZ
BehaviorModule **Object::getBehaviorModules() const
{
	return m_behaviors;
}

// ?getBodyModule@Object@@QBEPAVBodyModuleInterface@@XZ
BodyModuleInterface *Object::getBodyModule() const
{
	return m_body;
}

// ?getStealth@Object@@QBEPAVStealthUpdate@@XZ
StealthUpdate *Object::getStealth() const
{
	return m_stealth;
}

// ?getAI@Object@@QAEPAVAIUpdateInterface@@XZ
AIUpdateInterface *Object::getAI()
{
	return m_ai;
}

// ?friend_getRadarData@Object@@QAEPAVRadarObject@@XZ
RadarObject *Object::friend_getRadarData()
{
	return m_radarData;
}

// ?rva00313EA8@Object@@QBEPAXXZ
// Retail 0x00313EA8. Unclaimed 7B getter in the Object module run at
// 0x313E8C..0x313EBD (behaviors/body/stealth/ai/radar all 7B here). Reads
// [ecx+0x1A4], the slot between m_1A0 and m_radarData. Same-Object evidence:
// FUN_004A03BF calls it on the same esi as the five proven getters and caches
// the result alongside radar/ai (0xA0440/0xA044A/0xA0454). Semantic identity
// (physics vs contain vs disabledMask vs partitionData) unproven, so the name
// keeps the address token per the opaque convention.
void *Object::rva00313EA8() const
{
	return m_1A4;
}

// ?testStatus@Object@@QBE_NW4ObjectStatusTypes@@@Z
// Retail 0x0004E536. Plain bit test over the status words at +0x94; the bit
// indices callers pass run past 70, so this is the ObjectStatus mask, and the
// same shape with the KindOf mask below is isKindOf.
Bool Object::testStatus( ObjectStatusTypes bit ) const
{
	return ( m_statusBits[(UnsignedInt)bit >> 5] & ( 1 << ( bit & 31 ) ) ) != 0;
}

// ?isKindOf@Object@@QBE_NW4KindOfType@@@Z
// Retail 0x0006F039. Same shape over the KindOf words at +0x10C; callers pass
// bits past 400, which only the KindOf mask spans.
Bool Object::isKindOf( KindOfType kind ) const
{
	return ( m_kindOfBits[(UnsignedInt)kind >> 5] & ( 1 << ( kind & 31 ) ) ) != 0;
}
