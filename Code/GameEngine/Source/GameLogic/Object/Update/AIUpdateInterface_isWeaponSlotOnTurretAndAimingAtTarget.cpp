// cl: /O1 /DNDEBUG /MD
//
// ?isWeaponSlotOnTurretAndAimingAtTarget@AIUpdateInterface@@QBE_NW4WeaponSlotType@@PBVObject@@@Z,
// retail 0x002626B7, 67 bytes. Dedicated TU.
// Verbatim BFME2 logic (Code/GameEngine/Source/GameLogic/Object/Update/
// AIUpdate.cpp:735) with the BFME2 layout: m_turretAI lives at +0x20C
// (single turret, MAX_TURRETS is 1). Both TurretAI queries are direct
// (non-virtual) const calls, resolved by pins.

typedef bool Bool;

enum WeaponSlotType
{
	WEAPONSLOT_PRIMARY = 0,
	WEAPONSLOT_COUNT = 6
};

enum
{
	MAX_TURRETS = 1
};

struct TurretAI
{
	Bool isWeaponSlotOnTurret(WeaponSlotType wslot) const;
	Bool isTryingToAimAtTarget(const class Object *victim) const;
};

class AIUpdateInterface
{
	char m_pad[0x20C];
	TurretAI *m_turretAI[MAX_TURRETS];

public:
	Bool isWeaponSlotOnTurretAndAimingAtTarget(WeaponSlotType wslot, const class Object *victim) const;
};

// ?isWeaponSlotOnTurretAndAimingAtTarget@AIUpdateInterface@@QBE_NW4WeaponSlotType@@PBVObject@@@Z
Bool AIUpdateInterface::isWeaponSlotOnTurretAndAimingAtTarget(WeaponSlotType wslot, const class Object *victim) const
{
	for (int i = 0; i < MAX_TURRETS; ++i)
	{
		if (m_turretAI[i] && m_turretAI[i]->isWeaponSlotOnTurret(wslot))
		{
			return m_turretAI[i]->isTryingToAimAtTarget(victim);
		}
	}
	return false;
}
